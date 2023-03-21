internal Packet_Queue packet_queue_create(Memory_Arena* arena,
                                          i32 entries_capacity,
                                          i32 buffer_capacity,
                                          packet_queue_send_t* packet_queue_send_func)
{
	Packet_Queue result = { 0 };

	result.entries = memory_arena_push_array(arena, Packet_Queue_Entry, entries_capacity);
	//result.entries = memory_arena_allocate(arena, sizeof(*result.entries) * entries_capacity);
	result.entries_capacity = entries_capacity;

	result.buffer = memory_arena_push_length(arena, buffer_capacity);
	//result.buffer = memory_arena_allocate(arena, buffer_capacity);
	result.buffer_capacity = buffer_capacity;

	result.packet_queue_send = packet_queue_send_func;

	return result;
}

internal void packet_queue_push(Packet_Queue* queue,
                                void* session_state,
                                //i32 max_packed_length,
                                //i32 packet_kind,
                                u8* data,
                                i32 data_length)
{
	if (queue->entries_tail == queue->entries_capacity)
	{
		printf("[X] Packet Queue entries capacity exceeded\n");
		abort();
	}

	if (queue->buffer_tail + data_length > queue->buffer_capacity)
	{
		printf("[X] Packet Queue buffer capacity exceeded\n");
		abort();
	}

	Packet_Queue_Entry* entry = &queue->entries[queue->entries_tail];
	//entry->packet_kind = packet_kind;
	entry->buffer_offset = queue->buffer_tail;
	entry->length = data_length;
	//entry->max_packed_length = max_packed_length;
	entry->session_state = session_state;
	queue->entries_tail += 1;

	util_memory_copy(queue->buffer + queue->buffer_tail,
	                 data,
	                 data_length);
	queue->buffer_tail += data_length;
}

// TODO(rhett): don't think I'm happy with how this works yet
internal void packet_queue_pop_and_send(Packet_Queue* queue,
                                        void* server_state)
{
	if (!queue->entries_tail)
	{
		// TODO(rhett): maybe we won't crash here later on
		printf("[X] Nothing to pop from Packet Queue\n");
		abort();
	}

	if (!queue->buffer_tail)
	{
		printf("[X] No data in Packet Queue buffer\n");
		abort();
	}

	Packet_Queue_Entry* entry = &queue->entries[queue->entries_tail - 1];

	queue->packet_queue_send(server_state,
	                         entry->session_state,
	                         queue->buffer + entry->buffer_offset,
	                         entry->length);

	// TODO(rhett): do we need to zero the buffer?
	util_memory_set(queue->buffer + entry->buffer_offset,
	                0,
	                entry->length);
	
	queue->buffer_tail -= entry->length;
	queue->entries_tail -= 1;
	*entry = (Packet_Queue_Entry) { 0 };

	//return result;
}
