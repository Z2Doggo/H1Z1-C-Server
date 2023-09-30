typedef struct NpcData
{
    u64 guid;
    u64 characterId;
    uint2b transientId;
    u32 modelId;
    vec4 scale; // just do vec4 for now, cba with arrays
    void *resources;
    vec4 position;
    vec4 rotation;
    void *attachedObject;
    u32 vehicleId;
    u32 positionUpdateType;
    void *color;
    void *unkArray1[sizeof(u32)]; // default KB(10) for now, will see if this crashes anything
    u32 destroyedState;
    void *unkArray5[sizeof(u32)];
    void *unkArray17[sizeof(u32)];
    void *unkArray18[sizeof(u32)];
} NpcData;

typedef struct Seats
{
    b8 seat1;
    b8 seat2;
    b8 seat3;
    b8 seat4;
} Seats;

typedef struct Passengers
{
    void *passenger1;
    void *passenger2;
    void *passenger3;
    void *passenger4;
} Passengers;

typedef struct PositionUpdate
{
    // I will just typecast all of it
    u32 flags;
    u32 sequenceTime;
    u32 unkByte3;
    u32 stance;
    vec4 position;
    void *orientation;
    u32 frontTilt;
    u32 sideTilt;
    u32 angleChange;
    u32 vecticalSpeed;
    u32 horizontalSpeed;
    u32 unkFloat12;
    void *rotation;
    void *rotationRaw;
    vec4 lookAt;
    void *direction;
    void *engineRPM;
} positionUpdate;

typedef struct CharacterEquipment
{
    char *modelName;
    u32 modelNameLength;
    u64 guid;
    char *defaultTextureAlias;
    char *textureAlias;
    char *tintAlias;
    char *decalAlias;
} CharacterEquipment;

typedef struct UnkArray
{
    u32 unkDword1;
    u32 unkDword2;
    u32 unkDword3;
    u32 unkDword4;
    u32 unkDword5;
    u32 unkDword6;
    u32 unkDword7;
} UnkArray;

typedef struct Weather
{
    char *templateName;
    char *name;
    u32 unkDword1;
    u32 unkDword2;
    u32 unkDword3;
    u32 unkDword4;
    u32 fogDensity;
    u32 fogGradient;
    u32 fogFloor;
    u32 unkDword5;
    u32 rain;
    u32 temp;
    u32 skyColor;
    u32 cloudWeight0;
    u32 cloudWeight1;
    u32 cloudWeight2;
    u32 cloudWeight3;
    u32 sunAxisX;
    u32 sunAxisY;
    u32 sunAxisZ;
    u32 unkDword6;
    u32 unkDword7;
    u32 unkDword8;
    u32 wind;
    u32 unkDword9;
    u32 unkDword10;
    u32 unkDword11;
    u32 unkDword12;
    UnkArray unkArray[sizeof(u32)];
} Weather;

typedef struct SkyData
{
    char *templateName;
    u32 snow;
    u32 snowMap;
    u32 colorGradient;
    u32 sunAxisX;
    u32 sunAxisY;
    u32 wind;
} SkyData;

typedef struct HitReport
{
    u32 sessionPorjectileCount;
    u64 characterId;
    vec4 position;
    u32 unkFlag1;
    u64 hitLocation;
    u32 totalShotCount;
    u32 unkByte1;
} HitReport;

typedef struct DamageInfo
{
    u64 entity;
    Items weapon;
    u32 damage;
    b8 causeBleed;
    HitReport hitReport;
    char *message;
} DamageInfo;

typedef struct DamageRecord
{
    struct source_s
    {
        char *name;
        u32 ping;
    } *source;
    struct target_s
    {
        char *name;
        u32 ping;
    } *target;
    struct hitInfo_s
    {
        u32 timeStamp;
        Items weapon;
        u64 distance;
        u64 hitLocation;
        vec4 hitPosition;
        u32 holdHP;
        u32 newHP;
        char *message;
    } *hitInfo;
} DamageRecord;

typedef struct FireHint
{
    u32 id;
    vec4 position;
    u32 rotation;
    u32 hitNumber;
    // TODO: FINISH THIS STRUCT
} FireHint;

typedef struct ZoneServer2016
{
    void *any;
} ZoneServer2016;