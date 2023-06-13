
#define SESSION_MAP_OVERHEAD(value)  (value * 4)
#define SESSION_MAP_MAX_COLLISION    3

typedef struct character_name_string character_name_string;
struct character_name_string
{
	u32 length;
	char *content;
};

typedef struct Session_Handle Session_Handle;
struct Session_Handle
{
	u32 id;
};

typedef enum Session_Kind
{
	Session_Kind_Unhandled,
	Session_Kind_Ping_Responder,
} Session_Kind;

typedef union Session_Address Session_Address;
union Session_Address
{
	u64 full;
	struct
	{
		u32 ip;
		u16 port;
	};
};

typedef struct Protocol_Options Protocol_Options;
struct Protocol_Options
{
	u32 crc_seed;
	u8 crc_size;
	u16 compression;
	u32 udp_size;
	b32 use_encryption;
};

typedef struct Session_State Session_State;
struct Session_State
{
	Session_Handle handle;
	Session_Address address;

	Protocol_Options protocol_options;
	// TODO(rhett): gonna need to keep track of what the client has acked, right?
	i32 acked_in;
	i32 sequence_in;
	// TODO(rhett): acked_out?
	i32 sequence_out;
	Rc4_State rc4_state_in;
	Rc4_State rc4_state_out;

	// TODO(rhett): we can't feed handle to the game :(
	u32 id;
	Session_Kind kind;
};

//------------------------------------------------------------------------------------------------------------------------
// NOTE(rhett): SESSION HANDLES ATTEMPT 1
//------------------------------------------------------------------------------------------------------------------------

// NOTE(rhett): [I]ndex, [G]eneration
// NOTE(rhett): GGGGGGGGGGGGG_____IIIIIIIIIIIIII
// NOTE(rhett): ________________________________
#define SESSION_HANDLE_GENERATION_READ(handle) (handle >> 19)
#define SESSION_HANDLE_GENERATION_WRITE(handle, value) handle |= (value << 19)
#define SESSION_HANDLE_INDEX_READ(handle) (handle & 0x3FFF)
#define SESSION_HANDLE_INDEX_WRITE(handle, value) handle |= (value & 0x3FFF)


typedef enum
{
	Session_Slot_Kind_Invalid,
	Session_Slot_Kind_Free,
	Session_Slot_Kind_Active,
} Session_Slot_Kind;

typedef struct Session_Slot Session_Slot;
struct Session_Slot
{
	u32 generation;
	Session_Slot_Kind kind;
	union
	{
		Session_State state;
		u32 next_index;
		// TODO(rhett): better union name
	} content;
};

typedef struct Session_Address_Bucket Session_Address_Bucket;
struct Session_Address_Bucket
{
	Session_Address key;
	Session_Handle value;
};

typedef struct Session_Pool Session_Pool;
struct Session_Pool
{
	u32 active_count;
	u32 free_head_index;
	// NOTE(rhett): index will be less than 32 bits
	u32 slots_capacity;
	Session_Slot* slots;
	// TODO(rhett): consider making some of these isizes or something
	u32 map_bucket_count;
	Session_Address_Bucket* session_address_map;
};

void session_pool_free_all(Session_Pool* pool)
{
	ASSERT(pool);

	pool->free_head_index = 1;
	for (u32 slot_iter = 1; slot_iter < pool->slots_capacity - 1; slot_iter++)
	{
		pool->slots[slot_iter].content.next_index = slot_iter + 1;
		pool->slots[slot_iter].kind = Session_Slot_Kind_Free;
	}
	pool->slots[pool->slots_capacity - 1].content.next_index = 0;
	pool->slots[pool->slots_capacity - 1].kind = Session_Slot_Kind_Free;
}

// NOTE(rhett): Reserve slot 0 as invalid
Session_Pool session_pool_create(Arena* arena, u32 capacity)
{
	// TODO(rhett): investigate alignment

	Session_Pool result = 
	{
		.slots_capacity = capacity,
		.slots = arena_push_array(arena, Session_Slot, capacity),
		.map_bucket_count = SESSION_MAP_OVERHEAD(capacity),
		.session_address_map = arena_push_array(arena, Session_Address_Bucket, result.map_bucket_count),
	};

	session_pool_free_all(&result);

	return result;
}

