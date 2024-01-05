void readPositionUpdateData(App_State* app,
    Session_State* session,
    u8* data,
    u32 offset)
{
    Zone_Packet_PlayerUpdatePosition obj = { 0 }; // init
    u32 start_offset = offset; // offset is u32 for 2bit values, other than that, will need to typecast to a (u8 *) - doggo

    obj.flag = endian_read_u16_little(data + offset);
    offset += 2;

    obj.sequence = endian_read_u32_little(data + offset);
    offset += 4;

    obj.ubyte = endian_read_u8_little(data + offset);
    offset += 1;

    int2b v; // signed, also maybe init this aswell?
    euler_angle euler; // needed for the last part of this packet

    if (obj.flag & 1) {
        v = endian_read_int2b_little(data, offset);
        session->stance = v.value;
        offset += v.length;
    }

    if (obj.flag & 2) {
        v = endian_read_int2b_little(data, offset);
        session->position.x = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->position.y = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->position.z = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x20) {
        session->orientation = endian_read_f32_little(data + offset);
        offset += 4;
    }

    if (obj.flag & 0x40) {
        v = endian_read_int2b_little(data, offset);
        session->front_tilt = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x80) {
        v = endian_read_int2b_little(data, offset);
        session->side_tilt = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 4) {
        v = endian_read_int2b_little(data, offset);
        session->angle_change = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x8) {
        v = endian_read_int2b_little(data, offset);
        session->vertical_speed = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x10) {
        v = endian_read_int2b_little(data, offset);
        session->horizontal_speed = v.value / 10;
        offset += v.length;
    }

    if (obj.flag & 0x100) {
        session->unknown12_f32;
        v = endian_read_int2b_little(data, offset);
        session->unknown12_f32.x = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->unknown12_f32.y = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->unknown12_f32.z = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x200) {
        v = endian_read_int2b_little(data, offset);
        euler.qx = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        euler.qy = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        euler.qz = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        euler.qw = v.value / 100;
        session->rotation = eul2quat(&euler);
        session->rotationRaw = euler;
        session->lookAt = eul2quat(&euler); // praying to the machine gods this works
        offset += v.length;
    }

    if (obj.flag & 0x400) {
        v = endian_read_int2b_little(data, offset);
        session->direction = v.value / 10;
        offset += v.length;
    }

    if (obj.flag & 0x800) {
        v = endian_read_int2b_little(data, offset);
        session->engine_rpm = v.value / 10;
        offset += v.length;
    }

    zone_packet_send(app,
        session,
        &app->arena_per_tick,
        KB(10),
        Zone_Packet_Kind_PlayerUpdatePosition,
        &obj);
}

typedef struct BaseItem {
    u32 itemDefId;
    u32 slotId;
    u64 itemGuid;
    u64 containerGuid;
    u32 currentDurability;
    u8 debugFlag;
    u32 stackCount;
    Weapon* weapon;
    bool hasAirdropCleareance;
} BaseItem;

BaseItem* BaseItemConstructor(u32 itemDefId, u64 guid, u32 durability, u32 stackCount)
{
    BaseItem* baseItem = malloc(sizeof(BaseItem));
    if (!baseItem) {
        fprintf_s(stderr, "Failed to allocate memory to BaseItem struct in BaseItemConstructor function!\n");

        return NULL;
    }

    baseItem->slotId = 0;
    baseItem->containerGuid = 0x0ull;
    baseItem->hasAirdropCleareance = false;

    baseItem->itemDefId = itemDefId;
    baseItem->itemGuid = guid;
    baseItem->currentDurability = durability;

    if (stackCount < 0) {
        fprintf_s(stderr, "Negative stackCount: (%u); detected for itemId: (%u)!\n", stackCount, itemDefId);
        baseItem->stackCount = 0;

        free(baseItem);

        return NULL;
    } else {
        baseItem->stackCount = stackCount;
    }

    return baseItem;
}

bool IsValid(u8 flag)
{
    BaseItem* baseItem = NULL;

    if (flag) {
        baseItem = malloc(sizeof(BaseItem));
        if (!baseItem) {
            fprintf_s(stderr, "Failed to allocate memory to BaseItem struct in IsValid function!\n");

            return false;
        }

        baseItem->debugFlag = flag;
    }

    if (baseItem->stackCount <= 0) {
        fprintf_s(stderr, "Item is invalid; itemDefId: (%u), stackCount: (%u), debugFlag: (%u)\n", baseItem->itemDefId, baseItem->stackCount, baseItem->debugFlag);
        free(baseItem);

        return false;
    }

    free(baseItem);

    return true;
}

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
    bool noTrade;
    bool singleUse;
    char* modelName;
    u32 genderUsage;
    char* textureAlias;
    u32 shaderParamGroupId;
    u32 categoryId;
    bool memberOnly;
    bool nonMiniGame;
    u32 param1;
    u32 param2;
    u32 param3;
    bool noSale;
    u32 weaponTrailEffectId;
    u32 useRequirementId;
    u32 clientUseRequirementId;
    u32 compositeEffectId;
    u32 powerRating;
    u32 miniProfileRank;
    u32 rarity;
    u32 contentId;
    bool noLiveGamer;
    bool combatOnly;
    bool forceDisablePreview;
    u32 memberDiscount;
    u32 raceSetId;
    u32 vipRankRequired;
    u32 persistProfileSwitch;
    bool flagQuickUse;
    bool flagCanEquip;
    bool flagAccountScope;
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
    bool flagNoDragDrop;
    u32 interactionAnimationId;
    bool isArmor;
    u32 passiveEquiptSlotGroupId;
    u32 scrapValueOverride;

    // server-side only - added by h1emu
    u32 worldModelId;
    u32 pickupEffect;
    u32 placementModelId;
} ItemDefinition;

