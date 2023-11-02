// TODO(rhett): actually probably don't need this
// TODO(rhett): or maybe I do?
// YOTE_IMPLEMENTATION

// YOTE_SLOW
// YOTE_INTERNAL

// YOTE_USE_ARENA
// YOTE_USE_STRING

// TODO(rhett): maybe x86 xor x64
// YOTE_NO_X64 ??

// TODO(rhett): Sort out standard library dependence
// TODO(rhett): size is count of bytes. length is count of contiguous elements?

//====================================================================================================
// Base - Required by all lower layers. Includes other 'Base' layers
//====================================================================================================

#include <stdbool.h>
#include <stdint.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef intptr_t iptr;
typedef ptrdiff_t isize;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uintptr_t uptr;
typedef size_t usize;

typedef i8 b8;
typedef i16 b16;
typedef i32 b32;
typedef i64 b64;

typedef unsigned char uchar;
typedef float f32;
typedef double f64;

#if defined(YOTE_INTERNAL)
// NOTE(rhett): removing static linkage to play along with superluminal
#define internal
// TODO(rhett): This may depend on msvc.
#define DEBUG_BREAK __debugbreak()
#else
#define internal static
#define DEBUG_BREAK
#endif // YOTE_INTERNAL

#define local_persist static
#define global static

// TODO(rhett): windows.h will probably override this. think about it

#define KB(n) ((n) * 1024)
#define MB(n) (KB(n) * 1024)
// TODO(rhett): integral promotion may become an issue
#define GB(n) (MB(n) * (u64)1024)
#define TB(n) (GB(n) * (u64)1024)

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

#define OFFSET_OF(type, member) ((isize) & ((type *)0)->member)
#define SIZE_OF(x) ((isize)sizeof(x))
#define UNUSED(x) (void)x
#define IS_POWER_OF_TWO(x) ((x & (x - 1)) == 0)
#define ARRAY_COUNT(a) (SIZE_OF(a) / SIZE_OF(a[0]))
#define STRINGIFY_INTERNAL(x) #x
#define STRINGIFY(x) STRINGIFY_INTERNAL(x)
#define ABORT *(int *)0 = 0
#define ABORT_MSG(msg) ABORT

#if defined(YOTE_SLOW)
#define ASSERT(expr) \
	if (!(expr))     \
	{                \
		ABORT;       \
	}
// TODO(rhett): Probably don't need to wrap msg in parens or logical NOTs, right?
#define ASSERT_MSG(expr, msg) ASSERT((expr) && msg)
#else
#define ASSERT(expr)
#define ASSERT_MSG(expr, msg)
#endif // YOTE_SLOW

// NOTE(rhett): Causes a negative subscript error if condition is false
// TODO(rhett): Probably don't need to undefine these
#define STATIC_ASSERT_INTERNAL_1(cond, line) typedef char static_assert_line_##line[(!!(cond)) * 2 - 1]
#define STATIC_ASSERT_INTERNAL_2(cond, line) STATIC_ASSERT_INTERNAL_1(cond, line)
#define STATIC_ASSERT(cond) STATIC_ASSERT_INTERNAL_2(cond, __LINE__)

#define MESSAGE_NAMESPACE_DEFAULT "Default"
#define MESSAGE_NAMESPACE MESSAGE_NAMESPACE_DEFAULT
#define MESSAGE_CONCAT_INFO(msg) "[*] [" MESSAGE_NAMESPACE "] " msg
#define MESSAGE_CONCAT_WARN(msg) "[!] [" MESSAGE_NAMESPACE "] " msg
#define MESSAGE_CONCAT_FATAL(msg) "[X] [" MESSAGE_NAMESPACE "] <" __FILE__ "(" STRINGIFY(__LINE__) ")> " msg

#define EVAL_PRINT_I32(x) printf("%s = %d:%x\n", #x, x, x)
#define EVAL_PRINT_U32(x) printf("%s = %u:%x\n", #x, x, x)
#define EVAL_PRINT_I64(x) printf("%s = %lld:%llx\n", #x, x, x)
#define EVAL_PRINT_U64(x) printf("%s = %llu:%llx\n", #x, x, x)
#define EVAL_PRINT_F32(x) printf("%s = %f:%x\n", #x, x, *(u32 *)&x)
#define EVAL_PRINT_F64(x) printf("%s = %f:%x\n", #x, x, *(u64 *)&x)
#define EVAL_PRINT_CSTR(x) printf("%s = \"%s\"\n", #x, x)

