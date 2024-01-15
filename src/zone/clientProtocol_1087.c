DWORD WINAPI ZonePacketSendThread(LPVOID lpParam)
{
    ThreadParams *params = lpParam;

    AppState *app = params->app;
    SessionState *session = params->session;
    Arena *arena = params->arena;
    u32 maxLen = params->maxLen;
    Zone_Packet_Kind kind = params->kind;
    void *packetPtr = params->packetPtr;

    u8 *baseBuffer = arena_push_size(arena, maxLen);
    u8 *packedBuffer = baseBuffer + TunnelDataHeaderLen;

    u32 packedLen = zone_packet_pack(kind, packetPtr, packedBuffer);
    u32 totalLen = packedLen + TunnelDataHeaderLen;

    arena_rewind(arena, maxLen - totalLen);
    GatewayTunnelDataSend(app, session, baseBuffer, totalLen);

    return 0;
}

void ZonePacketSend(AppState *app, SessionState *session, Arena *arena, u32 maxLen, Zone_Packet_Kind kind, void *packetPtr)
{
    ThreadParams params;

    params.app = app;
    params.session = session;
    params.arena = arena;
    params.maxLen = maxLen;
    params.kind = kind;
    params.packetPtr = packetPtr;

    HANDLE threadHandles[MAX_THREADS];
    threadHandles[0] = CreateThread(NULL, 0, ZonePacketSendThread, &params, 0, NULL);

    if (threadHandles[0] == NULL)
    {
        ABORT_MSG("Thread failed to create!\n");
    }

    DWORD result = WaitForMultipleObjects(1, threadHandles, TRUE, INFINITE);

    if (result == WAIT_FAILED)
    {
        ABORT_MSG("Wait for threads failed!\n");
    }

    for (u32 i = 0; i < 1; i++)
    {
        CloseHandle(threadHandles[i]);
    }
}

void ZonePacketRawFileSend(AppState *app, SessionState *session, Arena *arena, u32 maxLen, char *path)
{
    u8 *baseBuffer = arena_push_size(arena, maxLen);
    u8 *packedBuffer = baseBuffer + TunnelDataHeaderLen;

    u32 packedLen = app->api->buffer_load_from_file(path, baseBuffer + TunnelDataHeaderLen, maxLen);
    u32 totalLen = packedLen + TunnelDataHeaderLen;

    arena_rewind(arena, maxLen - totalLen);
    GatewayTunnelDataSend(app, session, baseBuffer, totalLen);
}