ItemDefinition* GetItemDefinition(u32 itemDefId)
{
    if (!itemDefId) {
        fprintf_s(stderr, "ItemDefinitionId is invalid! Please check errors!\n");

        return NULL;
    }

    ItemDefinition* itemDef = malloc(sizeof(ItemDefinition));
    if (!itemDef) {
        fprintf_s(stderr, "Failed to allocate memory to ItemDefinition struct in GetItemDefinition function!\n");

        return NULL;
    }

    ItemDefinition* result = &itemDef[itemDefId];

    free(itemDef);

    return result;
}

bool IsWeapon(u32 itemDefId)
{
    if (itemDefId != 0) {
        ItemDefinition* itemDef = malloc(sizeof(ItemDefinition));
        if (itemDef != NULL) {
            u32 itemType = itemDef[itemDefId].itemType;
            free(itemDef);

            return itemType == 20;
        }
    }

    return false;
}

bool IsArmor(u32 itemDefId)
{
    if (itemDefId != 0) {
        ItemDefinition* itemDef = malloc(sizeof(ItemDefinition));
        if (itemDef != NULL) {
            itemDef = GetItemDefinition(itemDefId);

            if (itemDef->descriptionId == 12073 || itemDef->descriptionId == 11151 || itemDef->descriptionId == 11153) {
                free(itemDef);

                return true;
            }

            free(itemDef);
        }
    }

    return false;
}

bool IsHelmet(u32 itemDefId)
{
    if (itemDefId != 0) {
        ItemDefinition* itemDef = malloc(sizeof(ItemDefinition));
        if (itemDef != NULL) {
            itemDef = GetItemDefinition(itemDefId);

            if (itemDef->descriptionId == 9945 || itemDef->descriptionId == 12994 || itemDef->descriptionId == 9114 || itemDef->descriptionId == 9945) {
                free(itemDef);

                return true;
            }

            free(itemDef);
        }
    }

    return false;
}

typedef struct ItemSubData {
    bool hasSubData;
} ItemSubData;

typedef struct ItemData {
    u32 itemDefinitionId;
    u32 tintId;
    u64 guid;
    u32 count;
    ItemSubData itemSubData;
    u64 containerGuid;
    u32 containerDefinitionId;
    u32 containerSlotId;
    u32 baseDurability;
    u32 currentDurability;
    u32 maxDurabilityFromDefinition;
    bool unknownBoolean1;
    u64 ownerCharacterId;
    u32 unknownDword9;
    Weapon weaponData;
} ItemData;

ItemData* pGetItemWeaponData(BaseItem* slot)
{
    if (slot->weapon) {
        // Put something here
    }

    return NULL; // temporary return value
}

ItemData pGetItemData(u32 containerDefId)
{
    BaseItem* baseItem = malloc(sizeof(BaseItem));
    if (!baseItem) {
        fprintf_s(stderr, "Failed to allocate memory to BaseItem struct in pGetItemData function!\n");
        ItemData defaults = { 0 };

        return defaults;
    }

    u32 durability = 0;

    while (true) {
        if (IsWeapon(baseItem->itemDefId)) {
            durability = 2000;
        } else if (IsArmor(baseItem->itemDefId)) {
            durability = 1000;
        } else if (IsHelmet(baseItem->itemDefId)) {
            durability = 100;
        }
    }

    ItemData result = {
        .itemDefinitionId = baseItem->itemDefId,
        .tintId = 0,
        .guid = baseItem->itemGuid,
        .count = baseItem->stackCount,
        .itemSubData = { .hasSubData = false },
        .containerGuid = baseItem->containerGuid,
        .containerDefinitionId = containerDefId,
        .containerSlotId = baseItem->slotId,
        .baseDurability = durability,
        .currentDurability = durability ? baseItem->currentDurability : 0,
        .maxDurabilityFromDefinition = durability,
        .unknownBoolean1 = true,
        .ownerCharacterId = 0x0000000000000001ull,
        .unknownDword9 = 1,
        // Initialize weaponData here
    };

    free(baseItem);

    return result;
}

void AddItem(App_State* app, Session_State* session, BaseItem* baseItem, u32 containerDefId)
{
}

// god have mercy on my soul for making this function
void ClientUpdateBase(App_State* app, Session_State* session, u8* data, u32 dataLen)
{
    u8 packetId = *data;
    u8 subPacketId = data[1];

    switch (subPacketId) {
    case 0x01: {
        NULL;
    } break;
    case 0x02: {

    } break;
    }
}