// TODO(rhett): try this
#define DO_ONCE(to_do)                        \
	local_persist b32 do_once_##__LINE__ = 0; \
	if (!do_once_##__LINE__++)                \
	{                                         \
		to_do;                                \
	}

// TODO(rhett): solidify distinction between args and params

// NOTE(rhett): https://stackoverflow.com/a/34182426
// TODO(rhett): Do we need STRIP_PARAMS around the UNPACK_PARAMS?
// #define STRIP_PARENS(X)     X
#define UNPACK_PARAMS(...) __VA_ARGS__
#define PASS_PARAMS(X) UNPACK_PARAMS X

#define PARAMS_DECLARE(return_type, name, args) \
	typedef struct name##_params                \
	{                                           \
		int _;                                  \
		args;                                   \
	} name##_params;                            \
	return_type(name)(name##_params params)
#define PARAMS_BIND(name, defaults, ...) name((name##_params){defaults, ._ = 0, __VA_ARGS__})

// #define foo(...) PARAMS_BIND(foo, PASS_PARAMS((.a=1, .b=2, .c=3, .d=4)), __VA_ARGS__)
// PARAMS_DECLARE(foo, int a; int b; int c; int d, void)
//{
// printf("%d %d %d %d\n", params.a, params.b, params.c, params.d);
//}

#if 0
// TODO(rhett): empty field at start to allow no params?
#define PARAMS_DECLARE(return_type, name, ...) \
	typedef struct                             \
	{                                          \
		u32 unused;                            \
		__VA_ARGS__;                           \
	} name##_params;                           \
	return_type name##_internal(name##_params params)
#define PARAMS_BIND(name, ...) name##_internal((name##_params){0, __VA_ARGS__})
#define PARAMS_DEFAULT(name, value) name = params.name ? params.name : (value)
#endif

// #define test_func(...) PARAMS_BIND(test_func, __VA_ARGS__)
// PARAMS_DECLARE(void, test_func, u32 a0; f32 a1;)
//{
// u32 PARAMS_DEFAULT(a0, 123);
// f32 PARAMS_DEFAULT(a1, 321.0f);
//
// EVAL_PRINT_U32(a0);
// EVAL_PRINT_F32(a1);
//
// DEBUG_BREAK;
//}

STATIC_ASSERT(SIZE_OF(u8) == 1);
STATIC_ASSERT(SIZE_OF(i8) == 1);
STATIC_ASSERT(SIZE_OF(b8) == 1);
STATIC_ASSERT(SIZE_OF(u16) == 2);
STATIC_ASSERT(SIZE_OF(i16) == 2);
STATIC_ASSERT(SIZE_OF(b16) == 2);
STATIC_ASSERT(SIZE_OF(u32) == 4);
STATIC_ASSERT(SIZE_OF(i32) == 4);
STATIC_ASSERT(SIZE_OF(b32) == 4);
STATIC_ASSERT(SIZE_OF(f32) == 4);
STATIC_ASSERT(SIZE_OF(u64) == 8);
STATIC_ASSERT(SIZE_OF(i64) == 8);
STATIC_ASSERT(SIZE_OF(b64) == 8);
STATIC_ASSERT(SIZE_OF(f64) == 8);
STATIC_ASSERT(SIZE_OF(uptr) == 4 || SIZE_OF(uptr) == 8);
STATIC_ASSERT(SIZE_OF(iptr) == 4 || SIZE_OF(iptr) == 8);
STATIC_ASSERT(SIZE_OF(isize) == 4 || SIZE_OF(isize) == 8);
STATIC_ASSERT(SIZE_OF(isize) == 4 || SIZE_OF(isize) == 8);

typedef struct Buffer Buffer;
struct Buffer
{
	isize size;
	u8 *data;
};

typedef struct Stream Stream;
struct Stream
{
	Buffer buffer;
	uptr cursor;
};

internal void base_memory_fill(void *destination, u8 value, isize size)
{
	for (isize i = 0; i < size; i++)
	{
		*(u8 *)((uptr)destination + i) = value;
	}
}

internal void base_memory_copy(void *destination, void *source, isize size)
{
	for (isize i = 0; i < size; i++)
	{
		*(u8 *)((uptr)destination + i) = *(u8 *)((uptr)source + i);
	}
}

// TODO(rhett): Use length instead here? Or will that be more confusing since they're equal in this context?
internal isize base_ztstring_size(u8 *data)
{
	isize count = 0;
	for (; data[count] != 0; count++)
		;

	return count;
}

internal uptr base_align_forward(uptr ptr, isize align)
{
	ASSERT(IS_POWER_OF_TWO(align));

	uptr remainder = ptr & (align - 1);
	if (remainder)
	{
		ptr += align - remainder;
	}

	return ptr;
}

//====================================================================================================
// Memory Arena -
//====================================================================================================

#if defined(YOTE_USE_ARENA)

// TODO(rhett): Re-write debug/internal code
// TODO(rhett): is this a fine default?
#define ARENA_ALIGN_DEFAULT (sizeof(void *) * 2)
#define ARENA_DEFAULT_PARAMS PASS_PARAMS((.should_clear = true, .alignment = ARENA_ALIGN_DEFAULT))

typedef struct Arena Arena;
struct Arena
{
	void *buffer;
	isize capacity;
	isize tail_offset;

	char *name;
	isize padding;
	isize peak_used;
	isize peak_padding;
	i32 active_count;
};

typedef struct Arena_Temp Arena_Temp;
struct Arena_Temp
{
	Arena *arena;
	isize tail_offset;
};

#define arena_push_size(...) PARAMS_BIND(arena_push_size, ARENA_DEFAULT_PARAMS, __VA_ARGS__)
PARAMS_DECLARE(void *, arena_push_size, Arena *arena; isize size; b32 should_clear; isize alignment)
{
	// TODO(rhett): think about if I can simplify this. probably not
	// Arena* arena = params.arena;
	// isize size = params.size;
	ASSERT(params.arena);
	ASSERT(params.size);
	// NOTE(rhett): default must be false since false is a valid input
	// b32 PARAMS_DEFAULT(should_skip_clear, false);
	// isize PARAMS_DEFAULT(alignment, ARENA_ALIGN_DEFAULT);

	uptr aligned_ptr = base_align_forward((uptr)params.arena->buffer + params.arena->tail_offset, params.alignment);
	isize padding = 0;
	padding = aligned_ptr - ((uptr)params.arena->buffer + params.arena->tail_offset);

	// TODO(rhett): Assert for now. we should be able to recover from this later I think
	ASSERT_MSG((params.size + padding) < params.arena->capacity, "Allocation excedes arena capacity");

	if (params.should_clear)
	{
		base_memory_fill((void *)aligned_ptr, 0, params.size);
	}

	params.arena->padding += padding;
	params.arena->tail_offset += params.size + padding;
	params.arena->active_count += 1;

	return (void *)aligned_ptr;
}

// TODO(rhett): preeeeeeeeeetty sure this will work right
#define arena_push_struct(arena, type, ...) (type *)arena_push_size(arena, SIZE_OF(type), __VA_ARGS__)
#define arena_push_array(arena, type, count, ...) (type *)arena_push_size(arena, SIZE_OF(type) * count, __VA_ARGS__)
#define arena_bootstrap_push_struct(buffer, capacity, name, type, member, ...) arena_bootstrap_push_size(buffer, capacity, name, SIZE_OF(type), offsetof(type, member), __VA_ARGS__)

#define arena_push_copy(...) PARAMS_BIND(arena_push_copy, ARENA_DEFAULT_PARAMS, __VA_ARGS__)
PARAMS_DECLARE(void *, arena_push_copy, Arena *arena; void *source; isize source_size; b32 should_clear; isize alignment)
{
	ASSERT(params.arena);
	ASSERT(params.source);
	ASSERT(params.source_size);

	void *result = arena_push_size(params.arena,
								   params.source_size,
								   params.should_clear,
								   params.alignment);
	base_memory_copy(result, params.source, params.source_size);
	return result;
}

#define arena_push_copy_zero_terminate(...) PARAMS_BIND(arena_push_copy_zero_terminate, ARENA_DEFAULT_PARAMS, __VA_ARGS__)
PARAMS_DECLARE(void *, arena_push_copy_zero_terminate, Arena *arena; void *source; isize source_size; b32 should_clear; isize alignment)
{
	ASSERT(params.arena);
	ASSERT(params.source);
	ASSERT(params.source_size);

	void *result = arena_push_size(params.arena,
								   params.source_size + 1,
								   params.should_clear,
								   params.alignment);
	base_memory_copy(result, params.source, params.source_size);
	return result;
}

#define arena_push_copy_ztstring_as_string(...) PARAMS_BIND(arena_push_copy_ztstring_as_string, ARENA_DEFAULT_PARAMS, __VA_ARGS__)
PARAMS_DECLARE(Buffer, arena_push_copy_ztstring_as_string, Arena *arena; void *source; b32 should_clear; isize alignment)
{
	ASSERT(params.arena);
	ASSERT(params.source);

	// NOTE(rhett): keeping zero-termination for functions that expect that
	Buffer result =
		{
			.size = base_ztstring_size(params.source),
			.data = arena_push_size(params.arena, result.size + 1, params.should_clear, params.alignment),
		};
	base_memory_copy(result.data, params.source, result.size);
	return result;
}

// TODO(rhett): how should we handle names? only in internal mode?
#define arena_bootstrap_push_size(...) PARAMS_BIND(arena_bootstrap_push_size, ARENA_DEFAULT_PARAMS, __VA_ARGS__)
PARAMS_DECLARE(void *, arena_bootstrap_push_size, void *buffer; isize capacity; char *name; isize struct_size; isize offset_to_arena; b32 should_clear; isize alignment)
{
	ASSERT(params.buffer);
	ASSERT(params.capacity);
	ASSERT(params.name);
	ASSERT(params.struct_size);
	ASSERT(params.offset_to_arena);

	Arena bootstrap =
		{
			.buffer = params.buffer,
			.capacity = params.capacity,
			.name = params.name,
		};
	void *bootstrap_struct = arena_push_size(&bootstrap, params.struct_size, params.should_clear, params.alignment);
	*(Arena *)((uptr)bootstrap_struct + params.offset_to_arena) = bootstrap;

	return bootstrap_struct;
}

internal void arena_rewind(Arena *arena, u32 rewind_size)
{
	arena->tail_offset -= rewind_size;
}

internal void arena_reset(Arena *arena)
{
	arena->peak_used = MAX(arena->tail_offset, arena->peak_used);
	arena->peak_padding = MAX(arena->padding, arena->peak_padding);
	arena->active_count = 0;
	arena->tail_offset = 0;
	arena->padding = 0;
}

internal Arena_Temp arena_temp_begin(Arena *arena)
{
	return (Arena_Temp){.arena = arena, .tail_offset = arena->tail_offset};
}

internal void arena_temp_end(Arena_Temp temp)
{
	temp.arena->tail_offset = temp.tail_offset;
}

#endif // YOTE_USE_ARENA

//====================================================================================================
// String - String related functions which require higher layers such as Memory Arena
//====================================================================================================

#if defined(YOTE_USE_STRING)

typedef struct Substring_List Substring_List;
struct Substring_List
{
	//	String backing_string;
	isize substrings_count;
	Buffer *substrings;
};

Substring_List string_ztstring_copy_and_split(char *source, char delim, isize max_substrings, Arena *arena)
{
	Substring_List result =
		{
			.substrings = arena_push_array(arena, Buffer, max_substrings),
		};

	b32 is_within_quotes = false;
	b32 was_within_quotes = false;
	b32 is_within_arg = false;
	isize arg_start = 0;

	isize source_size = base_ztstring_size((u8 *)source);
	isize source_pos;
	for (source_pos = 0; source_pos < source_size; source_pos++)
	{
		char current_char = source[source_pos];

		if (current_char == '\"')
		{
			was_within_quotes = is_within_quotes;
			is_within_quotes = !is_within_quotes;
			continue;
		}
		else if (current_char == delim && !is_within_quotes)
		{
			if (is_within_arg)
			{
				is_within_arg = false;
				isize substring_size = source_pos - arg_start - was_within_quotes;
				result.substrings[result.substrings_count].size = substring_size;
				result.substrings[result.substrings_count].data = arena_push_copy_zero_terminate(arena, (void *)((uptr)source + arg_start), substring_size);
				// printf("> : %lld\n", result.substrings_count);
				// EVAL_PRINT_I64(substring_size);
				result.substrings_count += 1;
				was_within_quotes = false;
			}
		}
		else
		{
			if (!is_within_arg)
			{
				is_within_arg = true;
				arg_start = source_pos;
				// printf("<");
			}
			// printf("%c", current_char);
		}
	}

	if (is_within_arg)
	{
		is_within_arg = false;
		isize substring_size = source_pos - arg_start - was_within_quotes;
		result.substrings[result.substrings_count].size = substring_size;
		result.substrings[result.substrings_count].data = arena_push_copy_zero_terminate(arena, (void *)((uptr)source + arg_start), substring_size);
		// printf("> : %lld\n", result.substrings_count);
		// EVAL_PRINT_I64(substring_size);
		result.substrings_count += 1;
		was_within_quotes = false;
	}

	return result;
}

#endif // YOTE_USE_STRING