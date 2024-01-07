#define MaxSequence 0xffff
#define MaxUint8 0xff
#define DATA_HEADER_LENGTH 4

typedef struct Node
{
    int key;
    void *value;
    struct Node *next;
} Node;

typedef struct Map
{
    Node *head;
} Map;

inline void initMap(Map *map)
{
    map->head = NULL;
}

inline void addToMap(Map *map, int key, void *value)
{
    Node *newNode = malloc(sizeof(Node));
    if (!newNode)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->key = key;
    newNode->value = value;
    newNode->next = map->head;
    map->head = newNode;
}

inline void *getFromMap(Map *map, int key)
{
    Node *current = map->head;

    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

inline void deleteFromMap(Map *map, int key)
{
    Node *current = map->head;
    Node *prev = NULL;

    while (current != NULL && current->key != key)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        if (prev != NULL)
        {
            prev->next = current->next;
        }
        else
        {
            map->head = current->next;
        }
        free(current);
    }
    else
    {
        printf("Key %d not found in the map.\n", key);
    }
}

inline void cleanupMap(Map *map)
{
    Node *current = map->head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    map->head = NULL;
}

typedef struct AppData
{
    unsigned char *data;
    unsigned int dataLen;
    bool isFragment;
} AppData;

typedef struct SOEInputStream
{
    u16 _nextSequence;
    u16 _lastAck;
    AppData _appData;
    Map *_map;
    bool _useEncryption;
    i32 _lastProcessedSequence;
    Rc4_State rc4;
    bool hasCpf;
    i32 cpfTotalSize;
    i32 cpfDataSize;
    u8 *cpfDataWithoutHeader;
    i32 *cpfProcessFragmentSequences;
    i32 cpfProcessFragmentSequencesLength;
} SOEInputStream;

void inputStreamConstructor(unsigned char *cryptoKey)
{
    SOEInputStream *inputStream = malloc(sizeof(SOEInputStream));
    if (!inputStream)
    {
        fprintf(stderr, "Failed to allocate memory to inputStream struct in inputStreamConstructor function!\n");
        exit(EXIT_FAILURE);
    }

    inputStream->_lastProcessedSequence = -1;
    inputStream->_useEncryption = false;
    inputStream->cpfTotalSize = -1;
    inputStream->cpfDataSize = -1;

    crypt_rc4_transform(&inputStream->rc4, cryptoKey, inputStream->_appData.dataLen);
}
