// TODO(rhett): Handle out-of-order packets

u32 input_stream_read_chunk_length(u8 *data, u32 *chunk_length_ptr)
{
    u32 offset = 0;
    u32 chunk_length = data[offset];
    offset += 1;

    if (chunk_length == 0xff)
    {
        if (data[offset] == 0xff && data[offset + 1] == 0xff)
        {
            offset += 2;
            chunk_length = endian_read_u32_big(data + offset);
            offset += 4;
        }
        else if (data[offset] > 0)
        {
            offset++;
            chunk_length = endian_read_u16_big(data + offset);
            offset += 2;
        }
    }

    *chunk_length_ptr = chunk_length;
    return offset;
}

void input_stream_channel_packet_data_parse(Input_Stream *stream, u8 *data, u32 data_length, void *server, void *session)
{
    u32 offset = 0;
    if (data[0] == 0x0 && data[1] == 0x19)
    {
        u32 chunk_length;
        offset = 2;
        while (offset < data_length)
        {
            offset += input_stream_read_chunk_length(data + offset, &chunk_length);

            if (stream->use_encryption)
            {
                // if (chunk_length > 1 && endian_read_u16_little(data + offset) == 0)
                if (chunk_length > 1 && *(u8 *)(data + offset) == 0)
                {
                    offset += 1;
                    chunk_length -= 1;
                }
                crypt_rc4_transform(&stream->rc4_state, data + offset, chunk_length);
            }

            // TODO(rhett):
            if (*stream->data_callback_ptr)
            {
                (*stream->data_callback_ptr)(server, session, data + offset, chunk_length);
            }

            offset += chunk_length;
        }
    }
    else
    {
        if (stream->use_encryption)
        {
            if (data_length > 1 && endian_read_u16_little(data + offset) == 0)
            {
                offset += 1;
                data_length -= 1;
            }
            crypt_rc4_transform(&stream->rc4_state, data + offset, data_length);
        }

        // TODO(rhett):
        if (*stream->data_callback_ptr)
        {
            (*stream->data_callback_ptr)(server, session, data + offset, data_length);
        }
    }
}

void input_stream_fragments_process(Input_Stream *stream, void *server, void *session)
{
    i32 fragment_next = (stream->processed_fragment_previous + 1) & 0xffff;
    Fragment_Entry head = stream->fragment_pool->fragments[0];

    if (head.data_length)
    {
        if (!head.is_fragment)
        {
            stream->processed_fragment_previous = fragment_next;
            input_stream_channel_packet_data_parse(stream, head.data, head.data_length, server, session);
            fragment_pool_advance(stream->fragment_pool);
        }
        else
        {
            if (stream->fragment_pool->buffer_tail == stream->fragment_pool->buffer_target_length)
            {
                // TODO(rhett): Might need to decrement this
                stream->processed_fragment_previous = stream->fragment_pool->fragments_count - 1;
                input_stream_channel_packet_data_parse(stream, head.data, stream->fragment_pool->buffer_target_length, server, session);
                fragment_pool_advance(stream->fragment_pool);
            }
        }
    }
}

// TODO(rhett): Ack callback might want to use a session id or index instead of a pointer later on
void input_stream_write(Input_Stream *stream, u8 *data, u32 data_length, i32 sequence, b32 is_fragment, void *server, void *session)
{
    if (stream->sequence_next == -1)
    {
        stream->sequence_next = sequence;
    }

    if (sequence > stream->sequence_next)
    {
        // TODO(rhett): handle this
        printf("[!] Sequence out of order; expected %d, got %d. Throwing away\n", stream->sequence_next, sequence);

        return;
    }

    fragment_pool_insert(stream->fragment_pool, sequence, data, data_length, is_fragment);

    i32 ack = sequence;
    for (i32 i = 1; i < 0x10000; i++)
    {
        i32 j = (stream->ack_previous + i) & 0xffff;

        if (stream->fragment_pool->fragments[j].data)
        {
            ack = j;
        }
        else
        {
            break;
        }
    }

    if (ack > stream->ack_previous)
    {
        stream->ack_previous = ack;
        // TODO(rhett): Using pointer for session, maybe move to an index
        if (*stream->ack_callback_ptr && session)
        {
            (*stream->ack_callback_ptr)(ack, session);
            // on_input_stream_ack(ack, session);
        }
    }

    stream->sequence_next = (stream->ack_previous + 1) & 0xffff;
    input_stream_fragments_process(stream, server, session);
}

Input_Stream input_stream_init(Fragment_Pool *fragment_pool, u8 *rc4_key_decoded, u32 rc4_key_decoded_length, b32 use_encryption)
{
    Input_Stream result = {0};

    crypt_rc4_initialize(&result.rc4_state, rc4_key_decoded, rc4_key_decoded_length);

    result.sequence_next = -1;
    result.ack_previous = -1;
    result.processed_fragment_previous = -1;
    result.use_encryption = use_encryption;
    result.fragment_pool = fragment_pool;

    return result;
}
