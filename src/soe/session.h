typedef enum SessionKind
{
    SessionKindUnhandled,
    SessionKindPingResponder,
} SessionKind;

typedef union SessionAddress
{
    u64 full;
    struct
    {
        u32 ip;
        u16 port;
    };
} SessionAddress;

/*
typedef struct oldPosition
{
    vec4 position;
    u32 time;
} oldPosition;

typedef struct pvpStatsStruct
{
    u32 shotsFired;
    u32 shotsHit;
    u32 head;
    u32 spine;
    u32 hands;
    u32 legs;
} pvpStatsStruct;

typedef struct clientLogging
{
    u32 logLen;
    char *logString;
    bool isSuspicious;
} clientLogging;

typedef struct lastDeatherReportStruct
{
    vec4 position;
    vec4 enemyPosition;
    u32 distance;
    // zoneClient* client;
} lastDeatherReportStruct;

typedef struct dtosSpawned
{
    void *spawnedDTOs; // hacky way of making an 'any' variable!;
} dtosSpawned;

typedef struct characterState
{
    vec4 position;
    vec4 rotation;
} characterState;

typedef struct BaseEntity
{
    u64 characterId;
    u32 transientIdValue;
    u32 actorModelId;
    characterState *state;
    vec4 scale; // default value is { 1, 1, 1, 1 };
    u32 npcRenderDistance;
    u32 interactionDistance;
} BaseEntity;

typedef struct DamageInfo
{
    u32 entity_len;
    char *entity;
    u32 damage;
    bool causeBleed;
    u32 message_len;
    char *message;
} DamageInfo;

typedef struct zoneClient
{
    u64 guid;
    u32 currentPOI;
    bool firstLoading;      // FALSE
    bool isLoading;         // TRUE
    bool characterReleased; // FALSE
    bool isSynced;          // FALSE
    bool isInteracting;     // FALSE
    bool isAdmin;           // FALSE
    bool isDebugMode;       // FALSE
    bool isDecoy;           // FALSE
    u64 banType;
    u64 HWID;
    vec4 posAtLastRoutine; // not sure if needed
    vec4 posAtTimerStart;  // also not sure if needed either?
    oldPosition *oldPos;
    bool enableChecks; // TRUE
    u32 speedWarnsNumber;
    pvpStatsStruct *pvpStats;
    clientLogging *clientLogs;
    u32 reports;
    lastDeatherReportStruct *lastDeathReport;
    // hud timer is null?
    dtosSpawned *spawnedDTOs;
    BaseEntity *spawnedEntities;
    BaseEntity *sentInteractionData;
    bool radio; // FALSE
    u64 loginSessionId;
    // don't need pingTimer from the typescript server!
    u32 sessionId;
    u64 soeClientId;
    u32 lastKeepAliveTime; // default value is 0;
    u32 pings;
    u32 averagePing;
    u32 averagePingLen; // default value is 4;
    u32 pingWarnings;
    bool isWeaponLock;     // FALSE
    bool averagePingReady; // FALSE
    // do I need to add chunkRenderDistance from the typescript server? probably not, but will keep this comment just in case I change my mind;
    u32 routineCounter;
    u32 zonePings;
    bool properlyLoggedOut; // FALSE
    u32 permisssionLvl;   // default is 0
    // wtf is fireHints on the typescript server?
    bool isInAir;        // FALSE
    u32 startLocation; // 0 is default;
    vec4 startingPosition;
    bool firstReleased;           // TRUE
    bool isMuted;                 // FALSE
    u32 blockedPositionUpdates; // 0
    u32 flaggedShots;           // 0
    bool isFairPlayFlagged;       // FALSE, keep in my that I will most likely do a proper version of server side anticheat than convert h1emu's fairplay method?
    DamageInfo *damageInfo;
    // string array
    char **managedObjects;
    i32 managedObjectsCount;
    // end of string array

    bool initialized; // dunno what value the bool is supposed to be?
} zoneClient;
*/

typedef struct CharacterName
{
    char *name;
    u32 nameLen;
} CharacterName;

typedef struct pGetPlayerActorData pGetPlayerActorData;
struct pGetPlayerActorData
{
    u32 headType;
    u32 actorModelId;
    u32 hairModelLen;
    char *hairModel;
    u32 headActorLen;
    char *headActor;
    u32 gender;
};

typedef struct CharacterCreateReply CharacterCreateReply;
struct CharacterCreateReply
{
    u32 status;
    u64 characterId;
    u32 count;
};

struct SessionState
{
    SessionAddress address;
    u32 id;

    // login related structs
    CharacterCreateReply createReply;

    // zoneClient client;
    pGetPlayerActorData pGetPlayerActor;

    // gateway channel stuff & testing related
    u8 gatewayChannel;
    CharacterName characterName;

    u64 characterId;
    u64 guid;
    u64 itemGuid;
    u32 transientId;
    u32 transientIdLen;

    u32 selected_server_id;
    bool finished_loading;
    bool first_login;
    bool is_synced;

    SessionKind kind;
    ConnectionArgs args;

    i32 nextAck;
    i32 previousAck;

    // New SOE protocol related structs, WiP
    FragmentPool inputPool;
    FragmentPool outputPool;

    SOEInputStream inputStream;
    SOEOutputStream outputStream;

    // begin world_character struct
    bool characterReleased;
    bool isLoading;
    bool isMoving;
    bool isRunning;
    bool isJumping;
    bool isInAir;
    bool isWalking;
    bool isHidden;
    bool isBleeding;
    bool isBandaged;
    bool isExhausted;
    bool isAlive;
    bool isRespawning;
    bool isSpectator;
    bool isMuted;
    bool isAdmin;
    bool isReady;
    bool hasGodMode;
    bool hasConveys;

    u64 creationDate;
    u64 lastLoginDate;

    i32 stance;
    vec4 position;
    vec3 positionLightWeight; // for lightweight packets
    vec4 unkVec4;
    vec4 rotation;
    euler_angle rotationRaw;
    vec4 lookAt;
    f32 orientation;
    i32 direction;
    i32 frontTilt;
    i32 sideTilt;
    i32 angleChange;
    i32 verticalSpeed;
    i32 horizontalSpeed;
    i32 engineRpm;
    i32 sequenceTime;
    u8 unkByte;
    // end world_character struct
};