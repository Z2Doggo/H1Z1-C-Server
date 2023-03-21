// TODO(rhett): Re-write debug/internal code
// TODO(rhett): is this a fine default?
#define MEMORY_ARENA_ALIGN_DEFAULT (sizeof(void*)*2)


typedef struct Memory_Arena Memory_Arena;
struct Memory_Arena
{
	void* buffer;
	usize capacity;
	usize tail_offset;

//#if defined(INTERNAL)
	char* name;
	usize padding;
	usize peak_used;
	usize peak_padding;
	i32 active_count;
//#endif
};

typedef struct Memory_Arena_Temp Memory_Arena_Temp;
struct Memory_Arena_Temp
{
	Memory_Arena* arena;
	usize tail_offset;
};


internal Memory_Arena memory_arena_init(void* buffer, usize length, char* name)
{
	Memory_Arena result =
	{
		.capacity = length,
		.buffer = buffer,
		.name = name,
	};

	return result;
}

#define memory_arena_push_struct_align(arena, type, align) (type*)memory_arena_push_length_align(arena, sizeof(type), align)
#define memory_arena_push_struct(arena, type) memory_arena_push_struct_align(arena, type, MEMORY_ARENA_ALIGN_DEFAULT)
#define memory_arena_push_length(arena, length) memory_arena_push_length_align(arena, length, MEMORY_ARENA_ALIGN_DEFAULT)
#define memory_arena_push_array_align(arena, type, count, align) (type*)memory_arena_push_length_align(arena, sizeof(type) * count, align)
#define memory_arena_push_array(arena, type, count) memory_arena_push_array_align(arena, type, count, MEMORY_ARENA_ALIGN_DEFAULT)

internal void* memory_arena_push_length_align(Memory_Arena* arena, usize length, usize align)
{
	uptr aligned_ptr = util_align_forward((uptr)arena->buffer + arena->tail_offset, align);
	isize padding = 0;
	padding = aligned_ptr - ((uptr)arena->buffer + arena->tail_offset);

	if (length > (arena->capacity - aligned_ptr))
	{
		printf("[X] Allocation excedes arena capacity: '%s' - %u > (%u - %u)\n",
		       arena->name, length, arena->capacity, arena->tail_offset);
		return NULL;
	}

	// TODO(rhett): zeroing memory by default for now
	util_memory_set((void*)aligned_ptr, 0, length + padding);

	arena->padding += padding;
	arena->tail_offset += length + padding;
	arena->active_count += 1;
	
	return (void*)aligned_ptr;
}

internal void memory_arena_rewind(Memory_Arena* arena, u32 rewind_length)
{
	arena->tail_offset -= rewind_length;
}

internal void memory_arena_reset(Memory_Arena* arena)
{
	arena->peak_used = MAX(arena->tail_offset, arena->peak_used);
	arena->peak_padding = MAX(arena->padding, arena->peak_padding);
	arena->active_count = 0;
	arena->tail_offset = 0;
	arena->padding = 0;
}

internal Memory_Arena_Temp memory_arena_temp_begin(Memory_Arena* arena)
{
	return (Memory_Arena_Temp) { .arena = arena, .tail_offset = arena->tail_offset };
}

internal void memory_arena_temp_end(Memory_Arena_Temp temp)
{
	temp.arena->tail_offset = temp.tail_offset;
}
