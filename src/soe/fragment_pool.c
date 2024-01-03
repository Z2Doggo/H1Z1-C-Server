Fragment_Pool fragment_pool_create(u32 capacity, u32 packet_length, Arena *arena)
{
    Fragment_Pool result = {
        .capacity = capacity,
        .packet_length = packet_length,
        //.fragments = arena_allocate(arena, sizeof(*result.fragments) * capacity),
        .fragments = arena_push_array(arena, Fragment_Entry, capacity),
        .buffer = arena_push_size(arena, packet_length * capacity),
        //.buffer = arena_allocate(arena, packet_length * capacity),
    };

    return result;
}

// TODO(rhett): make sure we're taking crc length into account in the fragment pool and we snip it off
void fragment_pool_insert(Fragment_Pool *pool, i32 sequence, u8 *data, u32 data_length, b32 is_fragment)
{
    if (sequence < pool->sequence_base)
    {
        printf("[!!!] Attempting to insert older sequence (%d), rejecting\n", sequence);
        return;
    }

    i32 index = sequence - pool->sequence_base;

    printf("[***] fragment_pool_insert: sequence=%d,  data=%p, data_length=%d, is_fragment=%d, index=%d\n",
           sequence, data, data_length, is_fragment, index);

    // if (index > pool->capacity)
    //{
    ASSERT_MSG(index < pool->capacity, "exceeds pool capacity");
    // printf("[X] fragment_pool_insert; %d (sequence=%d - base=%d) exceeds pool capacity\n",
    // index, sequence, pool->sequence_base);
    // abort();
    //}

    // if (data_length > pool->packet_length)
    //{
    ASSERT_MSG(data_length < pool->packet_length, "exceeds packet length");

    // printf("[X] fragment_pool_insert; Data length %d exceeds packet length (%d)\n",
    // data_length, pool->packet_length);
    // abort();
    //}

    // if (pool->fragments[index].data_length)
    //{
    ASSERT_MSG(!pool->fragments[index].data_length, "already in use");
    // printf("[X] fragment_pool_insert: Sequence %d already in use\n", index);
    // abort();
    //}

    if (index == 0 && is_fragment)
    {
        pool->buffer_target_length = endian_read_u32_big(data);
        printf("[***] Fragment_Pool target length updated: %d\n", pool->buffer_target_length);
        data_length -= 4;
        data += 4;
    }

    pool->fragments[index].is_fragment = is_fragment;
    pool->fragments[index].data_length = data_length;
    if (is_fragment)
    {
        // NOTE(rhett): Overlap fragment boundaries
        pool->fragments[index].data = pool->buffer + pool->buffer_tail;
        pool->buffer_tail += data_length;
    }
    else
    {
        // NOTE(rhett): Align to fragment boundaries
        pool->fragments[index].data = pool->buffer + (index * pool->packet_length);
        pool->buffer_tail += (index + 1) * pool->packet_length;
    }

    base_memory_copy(pool->fragments[index].data, data, data_length);
    pool->fragments_count++;
}

void fragment_pool_advance(Fragment_Pool *pool)
{
    pool->sequence_base += pool->fragments_count;
    printf("[***] Advancing Fragment_Pool; New base: %d\n", pool->sequence_base);
    pool->buffer_target_length = 0;

    // for (u32 i = 0; i < pool->buffer_tail; i++)
    //     {
    //     pool->buffer[i] = 0;
    //     }
    pool->buffer_tail = 0;

    for (u32 i = 0; i < pool->fragments_count; i++)
    {
        pool->fragments[i].data = 0;
        pool->fragments[i].data_length = 0;
        pool->fragments[i].is_fragment = 0;
    }
    pool->fragments_count = 0;
}
