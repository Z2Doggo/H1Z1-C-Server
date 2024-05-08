typedef struct FragmentEntry {
    u8* data;
    u32 dataLen;
    b32 isFragment;
} FragmentEntry;

typedef struct FragmentPool {
    u32 packetLen;

    i32 sequenceBase;
    FragmentEntry* entry;
    u32 fragmentCount;

    u8* buffer;
    u32 bufferTail;
    u32 bufferTargetLen;
} FragmentPool;

#define InputStreamCallbackAck(name) void name(void* session, i32 ack)
typedef InputStreamCallbackAck(inputStreamCallbackAck);

#define InputStreamCallbackData(name) void name(void* app, void* session, u8* data, u32 dataLen)
typedef InputStreamCallbackData(inputStreamCallbackData);

typedef struct SOEInputStream {
    Rc4_State rc4;
    FragmentPool* pool;

    inputStreamCallbackAck** ackCallbackPtr;
    inputStreamCallbackData** dataCallbackPtr;

    i32 nextSequence;
    i32 previousAck;
    i32 nextFragment;
    i32 previousProcessedFragment;
    b32 useEncryption;
} SOEInputStream;

#define OutputStreamCallbackData(name)                                                                 \
    void name(void* app, void* session, u8* data, u32 dataLen, i32 sequence, b32 isFragment)
typedef OutputStreamCallbackData(outputStreamCallbackData);

typedef struct SOEOutputStream {
    Rc4_State rc4;
    FragmentPool* pool;

    outputStreamCallbackData** dataCallbackPtr;

    i32 sequence;
    i32 previousAck;
    b32 useEncryption;
} SOEOutputStream;

typedef struct ConnectionArgs {
    u32 crcSeed;
    u8 crcLen;
    u8 compression;
    u32 udpLen;
    u8 encryption;
    b32 dumpCore;
    b32 dumpLogin;
    b32 dumpTunnel;
    b32 dumpGateway;
    b32 dumpZone;
} ConnectionArgs;