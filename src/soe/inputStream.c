u32 InputStreamReadLen(u8 *data, u32 *chunkLenPtr)
{
    u32 offset = 0;
    u32 chunkLen = data[offset];

    offset += 1;

    if (chunkLen == 0xff)
    {
        if (data[offset] == 0xff && data[offset + 1] == 0xff)
        {
            offset += 2;
            chunkLen = endian_read_u32_big(data + offset);
            offset += 4;
        }
        else if (data[offset] > 0)
        {
            offset++;
            chunkLen = endian_read_u16_big(data + offset);
            offset += 2;
        }
    }

    *chunkLenPtr = chunkLen;

    return offset;
}

void InputStreamChannelDataParse(AppState *app, SessionState *session, SOEInputStream *input, u8 *data, u32 dataLen)
{
    u32 offset = 0;

    if (data[0] == 0x00 && data[1] == 0x19)
    {
        u32 chunkLen;
        offset += 2;

        while (offset < dataLen)
        {
            offset += InputStreamReadLen(data + offset, &chunkLen);

            if (input->useEncryption)
            {
                if (chunkLen > 1 && *(u8 *)(data + offset) == 0)
                {
                    offset += 1;
                    chunkLen -= 1;
                }

                crypt_rc4_transform(&input->rc4, data + offset, chunkLen);
            }

            if (*input->dataCallbackPtr)
            {
                (*input->dataCallbackPtr)(app, session, data + offset, chunkLen);
            }

            offset += chunkLen;
        }
    }
    else
    {
        if (input->useEncryption)
        {
            if (dataLen > 1 && endian_read_u16_little(data + offset) == 0)
            {
                offset += 1;
                dataLen -= 1;
            }

            crypt_rc4_transform(&input->rc4, data + offset, dataLen);
        }

        if (*input->dataCallbackPtr)
        {
            (*input->dataCallbackPtr)(app, session, data + offset, dataLen);
        }
    }
}

void InputStreamFragmentProcess(AppState *app, SessionState *session, SOEInputStream *input)
{
    i32 nextFragment = (input->previousProcessedFragment + 1) & 0xffff;
    FragmentEntry entry = input->pool->entry[0];

    if (entry.dataLen)
    {
        if (!entry.isFragment)
        {
            input->previousProcessedFragment = nextFragment;

            InputStreamChannelDataParse(app, session, input, entry.data, entry.dataLen);
            FragmentAdvance(input->pool);
        }
        else
        {
            if (input->pool->bufferTail == input->pool->bufferTargetLen)
            {
                input->previousProcessedFragment = input->pool->fragmentCount - 1;

                InputStreamChannelDataParse(app, session, input, entry.data, input->pool->bufferTargetLen);
                FragmentAdvance(input->pool);
            }
        }
    }
}

void InputStreamWrite(AppState *app, SessionState *session, SOEInputStream *input, u8 *data, u32 dataLen, i32 sequence, b32 isFragment)
{
    if (input->nextSequence == -1)
    {
        input->nextSequence = sequence;
    }

    if (sequence > input->nextSequence)
    {
        printf("[!] Sequence out of order; expected %d, got %d. Throwing away!\n", input->nextSequence, sequence);

        return;
    }

    FragmentInsert(input->pool, sequence, data, dataLen, isFragment);
    i32 ack = sequence;

    for (i32 i = 1; i < 0x10000; i++)
    {
        i32 j = (input->previousAck + i) & 0xffff;

        if (input->pool->entry[j].data)
        {
            ack = j;
        }
        else
        {
            break;
        }
    }

    if (ack > input->previousAck)
    {
        input->previousAck = ack;

        if (*input->ackCallbackPtr)
        {
            (*input->ackCallbackPtr)(session, ack);
        }
    }

    input->nextSequence = (input->previousAck + 1) & 0xffff;
    InputStreamFragmentProcess(app, session, input);
}

SOEInputStream InputStreamInit(FragmentPool *pool, u8 *rc4KeyDecoded, u32 rc4KeyLen, b32 useEncryption)
{
    SOEInputStream input = {0};

    crypt_rc4_initialize(&input.rc4, rc4KeyDecoded, rc4KeyLen);

    input.nextSequence = -1;
    input.previousAck = -1;
    input.previousProcessedFragment = -1;
    input.useEncryption = useEncryption;
    input.pool = pool;

    return input;
}
