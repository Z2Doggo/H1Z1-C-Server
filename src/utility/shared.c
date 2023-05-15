#define MAX_RESOURCES 10000 // or some other suitable value

u32 _resources[MAX_RESOURCES] = {10000}; // initialize all values to 10000

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

u32 getResourceType(u32 resource_id) {
    switch (resource_id) {
      case HEALTH_ID:
        return HEALTH;
      case HUNGER_ID:
        return HUNGER;
      case HYDRATION_ID:
        return HYDRATION;
      case STAMINA_ID:
        return STAMINA;
      case VIRUS_ID:
        return VIRUS;
      case BLEEDING_ID:
        return BLEEDING;
      case COMFORT_ID:
        return COMFORT;
      case FUEL_ID:
        return FUEL;
      case CONDITION_ID:
        return CONDITION;
      default:
        return 0;
    }
}

resource_data* pGetResources(u32 num_resources) 
{
    resource_data* result = malloc(sizeof(resource_data) * num_resources);
    u32 resource_id = HEALTH_ID;
    u32 resourceType = getResourceType(resource_id);
    u32* pValue = _resources;
    u32 value = pValue[resource_id] > 0 ? pValue[resource_id] : 0;
    for (u32 i = 0; i < num_resources; i++) 
    {
        result[i] = (resource_data) 
        {
            .resource_type1 = resourceType,
            .resource_id = resource_id,
            .resource_type2 = resourceType,
            .value = value,
        };
        
        resource_id++;
    }

    return result;
}
