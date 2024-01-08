SOEInputStream *fragmentCreate(SOEInputStream *inputStream, u32 capacity, u32 packetLen, Arena *arena)
{
    inputStream->_capacity = capacity;
    inputStream->_packetLen = packetLen;
    inputStream->_appData = arena_push_array(arena, AppData, capacity);
    inputStream->_appData->buffer = arena_push_size(arena, packetLen * capacity);

    return inputStream;
}

void fragmentInsert(SOEInputStream *inputStream, i32 sequence, u8 *data, u32 dataLen, bool isFragment)
{
    if (sequence < inputStream->_sequenceBase)
    {
        printf_s("[!!!] Attempting to insert older sequence (%d), rejecting\n", sequence);
        return;
    }

    i32 index = sequence - inputStream->_sequenceBase;
    printf_s("[***] fragmentInsert: sequence=%d,  data=%p, data_length=%d, is_fragment=%d, index=%d\n", sequence, data, dataLen, isFragment, index);

    ASSERT_MSG(index < inputStream->_capacity, "exceeds pool capacity");
    ASSERT_MSG(dataLen < inputStream->_packetLen, "exceeds packet length");
    ASSERT_MSG(!inputStream->_appData[index].dataLen, "already in use");

    if (index == 0 && isFragment)
    {
        inputStream->_appData->dataLen = endian_read_u32_big(data);
        printf_s("[***] Fragment_Pool target length updated: %d\n", inputStream->_appData->dataLen);

        dataLen -= 4;
        data += 4;
    }

    inputStream->_appData[index].isFragment = isFragment;
    inputStream->_appData[index].dataLen = dataLen;
    if (isFragment)
    {
        inputStream->_appData[index].data = inputStream->_appData->buffer + inputStream->_appData->bufferTail;
        inputStream->_appData->bufferTail += dataLen;
    }
    else
    {
        inputStream->_appData[index].data = inputStream->_appData->buffer + (index * inputStream->_packetLen);
        inputStream->_appData->bufferTail += (index + 1) * inputStream->_packetLen;
    }

    memcpy(inputStream->_appData[index].data, data, dataLen);
    inputStream->fragmentCount++;
}

void fragmentAdvance(SOEInputStream *inputStream)
{
    inputStream->_sequenceBase += inputStream->fragmentCount;
    printf_s("[***] Advancing Fragment_Pool; New base: %d\n", inputStream->_sequenceBase);

    inputStream->_appData->bufferLen = 0;
    inputStream->_appData->bufferTail = 0;

    for (u32 i = 0; i < inputStream->fragmentCount; i++)
    {
        inputStream->_appData[i].data = 0;
        inputStream->_appData[i].dataLen = 0;
        inputStream->_appData[i].isFragment = 0;
    }

    inputStream->fragmentCount = 0;
}
