//internal uptr util_align_forward(uptr ptr, usize align)
//{
//	assert(IS_POWER_OF_TWO(align));
//
//	uptr remainder = ptr & (align - 1);
//	if (remainder)
//	{
//		ptr += align - remainder;
//	}
//	return ptr;
//}
//
//internal void util_memory_set(void* destination, u8 value, usize length)
//{
//	for (usize i = 0; i < length; i++)
//	{
//		*(u8*)((uptr)destination + i) = value;
//	}
//}
//
//internal void util_memory_copy(void* destination, void* source, usize length)
//{
//	for (usize i = 0; i < length; i++)
//	{
//		*(u8*)((uptr)destination + i) = *(u8*)((uptr)source + i);
//	}
//}
//
internal u32 util_string_length(i8* data)
{
	u32 tail = 0;
	i8 c;
	do
	{
		c = data[tail++];
	}
	while (c != 0);

	return tail;
}
//
//internal void util_string_concat(i8* destination, u32 length, i8* source)
//{
//	u32 destination_tail;
//	for (destination_tail = 0; destination_tail < length; )
//	{
//		if (!destination[destination_tail])
//		{
//			break;
//		}
//		destination_tail++;
//	}
//
//	i8 c;
//	do
//	{
//		c = source[destination_tail];
//		destination[destination_tail++] = c;
//	}
//	while (c != 0);
//}
//
//internal b32 util_string_compare(i8* string_1, i8* string_2)
//{
//	u32 length_1 = util_string_length(string_1);
//	u32 length_2 = util_string_length(string_2);
//
//	if (length_1 != length_2)
//	{
//		return FALSE;
//	}
//
//	for (u32 i = 0; i < length_1; i++)
//	{
//		if (string_1[i] != string_2[i])
//		{
//			return FALSE;
//		}
//	}
//
//	return TRUE;
//}

// NOTE(rhett): Sloppy but does what I want
// internal void
// util_byte_dump(void* data, u32 data_length)
//     {
//     u32 bytes_per_line = 8;
//     u32 line_count = data_length / bytes_per_line;
//     if (data_length % bytes_per_line)
//         {
//         ++line_count;
//         }

//     printf("\n==== Base: %p\n", data);
//     for (u32 i = 0; i < line_count; ++i)
//         {
//         printf("%08X: ", i*bytes_per_line);
//         for (u32 j = 0; j < bytes_per_line; ++j)
//             {
//             if (!(bytes_per_line % 2) && j == bytes_per_line / 2)
//                 {
//                 putchar(' ');
//                 }
//             if (j < data_length - (i*bytes_per_line))
//                 {
//                 printf("%02x ", *(u8*)((uptr)data + (i*bytes_per_line+j)));
//                 }
//             else
//                 {
//                 printf("   ");
//                 }
//             }

//         printf("| ");
//         for (u32 j = 0; j < bytes_per_line; ++j)
//             {
//             char byte = *(char*)((uptr)data + (i*bytes_per_line+j));
//             if (!(bytes_per_line % 2) && j == bytes_per_line / 2)
//                 {
//                 putchar(' ');
//                 }
            
//             if (byte < '!' || byte > '~')
//                 {
//                 byte = '.';
//                 }

//             if (j < data_length - (i*bytes_per_line))
//                 {
//                 printf("%c", byte);
//                 }
//             else
//                 {
//                 putchar(' ');
//                 }
//             }
//         printf(" |\n");
//         }
//     putchar('\n');

//     return;
//     }

#if 0
internal void
util_base64_generate_encoding_table()
    {
    u8 table[64] = {0};
    u32 table_pos = 0;
    for (u8 i = 'A'; i <= 'Z'; i++)
        {
        table[table_pos++] = i;
        }
    for (u8 i = 'a'; i <= 'z'; i++)
        {
        table[table_pos++] = i;
        }
    for (u8 i = '0'; i <= '9'; i++)
        {
        table[table_pos++] = i;
        }
    table[table_pos++] = '+';
    table[table_pos++] = '/';

    u8 buffer[KB(4)] = {0};
    u32 offset = 0;
    offset += sprintf(buffer+offset, "u8 encoding_table[%zu] = {\n", sizeof(table));
    for (u32 i = 0; i < sizeof(table); i++)
        {
        offset += sprintf(buffer+offset, "\'%c\', ", table[i]);
        if (!((i + 1) % 8))
            {
            offset += sprintf(buffer+offset, "\n");
            }
        }
    offset += sprintf(buffer+offset, "};");

    win32_write_buffer_to_file("encoding_table.c", buffer, offset);
    }

