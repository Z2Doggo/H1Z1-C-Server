typedef enum Session_Kind
{
	Session_Kind_Unhandled,
	Session_Kind_Ping_Responder,
} Session_Kind;

typedef enum Stances
{
	STANDING = 1089,
	MOVE_STANDING_SPRINTING = 66565,
	MOVE_STANDING_FORWARD = 66561,
	MOVE_STANDING_BACKWARDS = 33793,
	MOVE_STANDING_LEFT = 132097,
	MOVE_STANDING_RIGHT = 263169,

	CROUCHING = 1091,
	MOVE_CROUCHING_FORWARD = 66563,
	MOVE_CROUCHING_BACKWARDS = 33795,
	MOVE_CROUCHING_LEFT = 132099,
	MOVE_CROUCHING_RIGHT = 263171,

	PRONING = 5185,
	MOVE_PRONING_FORWARD = 70657,
	MOVE_PRONING_BACKWARDS = 37889,
	MOVE_PRONING_LEFT = 136193,
	MOVE_PRONING_RIGHT = 267265,

	JUMPING_STANDING = 1105,
	JUMPING_FORWARD_SPRINTING = 66581,
	JUMPING_WORWARD = 66577,
	JUMPING_BACKWARDS = 33809,
	JUMPING_LEFT = 132113,
	JUMPING_RIGHT = 263185,
	JUMPING_FORWARD_LEFT = 197649,
	JUMPING_FORWARD_LEFT_SPRINTING = 197653,
	JUMPING_FORWARD_RIGHT = 328721,
	JUMPING_FORWARD_RIGHT_SPRINTING = 328725,
	JUMPING_BACKWARDS_LEFT = 164881,
	JUMPING_BACKWARDS_RIGHT = 295953,

	SITTING = 525377,
	STANCE_XS = 525393,
	STANCE_XS_FP = 2622545,
	// haven't seen this stance anywhere else other than during XS glitching
} Stances;

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

typedef struct character_name_string character_name_string;
struct character_name_string 
{
	u32 length;
	char* content;
};

typedef struct resource_ids resource_ids;
struct resource_ids {
    int HEALTH_ID;
    int HUNGER_ID;
    int HYDRATION_ID;
    int STAMINA_ID;
    int VIRUS_ID;
    int BLEEDING_ID;
    int COMFORT_ID;
    int FUEL_ID;
    int CONDITION_ID;
};

typedef struct resource_types resource_types;
struct resource_types {
    u32 CONDITION;
    u32 HEALTH;
    u32 HUNGER;
    u32 HYDRATION;
    u32 STAMINA;
    u32 VIRUS;
    u32 BLEEDING;
    u32 COMFORT;
    u32 FUEL;
};

typedef struct Session_State Session_State;
struct Session_State
{
	Session_Address address;
	u32 id;
	
	character_name_string name_self;

	u64 			character_id;
	u64 			guid;
	u64				item_guid;
	uint2b 			transient_id;

	u32 			selected_server_id;
	u8 				finished_loading;
	u8 				first_login;
	u8 				gateway_channel;
	u8 				is_synced;

	Session_Kind kind;
	Connection_Args connection_args;

	i32 ack_next;
	i32 ack_previous;

	Fragment_Pool input_fragment_pool;
	// TODO(rhett): is the output fragment pool packet length supposed to match a data header?
	//              We could probably even replace this with just a flat buffer eventually,
	//							solving this little issue
	Fragment_Pool output_fragment_pool;

	Input_Stream input_stream;
	Output_Stream output_stream;
	
	// begin world_character struct
	u8 				character_released;
	u8				is_loading;
	u8              is_moving;
	u8              is_running;
	u8              is_jumping;
	u8              is_in_air;
	u8              is_walking;
	u8              is_hidden;
	u8              is_bleeding;
	u8              is_bandaged;
	u8              is_exhausted;
	u8              is_alive;
	u8              is_respawning;
	u8              is_spectator;
	u8              is_muted;
	u8              is_admin;
	u8              has_god_mode;
	u8              has_conveys;

	u64             creation_date;
	u64             last_login_date;

	i32 			stance;
	i32             position[3];
	f32             orientation;
	i32             direction;
	i32             front_tilt;
	i32             side_tilt;
	i32             angle_change;
	i32             vertical_speed;
	i32             horizontal_speed;
	i32             engine_rpm;
	// end world_character struct	
};