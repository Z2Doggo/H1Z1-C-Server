void output_stream_write(Output_Stream* stream,
    u8* data,
    u32 data_length,
    b32 should_override_encryption,
    void* server,
    void* session)
{
    if (stream->use_encryption && !should_override_encryption) {
        crypt_rc4_transform(&stream->rc4_state, data, data_length);

        // NOTE(rhett): Being explicit here
        // if (data[0] == 0)
        //{
        //// TODO(rhett): Looks like the js server prepends another zero
        // printf("[X] output_stream data begins with a zero, handle this\n");
        // data_length++; // ?
        // data--;
        // }
    }

    if (data_length <= stream->fragment_pool->packet_length) {
        stream->sequence++;

        // TODO(rhett):
        if (*stream->data_callback_ptr) {
            (*stream->data_callback_ptr)(server, session, data, data_length, stream->sequence, false);
        }
    } else {
        // TODO(rhett): still some cleanup to do
        // TODO(rhett): this will need to match output stream fragment length. switch to an arena
        ASSERT((MAX_PACKET_LENGTH - DATA_HEADER_LENGTH) == (512 - 4)
            && (MAX_PACKET_LENGTH - DATA_HEADER_LENGTH) == stream->fragment_pool->packet_length);
        u8 temp_buffer[MAX_PACKET_LENGTH - DATA_HEADER_LENGTH] = { 0 };
        // TODO(rhett): maybe endian_write should return bytes written incase we swap it out?
        endian_write_u32_big(temp_buffer, data_length);
        u32 initial_offset = sizeof(u32);

        for (u32 i = 0; i < data_length;) {
            u32 partial_data_length = MIN(data_length - i, stream->fragment_pool->packet_length);
            partial_data_length -= initial_offset;
            stream->sequence++;
            base_memory_copy(&temp_buffer[initial_offset],
                (void*)((uptr)data + i),
                partial_data_length);

            // TODO(rhett):
            if (*stream->data_callback_ptr) {
                (*stream->data_callback_ptr)(server,
                    session,
                    temp_buffer,
                    partial_data_length + initial_offset,
                    stream->sequence,
                    true);
            }

            i += partial_data_length;
            initial_offset = 0;
        }
    }
}

internal void output_stream_ack_update(Output_Stream* stream, i32 sequence)
{
    printf("[*] output_stream_ack_update; ack_previous=%d, sequence=%d\n", stream->ack_previous, sequence);
    stream->ack_previous = sequence;
}

internal Output_Stream output_stream_init(Fragment_Pool* fragment_pool, u8* rc4_key_decoded, u32 rc4_key_decoded_length, b32 use_encryption)
{
    Output_Stream result = { 0 };

    crypt_rc4_initialize(&result.rc4_state, rc4_key_decoded, rc4_key_decoded_length);

    result.sequence = -1;
    result.ack_previous = -1;
    // result.fragment_length = fragment_length;
    result.use_encryption = use_encryption;

    result.fragment_pool = fragment_pool;

    return result;
}
