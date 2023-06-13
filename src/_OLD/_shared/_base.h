#if defined(INTERNAL)
	#define internal     extern
#else
	#define internal     static
#endif
#define local_persist  static
#define global         static
#define dll_external   extern __declspec(dllexport)

//// Macros
#define KB(n)  (n << 10)
#define MB(n)  (n << 20)
#define GB(n)  ((u64)n << 30)
#define TB(n)  ((u64)n << 40)

#define MIN(a,b)  (a < b ? a : b)
#define MAX(a,b)  (a > b ? a : b)

#define UNUSED(x)  (void)x

#define EVAL_PRINT_U8(x)    printf("%s = %u:%x\n",#x,(u8)x,(u8)x)
#define EVAL_PRINT_I8(x)    printf("%s = %d:%x\n",#x,(i8)x,(i8)x)
#define EVAL_PRINT_U16(x)   printf("%s = %u:%x\n",#x,(u16)x,(u16)x)
#define EVAL_PRINT_I16(x)   printf("%s = %d:%x\n",#x,(i16)x,(i16)x)
#define EVAL_PRINT_U32(x)   printf("%s = %u:%x\n",#x,(u32)x,(u32)x)
#define EVAL_PRINT_I32(x)   printf("%s = %d:%x\n",#x,(i32)x,(i32)x)
#define EVAL_PRINT_U64(x)   printf("%s = %llu:%llx\n",#x,(u64)x,(u64)x)
#define EVAL_PRINT_I64(x)   printf("%s = %lld:%llx\n",#x,(i64)x,(i64)x)
#define EVAL_PRINT_F32(x)   printf("%s = %f:%x\n",#x,(f32)x,*(u32*)&x)
#define EVAL_PRINT_CSTR(x)  printf("%s = \"%s\"\n",#x,x)

#define IS_POWER_OF_TWO(x)     ((x & (x - 1)) == 0)
#define ARRAY_COUNT(a)         (sizeof(a) / sizeof(a[0]))
#define STRINGIFY_INTERNAL(x)  #x
#define STRINGIFY(x)           STRINGIFY_INTERNAL(x)

#if !defined(TRUE)
	#define TRUE  (0 == 0)
#endif
#if !defined(FALSE)
	#define FALSE  (0 != 0)
#endif

//// Types
typedef    int8_t  i8;
typedef   int16_t  i16;
typedef   int32_t  i32;
typedef   int64_t  i64;
typedef  intptr_t  iptr;
typedef ptrdiff_t  i64;

typedef   uint8_t  u8;
typedef  uint16_t  u16;
typedef  uint32_t  u32;
typedef  uint64_t  u64;
typedef uintptr_t  u64;
typedef    size_t  usize;

typedef wchar_t  wchar;

typedef  i8  b8;
typedef i16  b16;
typedef i32  b32;
typedef i64  b64;

typedef    u16  f16;
typedef  float  f32;
typedef double  f64;


