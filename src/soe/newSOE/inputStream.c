u32 readDataLength(AppData *appData, u8 *data)
{
    appData->data = data;

    u32 offset = 0;
    u32 chunkLength = data[offset];
    offset += 1;

    if (chunkLength == 0xff)
    {
        if (data[offset] == 0xff && data[offset + 1] == 0xff)
        {
            offset += 2;
            chunkLength = endian_read_u32_big(data + offset);
            offset += 4;
        }
        else if (data[offset] > 0)
        {
            offset++;
            chunkLength = endian_read_u16_big(data + offset);
            offset += 2;
        }
    }

    return offset;
}

AppData *parseChannelData(SOEInputStream *inputStream, u8 *data)
{
    inputStream->_appData->data = data;

    u32 offset = 0;
    u32 chunkLength = data[offset];

    if (data[0] == 0x0 && data[1] == 0x19)
    {
        offset = 2;

        while (offset < inputStream->_appData->dataLen)
        {
            offset = readDataLength(inputStream->_appData, data + offset);

            if (inputStream->_useEncryption)
            {
                if (chunkLength > 1 && *(u8 *)(data + offset) == 0)
                {
                    offset += 1;
                    chunkLength -= 1;
                }

                crypt_rc4_transform(&inputStream->rc4, data + offset, chunkLength);
            }

            offset += chunkLength;
        }
    }
    else
    {
        if (inputStream->_useEncryption)
        {
            if (inputStream->_appData->dataLen > 1 && endian_read_u16_little(data + offset) == 0)
            {
                offset += 1;
                inputStream->_appData->dataLen -= 1;
            }
            crypt_rc4_transform(&inputStream->rc4, data + offset, inputStream->_appData->dataLen);
        }
    }

    return inputStream->_appData;
}

static AppData *processSingleData(SOEInputStream *inputStream, i32 sequence)
{
    inputStream->_lastProcessedSequence = sequence;
    return parseChannelData(inputStream, inputStream->_appData->data);
}

static AppData *processFragmentedData(SOEInputStream *inputStream, i32 firstPacketSequence)
{
    if (!inputStream->hasCpf)
    {
        addToMap(&inputStream->_map, inputStream->_map.head->next, firstPacketSequence, &inputStream->_appData->dataLen);

        inputStream->cpfTotalSize = endian_read_u32_big(inputStream->_appData->data);
        inputStream->cpfDataSize = 0;

        inputStream->cpfDataWithoutHeader = realloc(inputStream->cpfDataWithoutHeader, inputStream->cpfTotalSize);
        inputStream->_lastProcessedSequence = 0;
        inputStream->hasCpf = true;
    }

    for (i32 i = 0; i < inputStream->_appData->dataLen; i++)
    {
        i32 fragmentSequence = (firstPacketSequence + i) % MaxSequence;
        i32 fragment = fragmentSequence;

        if (fragment)
        {
            bool isFirstPacket = fragmentSequence == firstPacketSequence;

            inputStream->cpfProcessFragmentSequences++;
            inputStream->cpfProcessFragmentSequences = realloc(inputStream->cpfProcessFragmentSequences, inputStream->cpfProcessFragmentSequencesLength * sizeof(i32));
            (inputStream->cpfProcessFragmentSequences)[inputStream->cpfProcessFragmentSequencesLength - 1] = fragmentSequence;

            memcpy(inputStream->cpfDataWithoutHeader, &inputStream->cpfDataSize, isFirstPacket ? DATA_HEADER_LENGTH : 0);
            u32 fragmentDataLen = isFirstPacket ? sizeof(fragment) - 4 : sizeof(fragment);
            inputStream->cpfDataSize += fragmentDataLen;

            if (inputStream->cpfDataSize > inputStream->cpfTotalSize)
            {
                fprintf_s(stderr, "Error!\n");
                return NULL;
            }

            if (inputStream->cpfDataSize == inputStream->cpfTotalSize)
            {
                for (i32 k = 0; k < inputStream->cpfProcessFragmentSequencesLength; k++)
                {
                    deleteFromMap(&inputStream->_map, inputStream->cpfProcessFragmentSequences[k]);
                }
            }

            inputStream->_lastProcessedSequence = fragmentSequence;
            inputStream->hasCpf = false;

            return parseChannelData(inputStream, inputStream->cpfDataWithoutHeader);
        }
        else
        {
            return NULL;
        }
    }

    return NULL;
}

static void _processAppData(SOEInputStream *inputStream)
{
    for (i32 i = 0; i < inputStream->_appData->dataLen; i++)
    {
        AppData data = inputStream->_appData[i];

        if (inputStream->_useEncryption)
        {
            if (data.dataLen > 1 && endian_read_u16_little(data.data) == 0)
            {
                crypt_rc4_transform(&inputStream->rc4, data.data + 1, data.dataLen - 1);
            }
            else
            {
                crypt_rc4_transform(&inputStream->rc4, data.data, data.dataLen);
            }
        }

        printf_s("%p", data.data);
    }
}

static void _processData(SOEInputStream *inputStream)
{
    i32 nextFragmentSequence = (inputStream->_lastProcessedSequence + 1) & MaxSequence;
    getFromMap(&inputStream->_map, nextFragmentSequence);

    if (nextFragmentSequence)
    {
        if (inputStream->_appData->isFragment)
        {
            processFragmentedData(inputStream, nextFragmentSequence);
        }
        else
        {
            processSingleData(inputStream, nextFragmentSequence);
        }

        if (inputStream->_appData && inputStream->_appData->dataLen)
        {
            _processAppData(inputStream);

            // for packets received out of order
            _processData(inputStream);
        }
    }
}

void writeInputData(SOEInputStream *inputStream, u8 *data, i32 sequence, bool isFragment)
{
    if (inputStream->_nextSequence = -1)
    {
        inputStream->_nextSequence = sequence;
    }

    if (sequence >= inputStream->_nextSequence)
    {
        printf("[!] Sequence out of order; expected %d, got %d. Throwing away\n", inputStream->_nextSequence, sequence);
    }

    addToMap(&inputStream->_map, inputStream->_map.head->next, *data, &isFragment);
    i32 ack = sequence;

    for (i32 i = 1; i < 0x10000; i++)
    {
        i32 j = (inputStream->_lastAck + i) & 0xffff;
        if (inputStream->_appData[j].data)
        {
            ack = j;
        }
        else
        {
            break;
        }
    }

    if (ack > inputStream->_lastAck)
    {
        inputStream->_lastAck = ack;
    }

    inputStream->_nextSequence = (inputStream->_lastAck + 1) & 0xffff;
    _processData(inputStream);
}

void inputStreamConstructor(SOEInputStream *inputStream, u8 *cryptoKey)
{
    inputStream->_lastProcessedSequence = -1;
    inputStream->_useEncryption = false;
    inputStream->cpfTotalSize = -1;
    inputStream->cpfDataSize = -1;

    crypt_rc4_transform(&inputStream->rc4, cryptoKey, inputStream->_appData->dataLen);
}