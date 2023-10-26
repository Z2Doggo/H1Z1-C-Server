typedef struct Weapon
{
    u64 itemGuid;
    u32 itemDefinitionId;
    u32 ammoCount;
    Timer *reloadTimer;
    u32 currentReloadCount;
} Weapon;

typedef struct BaseItem
{
    u32 itemDefinitionId;
    u32 slot;
    u64 itemGuid;
    char *containerGuid;
    u32 currentDurability;
    char *debugFlag;
    u32 stackCount;
    Weapon *weapon;
} BaseItem;

void baseItemConstructor(u32 itemDefinitionId,
                         u64 guid,
                         u32 durability,
                         u32 stackCount)
{
    BaseItem *baseItem = (BaseItem *)malloc(sizeof(BaseItem));

    baseItem->itemDefinitionId = itemDefinitionId;
    baseItem->itemGuid = guid;
    baseItem->currentDurability = durability;
    baseItem->stackCount = stackCount;

    if (stackCount < 0)
    {
<<<<<<< HEAD
        printf("Negative stackCount: %d, detected for item: %u, debugFlag: %s", stackCount, itemDefinitionId, baseItem->debugFlag);
=======
        printf("Negative stackCount: %u, detected for item: %u, debugFlag: %s", stackCount, itemDefinitionId, baseItem->debugFlag);
>>>>>>> 215f4353346507dd61aeefb9a988d9fe5b650f5f
        baseItem->stackCount = 0;
    }
    else
    {
        baseItem->stackCount = stackCount;
    }
}

b8 isValid(char *flag)
{
    BaseItem *baseItem = (BaseItem *)malloc(sizeof(BaseItem));

    if (flag)
    {
        baseItem->debugFlag = flag;
    }

    if (baseItem->stackCount <= 0)
    {
        printf("Item is invalid! itemDefId: %u, stackCount: %u, debugFlag: %s", baseItem->itemDefinitionId, baseItem->stackCount, baseItem->debugFlag);
        return false;
    }

    return true;
}

void weaponConstructor(BaseItem *baseItem, u32 ammoCount)
{
    Weapon *weapon = (Weapon *)malloc(sizeof(Weapon));

    Timer *reloadTimer = createTimer(5);
    weapon->reloadTimer = reloadTimer;
    startTimer(reloadTimer);
    Sleep(5000);
    stopTimer(reloadTimer);

    weapon->currentReloadCount = 0;
    weapon->itemGuid = baseItem->itemGuid;
    weapon->itemDefinitionId = baseItem->itemDefinitionId;
    weapon->ammoCount = ammoCount;

    baseItem->weapon = weapon;
}
