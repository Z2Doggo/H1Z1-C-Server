#include "stream.h"

u32 readDataLength(u8 *data)
{
    AppData *appData = malloc(sizeof(AppData));
    if (!appData)
    {
        fprintf(stderr, "Failed to allocate memory to AppData struct in parseChannelData function!\n");

        return 0;
    }

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

AppData *parseChannelData(u8 *data)
{
    AppData *appData = malloc(sizeof(AppData));
    if (!appData)
    {
        fprintf(stderr, "Failed to allocate memory to AppData struct in parseChannelData function!\n");

        return NULL;
    }

    appData->data = data;

    SOEInputStream *inputStream = malloc(sizeof(SOEInputStream));
    if (!inputStream)
    {
        fprintf(stderr, "Failed to allocate memory to SOEInputStream struct in parseChannelData function!\n");

        return NULL;
    }

    u32 offset = 0;
    u32 chunkLength = data[offset];

    if (data[0] == 0x0 && data[1] == 0x19)
    {
        offset = 2;

        while (offset < appData->dataLen)
        {
            offset = readDataLength(data + offset);

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
            if (appData->dataLen > 1 && endian_read_u16_little(data + offset) == 0)
            {
                offset += 1;
                appData->dataLen -= 1;
            }
            crypt_rc4_transform(&inputStream->rc4, data + offset, appData->dataLen);
        }
    }

    return appData;
}

static AppData *processSingleData(i32 sequence)
{
    SOEInputStream *inputStream = malloc(sizeof(SOEInputStream));
    if (!inputStream)
    {
        fprintf(stderr, "Failed to allocate memory to inputStream struct in processSingleData function!\n");
        return NULL;
    }

    inputStream->_lastProcessedSequence = sequence;
    return parseChannelData(inputStream->_appData.data);
}

static AppData *processFragmentedData(i32 firstPacketSequence)
{
    SOEInputStream *inputStream = malloc(sizeof(SOEInputStream));
    if (!inputStream)
    {
        fprintf(stderr, "Failed to allocate memory to inputStream struct in processFragmentedData function!\n");
        return NULL;
    }

    if (!inputStream->hasCpf)
    {
        addToMap(inputStream->_map, firstPacketSequence, &inputStream->_appData.dataLen);

        inputStream->cpfTotalSize = endian_read_u32_big(inputStream->_appData.data);
        inputStream->cpfDataSize = 0;

        inputStream->cpfDataWithoutHeader = realloc(inputStream->cpfDataWithoutHeader, inputStream->cpfTotalSize);
        inputStream->_lastProcessedSequence = 0;
        inputStream->hasCpf = true;
    }

    for (i32 i = 0; i < inputStream->_appData.dataLen; i++)
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
                fprintf(stderr, "Error!\n");
                return NULL;
            }

            if (inputStream->cpfDataSize == inputStream->cpfTotalSize)
            {
                for (i32 k = 0; k < inputStream->cpfProcessFragmentSequencesLength; k++)
                {
                    deleteFromMap(inputStream->_map, inputStream->cpfProcessFragmentSequences[k]);
                }
            }

            inputStream->_lastProcessedSequence = fragmentSequence;
            inputStream->hasCpf = false;

            return parseChannelData(inputStream->cpfDataWithoutHeader);
        }
        else
        {
            return NULL;
        }
    }

    return NULL;
}

static void _processAppData(AppData *appData)
{
    SOEInputStream *inputStream = malloc(sizeof(SOEInputStream));
    if (!inputStream)
    {
        fprintf(stderr, "Failed to allocate memory to inputStream struct in processFragmentedData function!\n");
        exit(EXIT_FAILURE);
    }

    for (i32 i = 0; i < appData->dataLen; i++)
    {
        AppData data = appData[i];

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

        printf("%p", data.data);
    }
}

static void _processData()
{
    SOEInputStream *inputStream = malloc(sizeof(SOEInputStream));
    if (!inputStream)
    {
        fprintf(stderr, "Failed to allocate memory to inputStream struct in processFragmentedData function!\n");
        exit(EXIT_FAILURE);
    }

    i32 nextFragmentSequence = (inputStream->_lastProcessedSequence + 1) & MaxSequence;
    getFromMap(inputStream->_map, nextFragmentSequence);

    if (nextFragmentSequence)
    {
        AppData *appData = NULL;

        if (inputStream->_appData.isFragment)
        {
            processFragmentedData(nextFragmentSequence);
        }
        else
        {
            processSingleData(nextFragmentSequence);
        }

        if (appData && appData->dataLen)
        {
            _processAppData(appData);

            // for packets received out of order
            _processData();
        }
    }
}