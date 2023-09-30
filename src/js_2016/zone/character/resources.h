typedef enum ResourceIds
{
    HEALTH = 1,
    HUNGER = 4,
    HYDRATION = 5,
    STAMINA = 6,
    VIRUS = 12,
    BLEEDING = 21,
    COMFORT = 68,
    FUEL = 396,
    CONDITION = 561,
    CONSTRUCTION_CONDITION = 567
} ResourceIds;

typedef enum ResourceTypes
{
    RESOURCE_HEALTH = 1,
    RESOURCE_HUNGER = 4,
    RESOURCE_HYDRATION = 5,
    RESOURCE_STAMINA = 6,
    RESOURCE_VIRUS = 12,
    RESOURCE_BLEEDING = 21,
    RESOURCE_COMFORT = 68,
    RESOURCE_FUEL = 50,
    RESOURCE_CONDITION = 1,
} ResourceTypes;

u32 getResourceType(ResourceIds resourceId)
{
    switch (resourceId)
    {
    case HEALTH:
        return RESOURCE_HEALTH;
    case HUNGER:
        return RESOURCE_HUNGER;
    case HYDRATION:
        return RESOURCE_HYDRATION;
    case STAMINA:
        return RESOURCE_STAMINA;
    case VIRUS:
        return RESOURCE_VIRUS;
    case BLEEDING:
        return RESOURCE_BLEEDING;
    case COMFORT:
        return RESOURCE_COMFORT;
    case FUEL:
        return RESOURCE_FUEL;
    case CONDITION:
        return RESOURCE_CONDITION;
    default:
        return 0;
    };
};