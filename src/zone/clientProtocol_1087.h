typedef struct ThreadParams {
    AppState* app;
    SessionState* session;
    Arena* arena;
    u32 maxLen;
    Zone_Packet_Kind kind;
    void* packetPtr;
} ThreadParams;

typedef struct BaseItem {
    u32 itemDefId;
    u32 slotId;
    u64 itemGuid;
    u64 containerGuid;
    u32 containerDefId;
    u32 currentDurability;
    u8 debugFlag;
    u32 stackCount;
    Weapon* weapon;
    b8 hasAirdropCleareance;
} BaseItem;

typedef struct ItemDefinition {
    char* name;
    u32 id;
    char* codeFactoryName;
    u32 nameId;
    u32 descriptionId;
    u32 imageSetId;
    u32 activatableAbilityId;
    u32 passiveAbilityId;
    u32 cost;
    u32 itemClass;
    u32 maxStackSize;
    u32 minStackSize;
    u32 profileOverride;
    b8 noTrade;
    b8 singleUse;
    char* modelName;
    u32 genderUsage;
    char* textureAlias;
    u32 shaderParamGroupId;
    u32 categoryId;
    b8 memberOnly;
    b8 nonMiniGame;
    u32 param1;
    u32 param2;
    u32 param3;
    b8 noSale;
    u32 weaponTrailEffectId;
    u32 useRequirementId;
    u32 clientUseRequirementId;
    u32 compositeEffectId;
    u32 powerRating;
    u32 miniProfileRank;
    u32 rarity;
    u32 contentId;
    b8 noLiveGamer;
    b8 combatOnly;
    b8 forceDisablePreview;
    u32 memberDiscount;
    u32 raceSetId;
    u32 vipRankRequired;
    u32 persistProfileSwitch;
    b8 flagQuickUse;
    b8 flagCanEquip;
    b8 flagAccountScope;
    u32 uiModelCameraId;
    u32 equipCountMax;
    u32 currencyType;
    u32 datasheetId;
    u32 itemType;
    u32 skillSetId;
    char* overlayTexture;
    char* decalSlot;
    u32 overlayAdjustment;
    u32 trialDurationSec;
    u32 nextTrialDelaySec;
    u32 passiveAbilitySetId;
    u32 hudImageSetId;
    char* overrideAppearance;
    u32 overrideCameraId;
    char* playerStudioDisplayName;
    char* stringParam1;
    u32 bulk;
    u32 activeEquipSlotId;
    u32 passiveEquipSlotId;
    u32 useItemReticleId;
    u32 grinderRewardSetId;
    u32 buildBarGroupId;
    b8 flagNoDragDrop;
    u32 interactionAnimationId;
    b8 isArmor;
    u32 passiveEquiptSlotGroupId;
    u32 scrapValueOverride;

    // BaseItem struct ptr
    BaseItem* baseItem;
} ItemDefinition;

typedef struct ItemData {
    u32 itemDefinitionId;
    u32 tintId;
    u64 guid;
    u32 count;
    struct ItemSubData {
        b8 hasSubData;
    }* itemSubData;
    u64 containerGuid;
    u32 containerDefinitionId; // added by doggo
    u32 containerSlotId;
    u32 baseDurability;
    u32 currentDurability;
    u32 maxDurabilityFromDefinition;
    b8 unknownBoolean1;
    u64 ownerCharacterId;
    u32 unknownDword9;
    Weapon weaponData;

    // ItemDefinition struct ptr
    ItemDefinition* itemDef;
} ItemData;