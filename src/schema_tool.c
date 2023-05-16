// TODO(rhett): add namespaces
// TODO(rhett): write_parents shouldn't assume an array
// TODO(rhett): vec4 is assuming f32 for now, might make it swappable

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "shared/base.h"

#include "utility/strings.c"
#include "utility/util.c"
//#include "platform/os_win32.c"


internal u32
	win32_buffer_load_from_file(char* file_path, u8* buffer, u32 buffer_length)
{
	HANDLE file_handle = CreateFile(file_path,
	                                GENERIC_READ,
	                                FILE_SHARE_READ,
	                                0,
	                                OPEN_EXISTING,
	                                FILE_ATTRIBUTE_NORMAL,
	                                0);

	if (file_handle == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	// get file size
	u32 file_size = GetFileSize(file_handle, 0);
	if (file_size > buffer_length)
	{
		return 0;
	}

	if (!buffer)
	{
		return 0;
	}

	// NOTE(rhett): Read entire file into buffer
	u32 bytes_read;
	ReadFile(file_handle, buffer, file_size, (LPDWORD)&bytes_read, 0);

	CloseHandle(file_handle);
	return bytes_read;
}

internal u32
	win32_buffer_write_to_file(char* file_path, u8* buffer, u32 buffer_length)
{
	HANDLE file_handle = CreateFile(file_path,
	                                GENERIC_WRITE,
	                                0,
	                                0,
	                                CREATE_ALWAYS,
	                                FILE_ATTRIBUTE_NORMAL,
	                                0);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		printf("Unable to open file: %s\n", file_path);
		return 0;
	}


	if (!buffer)
	{
		printf("Buffer is empty.\n");
		CloseHandle(file_handle);
		return 0;
	}

	u32 bytes_written;    
	if (!WriteFile(file_handle,
	               buffer,
	               buffer_length,
	               (LPDWORD)&bytes_written,
	               0))
	{
		printf("Unable to write file \"%s\" - GetLastError(%d)\n",
		       file_path,
		       GetLastError());
		CloseHandle(file_handle);
		return 0;
	}

	CloseHandle(file_handle);
	return bytes_written;
}


//#include "utility/debug.c"

#define MAX_KEYWORD_HASH_MAP_BUCKETS 8192
#define MAX_KEYWORD_HASH_MAP_COLLISIONS 2
#define MAX_KEYWORD_HASH_MAP_KEY_LENGTH 8
#define MAX_IDENTIFIER_LENGTH 64


// NOTE(rhett): stolen idea from the odin-lang tokenizer. saves typing
#define TOKEN_KINDS \
TOKEN_KIND(T_Invalid, "Invalid"), \
\
TOKEN_KIND(T__Keyword_Begin, ""), \
TOKEN_KIND(T_Group,   "group"), \
TOKEN_KIND(T_Packet,  "packet"), \
TOKEN_KIND(T_Endian,  "endian"), \
TOKEN_KIND(T_Opcode,  "opcode"), \
TOKEN_KIND(T__Keyword_End, ""), \
\
TOKEN_KIND(T__Types_Begin, ""), \
\
TOKEN_KIND(T__Special_Type_Begin, ""), \
TOKEN_KIND(T_List,    "list"), \
TOKEN_KIND(T_String,  "string"), \
TOKEN_KIND(T_Bytes,   "bytes"), \
TOKEN_KIND(T_Stream,  "stream"), \
TOKEN_KIND(T_Uint2b,  "uint2b"), \
TOKEN_KIND(T_Vec4,    "vec4"), \
TOKEN_KIND(T_Vec3,    "vec3"), \
TOKEN_KIND(T_Switch,  "switch"), \
TOKEN_KIND(T_Case,    "case"), \
TOKEN_KIND(T__Special_Type_End, ""), \
\
TOKEN_KIND(T__Integral_Begin, ""), \
TOKEN_KIND(T_B8,   "b8"), \
TOKEN_KIND(T_B16, "b16"), \
TOKEN_KIND(T_B32, "b32"), \
TOKEN_KIND(T_B64, "b64"), \
TOKEN_KIND(T_I8,   "i8"), \
TOKEN_KIND(T_I16, "i16"), \
TOKEN_KIND(T_I32, "i32"), \
TOKEN_KIND(T_I64, "i64"), \
TOKEN_KIND(T_U8,   "u8"), \
TOKEN_KIND(T_U16, "u16"), \
TOKEN_KIND(T_U32, "u32"), \
TOKEN_KIND(T_U64, "u64"), \
TOKEN_KIND(T_F32, "f32"), \
TOKEN_KIND(T_F64, "f64"), \
TOKEN_KIND(T__Integral_End, ""), \
\
TOKEN_KIND(T__Endian_Type_Begin, ""), \
TOKEN_KIND(T_Endian_Little, "little"), \
TOKEN_KIND(T_Endian_Big,    "big"), \
TOKEN_KIND(T__Endian_Type_End, ""), \
\
TOKEN_KIND(T__Types_End, ""), \
\
TOKEN_KIND(T_Open_Brace,    "Open_Brace"), \
TOKEN_KIND(T_Close_Brace,   "Close_Brace"), \
TOKEN_KIND(T_Open_Bracket,  "Open_Bracket"), \
TOKEN_KIND(T_Close_Bracket, "Close_Bracket"), \
TOKEN_KIND(T_Colon,         "Colon"), \
\
TOKEN_KIND(T_Identifier, "Identifier"), \
TOKEN_KIND(T_Number,     "Number"), \
TOKEN_KIND(T_Hex_Number, "Hex_Number"), \
\
TOKEN_KIND(T_New_Line, "New_Line"), \
TOKEN_KIND(T_EOF,      "EOF"), \
\
TOKEN_KIND(T__End, "")

typedef enum Token_Kind
{
#define TOKEN_KIND(e, s) e
	TOKEN_KINDS
#undef TOKEN_KIND
} Token_Kind;

char token_names[][T__End] =
{
#define TOKEN_KIND(e, s) s
	TOKEN_KINDS
#undef TOKEN_KIND
};


typedef struct ST_Buffer ST_Buffer;
struct ST_Buffer
{
	u32 capacity;
	u32 tail;
	u8* data;
};


internal void
print_string(char* data, u32 data_length)
{
	for (u32 i = 0; i < data_length; i++)
	{
		putchar(data[i]);
	}
}


// TODO(rhett): Likely wasteful
typedef struct Keyword_Hash_Map_Bucket Keyword_Hash_Map_Bucket;
struct Keyword_Hash_Map_Bucket
{
	u64 hash;
	Token_Kind value;
};

// NOTE(rhett): Keyword hash stuff. just putting keywords in a u64 is probably enough
typedef struct Keyword_Hash_Map Keyword_Hash_Map;
struct Keyword_Hash_Map
{
	u32 capacity;
	u32 entry_count;
	Keyword_Hash_Map_Bucket buckets[MAX_KEYWORD_HASH_MAP_BUCKETS];
};

// NOTE(rhett): Must be no more than 8 bytes
internal void
	keyword_hash_map_key_insert(Keyword_Hash_Map* map, char* key, u32 key_length, Token_Kind value)
{
	u64 hash = *(u64*)key;

	if (!key_length)
	{
		key_length = util_string_length(key);
	}

	if (key_length > sizeof(hash))
	{
		printf("[X] Cannot insert key larger than size of hash.\n");
		abort();
		return;
	}

	// NOTE(rhett): mask out potential junk data
	if (key_length < sizeof(hash))
	{
		u64 mask = ~0ull >> ((sizeof(hash) - key_length) * 8);
		hash &= mask;
	}

	u32 index = hash & map->capacity - 1;

	for (u32 collision_count = 0; map->buckets[index].hash; index++, collision_count++)
	{
		if (collision_count >= MAX_KEYWORD_HASH_MAP_COLLISIONS)
		{
			printf("[X] Max collision count reached. Adjust hash map\n");
			abort();
			return;
		}

#ifdef SCHM_DEBUG
		printf("[!] Collision at bucket %u from ", index);
		print_string(key, key_length);
		putchar('\n');
#endif
	}

	map->buckets[index].hash = hash;
	map->buckets[index].value = value;
	map->entry_count++;
#ifdef SCHM_DEBUG
	printf("[*] Inserted %d into bucket %d. Load=%f\n", value, index, (f64)map->entry_count / (f64)map->capacity);
#endif
}

internal Token_Kind
	keyword_hash_map_value_get(Keyword_Hash_Map* map, char* key, u32 key_length)
{
	u64 hash = *(u64*)key;

	if (!key_length)
	{
		key_length = util_string_length(key);
	}

	if (key_length > sizeof(hash))
	{
		printf("[X] Cannot use key larger than size of hash.\n");
		abort();
	}

	// NOTE(rhett): mask out potential junk data
	if (key_length < sizeof(hash))
	{
		u64 mask = ~0ull >> ((sizeof(hash) - key_length) * 8);
		hash &= mask;
	}

	u32 index = hash & map->capacity - 1;

	for (u32 collision_count = 0; map->buckets[index].hash != hash; index++, collision_count++)
	{
		if (collision_count >= MAX_KEYWORD_HASH_MAP_COLLISIONS)
		{
#ifdef SCHM_DEBUG
			printf("[*] Key not found in hash map\n");
#endif
			return 0;
		}

#ifdef SCHM_DEBUG
		printf("[!] Collision at bucket %u while getting ", index);
		print_string(key, key_length);
		putchar('\n');
#endif
	}

	u64 result = map->buckets[index].value;
#ifdef SCHM_DEBUG
	printf("[*] Found %llu at bucket %d\n", result, index);
#endif
	return result;
}


