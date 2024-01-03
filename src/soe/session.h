typedef enum Session_Kind
{
    Session_Kind_Unhandled,
    Session_Kind_Ping_Responder,
} Session_Kind;

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
    u32 logLength;
    char *logString;
    b8 isSuspicious;
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
    b8 causeBleed;
    u32 message_len;
    char *message;
} DamageInfo;

typedef struct zoneClient
{
    u64 guid;
    u32 currentPOI;
    b8 firstLoading;      // FALSE
    b8 isLoading;         // TRUE
    b8 characterReleased; // FALSE
    b8 isSynced;          // FALSE
    b8 isInteracting;     // FALSE
    b8 isAdmin;           // FALSE
    b8 isDebugMode;       // FALSE
    b8 isDecoy;           // FALSE
    u64 banType;
    u64 HWID;
    vec4 posAtLastRoutine; // not sure if needed
    vec4 posAtTimerStart;  // also not sure if needed either?
    oldPosition *oldPos;
    b8 enableChecks; // TRUE
    u32 speedWarnsNumber;
    pvpStatsStruct *pvpStats;
    clientLogging *clientLogs;
    u32 reports;
    lastDeatherReportStruct *lastDeathReport;
    // hud timer is null?
    dtosSpawned *spawnedDTOs;
    BaseEntity *spawnedEntities;
    BaseEntity *sentInteractionData;
    b8 radio; // FALSE
    u64 loginSessionId;
    // don't need pingTimer from the typescript server!
    u32 sessionId;
    u64 soeClientId;
    u32 lastKeepAliveTime; // default value is 0;
    u32 pings;
    u32 averagePing;
    u32 averagePingLength; // default value is 4;
    u32 pingWarnings;
    b8 isWeaponLock;     // FALSE
    b8 averagePingReady; // FALSE
    // do I need to add chunkRenderDistance from the typescript server? probably not, but will keep this comment just in case I change my mind;
    u32 routineCounter;
    u32 zonePings;
    b8 properlyLoggedOut; // FALSE
    u32 permisssionLvl;   // default is 0
    // wtf is fireHints on the typescript server?
    b8 isInAir;        // FALSE
    u32 startLocation; // 0 is default;
    vec4 startingPosition;
    b8 firstReleased;           // TRUE
    b8 isMuted;                 // FALSE
    u32 blockedPositionUpdates; // 0
    u32 flaggedShots;           // 0
    b8 isFairPlayFlagged;       // FALSE, keep in my that I will most likely do a proper version of server side anticheat than convert h1emu's fairplay method?
    DamageInfo *damageInfo;
    // string array
    char **managedObjects;
    i32 managedObjectsCount;
    // end of string array

    b8 initialized; // dunno what value the bool is supposed to be?
} zoneClient;
*/

typedef struct characterName characterName;
struct characterName
{
    char *nameContent;
    u32 nameLength;
};

typedef struct pGetPlayerActorData pGetPlayerActorData;
struct pGetPlayerActorData
{
    u32 headType;
    u32 actorModelId;
    u32 hairModelLength;
    char *hairModel;
    u32 headActorLength;
    char *headActor;
    u32 gender;
};

typedef struct CharacterCreateReply CharacterCreateReply;
struct CharacterCreateReply
{
    u32 status;
    u64 character_id;
    u32 count;
};

typedef struct Session_State Session_State;
struct Session_State
{
    Session_Address address;
    u32 id;

    // login related structs
    CharacterCreateReply createReply;

    // zoneClient client;
    pGetPlayerActorData pGetPlayerActor;

    // gateway channel stuff & testing related
    struct Gateway_Packet_TunnelPacket *tunnelPacket;
    u8 gateway_channel;
    characterName name;

    u64 character_id;
    u64 guid;
    u64 item_guid;
    uint2b transient_id;

    u32 selected_server_id;
    b8 finished_loading;
    b8 first_login;
    b8 is_synced;

    Session_Kind kind;
    Connection_Args connection_args;

    i32 ack_next;
    i32 ack_previous;
    const char *authKey;

    Fragment_Pool input_fragment_pool;
    // TODO(rhett): is the output fragment pool packet length supposed to match a data header?
    //              We could probably even replace this with just a flat buffer eventually,
    //							solving this little issue
    Fragment_Pool output_fragment_pool;

    Input_Stream input_stream;
    Output_Stream output_stream;

    // begin world_character struct
    b8 character_released;
    b8 is_loading;
    b8 is_moving;
    b8 is_running;
    b8 is_jumping;
    b8 is_in_air;
    b8 is_walking;
    b8 is_hidden;
    b8 is_bleeding;
    b8 is_bandaged;
    b8 is_exhausted;
    b8 is_alive;
    b8 is_respawning;
    b8 is_spectator;
    b8 is_muted;
    b8 is_admin;
    b8 is_ready;
    b8 has_god_mode;
    b8 has_conveys;

    u64 creation_date;
    u64 last_login_date;

    i32 stance;
    vec4 position;
    vec3 positionLW; // for lightweight packets
    vec4 unknown12_f32;
    vec4 rotation;
    euler_angle rotationRaw;
    vec4 lookAt;
    f32 orientation;
    i32 direction;
    i32 front_tilt;
    i32 side_tilt;
    i32 angle_change;
    i32 vertical_speed;
    i32 horizontal_speed;
    i32 engine_rpm;
    i32 sequence_time;
    u8 unk_byte;
    // end world_character struct
};