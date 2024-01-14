#define CorePacketIdLen 2

#define CoreSessionRequestId 0x01
#define CoreSessionReplyId 0x02
#define CoreMultiPacketId 0x03
#define CoreDisconnectId 0x05
#define CorePingId 0x06
#define CoreNetStatusRequestId 0x07
#define CoreNetStatusReplyId 0x08
#define CoreDataId 0x09
#define CoreDataFragmentId 0x0d
#define CoreOutOfOrderId 0x11
#define CoreAckId 0x15
#define CoreUnknown1cId 0x1c // TODO(rhett): Connection refused?
#define CoreFatalErrorId 0x1d
#define CoreFatalErrorReplyId 0x1e
#define CoreUnknown1fId 0x1f
#define CoreUnhandledId 0xffff

#define COREKINDS                                               \
    COREKIND(CoreKindUnhandled, "Unhandled"),                   \
        COREKIND(CoreKindSessionRequest, "SessionRequest"),     \
        COREKIND(CoreKindSessionReply, "SessionReply"),         \
        COREKIND(CoreKindMultiPacket, "MultiPacket"),           \
        COREKIND(CoreKindDisconnect, "Disconnect"),             \
        COREKIND(CoreKindPing, "Ping"),                         \
        COREKIND(CoreKindNetStatusRequest, "NetStatusRequest"), \
        COREKIND(CoreKindNetStatusReply, "NetStatusReply"),     \
        COREKIND(CoreKindData, "Data"),                         \
        COREKIND(CoreKindDataFragment, "DataFragment"),         \
        COREKIND(CoreKindOutOfOrder, "OutOfOrder"),             \
        COREKIND(CoreKindAck, "Ack"),                           \
        COREKIND(CoreKindUnknown1c, "UNKNOWN1C"),               \
        COREKIND(CoreKindFatalError, "FatalError"),             \
        COREKIND(CoreKindFatalErrorReply, "FatalErrorReply"),   \
        COREKIND(CoreKindUnknown1f, "UNKNOWN1F"),               \
        COREKIND(CoreKindEnd, "")

typedef enum CoreKindEnum
{
#define COREKIND(e, s) e
    COREKINDS
#undef COREKIND
} CoreKindEnum;

char *coreKindNames[CoreKindEnd + 1] =
    {
#define COREKIND(e, s) s
        COREKINDS
#undef COREKIND
};

typedef struct SessionRequest
{
    u32 crcLen;
    u32 sessionId;
    u32 udpLen;
    char protocolName[32];
} SessionRequest;

typedef struct SessionReply
{
    u32 sessionId;
    u32 crcSeed;
    u8 crcLen;
    u8 compression;
    u8 encryption;
    u32 udpLen;
    u32 soeProtocolVersion;
} SessionReply;

typedef struct Data
{
    u16 sequence;
    u8 *data;
    u32 dataLen;
    u16 crc;
} Data;

typedef struct Ack
{
    u16 sequence;
} Ack;