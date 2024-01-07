#define MaxSequence 0xffff
#define MaxUint8 0xff
#define DATA_HEADER_LENGTH 4

typedef struct Node
{
    i32 key;
    void *value;
    struct Node *next;
} Node;

typedef struct Map
{
    Node *head;
} Map;

typedef struct AppData
{
    u8 *data;
    u32 dataLen;
    bool isFragment;
    u8 *buffer;
    u32 bufferTail;
    u32 bufferLen;
} AppData;

typedef struct SOEInputStream
{
    u16 _nextSequence;
    u16 _lastAck;
    AppData *_appData;
    Map _map;
    bool _useEncryption;
    i32 _sequenceBase;
    i32 _capacity;
    u32 _packetLen;
    i32 _lastProcessedSequence;
    Rc4_State rc4;
    u32 fragmentCount;
    bool hasCpf;
    i32 cpfTotalSize;
    i32 cpfDataSize;
    u8 *cpfDataWithoutHeader;
    i32 *cpfProcessFragmentSequences;
    i32 cpfProcessFragmentSequencesLength;
} SOEInputStream;
