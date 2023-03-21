typedef struct Platform_State Platform_State;
typedef struct Platform_Socket Platform_Socket;


#define PLATFORM_FOLDER_CREATE(name) b32 name(char* folder_path)
typedef PLATFORM_FOLDER_CREATE(platform_folder_create);

#define PLATFORM_BUFFER_WRITE_TO_FILE(name) u32 name(char* file_path, void* buffer, u32 buffer_length)
typedef PLATFORM_BUFFER_WRITE_TO_FILE(platform_buffer_write_to_file);

#define PLATFORM_BUFFER_LOAD_FROM_FILE(name) u32 name(char* file_path, void* buffer, u32 buffer_length)
typedef PLATFORM_BUFFER_LOAD_FROM_FILE(platform_buffer_load_from_file);

#define PLATFORM_SOCKET_UDP_CREATE_AND_BIND(name) Platform_Socket name(Platform_State* state, u16 port)
typedef PLATFORM_SOCKET_UDP_CREATE_AND_BIND(platform_socket_udp_create_and_bind);

#define PLATFORM_RECEIVE_FROM(name) i32 name(Platform_Socket sock, void* buffer, i32 length, u32* from_ip, u16* from_port)
typedef PLATFORM_RECEIVE_FROM(platform_receive_from);

#define PLATFORM_SEND_TO(name) i32 name(Platform_Socket sock, void* buffer, i32 length, u32 to_ip, u16 to_port)
typedef PLATFORM_SEND_TO(platform_send_to);

#define PLATFORM_WALL_CLOCK(name) u64 name(void)
typedef PLATFORM_WALL_CLOCK(platform_wall_clock);

#define PLATFORM_ELAPSED_SECONDS(name) f32 name(Platform_State* state, u64 begin, u64 end)
typedef PLATFORM_ELAPSED_SECONDS(platform_elapsed_seconds);


typedef struct Platform_Api Platform_Api;
struct Platform_Api
{
	platform_folder_create* 						 folder_create;
	platform_buffer_write_to_file*       buffer_write_to_file;
	platform_buffer_load_from_file* 		 buffer_load_from_file;
	platform_socket_udp_create_and_bind* socket_udp_create_and_bind;
	platform_receive_from*  						 receive_from;
	platform_send_to*										 send_to;
	platform_wall_clock*								 wall_clock;
	platform_elapsed_seconds*						 elapsed_seconds;
};