internal void
	dump_char_table()
{
	char test[256] = { 0 };
	for (int i = 0; i < sizeof(test); i++)
	{
		test[i] = (char)i;
	}
	util_byte_dump(test, sizeof(test));
}


internal b32
	is_hex_digit(char c)
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

internal b32
	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

internal b32
	is_alpha(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

typedef struct Token Token;
struct Token
{
	Token_Kind kind;
	u32 lexeme_length;
	char* lexeme;
	u32 line;
};

internal u32
scan_tokens(u8* data, u32 data_length, Token* token_buffer, Keyword_Hash_Map* keyword_map)
{
	u32 token_buffer_count = 0;

	u32 lexeme_begin = 0;

	u32 byte_count = 0;
	u32 line_count = 1;
	for (; byte_count < data_length;)
	{
		switch (data[byte_count])
		{
			case '{':
			{
				token_buffer[token_buffer_count++] = (Token) { T_Open_Brace, 1, &data[byte_count], line_count };
				byte_count++;
			} break;

			case '}':
			{
				token_buffer[token_buffer_count++] = (Token) { T_Close_Brace, 1, &data[byte_count], line_count };
				byte_count++;
			} break;

			case '[':
			{
				token_buffer[token_buffer_count++] = (Token) { T_Open_Bracket, 1, &data[byte_count], line_count };
				byte_count++;
			} break;

			case ']':
			{
				token_buffer[token_buffer_count++] = (Token) { T_Close_Bracket, 1, &data[byte_count], line_count };
				byte_count++;
			} break;

			case ':':
			{
				token_buffer[token_buffer_count++] = (Token) { T_Colon, 1, &data[byte_count], line_count };
				byte_count++;
			} break;

			case '/':
			{
				if (data[byte_count + 1] == '/')
				{
					byte_count += 2;
					for (; data[byte_count] != '\n' && byte_count < data_length; byte_count++);
				}
			} break;

			case '?':
			case ' ':
			case '\t':
			case '\r':
			{
				byte_count++;
			} break;

			case '\n':
			{
				// NOTE(rhett): strip repeated new lines
				if (token_buffer_count > 0 && token_buffer[token_buffer_count - 1].kind != T_New_Line)
				{
					token_buffer[token_buffer_count++] = (Token) { T_New_Line, 1, &data[byte_count], line_count };
				}
				line_count++;
				byte_count++;
			} break;

			default:
			{
				if (data[byte_count] == '0')
				{
					if (data[byte_count + 1] == 'x')
					{
						// NOTE(rhett): hex
						byte_count += 2;
						lexeme_begin = byte_count;

						for (; is_hex_digit(data[byte_count]); byte_count++);
						token_buffer[token_buffer_count++] = (Token) { T_Hex_Number, byte_count - lexeme_begin, &data[lexeme_begin], line_count };
					}
					else
					{
						// NOTE(rhett): number prefixed with 0 for some reason?
						lexeme_begin = byte_count;
						for (; is_digit(data[byte_count]); byte_count++);
						token_buffer[token_buffer_count++] = (Token) { T_Number, byte_count - lexeme_begin, &data[lexeme_begin], line_count };
					}
				}
				else if (is_digit(data[byte_count]))
				{
					// NOTE(rhett): Number
					lexeme_begin = byte_count;
					for (; is_digit(data[byte_count]); byte_count++);
					token_buffer[token_buffer_count++] = (Token) { T_Number, byte_count - lexeme_begin, &data[lexeme_begin], line_count };
				}
				else if (is_alpha(data[byte_count]))
				{
					// NOTE(rhett): Identifier
					lexeme_begin = byte_count;
					for (; is_alpha(data[byte_count]) || is_digit(data[byte_count]); byte_count++);

					if (byte_count - lexeme_begin <= MAX_KEYWORD_HASH_MAP_KEY_LENGTH)
					{
						Token_Kind keyword = keyword_hash_map_value_get(keyword_map, &data[lexeme_begin], byte_count - lexeme_begin);
						if (keyword)
						{
#ifdef SCHM_DEBUG
							printf("[*] ");
							print_string(&data[lexeme_begin], byte_count - lexeme_begin);
							printf(" detected as keyword\n");
#endif
							token_buffer[token_buffer_count++] = (Token) { keyword, byte_count - lexeme_begin, &data[lexeme_begin], line_count };
						}
						else
						{
							token_buffer[token_buffer_count++] = (Token) { T_Identifier, byte_count - lexeme_begin, &data[lexeme_begin], line_count };
						}
					}
					else
					{
						token_buffer[token_buffer_count++] = (Token) { T_Identifier, byte_count - lexeme_begin, &data[lexeme_begin], line_count };
					}
				}
				else
				{
					// TODO(rhett): error
				}
			}
		}
	}
	token_buffer[token_buffer_count++] = (Token) { T_EOF, 0, 0, line_count };

	return token_buffer_count;
}

internal b32
	copy_char_array_to_cstring(char* data, u32 data_length, char* target, u32 target_length)
{
	if (data_length + 1 > target_length)
	{
		return 0;
	}

	for (u32 i = 0; i < data_length; i++)
	{
		target[i] = data[i];
	}
	target[data_length] = 0;

	return 1;
}

// TODO(rhett): think about the type of return value
internal u32
	char_to_number(char number_char)
{
	switch (number_char)
	{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'a': case 'A': return 10;
		case 'b': case 'B': return 11;
		case 'c': case 'C': return 12;
		case 'd': case 'D': return 13;
		case 'e': case 'E': return 14;
		case 'f': case 'F': return 15;
	}
	printf("[X] char_to_number cannot convert char '%#x' to number\n", number_char);
	abort();
}

internal u32
	number_token_to_u32(Token token)
{
	u32 base;
	u32 result = 0;

	// TODO(rhett): We can probably stick all number types in one token
	switch (token.kind)
	{
		case T_Number:
		{
			base = 10;
			for (u32 i = 0; i < token.lexeme_length; i++)
			{
				result *= base;
				result += char_to_number(token.lexeme[i]);
			}
			break;
		}
		case T_Hex_Number:
		{
			base = 16;
			for (u32 i = 0; i < token.lexeme_length; i++)
			{
				result *= base;
				result += char_to_number(token.lexeme[i]);
			}
			break;
		}
		default:
		{
			printf("[X] number_token_to_u32 needs a number or hex number token.\n");
			abort();
		}
	}

	return result;
}

#define PS_KINDS \
PS_KIND(State_Invalid), \
PS_KIND(State_Root), \
PS_KIND(State_Group), \
PS_KIND(State_Packet), \
PS_KIND(State_Basic), \
PS_KIND(State_List), \
PS_KIND(State_String), \
PS_KIND(State_Uint2b), \
PS_KIND(State_Stream), \
PS_KIND(State_Switch), \
PS_KIND(State_Case), \
PS_KIND(State_Bytes)

typedef enum Parser_State_Kind
{
#define PS_KIND(e) e
	PS_KINDS
#undef PS_KIND
} Parser_State_Kind;

char* ps_names[] =
{
#define PS_KIND(e) STRINGIFY(e)
	PS_KINDS
#undef PS_KIND
};

typedef struct Parser_State Parser_State;
struct Parser_State
{
	Parser_State_Kind kind;
	Token identifier;
	Token_Kind length_type;
	Token data_type;
	Token count_specifier;
	Token opcode;
	Token_Kind opcode_length_type;
	// TODO(rhett): think about if we need more than 2 opcodes
	Token subcode;
	Token_Kind subcode_length_type;
	Token packet;
	Token group;
	Token_Kind endian;
	Token parent;
};

#define MAX_STATE_STACK 64

typedef struct Output_Buffers Output_Buffers;
struct Output_Buffers
{
	u8 define_buffer[MB(1)];
	u32 define_buffer_tail;
	u8 kind_buffer[MB(1)];
	u32 kind_buffer_tail;
	u8 helper_struct_buffer[MB(1)];
	u32 helper_buffer_tail;
	u8 main_struct_buffer[MB(1)];
	u32 main_struct_buffer_tail;
	u8 packer_buffer[MB(1)];
	u32 packer_buffer_tail;
	u8 unpacker_buffer[MB(1)];
	u32 unpacker_buffer_tail;
	u8 registered_ids_buffer[MB(1)];
	u32 registered_ids_buffer_tail;
};

typedef enum Parser_Object_Kind
{
	PO_Invalid,
	PO_Group_Enter,
	PO_Group_Exit,
	PO_Packet_Enter,
	PO_Packet_Exit,
	PO_Field_Basic,
	PO_Field_String,
	PO_Field_Uint2b,
	PO_Field_Vec4,
	PO_Field_Vec3,
	PO_Field_Bytes,
	PO_List_Enter,
	PO_List_Exit,
	PO_Stream_Enter,
	PO_Stream_Exit,
	PO_Switch_Enter,
	PO_Switch_Exit,
	PO_Case_Enter,
	PO_Case_Exit,
} Parser_Object_Kind;

typedef struct Parser Parser;
struct Parser
{
	void (*emit_func)(Parser_Object_Kind kind, Parser_State state_stack[MAX_STATE_STACK], u32 state_stack_tail, Output_Buffers* output_buffers, b32 will_generate_struct, u32 depth);
	Parser_State state_stack[MAX_STATE_STACK];
	u32 state_stack_tail;
	Token* tokens;
	u32 tokens_tail;
	Output_Buffers* output_buffers;
	u32 depth;
};

// NOTE(rhett): prototype
internal void
state_field_enter(Parser* parser);


internal void
	state_case_enter(Parser* parser)
{
	parser->state_stack[parser->state_stack_tail].kind = State_Case;
	parser->tokens_tail++;

	// NOTE(rhett): smuggling case number into opcode
	if (!(parser->tokens[parser->tokens_tail].kind == T_Number || parser->tokens[parser->tokens_tail].kind == T_Hex_Number))
	{
		printf("[X] Expected case number for switch at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].opcode = parser->tokens[parser->tokens_tail];
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
	{
		printf("[X] Expected identifier for case at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
	parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail].identifier;
	parser->tokens_tail++;

	// TODO(rhett):  makes newlines for braces optional
	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after case at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Case_Enter, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}

	for (; parser->tokens[parser->tokens_tail].kind != T_Close_Brace && parser->tokens[parser->tokens_tail].kind != T_Case;)
	{
		Token_Kind token_kind = parser->tokens[parser->tokens_tail].kind;
		if (token_kind > T__Types_Begin && token_kind < T__Types_End)
		{
			state_field_enter(parser);
		}
	}
	//parser->tokens_tail++;

	//if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	//{
	//printf("[X] Expected newline after closed brace at line: %u\n", parser->tokens[parser->tokens_tail].line);
	//abort();
	//}
	//parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Case_Exit, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}
}


internal void state_switch_enter(Parser* parser)
{
	parser->state_stack[parser->state_stack_tail].kind = State_Switch;
	parser->tokens_tail++;

	// NOTE(rhett): Check if type of length variable is specified
	// NOTE(rhett): Default to u32
	parser->state_stack[parser->state_stack_tail].length_type = T_U32;

	if (parser->tokens[parser->tokens_tail].kind == T_Colon)
	{
		parser->tokens_tail++;

		if (!(parser->tokens[parser->tokens_tail].kind > T__Integral_Begin && parser->tokens[parser->tokens_tail].kind < T__Integral_End))
		{
			printf("[X] Expected an integral type after colon at line: %u\n", parser->tokens[parser->tokens_tail].line);
			abort();
		}
		parser->state_stack[parser->state_stack_tail].length_type = parser->tokens[parser->tokens_tail].kind;
		parser->tokens_tail++;
	}

	if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
	{
		printf("[X] Expected identifier for switch at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
	parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail].identifier;
	parser->tokens_tail++;

	// TODO(rhett):  makes newlines for braces optional
	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after switch at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	// TODO(rhett): next we need braces
	if (parser->tokens[parser->tokens_tail].kind != T_Open_Brace)
	{
		printf("[X] Expected open brace after %s at line %u\n",
		       token_names[parser->tokens[parser->tokens_tail - 3].kind],
		       parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after open brace at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Switch_Enter, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}

	for (; parser->tokens[parser->tokens_tail].kind != T_Close_Brace;)
	{
		Token_Kind token_kind = parser->tokens[parser->tokens_tail].kind;
		if (token_kind == T_Case)
		{
			parser->state_stack_tail++;
			parser->depth++;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
			
			state_case_enter(parser);
			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
			parser->depth--;
		}
	}
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after closed brace at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Switch_Exit, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}
}

internal void
state_stream_enter(Parser* parser)
{
	parser->state_stack[parser->state_stack_tail].kind = State_Stream;
	parser->tokens_tail++;

	// NOTE(rhett): Check if type of length variable is specified
	// NOTE(rhett): Default to u32
	parser->state_stack[parser->state_stack_tail].length_type = T_U32;

	if (parser->tokens[parser->tokens_tail].kind == T_Colon)
	{
		parser->tokens_tail++;

		if (!(parser->tokens[parser->tokens_tail].kind > T__Integral_Begin && parser->tokens[parser->tokens_tail].kind < T__Integral_End))
		{
			printf("[X] Expected an integral type after colon at line: %u\n", parser->tokens[parser->tokens_tail].line);
			abort();
		}
		parser->state_stack[parser->state_stack_tail].length_type = parser->tokens[parser->tokens_tail].kind;
		parser->tokens_tail++;
	}

	if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
	{
		printf("[X] Expected identifier for stream at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
	parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail].identifier;
	parser->tokens_tail++;

	// TODO(rhett):  makes newlines for braces optional
	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after stream at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	// TODO(rhett): next we need braces
	if (parser->tokens[parser->tokens_tail].kind != T_Open_Brace)
	{
		printf("[X] Expected open brace after %s at line %u\n",
					 token_names[parser->tokens[parser->tokens_tail - 3].kind],
					 parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after open brace at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Stream_Enter, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}

	for (; parser->tokens[parser->tokens_tail].kind != T_Close_Brace;)
	{
		Token_Kind token_kind = parser->tokens[parser->tokens_tail].kind;
		if (token_kind > T__Types_Begin && token_kind < T__Types_End)
		{
			state_field_enter(parser);
		}
	}
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after closed brace at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Stream_Exit, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}
}

internal void
state_list_enter(Parser* parser)
{
	parser->state_stack[parser->state_stack_tail].kind = State_List;
	parser->tokens_tail++;

	// NOTE(rhett): Check if type of length variable is specified
	// NOTE(rhett): Default to u32
	parser->state_stack[parser->state_stack_tail].length_type = T_U32;

	if (parser->tokens[parser->tokens_tail].kind == T_Colon)
	{
		parser->tokens_tail++;

		if (parser->tokens[parser->tokens_tail].kind > T__Integral_Begin && parser->tokens[parser->tokens_tail].kind < T__Integral_End)
		{
			parser->state_stack[parser->state_stack_tail].length_type = parser->tokens[parser->tokens_tail].kind;
			parser->tokens_tail++;
		}
		else if (parser->tokens[parser->tokens_tail].kind == T_Number || parser->tokens[parser->tokens_tail].kind == T_Hex_Number)
		{
			parser->state_stack[parser->state_stack_tail].count_specifier = parser->tokens[parser->tokens_tail];
			parser->tokens_tail++;
		}
		else
		{
			printf("[X] Expected an integral type or count specifier after colon at line: %u\n", parser->tokens[parser->tokens_tail].line);
			abort();
		}
	}

	if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
	{
		printf("[X] Expected identifier for field at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
	parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail].identifier;
	parser->tokens_tail++;

	// TODO(rhett):  makes newlines for braces optional
	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after list at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	// TODO(rhett): next we need braces
	if (parser->tokens[parser->tokens_tail].kind != T_Open_Brace)
	{
		printf("[X] Expected open brace after %s at line %u\n",
					token_names[parser->tokens[parser->tokens_tail - 3].kind],
					parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after open brace at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_List_Enter, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}

	for (; parser->tokens[parser->tokens_tail].kind != T_Close_Brace;)
	{
		Token_Kind token_kind = parser->tokens[parser->tokens_tail].kind;
		if (token_kind > T__Types_Begin && token_kind < T__Types_End)
		{
			state_field_enter(parser);
		}
	}
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after closed brace at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_List_Exit, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}
}

internal void
state_string_enter(Parser* parser)
{
	//parser->state_stack[parser->state_stack_tail].kind = State_String;
	parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
	parser->tokens_tail++;

	// NOTE(rhett): Check if type of length variable is specified
	// NOTE(rhett): Default to u32
	parser->state_stack[parser->state_stack_tail].length_type = T_U32;

	if (parser->tokens[parser->tokens_tail].kind == T_Colon)
	{
		parser->tokens_tail++;

		if (!(parser->tokens[parser->tokens_tail].kind > T__Integral_Begin && parser->tokens[parser->tokens_tail].kind < T__Integral_End))
		{
			printf("[X] Expected an integral type after colon at line: %u\n", parser->tokens[parser->tokens_tail].line);
			abort();
		}
		parser->state_stack[parser->state_stack_tail].length_type = parser->tokens[parser->tokens_tail].kind;
		parser->tokens_tail++;
	}

	if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
	{
		printf("[X] Expected identifier for field at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
	parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail].identifier;
	parser->tokens_tail++;

	// TODO(rhett):  makes newlines for braces optional
	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after string at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Field_String, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}
}

internal void
state_uint2b_enter(Parser* parser)
{
	//parser->state_stack[parser->state_stack_tail].kind = State_String;
	parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
	{
		printf("[X] Expected identifier for field at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
	parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail].identifier;
	parser->tokens_tail++;

	// TODO(rhett):  makes newlines for braces optional
	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after uint2b at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Field_Uint2b, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}
}

internal void
state_bytes_enter(Parser* parser)
{
	//parser->state_stack[parser->state_stack_tail].kind = State_Bytes;
	parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
	parser->tokens_tail++;

	// NOTE(rhett): Check if type of length variable is specified
	// NOTE(rhett): Default to u32
	parser->state_stack[parser->state_stack_tail].length_type = T_U32;

	if (parser->tokens[parser->tokens_tail].kind == T_Colon)
	{
		parser->tokens_tail++;

		if (!(parser->tokens[parser->tokens_tail].kind > T__Integral_Begin && parser->tokens[parser->tokens_tail].kind < T__Integral_End))
		{
			printf("[X] Expected an integral type after colon at line: %u\n", parser->tokens[parser->tokens_tail].line);
			abort();
		}
		parser->state_stack[parser->state_stack_tail].length_type = parser->tokens[parser->tokens_tail].kind;
		parser->tokens_tail++;
	}

	if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
	{
		printf("[X] Expected identifier for field at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
	parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail].identifier;
	parser->tokens_tail++;

	// TODO(rhett):  makes newlines for braces optional
	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after bytes at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Field_Bytes, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}
}

internal void
state_field_enter(Parser* parser)
{
	switch (parser->tokens[parser->tokens_tail].kind)
	{
		case T_List:
		{
			parser->state_stack_tail++;
			parser->depth++;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
	
			// TODO(rhett):  maybe these can use the same function
			state_list_enter(parser);
			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
			parser->depth--;
		} break;

		case T_Stream:
		{
			parser->state_stack_tail++;
			parser->depth++;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
	
			state_stream_enter(parser);
			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
			parser->depth--;
		} break;

		case T_Switch:
		{
			parser->state_stack_tail++;
			parser->depth++;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
	
			state_switch_enter(parser);
			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
			parser->depth--;
		} break;

		//case T_Case:
		//{
			//parser->state_stack_tail++;
			//parser->depth++;
			//parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			//parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			//parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			//parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			//parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			//parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			//parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			//parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
	//
			//state_case_enter(parser);
			//memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			//parser->state_stack_tail--;
			//parser->depth--;
		//} break;

		case T_String:
		{
			parser->state_stack_tail++;
			//parser->state_stack[parser->state_stack_tail].endian = State_String;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
			parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail - 1].parent;

			state_string_enter(parser);

			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
		} break;

		case T_Uint2b:
		{
			parser->state_stack_tail++;
			//parser->state_stack[parser->state_stack_tail].endian = State_Uint2b;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
			parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail - 1].parent;

			state_uint2b_enter(parser);

			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
		} break;
		case T_Bytes:
		{
			parser->state_stack_tail++;
			//parser->state_stack[parser->state_stack_tail].endian = State_Bytes;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
			parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail - 1].parent;

			state_bytes_enter(parser);

			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
		} break;

		case T_Vec4:
		{
			parser->state_stack_tail++;
			//parser->state_stack[parser->state_stack_tail].endian = State_Basic;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
			parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail - 1].parent;
			parser->tokens_tail++;

			if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
			{
				printf("[X] Expected identifier for field at line: %u\n", parser->tokens[parser->tokens_tail].line);
				abort();
			}
			parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
			parser->tokens_tail++;

			if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
			{
				printf("[X] Expected newline after field at line: %u\n", parser->tokens[parser->tokens_tail].line);
				abort();
			}
			parser->tokens_tail++;

			if (parser->emit_func)
			{
				parser->emit_func(PO_Field_Vec4, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
			}

			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
		} break;

		case T_Vec3:
		{
			parser->state_stack_tail++;
			//parser->state_stack[parser->state_stack_tail].endian = State_Basic;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
			parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail - 1].parent;
			parser->tokens_tail++;

			if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
			{
				printf("[X] Expected identifier for field at line: %u\n", parser->tokens[parser->tokens_tail].line);
				abort();
			}
			parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
			parser->tokens_tail++;

			if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
			{
				printf("[X] Expected newline after field at line: %u\n", parser->tokens[parser->tokens_tail].line);
				abort();
			}
			parser->tokens_tail++;

			if (parser->emit_func)
			{
				parser->emit_func(PO_Field_Vec3, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
			}

			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
		} break;

		default:
		{
			parser->state_stack_tail++;
			//parser->state_stack[parser->state_stack_tail].endian = State_Basic;
			parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
			parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
			parser->state_stack[parser->state_stack_tail].packet = parser->state_stack[parser->state_stack_tail - 1].packet;
			parser->state_stack[parser->state_stack_tail].opcode = parser->state_stack[parser->state_stack_tail - 1].opcode;
			parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->state_stack[parser->state_stack_tail - 1].opcode_length_type;
			parser->state_stack[parser->state_stack_tail].subcode = parser->state_stack[parser->state_stack_tail - 1].subcode;
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->state_stack[parser->state_stack_tail - 1].subcode_length_type;
			parser->state_stack[parser->state_stack_tail].data_type = parser->tokens[parser->tokens_tail];
			parser->state_stack[parser->state_stack_tail].parent = parser->state_stack[parser->state_stack_tail - 1].parent;
			parser->tokens_tail++;

			if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
			{
				printf("[X] Expected identifier for field at line: %u\n", parser->tokens[parser->tokens_tail].line);
				abort();
			}
			parser->state_stack[parser->state_stack_tail].identifier = parser->tokens[parser->tokens_tail];
			parser->tokens_tail++;

			if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
			{
				printf("[X] Expected newline after field at line: %u\n", parser->tokens[parser->tokens_tail].line);
				abort();
			}
			parser->tokens_tail++;

			if (parser->emit_func)
			{
				parser->emit_func(PO_Field_Basic, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
			}

			memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
			parser->state_stack_tail--;
		}
	}
}

internal void
state_packet_enter(Parser* parser)
{
	parser->state_stack[parser->state_stack_tail].kind = State_Packet;
	parser->tokens_tail++;


	// NOTE(rhett): We expect an opcode number first
	if (!(parser->tokens[parser->tokens_tail].kind == T_Number || parser->tokens[parser->tokens_tail].kind == T_Hex_Number))
	{
		printf("[X] Expected opcode number for packet at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].opcode = parser->tokens[parser->tokens_tail];
	parser->tokens_tail++;

	// NOTE(rhett): read opcode length type
	// NOTE(rhett): default to u8
	parser->state_stack[parser->state_stack_tail].opcode_length_type = T_U8;

	if (parser->tokens[parser->tokens_tail].kind == T_Colon)
	{
		parser->tokens_tail++;

		if (!(parser->tokens[parser->tokens_tail].kind > T__Integral_Begin && parser->tokens[parser->tokens_tail].kind < T__Integral_End))
		{
			printf("[X] Expected an integral type after colon at line: %u\n", parser->tokens[parser->tokens_tail].line);
			abort();
		}
		parser->state_stack[parser->state_stack_tail].opcode_length_type = parser->tokens[parser->tokens_tail].kind;
		parser->tokens_tail++;
	}


	// NOTE(rhett): read subcode
	if (parser->tokens[parser->tokens_tail].kind == T_Number || parser->tokens[parser->tokens_tail].kind == T_Hex_Number)
	{
		parser->state_stack[parser->state_stack_tail].subcode = parser->tokens[parser->tokens_tail];
		parser->tokens_tail++;

		// NOTE(rhett): read subcode length type
		// NOTE(rhett): default to u8
		parser->state_stack[parser->state_stack_tail].subcode_length_type = T_U8;

		if (parser->tokens[parser->tokens_tail].kind == T_Colon)
		{
			parser->tokens_tail++;

			if (!(parser->tokens[parser->tokens_tail].kind > T__Integral_Begin && parser->tokens[parser->tokens_tail].kind < T__Integral_End))
			{
				printf("[X] Expected an integral type after colon at line: %u\n", parser->tokens[parser->tokens_tail].line);
				abort();
			}
			parser->state_stack[parser->state_stack_tail].subcode_length_type = parser->tokens[parser->tokens_tail].kind;
			parser->tokens_tail++;
		}
	}


	// NOTE(rhett): Now the identifier
	if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
	{
		printf("[X] Expected identifier for packet at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].packet = parser->tokens[parser->tokens_tail];
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after packet at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	// NOTE(rhett): check if we will need a struct
	b32 will_generate_struct = 0;
	if (parser->tokens[parser->tokens_tail].kind > T__Types_Begin && parser->tokens[parser->tokens_tail].kind < T__Types_End)
	{
		will_generate_struct = 1;
	}
	if (parser->emit_func)
	{
		parser->emit_func(PO_Packet_Enter, parser->state_stack, parser->state_stack_tail, parser->output_buffers, will_generate_struct, parser->depth);
	}

	//parser->state_stack[parser->state_stack_tail].depth = parser->state_stack_tail;

	for (; !(parser->tokens[parser->tokens_tail].kind == T_Packet || parser->tokens[parser->tokens_tail].kind == T_EOF);) {
		if (parser->tokens[parser->tokens_tail].kind > T__Types_Begin && parser->tokens[parser->tokens_tail].kind < T__Types_End)
		{
			state_field_enter(parser);
		}
		else
		{
			printf("[X] Expected a type but got a %s at line: %u\n", token_names[parser->tokens[parser->tokens_tail].kind], parser->tokens[parser->tokens_tail].line);
			abort();
		}
	}

	if (parser->emit_func)
	{
		parser->emit_func(PO_Packet_Exit, parser->state_stack, parser->state_stack_tail, parser->output_buffers, will_generate_struct, parser->depth);
	}
	memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
	parser->state_stack_tail--;
}

internal void
state_group_enter(Parser* parser)
{
	parser->state_stack[parser->state_stack_tail].kind = State_Group;
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_Identifier)
	{
		printf("[X] Expected identifier for group at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->state_stack[parser->state_stack_tail].group = parser->tokens[parser->tokens_tail];
	parser->tokens_tail++;

	if (parser->tokens[parser->tokens_tail].kind != T_New_Line)
	{
		printf("[X] Expected newline after group at line: %u\n", parser->tokens[parser->tokens_tail].line);
		abort();
	}
	parser->tokens_tail++;

	if (parser->emit_func)
	{
		parser->emit_func(PO_Group_Enter, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}

	for (; !(parser->tokens[parser->tokens_tail].kind == T_Group || parser->tokens[parser->tokens_tail].kind == T_EOF);)
	{
		// NOTE(rhett): Next we expect a packet
		if (parser->tokens[parser->tokens_tail].kind != T_Packet)
		{
			printf("[X] Expected a packet at line: %u\n", parser->tokens[parser->tokens_tail].line);
			abort();
		}

		parser->state_stack_tail++;
		parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
		parser->state_stack[parser->state_stack_tail].group = parser->state_stack[parser->state_stack_tail - 1].group;
		state_packet_enter(parser);
	}

	if (parser->emit_func)
	{
		parser->emit_func(PO_Group_Exit, parser->state_stack, parser->state_stack_tail, parser->output_buffers, 0, parser->depth);
	}

	memset(&parser->state_stack[parser->state_stack_tail], 0, sizeof(parser->state_stack[parser->state_stack_tail]));
	parser->state_stack_tail--;
}


internal void
state_root_enter(Parser* parser)
{
	parser->state_stack[parser->state_stack_tail].kind = State_Root;
	parser->state_stack[parser->state_stack_tail].endian = T_Endian_Little;

	if (parser->tokens[parser->tokens_tail].kind == T_Group)
	{
		// NOTE(rhett): push state
		parser->state_stack_tail++;
		parser->state_stack[parser->state_stack_tail].endian = parser->state_stack[parser->state_stack_tail - 1].endian;
		state_group_enter(parser);
	}
}

internal u32
write_field_parents(u8* buffer,
										u32 buffer_tail,
										Parser_State state_stack[MAX_STATE_STACK],
										u32 state_stack_tail,
										u32 depth)
{
	u8 parent_buffer[MAX_IDENTIFIER_LENGTH] = { 0 };

	u32 result = 0;
	result += sprintf(buffer + buffer_tail + result,
										"packet->");
	if (state_stack[state_stack_tail].parent.lexeme_length)
	{
		for (u32 i = depth; i > 0; i--)
		{
			memcpy(parent_buffer, state_stack[state_stack_tail - i].parent.lexeme, state_stack[state_stack_tail - i].parent.lexeme_length);
			parent_buffer[state_stack[state_stack_tail - i].parent.lexeme_length] = 0;

			if (state_stack[state_stack_tail - i].kind == State_Switch || state_stack[state_stack_tail - i].kind == State_Case)
			{
				result += sprintf(buffer + buffer_tail + result,
				                  "%s.",
				                  parent_buffer);
			}
			else
			{
				result += sprintf(buffer + buffer_tail + result,
				                  "%s[%s_iter].",
				                  parent_buffer,
				                  parent_buffer);
			}
			
		}
	}

	return result;
}

internal void
emit_c_source(Parser_Object_Kind kind,
								Parser_State state_stack[MAX_STATE_STACK],
								u32 state_stack_tail,
								Output_Buffers* output_buffers,
								b32 will_generate_struct,
								u32 depth)
{
	u8 identifier_buffer[MAX_IDENTIFIER_LENGTH] = { 0 };
	memcpy(identifier_buffer, state_stack[state_stack_tail].identifier.lexeme, state_stack[state_stack_tail].identifier.lexeme_length);

	u8 identifier_buffer_upper[MAX_IDENTIFIER_LENGTH] = { 0 };
	for (u32 i = 0; i < state_stack[state_stack_tail].identifier.lexeme_length; ++i)
	{
		char c = *(state_stack[state_stack_tail].identifier.lexeme + i);
		if (c >= 'a' && c <= 'z')
		{
			c ^= 0b00100000;
		}
		identifier_buffer_upper[i] = c;
	}

	u8 identifier_buffer_lower[MAX_IDENTIFIER_LENGTH] = { 0 };
	for (u32 i = 0; i < state_stack[state_stack_tail].identifier.lexeme_length; ++i)
	{
		char c = *(state_stack[state_stack_tail].identifier.lexeme + i);
		if (c >= 'A' && c <= 'Z')
		{
			c ^= 0b00100000;
		}
		identifier_buffer_lower[i] = c;
	}

	u8 group_buffer[MAX_IDENTIFIER_LENGTH] = { 0 };
	memcpy(group_buffer, state_stack[state_stack_tail].group.lexeme, state_stack[state_stack_tail].group.lexeme_length);

	u8 group_buffer_upper[MAX_IDENTIFIER_LENGTH] = { 0 };
	for (u32 i = 0; i < state_stack[state_stack_tail].group.lexeme_length; ++i)
	{
		char c = *(state_stack[state_stack_tail].group.lexeme + i);
		if (c >= 'a' && c <= 'z')
		{
			c ^= 0b00100000;
		}
		group_buffer_upper[i] = c;
	}

	u8 group_buffer_lower[MAX_IDENTIFIER_LENGTH] = { 0 };
	for (u32 i = 0; i < state_stack[state_stack_tail].group.lexeme_length; ++i)
	{
		char c = *(state_stack[state_stack_tail].group.lexeme + i);
		if (c >= 'A' && c <= 'Z')
		{
			c ^= 0b00100000;
		}
		group_buffer_lower[i] = c;
	}

	u8 packet_buffer[MAX_IDENTIFIER_LENGTH] = { 0 };
	memcpy(packet_buffer, state_stack[state_stack_tail].packet.lexeme, state_stack[state_stack_tail].packet.lexeme_length);

	u8 packet_buffer_upper[MAX_IDENTIFIER_LENGTH] = { 0 };
	for (u32 i = 0; i < state_stack[state_stack_tail].packet.lexeme_length; ++i)
	{
		char c = *(state_stack[state_stack_tail].packet.lexeme + i);
		if (c >= 'a' && c <= 'z')
		{
			c ^= 0b00100000;
		}
		packet_buffer_upper[i] = c;
	}

	u8 packet_buffer_lower[MAX_IDENTIFIER_LENGTH] = { 0 };
	for (u32 i = 0; i < state_stack[state_stack_tail].packet.lexeme_length; ++i)
	{
		char c = *(state_stack[state_stack_tail].packet.lexeme + i);
		if (c >= 'A' && c <= 'Z')
		{
			c ^= 0b00100000;
		}
		packet_buffer_lower[i] = c;
	}

	// TODO(rhett): might move this
	u8 parent_buffer[MAX_IDENTIFIER_LENGTH] = { 0 };
	memcpy(parent_buffer, state_stack[state_stack_tail].parent.lexeme, state_stack[state_stack_tail].parent.lexeme_length);

	switch (kind)
	{
		case PO_Group_Enter:
		{
			output_buffers->kind_buffer_tail += sprintf(output_buffers->kind_buffer + output_buffers->kind_buffer_tail,
																									"\n#define %s_PACKET_KINDS \\\n%s_PACKET_KIND(%s_Packet_Kind_Unhandled, \"Unhandled\"), \\\n",
																									group_buffer_upper,
																									group_buffer_upper,
																									group_buffer);

			output_buffers->registered_ids_buffer_tail += sprintf(output_buffers->registered_ids_buffer + output_buffers->registered_ids_buffer_tail,
			                                                      "\nu32 %s_registered_ids[] =\n{\n",
			                                                      group_buffer_lower);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"\ninternal u32\n%s_packet_pack(%s_Packet_Kind packet_kind, void* packet_ptr, u8* buffer)\n{\n",
																										group_buffer_lower,
																										group_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"u32 offset = 0;\n\nprintf(\"\\n\");\nswitch(packet_kind)\n{\n");

			// TODO(rhett): specify opcode length
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"\ninternal void\n%s_packet_unpack(u8* data, u32 data_length, %s_Packet_Kind packet_kind, void* packet_ptr, Arena* arena)\n{\n",
																											group_buffer_lower,
																											group_buffer);

			// TODO(rhett): change offset length based on opcode length
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"UNUSED(data_length);\nu32 offset = 0;\n\nprintf(\"\\n\");\nswitch (packet_kind)\n{\n");
		} break;
		case PO_Group_Exit:
		{
			output_buffers->kind_buffer_tail += sprintf(output_buffers->kind_buffer + output_buffers->kind_buffer_tail,
																									"%s_PACKET_KIND(%s_Packet_Kind__End, \"\")\n\ntypedef enum %s_Packet_Kind\n{\n#define %s_PACKET_KIND(e, s) e\n%s_PACKET_KINDS\n#undef %s_PACKET_KIND\n} %s_Packet_Kind;\n\n",
																									group_buffer_upper,
																									group_buffer,
																									group_buffer,
																									group_buffer_upper,
																									group_buffer_upper,
																									group_buffer_upper,
																									group_buffer);

			output_buffers->kind_buffer_tail += sprintf(output_buffers->kind_buffer + output_buffers->kind_buffer_tail,
																									"char* %s_packet_names[%s_Packet_Kind__End + 1] =\n{\n#define %s_PACKET_KIND(e, s) s\n%s_PACKET_KINDS\n#undef %s_PACKET_KIND\n};\n\n",
																									group_buffer_lower,
																									group_buffer,
																									group_buffer_upper,
																									group_buffer_upper,
																									group_buffer_upper);

			output_buffers->registered_ids_buffer_tail += sprintf(output_buffers->registered_ids_buffer + output_buffers->registered_ids_buffer_tail,
			                                                      "};\n\n");

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"default:\n{\nprintf(MESSAGE_CONCAT_WARN(\"Packing %%s not implemented\\n\"), %s_packet_names[packet_kind]);\n}\n}\nreturn offset;\n}\n",
																										group_buffer_lower);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"default:\n{\nprintf(MESSAGE_CONCAT_WARN(\"Unpacking %%s not implemented\\n\"), %s_packet_names[packet_kind]);\n}\n}\n}\n",
																											group_buffer_lower);
		} break;
		case PO_Packet_Enter:
		{
			// TODO(rhett): max of 8 bytes of opcode
			u64 opcode_sum = number_token_to_u32(state_stack[state_stack_tail].opcode);

			if (state_stack[state_stack_tail].subcode.kind)
			{
				u32 shift_count = 0;
				switch (state_stack[state_stack_tail].subcode_length_type)
				{
					case T_U8:
					case T_I8:
					{
						shift_count = 8;
					} break;

					case T_U16:
					case T_I16:
					{
						shift_count = 16;
					} break;

					case T_U32:
					case T_I32:
					{
						shift_count = 32;
					} break;

					default:
					{
						printf("[X] Invalid subcode length type %s\n", token_names[state_stack[state_stack_tail].subcode_length_type]);
						abort();
					}
				}
				opcode_sum = (opcode_sum << shift_count) | number_token_to_u32(state_stack[state_stack_tail].subcode);
			}

			output_buffers->define_buffer_tail += sprintf(output_buffers->define_buffer + output_buffers->define_buffer_tail,
																										"#define %s_%s_ID %#llx\n",
																										group_buffer_upper,
																										packet_buffer_upper,
																										opcode_sum);

			output_buffers->kind_buffer_tail += sprintf(output_buffers->kind_buffer + output_buffers->kind_buffer_tail,
																									"%s_PACKET_KIND(%s_Packet_Kind_%s, \"%s\"), \\\n",
																									group_buffer_upper,
																									group_buffer,
																									packet_buffer,
																									packet_buffer);

			output_buffers->registered_ids_buffer_tail += sprintf(output_buffers->registered_ids_buffer + output_buffers->registered_ids_buffer_tail,
			                                                      "[%s_Packet_Kind_%s] = %#llx,\n",
			                                                      group_buffer,
			                                                      packet_buffer,
			                                                      opcode_sum);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"case %s_Packet_Kind_%s:\n{\n",
																										group_buffer,
																										packet_buffer);
	
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"printf(MESSAGE_CONCAT_INFO(\"Packing %s...\\n\"));\n",
																										packet_buffer);

			if (will_generate_struct)
			{
				output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																													"\ntypedef struct %s_Packet_%s %s_Packet_%s;\nstruct %s_Packet_%s\n{\n",
																													group_buffer,
																													packet_buffer,
																													group_buffer,
																													packet_buffer,
																													group_buffer,
																													packet_buffer);


				output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																											"%s_Packet_%s* packet = packet_ptr;\n\n",
																											group_buffer,
																											packet_buffer);


				output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																												"case %s_Packet_Kind_%s:\n{\n",
																												group_buffer,
																												packet_buffer);
	
				output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																												"printf(\"[*] Unpacking %s...\\n\");\n",
																												packet_buffer);

				output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																												"%s_Packet_%s* packet = packet_ptr;\n\n",
																												group_buffer,
																												packet_buffer);
			}
			// TODO(rhett): use active opcode data type
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"endian_write_%s_%s(buffer + offset, %#x);\noffset += sizeof(%s);\n\n",
																										token_names[state_stack[state_stack_tail].opcode_length_type],
																										token_names[state_stack[state_stack_tail].endian],
																										number_token_to_u32(state_stack[state_stack_tail].opcode),
																										token_names[state_stack[state_stack_tail].opcode_length_type]);

			if (state_stack[state_stack_tail].subcode.kind)
			{
				output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																											"endian_write_%s_%s(buffer + offset, %#x);\noffset += sizeof(%s);\n\n",
																											token_names[state_stack[state_stack_tail].subcode_length_type],
																											token_names[state_stack[state_stack_tail].endian],
																											number_token_to_u32(state_stack[state_stack_tail].subcode),
																											token_names[state_stack[state_stack_tail].subcode_length_type]);
			}

		} break;
		case PO_Packet_Exit:
		{
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"} break;\n\n");

			if (will_generate_struct)
			{
				output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																													"};\n\n");

				output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																												"} break;\n\n");
			}
		} break;

		case PO_Field_Vec4:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
			                                                   "%s %s;\n",
			                                                   token_names[state_stack[state_stack_tail].data_type.kind],
			                                                   identifier_buffer);


			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"// %s %s\n",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										identifier_buffer);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"endian_write_%s_%s(buffer + offset, ",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										token_names[state_stack[state_stack_tail].endian]);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s);\noffset += sizeof(f32) * 4;\n",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"printf(\"-- %-24s\\t%%f\\t%%f\\t%%f\\t%%f\\n\", (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.x, (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.y, (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.x, (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.w);\n\n",
																										identifier_buffer);


			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"// %s %s\n",
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s = endian_read_%s_%s(data + offset);\noffset += sizeof(f32) * 4;\n",
																											identifier_buffer,
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											token_names[state_stack[state_stack_tail].endian]);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"printf(\"-- %-24s\\t%%f\\t%%f\\t%%f\\t%%f\\n\", (f64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s.x, (f64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s.y, (f64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s.z, (f64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s.w);\n\n",
																											identifier_buffer);
		} break;

		case PO_Field_Vec3:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
			                                                   "%s %s;\n",
			                                                   token_names[state_stack[state_stack_tail].data_type.kind],
			                                                   identifier_buffer);


			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"// %s %s\n",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										identifier_buffer);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"endian_write_%s_%s(buffer + offset, ",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										token_names[state_stack[state_stack_tail].endian]);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s);\noffset += sizeof(f32) * 3;\n",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"printf(\"-- %-24s\\t%%f\\t%%f\\t%%f\\n\", (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.x, (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.y, (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.x);\n\n",
																										identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"// %s %s\n",
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s = endian_read_%s_%s(data + offset);\noffset += sizeof(f32) * 3;\n",
																											identifier_buffer,
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											token_names[state_stack[state_stack_tail].endian]);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"printf(\"-- %-24s\\t%%f\\t%%f\\t%%f\\n\", (f64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s.x, (f64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s.y, (f64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s.z);\n\n",
																											identifier_buffer);

		} break;

		case PO_Field_Basic:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												"%s %s;\n",
																												token_names[state_stack[state_stack_tail].data_type.kind],
																												identifier_buffer);

			// NOTE(rhett): packer
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"// %s %s\n",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										identifier_buffer);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"endian_write_%s_%s(buffer + offset, ",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										token_names[state_stack[state_stack_tail].endian]);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s);\noffset += sizeof(%s);\n",
																										identifier_buffer,
																										token_names[state_stack[state_stack_tail].data_type.kind]);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"printf(\"-- %-24s\\t%%lld\\t%%llxh\\t%%f\\n\", (i64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s, (u64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s, (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s);\n\n",
																										identifier_buffer);

			// NOTE(rhett): unpacker
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"// %s %s\n",
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s = endian_read_%s_%s(data + offset);\noffset += sizeof(%s);\n",
																											identifier_buffer,
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											token_names[state_stack[state_stack_tail].endian],
																											token_names[state_stack[state_stack_tail].data_type.kind]);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"printf(\"-- %-24s\\t%%lld\\t%%llxh\\t%%f\\n\", (i64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s, (u64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s, (f64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											");\n\n");
		} break;
		case PO_Field_String:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												 "%s %s_length;\n",
																												 token_names[state_stack[state_stack_tail].length_type],
																												 identifier_buffer);

			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												 "char* %s;\n",
																												 identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"// %s %s\n",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"endian_write_%s_%s(buffer + offset, ",
																										token_names[state_stack[state_stack_tail].length_type],
																										token_names[state_stack[state_stack_tail].endian]);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length);\noffset += sizeof(%s);\n",
																										identifier_buffer,
																										token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"printf(\"-- %-24s\\t%%lld\\t%%llxh\\t%%f\\n\", (i64)",
																										"STRING_LENGTH");

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length, (u64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length, (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length);\n",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"for (u32 %s_iter = 0; %s_iter < ",
																										identifier_buffer,
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length; %s_iter++)\n{\n",
																										identifier_buffer,
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"endian_write_i8_%s(buffer + offset, ",
																										token_names[state_stack[state_stack_tail].endian]);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s[%s_iter]);\n",
																										identifier_buffer,
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"offset++;\n}\n\n");

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"// %s %s\n",
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length = endian_read_%s_%s(data + offset);\noffset += sizeof(%s);\n",
																											identifier_buffer,
																											token_names[state_stack[state_stack_tail].length_type],
																											token_names[state_stack[state_stack_tail].endian],
																											token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s = arena_push_size(arena, ",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length);\n",
																											identifier_buffer);

			//output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"printf(\"-- %-24s\\t%%d\\n\", ",
																											"STRING_LENGTH");

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length);\n",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"for (%s %s_iter = 0; %s_iter < ",
																											token_names[state_stack[state_stack_tail].length_type],
																											identifier_buffer,
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length; %s_iter++)\n{\n",
																											identifier_buffer,
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s[%s_iter] = *(i8*)((uptr)data + offset);\n",
																											identifier_buffer,
																											identifier_buffer);
		
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"offset++;\n");

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"}\n\n");
		} break;

		case PO_Field_Uint2b:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
			                                                   "%s %s;\n",
			                                                   token_names[state_stack[state_stack_tail].data_type.kind],
			                                                   identifier_buffer);


			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"// %s %s\n",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										identifier_buffer);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"offset += endian_write_%s_%s(buffer + offset, ",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										token_names[state_stack[state_stack_tail].endian]);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.value);\n",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"printf(\"-- %-24s\\t%%lld\\t%%llxh\\n\", (i64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.value, (u64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s.value);\n\n",
																										identifier_buffer);


			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"// %s %s\n",
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s = endian_read_%s_%s(data + offset);\noffset += ",
																											identifier_buffer,
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											token_names[state_stack[state_stack_tail].endian]);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
			                                                "%s.length;\n",
			                                                identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"printf(\"-- %-24s\\t%%lld\\t%%llxh\\n\", (i64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s.value, (u64)",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s.value);\n\n",
																											identifier_buffer);

		} break;

		case PO_Field_Bytes:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												 "%s %s_length;\n",
																												 token_names[state_stack[state_stack_tail].length_type],
																												 identifier_buffer);

			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												 "u8* %s;\n",
																												 identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"// %s %s\n",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"endian_write_%s_%s(buffer + offset, ",
																										token_names[state_stack[state_stack_tail].length_type],
																										token_names[state_stack[state_stack_tail].endian]);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length);\noffset += sizeof(%s);\n",
																										identifier_buffer,
																										token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"printf(\"-- %-24s\\t%%lld\\t%%llxh\\t%%f\\n\", (i64)",
																										"BYTES_LENGTH");

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length, (u64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length, (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length);\n",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"for (u32 %s_iter = 0; %s_iter < ",
																										identifier_buffer,
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length; %s_iter++)\n{\n",
																										identifier_buffer,
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"endian_write_u8_%s(buffer + offset, ",
																										token_names[state_stack[state_stack_tail].endian]);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s[%s_iter]);\n",
																										identifier_buffer,
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"offset++;\n}\n\n");

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"// %s %s\n",
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length = endian_read_%s_%s(data + offset);\noffset += sizeof(%s);\n",
																											identifier_buffer,
																											token_names[state_stack[state_stack_tail].length_type],
																											token_names[state_stack[state_stack_tail].endian],
																											token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s = arena_push_size(arena, ",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length);\n",
																											identifier_buffer);

			//output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"printf(\"-- %-24s\\t%%d\\n\", ",
																											"BYTES_LENGTH");

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length);\n",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"for (%s %s_iter = 0; %s_iter < ",
																											token_names[state_stack[state_stack_tail].length_type],
																											identifier_buffer,
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length; %s_iter++)\n{\n",
																											identifier_buffer,
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s[%s_iter] = *(u8*)((uptr)data + offset);\n",
																											identifier_buffer,
																											identifier_buffer);
		
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"offset++;\n");

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"}\n\n");
		} break;
		case PO_List_Enter:
		{

			// NOTE(rhett): we'll re-use count for a specified count, just won't write or read it
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												"%s %s_count;\n",
																												token_names[state_stack[state_stack_tail].length_type],
																												identifier_buffer);

			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												"struct %s_s\n{\n",
																												 identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                              "// %s %s\n",
			                                              token_names[state_stack[state_stack_tail].data_type.kind],
			                                              identifier_buffer);

			if (!state_stack[state_stack_tail].count_specifier.kind)
			{
				output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
				                                              "endian_write_%s_%s(buffer + offset, ",
				                                              token_names[state_stack[state_stack_tail].length_type],
				                                              token_names[state_stack[state_stack_tail].endian]);

				output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
				output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
				                                              "%s_count);\noffset += sizeof(%s);\n",
				                                              identifier_buffer,
				                                              token_names[state_stack[state_stack_tail].length_type]);

				output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
				                                              "printf(\"-- %-24s\\t%%lld\\t%%llxh\\t%%f\\n\", (i64)",
				                                              "LIST_COUNT");

				output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
				output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
				                                              "%s_count, (u64)",
				                                              identifier_buffer);

				output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
				output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
				                                              "%s_count, (f64)",
				                                              identifier_buffer);

				output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
				output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
				                                              "%s_count);\n\n",
				                                              identifier_buffer);
			}
			else
			{
				output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
				output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
				                                              "%s_count = %d;\n",
				                                              identifier_buffer,
				                                              number_token_to_u32(state_stack[state_stack_tail].count_specifier));
			}

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"for (u32 %s_iter = 0; %s_iter < ",
																										identifier_buffer,
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_count; %s_iter++)\n{\n",
																										identifier_buffer,
																										identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"// %s %s\n",
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											identifier_buffer);


			// TODO(rhett): store function names somewhere, switch depending on endianess
			if (!state_stack[state_stack_tail].count_specifier.kind)
			{
				output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
				output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
				                                                "%s_count = endian_read_%s_%s(data + offset);\noffset += sizeof(%s);\n",
				                                                identifier_buffer,
				                                                token_names[state_stack[state_stack_tail].length_type],
				                                                token_names[state_stack[state_stack_tail].endian],
				                                                token_names[state_stack[state_stack_tail].length_type]);
			}
			else
			{
				output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
				output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
				                                                "%s_count = %d;\n",
				                                                identifier_buffer,
				                                                number_token_to_u32(state_stack[state_stack_tail].count_specifier));
			}

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s = arena_push_size(arena, ",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_count * sizeof(",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s[0]));\n",
																											identifier_buffer);

			//output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"printf(\"-- %-24s\\t%%d\\n\", ",
																											"LIST_COUNT");

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_count);\n",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"for (%s %s_iter = 0; %s_iter < ",
																											token_names[state_stack[state_stack_tail].length_type],
																											identifier_buffer,
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_count; %s_iter++)\n{\n",
																											identifier_buffer,
																											identifier_buffer);
		} break;
		case PO_List_Exit:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												 "}* %s;\n",
																												 identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"} // %s\n\n",
																										identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"} // %s\n\n",
																											identifier_buffer);
		} break;
		// TODO(rhett): Stream doesn't need a for loop
		case PO_Stream_Enter:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												 "%s %s_length;\n",
																												 token_names[state_stack[state_stack_tail].length_type],
																												 identifier_buffer);

			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												 "struct %s_s\n{\n",
																												 identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"// %s %s\n",
																										token_names[state_stack[state_stack_tail].data_type.kind],
																										identifier_buffer);

			// TODO(rhett): come back to this pointer to write total length
			//output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										//"endian_write_%s_%s(buffer + offset, ",
																										//token_names[state_stack[state_stack_tail].length_type],
																										//token_names[state_stack[state_stack_tail].endian]);
