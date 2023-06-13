#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "shared/base.h"
//#include "utility/endian.c"
//#include "utility/util.c"

//#define WIN32_LEAN_AND_MEAN
//#include <windows.h>
//#include <process.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <timeapi.h>
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdarg.h>
//
//void internal
//	debug_printf(char* format_message, ...)
//{
//	va_list args;
//	va_start(args, format_message);
//
//	char buffer[1024];
//	vsprintf(buffer, format_message, args);
//	va_end(args);
//
//	printf(buffer);
//	FILE* fp = fopen("output.log", "w");
//	fputs(buffer, fp);
//	fclose(fp);
//}
//#define printf(s, ...) debug_printf(s, __VA_ARGS__) 
//
//#include "utility/debug.c"
//#define malloc(sz)  debug_alloc_and_zero(sz,__LINE__,__FILE__)
//#define free(ptr)   debug_free(ptr,__LINE__,__FILE__)
//
//#include "utility/crypt_rc4.c"
//#include "utility/endian.c"
//#include "utility/strings.c"
//#include "platform/os_win32.c"
//#include "platform/os_win32_net.c"
//#include "utility/util.c"


//void
//rc4_cipher(char* path)
//    {
//    char rc4_key_encoded[] = "F70IaxuU8C/w7FPXY1ibXw==";
//
//    char rc4_key_decoded[265] = {0};
//    u32 rc4_key_decoded_length = util_base64_decode(rc4_key_encoded,
//                                                    sizeof(rc4_key_encoded) - 1,
//                                                    rc4_key_decoded);
//
//    u8* buffer = malloc(MB(10));
//    u32 bytes_read = win32_buffer_load_from_file(path, buffer, MB(10));
//
//    util_rc4(rc4_key_decoded, rc4_key_decoded_length, buffer, bytes_read);
//    win32_buffer_write_to_file(path, buffer, bytes_read);
//
//    }
//
//#undef MB
//#undef KB
//#undef GB
//#include "external/lz4.h"
//#include "external/lz4.c"
//#undef MB
//#undef KB
//#undef GB
//#define MB(n) (n << 20)
//
//void lz4_decompress(char* path)
//    {
//
//    u8* dest_buffer = malloc(MB(10));
//    u8* src_buffer = malloc(MB(10));
//    u32 bytes_read = win32_buffer_load_from_file(path, src_buffer, MB(10));
//
//    i32 result = LZ4_decompress_safe(src_buffer, dest_buffer, bytes_read, MB(10));
//
//    win32_buffer_write_to_file("decomp.bin", dest_buffer, result);
//
//    }

//typedef struct Memory_Arena Memory_Arena;
//struct Memory_Arena
//{
	//u8* buffer;
	//u32 capacity;
	//u32 tail;
//};
//
//internal Memory_Arena
//memory_arena_init(u32 length, u8* buffer)
//{
	//Memory_Arena result =
	//{
		//.buffer = buffer,
		//.capacity = length,
	//};
//
	//return result;
//}
//
//// TODO(rhett): add alignment
//internal void*
//memory_arena_allocate(Memory_Arena* arena, u32 length)
//{
	//if (length > (arena->capacity - arena->tail))
	//{
		//printf("[X] Allocation excedes arena capacity: %u > (%u - %u)\n",
					 //length, arena->capacity, arena->tail);
		//abort();
	//}
	//
	//void* result = arena->buffer + arena->tail;
	//arena->tail += length;
//
	//return result;
//}
//#include "utility/memory_arena.c"

//typedef u32 Invalid;

//#include "../schema/output/test.c"

#if 0
u8 dummy_LoginRequest[] =
{
	0x01,
	0x05, 'G', 'l', 'o', 'o', 'p',
	0x04, 0x00, 0x00, 0x00, 'S', 'l', 'o', 'p',
};

u8 dummy_LoginReply[] =
{
	0x02,
	0x0a,
	0x0b,
	0x01, 0x02, 0x03, 0x04,
	0x0c,
	0x03, 0x00, 0x00, 0x00, 0xAA, 0xBB, 0xCC,
};

u8 dummy_TestSchema[] =
{
	0x03,
	0x0a,
	0x02, 0x00, // list_0
		// [0]
		0x10,
		0x01, 0x00, 0x00, 0x00, // list_1
			0x20,
			0x02, 0x00, 0x00, 0x00, // list_2
				// [0]
				0xaa, 0xbb, 0xcc, 0xdd,
				// [1]
				0xdd, 0xcc, 0xbb, 0xaa,
		// [1]
		0x11,
		0x01, 0x00, 0x00, 0x00, // list_1
			0x21,
			0x01, 0x00, 0x00, 0x00, // list_2
				0xab, 0xbc, 0xcd, 0xde,
	0x0b,
};
#endif


#define coroutine_begin     static i32 state = 0; switch (state) { case 0:
// NOTE(rhett): note the use of `do ... while(0)` to ensure that `crReturn` does not need braces around it when it comes directly between `if` and `else`
#define coroutine_yield(x)  do { state = __LINE__; return x; case __LINE__:; } while (0)
#define coroutine_end       }

i32 co_test()
{
	local_persist i32 i;

	coroutine_begin;
	for (i = 0; i < 10; i++)
	{
		coroutine_yield(i);
	}

	for (; i > 0; i--)
	{
		coroutine_yield(i);
	}
	coroutine_end;
	return -1;
}


