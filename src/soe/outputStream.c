void OutputStreamWrite(AppState *app, SessionState *session, SOEOutputStream *output, u8 *data, u32 dataLen, b32 overrideEncryption)
{
    if (output->useEncryption && !overrideEncryption)
    {
        crypt_rc4_transform(&output->rc4, data, dataLen);
    }

    if (dataLen <= output->pool->packetLen)
    {
        output->sequence++;

        if (*output->dataCallbackPtr)
        {
            (*output->dataCallbackPtr)(app, session, data, dataLen, output->sequence, false);
        }
    }
    else
    {
        ASSERT((MAX_PACKET_LENGTH - DATA_HEADER_LENGTH) == (512 - 4) && (MAX_PACKET_LENGTH - DATA_HEADER_LENGTH) == output->pool->packetLen);
        u8 tempBuffer[MAX_PACKET_LENGTH - DATA_HEADER_LENGTH] = {0};

        endian_write_u32_big(tempBuffer, dataLen);
        u32 initalOffset = sizeof(u32);

        for (u32 i = 0; i < dataLen;)
        {
            u32 partialDataLen = (dataLen - i, output->pool->packetLen);
            partialDataLen -= initalOffset;

            output->sequence++;
            memcpy(&tempBuffer[initalOffset], (void *)((uptr)data + i), partialDataLen);

            if (*output->dataCallbackPtr)
            {
                (*output->dataCallbackPtr)(app, session, tempBuffer, partialDataLen + initalOffset, output->sequence, true);
            }

            i += partialDataLen;
            initalOffset = 0;
        }
    }
}

void OutputStreamUpdateAck(SOEOutputStream *output, i32 sequence)
{
    printf("[*] OutputStreamUpdateAck; previousAck=%d, sequence=%d\n", output->previousAck, sequence);
    output->previousAck = sequence;
}

SOEOutputStream OutputStreamInit(FragmentPool *pool, u8 *rc4KeyDecoded, u32 rc4KeyLen, b32 useEncryption)
{
    SOEOutputStream output = {0};

    crypt_rc4_initialize(&output.rc4, rc4KeyDecoded, rc4KeyLen);

    output.sequence = -1;
    output.previousAck = -1;
    output.useEncryption = useEncryption;
    output.pool = pool;

    return output;
}