//
			//output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			//output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										//"%s_length);\noffset += sizeof(%s);\n",
																										//identifier_buffer,
																										//token_names[state_stack[state_stack_tail].length_type]);

			//output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"void* %s_length_ptr = buffer + offset;\noffset += sizeof(%s);\n",
																										identifier_buffer,
																										token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"printf(\"-- %-24s\\t%%lld\\t%%llxh\\t%%f\\n\", (i64)",
																										"STREAM_LENGTH");

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length, (u64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length, (f64)",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length);\n\n",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"u32 will_pack_%s = ",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"%s_length == ~(%s)0 ? 0 : 1;\n",
																										identifier_buffer,
																										token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"for (u32 %s_iter = 0; %s_iter < ",
																										identifier_buffer,
																										identifier_buffer);

			//output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"will_pack_%s; %s_iter++)\n{\n",
																										identifier_buffer,
																										identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"// %s %s\n",
																											token_names[state_stack[state_stack_tail].data_type.kind],
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);

			// TODO(rhett): store function names somewhere, switch depending on endianess
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length = endian_read_%s_%s(data + offset);\noffset += sizeof(%s);\n",
																											identifier_buffer,
																											token_names[state_stack[state_stack_tail].length_type],
																											token_names[state_stack[state_stack_tail].endian],
																											token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s = arena_push_size(arena, ",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length * sizeof(",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s[0]));\n",
																											identifier_buffer);

			//output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"printf(\"-- %-24s\\t%%d\\n\", ",
																											"STREAM_LENGTH");

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length);\n",
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"for (%s %s_iter = 0; %s_iter < (",
																											token_names[state_stack[state_stack_tail].length_type],
																											identifier_buffer,
																											identifier_buffer);

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_length > (%s)0 ? (%s)1 : (%s)0)",
																											identifier_buffer,
																											token_names[state_stack[state_stack_tail].length_type],
																											token_names[state_stack[state_stack_tail].length_type],
																											token_names[state_stack[state_stack_tail].length_type]);

			//output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"; %s_iter++)\n{\n",
																											identifier_buffer);
		} break;
		case PO_Stream_Exit:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
																												 "}* %s;\n",
																												 identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"} // %s\n",
																										identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
																										"endian_write_%s_%s((u8*)%s_length_ptr, (%s)((uptr)buffer + (uptr)offset - (uptr)%s_length_ptr - sizeof(%s)));\n\n",
																										token_names[state_stack[state_stack_tail].length_type],
																										token_names[state_stack[state_stack_tail].endian],
																										identifier_buffer,
																										token_names[state_stack[state_stack_tail].length_type],
																										identifier_buffer,
																										token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"} // %s\n\n",
																											identifier_buffer);
		} break;

		case PO_Switch_Enter:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
			                                                   "%s %s_case;\n",
			                                                   token_names[state_stack[state_stack_tail].length_type],
			                                                   identifier_buffer);
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
			                                                   "union\n{\n");

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
																											"%s_case = endian_read_%s_%s(data + offset);\noffset += sizeof(%s);\n",
																											identifier_buffer,
																											token_names[state_stack[state_stack_tail].length_type],
																											token_names[state_stack[state_stack_tail].endian],
																											token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
			                                                "switch(");

			output_buffers->unpacker_buffer_tail += write_field_parents(output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
			                                                "%s_case)\n{\n",
			                                                identifier_buffer);


			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                              "endian_write_%s_%s(buffer + offset, ",
			                                              token_names[state_stack[state_stack_tail].length_type],
			                                              token_names[state_stack[state_stack_tail].endian]);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                              "%s_case);\noffset += sizeof(%s);\n",
			                                              identifier_buffer,
			                                              token_names[state_stack[state_stack_tail].length_type]);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                              "printf(\"-- %-24s\\t%%lld\\t%%llxh\\t%%f\\n\", (i64)",
			                                              "SWITCH_CASE");

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                              "%s_case, (u64)",
			                                              identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                              "%s_case, (f64)",
			                                              identifier_buffer);

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                              "%s_case);\n\n",
			                                              identifier_buffer);

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                                "switch(");

			output_buffers->packer_buffer_tail += write_field_parents(output_buffers->packer_buffer, output_buffers->packer_buffer_tail, state_stack, state_stack_tail, depth - 1);
			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                                "%s_case)\n{\n",
			                                                identifier_buffer);
		} break;

		case PO_Switch_Exit:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
			                                                   "} %s;\n",
			                                                   identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
			                                                "};\n");

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                                "};\n");
		} break;

		case PO_Case_Enter:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
			                                                   "struct %s_s\n{\n",
			                                                   identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
			                                                "case %u:\n{\n",
			                                                number_token_to_u32(state_stack[state_stack_tail].opcode));

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                                "case %u:\n{\n",
			                                                number_token_to_u32(state_stack[state_stack_tail].opcode));

		} break;

		case PO_Case_Exit:
		{
			output_buffers->main_struct_buffer_tail += sprintf(output_buffers->main_struct_buffer + output_buffers->main_struct_buffer_tail,
			                                                   "} %s;\n",
			                                                   identifier_buffer);

			output_buffers->unpacker_buffer_tail += sprintf(output_buffers->unpacker_buffer + output_buffers->unpacker_buffer_tail,
			                                                "} break;\n");

			output_buffers->packer_buffer_tail += sprintf(output_buffers->packer_buffer + output_buffers->packer_buffer_tail,
			                                                "} break;\n");
		} break;
	}
};