internal void
util_base64_generate_decoding_table()
    {
    u8 encoding_table[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
                             'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
                             'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
                             'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 
                             'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
                             'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
                             'w', 'x', 'y', 'z', '0', '1', '2', '3', 
                             '4', '5', '6', '7', '8', '9', '+', '/',};

    u8 decoding_table[128];
    for (u32 i = 0; i < sizeof(decoding_table); i++)
        {
        decoding_table[i] = 0xff;
        }

    for (u8 i = 0; i < sizeof(decoding_table); i++)
        {
        for (u8 j = 0; j < sizeof(encoding_table); j++)
            {
            if (i == encoding_table[j])
                {
                decoding_table[i] = j;
                break;
                }
            else if (i == '=')
                {
                decoding_table[i] = 0;
                break;
                }
            }
        }

    u8 buffer[KB(4)] = {0};
    u32 offset = 0;

    offset += sprintf(buffer+offset, "u8 decoding_table[%zu] = {\n", sizeof(decoding_table));
    for (u32 i = 0; i < sizeof(decoding_table); i++)
        {
        offset += sprintf(buffer+offset, "0x%02x, ", decoding_table[i]);
        if (!((i + 1) % 8))
            {
            offset += sprintf(buffer+offset, "\n");
            }
        }
    offset += sprintf(buffer+offset, "};");
    win32_write_buffer_to_file("decoding_table.c", buffer, offset);
    }
#endif

internal u32
util_base64_calculate_decoded_length(u8* data, u32 data_length)
    {
    // TODO(rhett): correct this automatically 
			ASSERT_MSG(!(data_length % 4), "data_length is not divisible by 4");
    //if (data_length % 4)
        //{
        //printf("[X] data_length is not divisible by 4.\n");
        //abort();
        //}

    u32 result = (data_length / 4) * 3;
    if (data[data_length - 1] == '=')
        {
        result--;
        if (data[data_length - 2] == '=')
            {
            result--;
            }
        }

    return result;
    }

internal u32
util_base64_decode(u8* data, u32 data_length, u8* buffer)
    {
    // TODO(rhett): correct this automatically 
			ASSERT_MSG(!(data_length % 4), "data_length is not divisible by 4");
    //if (data_length % 4)
        //{
        //printf("[X] data_length is not divisible by 4.\n");
        //abort();
        //}

    // u8 encoding_table[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
    //                          'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
    //                          'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
    //                          'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 
    //                          'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
    //                          'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
    //                          'w', 'x', 'y', 'z', '0', '1', '2', '3', 
    //                          '4', '5', '6', '7', '8', '9', '+', '/'};

    u8 decoding_table[128] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                              0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                              0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                              0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                              0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                              0xff, 0xff, 0xff, 0x3e, 0xff, 0xff, 0xff, 0x3f, 
                              0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 
                              0x3c, 0x3d, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 
                              0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
                              0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 
                              0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 
                              0x17, 0x18, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff, 
                              0xff, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 
                              0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 
                              0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 
                              0x31, 0x32, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff};

    u32 i, j;
    for (i = j = 0; i < data_length; i+=4, j+=3)
        {
        buffer[j]   = (decoding_table[data[i]]   << 2) | (decoding_table[data[i+1]] >> 4);
        buffer[j+1] = (decoding_table[data[i+1]] << 4) | (decoding_table[data[i+2]] >> 2);
        buffer[j+2] = (decoding_table[data[i+2]] << 6) | (decoding_table[data[i+3]]);
        }

    return util_base64_calculate_decoded_length(data, data_length);
    }