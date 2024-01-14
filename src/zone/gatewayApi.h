#define TunnelDataHeaderLen 1

#define GatewayLoginRequestId 0x01
#define GatewayLoginReplyId 0x02
#define GatewayTunnelToExternalConnectionId 0x05
#define GatewayTunnelFromExternalConnectionId 0x06
#define GatewayChannelIsRoutableId 0x07

#define GATEWAYKINDS                                                                                      \
    GATEWAYKIND(GatewayKindUnhandled, "Unhandled"),                                                       \
        GATEWAYKIND(GatewayKindLoginRequest, "LoginRequest"),                                             \
        GATEWAYKIND(GatewayKindLoginReply, "LoginReply"),                                                 \
        GATEWAYKIND(GatewayKindTunnelPacketToExternalConnection, "TunnelPacketToExternalConnection"),     \
        GATEWAYKIND(GatewayKindTunnelPacketFromExternalConnection, "TunnelPacketFromExternalConnection"), \
        GATEWAYKIND(GatewayKindChannelIsRoutable, "ChannelIsRoutable"),                                   \
        GATEWAYKIND(GatewayKindEnd, "")

typedef enum GatewayKindEnum
{
#define GATEWAYKIND(e, s) e
    GATEWAYKINDS
#undef GATEWAYKIND
} GatewayKindEnum;

char *gatewayKindNames[GatewayKindEnd + 1] = {
#define GATEWAYKIND(e, s) s
    GATEWAYKINDS
#undef GATEWAYKIND
};

typedef struct GatewayLoginRequest
{
    u64 characterId;
    u32 serverTicketLen;
    char *serverTicket;
    u32 clientProtocolLen;
    char *clientProtocol;
    u32 clientBuildLen;
    char *clientBuild;
} GatewayLoginRequest;

typedef struct GatewayLoginReply
{
    bool isLoggedIn;
} GatewayLoginReply;

typedef struct GatewayTunnelPacket
{
    u8 channel;
    u32 dataLen;
    u8 *data;
} GatewayTunnelPacket;

typedef struct GatewayChannelIsRoutable
{
    u8 channel;
    bool isRoutable;
    bool unkBool;
} GatewayChannelIsRoutable;