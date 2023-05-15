#define CHARACTER_RESOURCES_COUNT 10
#define MAX_RESOURCES 10000 // or some other suitable value

u32 _resources[MAX_RESOURCES] = {0}; // initialize all values to zero

enum resource_id {
    HEALTH_ID = 1,
    HUNGER_ID = 4,
    HYDRATION_ID = 5,
    STAMINA_ID = 6,
    VIRUS_ID = 12,
    BLEEDING_ID = 21,
    COMFORT_ID = 68,
    FUEL_ID = 396,
    CONDITION_ID = 561
};

enum resource_type {
    CONDITION = 1,
    HEALTH = 1,
    HUNGER = 4,
    HYDRATION = 5,
    STAMINA = 6,
    VIRUS = 12,
    BLEEDING = 21,
    COMFORT = 68,
    FUEL = 50
};

typedef struct resource_data resource_data;
struct resource_data 
{
    u32 resource_type1;
    u32 resource_id;
    u32 resource_type2;
    u32 value;
};

resource_data* pGetResources() 
{
    resource_data* result = malloc(sizeof(resource_data) * CHARACTER_RESOURCES_COUNT);
    u32 resource_id = CONDITION_ID; // set initial resource ID
    for (u32 i = 0; i < CHARACTER_RESOURCES_COUNT; i++) 
    {
        u32 resourceType = CONDITION;

        switch (resource_id)
        {
            case HEALTH_ID:
                resourceType = HEALTH;
                break;
            case HUNGER_ID:
                resourceType = HUNGER;
                break;
            case HYDRATION_ID:
                resourceType = HYDRATION;
                break;
            case STAMINA_ID:
                resourceType = STAMINA;
                break;
            case VIRUS_ID:
                resourceType = VIRUS;
                break;
            case BLEEDING_ID:
                resourceType = BLEEDING;
                break;
            case COMFORT_ID:
                resourceType = COMFORT;
                break;
            case FUEL_ID:
                resourceType = FUEL;
                break;
            case CONDITION_ID:
                resourceType = CONDITION;
                break;
            default:
                break;
        }

        u32 value = _resources[resource_id] > 0 ? _resources[resource_id] : 0;

        result[i] = (resource_data) 
        {
            .resource_type1 = resourceType,
            .resource_id = resource_id,
            .resource_type2 = resourceType,
            .value = value,
        };
    }

    return result;
}
