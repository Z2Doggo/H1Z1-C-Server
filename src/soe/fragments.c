FragmentPool FragmentCreate(u32 capacity, u32 packetlen, Arena *arena)
{
    FragmentPool pool = {
        .capacity = capacity,
        .packetLen = packetlen,
        .entry = arena_push_array(arena, FragmentEntry, capacity),
        .buffer = arena_push_size(arena, packetlen * capacity),
    };

    return pool;
}

void FragmentInsert(FragmentPool *pool, i32 sequence, u8 *data, u32 dataLen, bool isFragment)
{
    if (sequence < pool->sequenceBase)
    {
        printf("[!!!] Attempting to insert older sequence (%d), rejecting current sequence!\n", sequence);
        return;
    }

    i32 index = sequence - pool->sequenceBase;
    printf("[***] FragmentInsert: sequence=%d,  data=%p, data_length=%d, is_fragment=%d, index=%d\n", sequence, data, dataLen, isFragment, index);

    ASSERT_MSG(index < pool->capacity, "exceeds pool capacity!\n");
    ASSERT_MSG(dataLen < pool->packetLen, "exceeds packet length!\n");
    ASSERT_MSG(!pool->entry[index].dataLen, "Already in use!\n");

    if (index == 0 && isFragment)
    {
        pool->bufferTargetLen = endian_read_u32_big(data);
        printf("[***] FragmentPool target length updated: %d\n", pool->bufferTargetLen);

        dataLen -= 4;
        data += 4;
    }

    pool->entry[index].isFragment = isFragment;
    pool->entry[index].dataLen = dataLen;

    if (isFragment)
    {
        pool->entry[index].data = pool->buffer + pool->bufferTail;
        pool->bufferTail += dataLen;
    }
    else
    {
        pool->entry[index].data = pool->buffer + (index * pool->packetLen);
        pool->bufferTail += (index + 1) * pool->packetLen;
    }

    memcpy(pool->entry[index].data, data, dataLen);
    pool->fragmentCount++;
}

void FragmentAdvance(FragmentPool *pool)
{
    pool->sequenceBase += pool->fragmentCount;
    printf("[***] Advancing FragmentPool; New base: %d\n", pool->sequenceBase);

    pool->bufferTargetLen = 0;
    pool->bufferTail = 0;

    for (u32 i = 0; i < pool->fragmentCount; i++)
    {
        pool->entry[i].data = 0;
        pool->entry[i].dataLen = 0;
        pool->entry[i].isFragment = 0;
    }

    pool->fragmentCount = 0;
}