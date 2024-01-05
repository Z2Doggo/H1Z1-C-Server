typedef struct Weapon {
    u64 itemGuid;
    u32 itemDefinitionId;
    u32 ammoCount;
    Timer* reloadTimer;
    u32 currentReloadCount;
} Weapon;
