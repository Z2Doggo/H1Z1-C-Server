#define CORE_PACKET_ID_LENGTH 2


#define CORE_SESSION_REQUEST_ID    0x01
#define CORE_SESSION_REPLY_ID      0x02
#define CORE_MULTI_PACKET_ID       0x03
#define CORE_DISCONNECT_ID         0x05
#define CORE_PING_ID               0x06
#define CORE_NET_STATUS_REQUEST_ID 0x07
#define CORE_NET_STATUS_REPLY_ID   0x08
#define CORE_DATA_ID               0x09
#define CORE_DATA_FRAGMENT_ID      0x0d
#define CORE_OUT_OF_ORDER_ID       0x11
#define CORE_ACK_ID                0x15
#define CORE_UNKNOWN_1C_ID         0x1c // TODO(rhett): Connection refused?
#define CORE_FATAL_ERROR_ID        0x1d
#define CORE_FATAL_ERROR_REPLY_ID  0x1e
#define CORE_UNKNOWN_1F_ID         0x1f
#define CORE_UNHANDLED_ID          0xffff

#define CORE_PACKET_KINDS \
	CORE_PACKET_KIND(Core_Packet_Kind_Unhandled, "Unhandled"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Session_Request, "SessionRequest"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Session_Reply, "SessionReply"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Multi_Packet, "MultiPacket"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Disconnect, "Disconnect"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Ping, "Ping"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Net_Status_Request, "NetStatusRequest"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Net_Status_Reply, "NetStatusReply"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Data, "Data"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Data_Fragment, "DataFragment"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Out_Of_Order, "OutOfOrder"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Ack, "Ack"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Unknown_1c, "UNKNOWN_1C"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Fatal_Error, "FatalError"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Fatal_Error_Reply, "FatalErrorReply"), \
	CORE_PACKET_KIND(Core_Packet_Kind_Unknown_1f, "UNKNOWN_1F"), \
	CORE_PACKET_KIND(Core_Packet_Kind__End, "")

typedef enum Core_Packet_Kind
{
#define CORE_PACKET_KIND(e, s) e
CORE_PACKET_KINDS
#undef CORE_PACKET_KIND
} Core_Packet_Kind;

char* core_packet_names[Core_Packet_Kind__End + 1] =
{
#define CORE_PACKET_KIND(e, s) s
CORE_PACKET_KINDS
#undef CORE_PACKET_KIND
};


typedef struct Session_Request
{
	u32  crc_length;
	u32  session_id;
	u32  udp_length;
	char protocol_name[32]; // TODO(rhett): take another look at this later
} Session_Request;

typedef struct Session_Reply
{
	u32  session_id;
	u32  crc_seed;
	u8     crc_length;
    u8     compression;
    u8     encryption;
	u32  udp_length;
	u32  soe_protocol_version;

} Session_Reply;

// TODO(rhett): Using Data struct for Data and Data Fragments
typedef struct Data
{
	u16 sequence;
	// TODO(rhett): Assuming short crc
	u8*   data;
	u32   data_length;
	u16 crc;
} Data;

typedef struct Ack
{
	u16 sequence;
} Ack;