typedef struct FragmentEntry
{
    u8 *data;
    u32 dataLen;
    bool isFragment;
} FragmentEntry;

typedef struct FragmentPool
{
    i32 capacity;
    u32 packetLen;

    i32 sequenceBase;
    FragmentEntry *entry;
    u32 fragmentCount;

    u8 *buffer;
    u32 bufferTail;
    u32 bufferTargetLen;
} FragmentPool;

#define InputStreamCallbackAck(name) void name(SessionState *session, i32 ack)
typedef InputStreamCallbackAck(inputStreamCallbackAck);

#define InputStreamCallbackData(name) void name(AppState *app, SessionState *session, u8 *data, u32 dataLen)
typedef InputStreamCallbackData(inputStreamCallbackData);

typedef struct SOEInputStream
{
    Rc4_State rc4;
    FragmentPool *pool;

    inputStreamCallbackAck **ackCallbackPtr;
    inputStreamCallbackData **dataCallbackPtr;

    i32 nextSequence;
    i32 previousAck;
    i32 nextFragment;
    i32 previousProcessedFragment;
    bool useEncryption;
} SOEInputStream;

#define OutputStreamCallbackData(name) void name(AppState *app, SessionState *session, u8 *data, u32 dataLen, i32 sequence, bool isFragment)
typedef OutputStreamCallbackData(outputStreamCallbackData);

typedef struct SOEOutputStream
{
    Rc4_State rc4;
    FragmentPool *pool;

    outputStreamCallbackData **dataCallbackPtr;

    i32 sequence;
    i32 previousAck;
    bool useEncryption;
} SOEOutputStream;

typedef struct ConnectionArgs
{
    u32 crcSeed;
    u8 crcLen;
    u8 compression;
    u32 udpLen;
    u8 encryption;
    bool dumpCore;
    bool dumpLogin;
    bool dumpTunnel;
    bool dumpGateway;
    bool dumpZone;
} ConnectionArgs;