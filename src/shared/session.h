typedef enum Session_Kind
{
	Session_Kind_Unhandled,
	Session_Kind_Ping_Responder,
} Session_Kind;

typedef union Session_Address Session_Address;
union Session_Address
{
	u64 full;
	struct
	{
		u32 ip;
		u16 port;
	};
};

typedef struct Session_State Session_State;
struct Session_State
{
	Session_Address address;
	u32 id;

	// struct character
	// {
		String 			character_name;
		u64 			character_id;
		u32 			selected_server_id;
		u8 				finished_loading;
	// };

	Session_Kind 	kind;
	Connection_Args connection_args;

	i32 			ack_next;
	i32 			ack_previous;

	Fragment_Pool 	input_fragment_pool;
	Fragment_Pool 	output_fragment_pool;

	Input_Stream 	input_stream;
	Output_Stream 	output_stream;
};