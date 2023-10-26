typedef struct State
{
    vec4 position;
    vec4 rotation;
} State;

typedef struct BaseEntity
{
    u64 characterId;
    uint2b transientId;
    u32 actorModelId;
    State state;
    vec4 scale;
    u32 npcRenderDistance;
    u32 interactionDistance;
} BaseEntity;

unsigned int getRenderDistance(BaseEntity *entity)
{
    u32 range = 0;

    switch (entity->actorModelId)
    {
    case 9115: // tamper
        range = 1000;
        break;
    case 9492: // expansion
    case 9181: // shack door
    case 9180: // metal shack
    case 9192: // small shack
    case 55:   // dew collector
    case 9223: // wood shack
    case 63:   // wood shack door
        range = 500;
        break;
    case 9487: // ramp
        range = 450;
        break;
    case 9488: // foundation stairs
    case 49:   // metal gate
    case 50:   // metal wall
    case 9407: // upper metal wall
    case 51:   // shelter
    case 52:   // large shelter
    case 9408: // upper level shelter
    case 9411: // upper level large shelter
    case 53:   // structure stairs
    case 9493: // tower
    case 9130: // foundation, lod distance is 2250, tho i dont think we need it to be that high
        range = 750;
        break;
    }
    return range ? range : 0;
}

void createBaseEntity(
    u64 characterId,
    uint2b transientId,
    u32 actorModelId,
    vec4 position,
    vec4 rotation)
// ZoneServer2016 server
{
    BaseEntity *entity = (BaseEntity *)malloc(sizeof(BaseEntity));

    entity->characterId = characterId;
    entity->transientId.value = transientId.value;
    entity->actorModelId = actorModelId;

    memcpy(&entity->state.position, &position, sizeof(vec4));
    memcpy(&entity->state.rotation, &rotation, sizeof(vec4));
    // entity.npcRenderDistance = getRenderDistance(actorModelId) ? getRenderDistance(actorModelId) : server.charactersRenderDistance;
    // entity.interactionDistance = server.interactionDistance;
}

void Damage() {} // do nothing

void OnPlayerSelect() {} // do nothing

void OnInteractionString() {} // do nothing

void OnProjectileHit() {} // do nothing

b8 Destroy()
{
    BaseEntity *entity = (BaseEntity *)malloc(sizeof(BaseEntity));

    if (entity == NULL)
    {
        printf("Failed to allocate memory for entity. Cannot destroy.\n");
        return false;
    }
    printf("Destroying entity with actorModelId: %u\n", entity->actorModelId);

    return true;
}

typedef struct ZoneClient2016
{
    u64 guid;
    // TODO: FINISH THIS!
} ZoneClientJS2016;