internal void
parse_tokens(Token* tokens, Output_Buffers* output_buffers)
{
	Parser parser =
	{
		.tokens = tokens,
		.output_buffers = output_buffers,
		.emit_func = emit_c_source,
	};

	state_root_enter(&parser);
}

// TODO(rhett): opcode type is hardcoded
int main(int argc, char* argv[])
{
	u32 file_buffer_length = MB(10);
	u8* file_buffer = malloc(file_buffer_length);

	u32 read_length = win32_buffer_load_from_file(argv[1], file_buffer, file_buffer_length);

	u32 token_buffer_capacity = MB(4) / sizeof(Token);
	Token* token_buffer = malloc(sizeof(Token) * token_buffer_capacity);

	Keyword_Hash_Map keyword_map = { .capacity = MAX_KEYWORD_HASH_MAP_BUCKETS, };
	for (int i = T__Keyword_Begin + 1; i < T__Keyword_End; i++)
	{
		keyword_hash_map_key_insert(&keyword_map, token_names[i], 0, (Token_Kind)i);
	}

	for (int i = T__Special_Type_Begin + 1; i < T__Special_Type_End; i++)
	{
		keyword_hash_map_key_insert(&keyword_map, token_names[i], 0, (Token_Kind)i);
	}

	for (int i = T__Integral_Begin + 1; i < T__Integral_End; i++)
	{
		keyword_hash_map_key_insert(&keyword_map, token_names[i], 0, (Token_Kind)i);
	}

	for (int i = T__Endian_Type_Begin + 1; i < T__Endian_Type_End; i++)
	{
		keyword_hash_map_key_insert(&keyword_map, token_names[i], 0, (Token_Kind)i);
	}

	printf("[*] Hash map load: %f\n", (f64)keyword_map.entry_count / (f64)keyword_map.capacity);

	u32 token_count = scan_tokens(file_buffer, read_length, token_buffer, &keyword_map);
	sizeof(token_count);
	//for (u32 i = 0; i < token_count; i++)
	//{
	//	printf("kind=%s, line=%d, ", token_names[token_buffer[i].type], token_buffer[i].line);
	//	print_string(token_buffer[i].lexeme, token_buffer[i].lexeme_length);
	//	putchar('\n');
	//}

	Output_Buffers* output_buffers = malloc(sizeof(*output_buffers));

	parse_tokens(token_buffer, output_buffers);

	ST_Buffer output_buffer =
	{
		.capacity = sizeof(*output_buffers),
		.data = malloc(sizeof(*output_buffers)),
	};

	memcpy(output_buffer.data + output_buffer.tail, output_buffers->define_buffer, output_buffers->define_buffer_tail);
	output_buffer.tail += output_buffers->define_buffer_tail;
	memcpy(output_buffer.data + output_buffer.tail, output_buffers->kind_buffer, output_buffers->kind_buffer_tail);
	output_buffer.tail += output_buffers->kind_buffer_tail;
	memcpy(output_buffer.data + output_buffer.tail, output_buffers->registered_ids_buffer, output_buffers->registered_ids_buffer_tail);
	output_buffer.tail += output_buffers->registered_ids_buffer_tail;
	memcpy(output_buffer.data + output_buffer.tail, output_buffers->helper_struct_buffer, output_buffers->helper_buffer_tail);
	output_buffer.tail += output_buffers->helper_buffer_tail;
	memcpy(output_buffer.data + output_buffer.tail, output_buffers->main_struct_buffer, output_buffers->main_struct_buffer_tail);
	output_buffer.tail += output_buffers->main_struct_buffer_tail;
	memcpy(output_buffer.data + output_buffer.tail, output_buffers->packer_buffer, output_buffers->packer_buffer_tail);
	output_buffer.tail += output_buffers->packer_buffer_tail;
	memcpy(output_buffer.data + output_buffer.tail, output_buffers->unpacker_buffer, output_buffers->unpacker_buffer_tail);
	output_buffer.tail += output_buffers->unpacker_buffer_tail;

	win32_buffer_write_to_file(argv[2], output_buffer.data, output_buffer.tail);

	return 0;
}