int
main(int argc, char* argv[])
{
	i32 i;
	do
	{
		printf("%d\n", i = co_test());
	}
	while (i != -1);

	__debugbreak();
	//Memory_Arena packet_unpack_arena = memory_arena_init(MB(1),
	                                                     //calloc(1, MB(1)),
	                                                     //"Unpack Arena");

#if 0
	{
		Login_Packet_LoginRequest LoginRequest = { 0 };
		login_packet_unpack(dummy_LoginRequest,
												sizeof(dummy_LoginRequest),
												Login_Packet_Kind_LoginRequest,
												&LoginRequest,
												&packet_unpack_arena);

		Login_Packet_LoginReply LoginReply = { 0 };
		login_packet_unpack(dummy_LoginReply,
												sizeof(dummy_LoginReply),
												Login_Packet_Kind_LoginReply,
												&LoginReply,
												&packet_unpack_arena);

		Login_Packet_TestSchema TestSchema = { 0 };
		login_packet_unpack(dummy_TestSchema,
												sizeof(dummy_TestSchema),
												Login_Packet_Kind_TestSchema,
												&TestSchema,
												&packet_unpack_arena);
	}
#endif

#if 0
	// NOTE(rhett): what have I done
	{
		u8 buffer[512] = { 0 };

		Test_Packet_TestSchema TestSchema =
		{
			.byte_0 = 0x01,

			.entry_data_case = 1,
			.entry_data.vartype_1 =
				(struct vartype_1_s) {
				.val_3 = 5.26f,
				.val_4_length = 5,
				.val_4 = "Teest",
			},

			.entry_data_2_case = 0,
			.entry_data_2.vartype_2 =
				(struct vartype_2_s) {
				.val = 0xab1111ba,
				.val_2 = 0x79,
			},

			.test_uint2b.value = 67108864,
			.test_position.x = 32.0f,
			.test_position.y = 1.0f,
			.test_position.z = 0.0f,
			.test_position.w = 2.0f,
			.test_repeat =
				(struct test_repeat_s[3]) {
					[0] =
					{
						.value = 43,
					},
					[1] =
					{
						.value = 609,
					},
					[2] =
					{
						.value = 26,
					},
				},

			.list_0_count = 0x02,
			.list_0 =
			(struct list_0_s[2]){
				[0] =
				{
					.nested_0 = 0x54,
					.stream_0 =
					(struct stream_0_s[1]){
						[0] =
						{
							.name_length = 8,
							.name = "stream_0",
							.id = 123321,
						}
					},
					.stream_0_1_length = ~0u,
					.list_1_count = 0x01,
					.list_1 =
					(struct list_1_s[1]){
						[0] =
						{
							.nested_1 = 0x87,
							.list_2_count = 0x01,
							.list_2 =
							(struct list_2_s[1]){
								[0] =
								{
									.nested_2 = 0xaabbccdd,
								},
							},
						},
					},
				},
				[1] =
				{
					.nested_0 = 0x98,
					.stream_0 =
					(struct stream_0_s[1]){
						[0] =
						{
							.name_length = 8,
							.name = "stream_1",
							.id = 0xabccba,
						}
					},
					.stream_0_1_length = ~0u,
					.list_1_count = 0x01,
					.list_1 =
					(struct list_1_s[1]){
						[0] =
						{
							.nested_1 = 0x05,
							.list_2_count = 0x01,
							.list_2 =
							(struct list_2_s[1]){
								[0] =
								{
									.nested_2 = 0xddbbccaa,
								},
							},
						},
					},
				},
			},
			.byte_1 = 0x90,
		};

		u32 packed_length = test_packet_pack(Test_Packet_Kind_TestSchema,
																					&TestSchema,
																					buffer);

		Test_Packet_TestSchema repacked_TestSchema = { 0 };
		// NOTE(rhett): pretend we read the opcode
		test_packet_unpack(buffer + 1,
												packed_length,
												Test_Packet_Kind_TestSchema,
												&repacked_TestSchema,
												&packet_unpack_arena);

		printf("");
	}
#endif

#if 0
	{
		u8 buffer[512] = { 0 };

		Login_Packet_LoginRequest LoginRequest =
		{
			.session_id = "Test String",
			.session_id_length = 11,
		};

		u32 packed_length = login_packet_pack(Login_Packet_Kind_LoginRequest,
												  							  &LoginRequest,
													  							buffer);

		Login_Packet_LoginRequest repacked_LoginRequest = { 0 };
		login_packet_unpack(buffer,
												packed_length,
												Login_Packet_Kind_LoginRequest,
												&repacked_LoginRequest,
												&packet_unpack_arena);

		Login_Packet_LoginReply LoginReply =
		{
			.is_allowed = 1,
			.unk_bool_2 = 0,
			.unk_u32 = 0x40800,
			//.unk_bool_3 = 1,
			//.payload_length = 8,
			//.payload = "\xaa\xbb\xcc\xdd\xee\xff\x11\x22",
		};

		packed_length = login_packet_pack(Login_Packet_Kind_LoginReply,
																					&LoginReply,
																					buffer);

		Login_Packet_LoginReply repacked_LoginReply = { 0 };
		login_packet_unpack(buffer,
												packed_length,
												Login_Packet_Kind_LoginReply,
												&repacked_LoginReply,
												&packet_unpack_arena);
	}
#endif

	return 0;
}