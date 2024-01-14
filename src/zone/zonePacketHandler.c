void ZonePacketHandler(AppState *app, SessionState *session, u8 *data, u32 dataLen)
{
    Zone_Packet_Kind kind;
    printf("\n");

    __time64_t timer;
    _time64(&timer);

    u32 packetId = *data;
    u32 subPacketId = data[1];

    switch (packetId)
    {
    case ZONE_CLIENTISREADY_ID:
    {
        kind = Zone_Packet_Kind_ClientIsReady;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);

        Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters preloadDone = {0};

        preloadDone.is_done = true;

        ZonePacketSend(app, session, &app->arenaPerTick, KB(30), Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters, &preloadDone);
        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_ZoneDoneSendingInitialData, 0);
        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_ClientUpdate_NetworkProximityUpdatesComplete, 0);

        Zone_Packet_Character_CharacterStateDelta stateDelta = {0};

        stateDelta.guid_1 = 0x00ull;
        stateDelta.guid_2 = 0x00ull;
        stateDelta.guid_3 = 0x40000000ull;
        stateDelta.guid_4 = 0x00ull;
        stateDelta.game_time = timer & 0x7fffffff;

        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_Character_CharacterStateDelta, &stateDelta);
    }
    break;
    case ZONE_CLIENTFINISHEDLOADING_ID:
    {
        bool finishedLoading = session->finished_loading;

        if (!finishedLoading)
        {
            kind = Zone_Packet_Kind_ClientFinishedLoading;
            printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);

            Zone_Packet_Character_WeaponStance weaponStance = {0};

            weaponStance.character_id = session->characterId;
            weaponStance.stance = 1;

            ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_Character_WeaponStance, &weaponStance);

            Zone_Packet_Equipment_SetCharacterEquipment setEquipment = {0};

            setEquipment.unk_string_1 = "Default";
            setEquipment.unk_string_1_length = STRLEN("Default");
            setEquipment.unk_string_2 = "#";
            setEquipment.unk_string_2_length = STRLEN("#");
            setEquipment.unk_bool_2 = true;

            setEquipment.length_1 = (struct length_1_s[1]){
                [0] = {
                    .character_id = 0x01ull,
                    .profile_id = 5,
                },
            };

            setEquipment.equipment_slot_array_count = 1;
            setEquipment.equipment_slot_array = (struct equipment_slot_array_s[1]){
                [0] = {
                    .length_2 = (struct length_2_s[1]){
                        [0] = {
                            .tint_alias = "Default",
                            .tint_alias_length = STRLEN("Default"),
                            .decal_alias = "#",
                            .decal_alias_length = STRLEN("#"),
                        },
                    },
                },
            };

            setEquipment.attachments_data_1_count = 1;

            setEquipment.attachments_data_1 = (struct attachments_data_1_s[1]){
                [0] = {
                    .tint_alias = "Default",
                    .tint_alias_length = STRLEN("Default"),
                    .decal_alias = "#",
                    .decal_alias_length = STRLEN("#"),
                },
            };

            ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_Equipment_SetCharacterEquipment, &setEquipment);

            Zone_Packet_Loadout_SetLoadoutSlots setLoadoutSlots = {0};

            setLoadoutSlots.character_id = 0x01ull;
            setLoadoutSlots.loadout_slot_data_count = 1;

            setLoadoutSlots.loadout_slot_data = (struct loadout_slot_data_s[1]){
                [0] = {
                    .unk_byte_1 = 255,
                },
            };

            ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_Loadout_SetLoadoutSlots, &setLoadoutSlots);
            finishedLoading = true;
        }
    }
    break;
    case ZONE_GETCONTINENTBATTLEINFO_ID:
    {
        kind = Zone_Packet_Kind_GetContinentBattleInfo;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);

        Zone_Packet_ContinentBattleInfo battleInfo = {0};

        battleInfo.zones_count = 1;

        battleInfo.zones = (struct zones_s[1]){
            [0] = {
                .continent_id = 1,
                .info_name_id = 1,
                .zone_description_id = 1,
                .zone_name = "LoginZone",
                .zone_name_length = STRLEN("LoginZone"),
                .hex_size = 100,
                .is_production_zone = 1,
            },
        };

        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_ContinentBattleInfo, &battleInfo);
    }
    break;
    case ZONE_CLIENTINITIALIZATIONDETAILS_ID:
    {
        kind = Zone_Packet_Kind_ClientInitializationDetails;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);
    }
    break;
    case ZONE_WALLOFDATA_UIEVENT_ID:
    {
        kind = Zone_Packet_Kind_WallOfData_UIEvent;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);

        Zone_Packet_WallOfData_UIEvent uiEvent = {0};
        zone_packet_unpack(data, dataLen, kind, &uiEvent, &app->arenaPerTick);

        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), kind, &uiEvent);
    }
    break;
    case ZONE_WALLOFDATA_CLIENTSYSTEMINFO_ID:
    {
        kind = Zone_Packet_Kind_WallOfData_ClientSystemInfo;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);

        Zone_Packet_WallOfData_ClientSystemInfo systemInfo = {0};
        zone_packet_unpack(data, dataLen, kind, &systemInfo, &app->arenaPerTick);

        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), kind, &systemInfo);
    }
    break;
    case ZONE_WALLOFDATA_CLIENTTRANSITION_ID:
    {
        kind = Zone_Packet_Kind_WallOfData_ClientTransition;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);

        Zone_Packet_WallOfData_ClientTransition clientTransition = {0};
        zone_packet_unpack(data, dataLen, kind, &clientTransition, &app->arenaPerTick);

        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), kind, &clientTransition);
    }
    break;
    case ZONE_SETLOCALE_ID:
    {
        kind = Zone_Packet_Kind_SetLocale;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);

        Zone_Packet_SetLocale setLocale = {0};

        setLocale.locale = "en_US";
        setLocale.locale_length = STRLEN("en_US");

        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), kind, &setLocale);
    }
    break;
    case ZONE_CLIENTLOG_ID:
    {
        kind = Zone_Packet_Kind_ClientLog;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);
    }
    break;
    case ZONE_CLIENTLOGOUT_ID:
    {
        kind = Zone_Packet_Kind_ClientLogout;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);
    }
    break;
    case ZONE_LOBBYGAMEDEFINITION_DEFINITIONSREQUEST_ID:
    {
        kind = Zone_Packet_Kind_LobbyGameDefinition_DefinitionsRequest;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);

        Zone_Packet_LobbyGameDefinition_DefinitionsResponse lobbyDefReply = {0};
        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_LobbyGameDefinition_DefinitionsResponse, &lobbyDefReply);
    }
    break;
    case ZONE_KEEPALIVE_ID:
    {
        kind = Zone_Packet_Kind_KeepAlive;
        printf(MESSAGE_CONCAT_INFO("Handling %s\n"), zone_packet_names[kind]);

        Zone_Packet_KeepAlive keepAlive = {0};
        zone_packet_unpack(data, dataLen, kind, &keepAlive, &app->arenaPerTick);

        ZonePacketSend(app, session, &app->arenaPerTick, KB(10), kind, &keepAlive);
    }
    break;
    default:
    {
        printf(MESSAGE_CONCAT_WARN("Unhandled Zone packet %#x %#x\n"), packetId, subPacketId);
    }
    }
}