void readPositionUpdateData(AppState *app, SessionState *session, u8 *data, u32 offset)
{
    Zone_Packet_PlayerUpdatePosition obj = {0}; // init
    u32 start_offset = offset;                  // offset is u32 for 2bit values, other than that, will need to typecast to a (u8 *) - doggo

    obj.flag = endian_read_u16_little(data + offset);
    offset += 2;

    obj.sequence = endian_read_u32_little(data + offset);
    offset += 4;

    obj.ubyte = endian_read_u8_little(data + offset);
    offset += 1;

    int2b v;           // signed, also maybe init this aswell?
    euler_angle euler; // needed for the last part of this packet

    if (obj.flag & 1)
    {
        v = endian_read_int2b_little(data, offset);
        session->stance = v.value;
        offset += v.length;
    }

    if (obj.flag & 2)
    {
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

    if (obj.flag & 0x20)
    {
        session->orientation = endian_read_f32_little(data + offset);
        offset += 4;
    }

    if (obj.flag & 0x40)
    {
        v = endian_read_int2b_little(data, offset);
        session->frontTilt = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x80)
    {
        v = endian_read_int2b_little(data, offset);
        session->sideTilt = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 4)
    {
        v = endian_read_int2b_little(data, offset);
        session->angleChange = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x8)
    {
        v = endian_read_int2b_little(data, offset);
        session->verticalSpeed = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x10)
    {
        v = endian_read_int2b_little(data, offset);
        session->horizontalSpeed = v.value / 10;
        offset += v.length;
    }

    if (obj.flag & 0x100)
    {
        session->unkVec4;
        v = endian_read_int2b_little(data, offset);
        session->unkVec4.x = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->unkVec4.y = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->unkVec4.z = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x200)
    {
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

    if (obj.flag & 0x400)
    {
        v = endian_read_int2b_little(data, offset);
        session->direction = v.value / 10;
        offset += v.length;
    }

    if (obj.flag & 0x800)
    {
        v = endian_read_int2b_little(data, offset);
        session->engineRpm = v.value / 10;
        offset += v.length;
    }

    ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_PlayerUpdatePosition, &obj);
}

bool IsValid(BaseItem *baseItem, u8 flag)
{
    if (flag)
    {
        baseItem->debugFlag = flag;
    }

    if (baseItem->stackCount <= 0)
    {
        fprintf(stderr, "Item is invalid; itemDefId: (%u), stackCount: (%u), debugFlag: (%u)\n", baseItem->itemDefId, baseItem->stackCount, baseItem->debugFlag);
        return false;
    }

    return true;
}

ItemDefinition GetItemDefinition(ItemDefinition *itemDef, u32 itemDefId)
{
    return itemDef[itemDefId];
}

bool IsWeapon(ItemDefinition *itemDef, u32 itemDefId)
{
    if (itemDefId != 0)
    {
        return itemDef[itemDefId].itemType == 20;
    }

    return false;
}

bool IsArmor(ItemDefinition *itemDef, u32 itemDefId)
{
    if (itemDefId != 0)
    {
        if (itemDef[itemDefId].descriptionId == 12073 || itemDef[itemDefId].descriptionId == 11151 || itemDef[itemDefId].descriptionId == 11153)
        {
            return true;
        }
    }

    return false;
}

bool IsHelmet(ItemDefinition *itemDef, u32 itemDefId)
{
    if (itemDefId != 0)
    {
        GetItemDefinition(itemDef, itemDefId);

        if (itemDef[itemDefId].descriptionId == 9945 || itemDef[itemDefId].descriptionId == 12994 || itemDef[itemDefId].descriptionId == 9114 || itemDef[itemDefId].descriptionId == 9945)
        {
            return true;
        }
    }

    return false;
}

ItemData GetItemData(ItemData *itemData, ItemDefinition *itemDef, u32 itemDefId)
{
    u32 durability = 0;

    while (true)
    {
        if (IsWeapon(itemDef, itemDef->baseItem[itemDefId].itemDefId))
        {
            durability = 2000;
            break;
        }
        else if (IsArmor(itemDef, itemDef->baseItem[itemDefId].itemDefId))
        {
            durability = 1000;
            break;
        }
        else if (IsHelmet(itemDef, itemDef->baseItem[itemDefId].itemDefId))
        {
            durability = 100;
            break;
        }
    }

    itemData->itemDefinitionId = itemDef->baseItem[itemDefId].itemDefId;
    itemData->tintId = 0;
    itemData->guid = itemDef->baseItem[itemDefId].itemGuid;
    itemData->count = itemDef->baseItem[itemDefId].stackCount;

    itemData->itemSubData->hasSubData = false;

    itemData->containerGuid = itemDef->baseItem[itemDefId].containerGuid;
    itemData->containerDefinitionId = itemDef->baseItem[itemDefId].containerDefId;
    itemData->containerSlotId = itemDef->baseItem[itemDefId].slotId;
    itemData->baseDurability = durability;
    itemData->currentDurability = durability ? itemDef->baseItem[itemDefId].currentDurability : 0;
    itemData->maxDurabilityFromDefinition = durability;
    itemData->unknownBoolean1 = true;
    itemData->ownerCharacterId = 0x0000000000000001ull;
    itemData->unknownDword9 = 1;
    /* Initialize weaponData here */

    return *itemData;
}