// TODO(rhett): return success? or bucket? bucket can be falsey and valid though signed bucket index, -1 error?
void session_address_map_insert(Session_Pool* pool, Session_Address address, Session_Handle handle)
{
	ASSERT(pool);
	ASSERT(address.full);
	ASSERT(handle.id);

	// TODO(rhett): investigate compiler output. maybe assert that we give a power of two pool capacity
	u32 index = address.full % pool->map_bucket_count;

	// NOTE(rhett): iterate while handle is truthy (occupied)
	for (u32 collision_iter = 0; pool->session_address_map[index].value.id; index++, collision_iter++)
	{
		if (collision_iter == SESSION_MAP_MAX_COLLISION)
		{
			NOT_IMPLEMENTED_MSG("Max collision count reached");
		}

		if (pool->session_address_map[index].value.id == handle.id)
		{
			NOT_IMPLEMENTED_MSG("Inserting duplicate value in address map");
		}
	}
	pool->session_address_map[index].key = address;
	pool->session_address_map[index].value = handle;
}

Session_Handle session_get_handle_from_address(Session_Pool* pool, Session_Address address)
{
	ASSERT(pool);
	ASSERT(address.full);

	// TODO(rhett): investigate compiler output. maybe assert that we give a power of two pool capacity
	u32 index = address.full % pool->map_bucket_count;

	for (u32 collision_iter = 0; pool->session_address_map[index].key.full != address.full; index++, collision_iter++)
	{
		if (collision_iter == SESSION_MAP_MAX_COLLISION)
		{
			return (Session_Handle) { 0 };
		}
	}

	return pool->session_address_map[index].value;
}

b32 session_address_map_key_exists(Session_Pool* pool, Session_Address address)
{
	UNUSED(pool);
	UNUSED(address);
	NOT_IMPLEMENTED;
	return 0;
}

Session_Handle session_acquire(Session_Pool* pool, Session_Address address)
{
	ASSERT(pool);
	ASSERT(address.full);

	Session_Handle result = { 0 };

	if (pool->active_count >= pool->slots_capacity)
	{
		NOT_IMPLEMENTED_MSG("Session pool full");
	}

	u32 index = pool->free_head_index;
	Session_Slot* slot = &pool->slots[index];

	pool->free_head_index = slot->content.next_index;
	pool->active_count++;

	slot->generation++;
	slot->kind = Session_Slot_Kind_Active;
	SESSION_HANDLE_INDEX_WRITE(result.id, index);
	SESSION_HANDLE_GENERATION_WRITE(result.id, slot->generation);
	session_address_map_insert(pool, address, result);

	base_memory_fill(&slot->content, 0, SIZE_OF(slot->content));
	Session_State* state = &slot->content.state;
	state->handle = result;
	state->address = address;

	return result;
}

Session_State* session_get_pointer_from_handle(Session_Pool* pool, Session_Handle handle)
{
#if 0
	printf(MESSAGE_CONCAT_DEBUG("Getting session pointer for %#x\n"), handle.id);
#endif

	u32 generation = SESSION_HANDLE_GENERATION_READ(handle.id);
	u32 index = SESSION_HANDLE_INDEX_READ(handle.id);

	ASSERT(index < pool->slots_capacity);
	// TODO(rhett): handle this case
	ASSERT(generation == pool->slots[index].generation);

	// TODO(rhett): maybe not right now?
	// NOTE(rhett): default to pointer to invalid slot
	//Session_State* result = &pool->slots[0];
	// TODO(rhett): Return pointer to invalid slot if something is wrong
	Session_State* result = &pool->slots[index].content.state;
	ASSERT(result);
	return result;
}

void session_release(Session_Pool* pool, Session_Handle handle)
{
	UNUSED(pool);
	UNUSED(handle);
	NOT_IMPLEMENTED;
}
