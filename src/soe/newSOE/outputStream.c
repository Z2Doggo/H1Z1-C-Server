void addToCache(SOEOutputStream *outputStream, i32 sequence, u8 *data, bool isFragment)
{
    outputStream->appData[sequence].data = data;
    outputStream->appData[sequence].isFragment = isFragment;
    outputStream->appData[sequence].sequence = sequence;
}

void deleteFromCache(SOEOutputStream *outputStream, i32 sequence)
{
    outputStream->appData[sequence].data = NULL;
    outputStream->appData[sequence].isFragment = false;
    outputStream->appData[sequence].sequence = -1;
}

bool isReliableAvailable(SOEOutputStream *outputStream)
{
    u16 sequenceAreEqual = outputStream->_lastAck == outputStream->reliableSequence;

    if (sequenceAreEqual)
    {
        return false;
    }

    u16 difference = outputStream->_last_available_reliable_sequence - outputStream->_lastAck;
    u16 differenceNotTooBig = difference < outputStream->maxSequenceAvailable;

    return differenceNotTooBig;
}

AppData *getAvailableReliableData(SOEOutputStream *outputStream)
{
    u32 capacity = 0;

    i32 firstLASequence = outputStream->_last_available_reliable_sequence;
    u16 targetSequence = firstLASequence + outputStream->maxSequenceAvailable;
    i32 laSequence = firstLASequence;

    AppData *data = NULL;

    while (laSequence != targetSequence)
    {
        i32 sequence = laSequence + 1;

        if (outputStream->appData[sequence].data != NULL)
        {
            data = realloc(data, (capacity + 1) * sizeof(AppData));

            if (data != NULL)
            {
                data[capacity] = outputStream->appData[sequence];
                capacity++;
                outputStream->_last_available_reliable_sequence = sequence;
            }
            else
            {
                fprintf_s(stderr, "Failed to re-allocate memory to data in getAvailableReliableData function!\n");

                return NULL;
            }
        }
        else
        {
            break;
        }

        laSequence = sequence;
    }

    return data;
}

void writeReliable(SOEOutputStream *outputStream, u8 *data, u32 dataLen)
{
    if (dataLen <= outputStream->fragmentSize)
    {
        outputStream->reliableSequence++;
        addToCache(outputStream, outputStream->reliableSequence, data, 0);
    }
    else
    {
        u8 *header = malloc(dataLen + 4);
        if (header == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return;
        }

        endian_write_u32_big(header, dataLen);
        memcpy(header + 4, data, dataLen);

        for (u8 *i = header; i < header + dataLen; i += outputStream->fragmentSize)
        {
            outputStream->reliableSequence++;
            addToCache(outputStream, outputStream->reliableSequence, i, 1);
        }
    }

    if (!outputStream->hasPendingEmit && isReliableAvailable(outputStream))
    {
        printf("Is Reliable\n");
        outputStream->hasPendingEmit = true;
    }
}

void writeOrdered(SOEOutputStream *outputStream, u8 *data, u32 dataLen)
{
    if (dataLen <= outputStream->fragmentSize)
    {
        outputStream->_order_sequence++;
        printf_s("Emitting on channel %p with sequence %u\n", data, outputStream->_order_sequence);
    }
    else
    {
        printf_s("Ordered packets can't be too large, this packet will be upgraded as a reliable one\n");
        writeReliable(outputStream, data, dataLen);
    }
}

void writeOutputData(SOEOutputStream *outputStream, u8 *data, u32 dataLen)
{
    if (outputStream->useEncryption)
    {
        crypt_rc4_transform(&outputStream->rc4, data, dataLen);
    }

    if (dataLen <= outputStream->appData->packetLen)
    {
        outputStream->sequence++;
    }
    else
    {
        ASSERT((MAX_PACKET_LENGTH - DATA_HEADER_LENGTH) == (512 - 4) && (MAX_PACKET_LENGTH - DATA_HEADER_LENGTH) == outputStream->appData->packetLen);

        u8 temp[MAX_PACKET_LENGTH - DATA_HEADER_LENGTH] = {0};
        endian_write_u32_big(temp, dataLen);

        u32 initialOffset = sizeof(u32);

        for (u32 i = 0; i < dataLen;)
        {
            u32 partialDataLen = MIN(dataLen - i, outputStream->appData->packetLen);
            partialDataLen -= initialOffset;

            outputStream->sequence++;
            memcpy(&temp[initialOffset], (void *)((uptr)data + i), partialDataLen);

            i += partialDataLen;
            initialOffset = 0;
        }
    }
}

void updateOutputAck(SOEOutputStream *outputStream, i32 sequence)
{
    printf_s("[*] updateOutputAck; ack_previous=%d, sequence=%d\n", outputStream->ackPrevious, sequence);
    outputStream->ackPrevious = sequence;
}

SOEOutputStream *initOutput(SOEOutputStream *outputStream, u8 *cryptoKey, u32 cryptoKeyLen, bool useEncryption)
{
    crypt_rc4_initialize(&outputStream->rc4, cryptoKey, cryptoKeyLen);

    outputStream->sequence = -1;
    outputStream->ackPrevious = -1;
    outputStream->useEncryption = useEncryption;

    return outputStream;
}
