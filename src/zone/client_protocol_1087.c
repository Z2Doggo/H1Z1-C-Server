#define REGISTER_PACKET_BASIC(id, kind)                                                  \
    case id:                                                                             \
    {                                                                                    \
        packet_kind = kind;                                                              \
        printf(MESSAGE_CONCAT_INFO("Handling %s...\n"), zone_packet_names[packet_kind]); \
    }                                                                                    \
    break;

typedef struct
{
    App_State *server_state;
    Session_State *session_state;
    Arena *arena;
    u32 max_length;
    Zone_Packet_Kind packet_kind;
    void *packet_ptr;
} ThreadParams;

DWORD WINAPI zone_packet_send_thread(LPVOID lpParam)
{
    ThreadParams *params = (ThreadParams *)lpParam;
    App_State *server_state = params->server_state;
    Session_State *session_state = params->session_state;
    Arena *arena = params->arena;
    u32 max_length = params->max_length;
    Zone_Packet_Kind packet_kind = params->packet_kind;
    void *packet_ptr = params->packet_ptr;

    // Your existing code for zone_packet_send goes here
    u8 *base_buffer = arena_push_size(arena, max_length);
    u8 *packed_buffer = base_buffer + TUNNEL_DATA_HEADER_LENGTH;
    u32 packed_length = zone_packet_pack(packet_kind, packet_ptr, packed_buffer);
    u32 total_length = packed_length + TUNNEL_DATA_HEADER_LENGTH;
    arena_rewind(arena, max_length - total_length);

    if (session_state->connection_args.should_dump_zone)
    {
        char dump_path[256] = {0};
        stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_S_zone_%s.bin", global_tick_count, global_dump_count++, zone_packet_names[packet_kind]);
        server_state->platform_api->buffer_write_to_file(dump_path, packed_buffer, packed_length);
    }

    gateway_tunnel_data_send(server_state, session_state, base_buffer, total_length);

    return 0;
}

internal void zone_packet_send(App_State *server_state, Session_State *session_state, Arena *arena, u32 max_length, Zone_Packet_Kind packet_kind, void *packet_ptr)
{
    ThreadParams params;
    params.server_state = server_state;
    params.session_state = session_state;
    params.arena = arena;
    params.max_length = max_length;
    params.packet_kind = packet_kind;
    params.packet_ptr = packet_ptr;

    // array to hold thread handles
    HANDLE threadHandles[3]; // increase if you dare!
    threadHandles[0] = CreateThread(NULL, 0, zone_packet_send_thread, &params, 0, NULL);

    if (threadHandles[0] == NULL)
    {
        printf("Thread failed to create!");
        ABORT;
    }

    // wait for multiple threads to finish
    DWORD result = WaitForMultipleObjects(1, threadHandles, TRUE, INFINITE);

    if (result == WAIT_FAILED)
    {
        printf("Wait for threads failed!");
        ABORT;
    }

    // close thread handles when done
    for (u32 i = 0; i < 1; i++)
    {
        CloseHandle(threadHandles[i]);
    }
}

internal void zone_packet_raw_file_send(App_State *server_state,
                                        Session_State *session_state,
                                        Arena *arena,
                                        u32 max_length,
                                        char *path)
{
    u8 *base_buffer = arena_push_size(arena, max_length);
    u8 *packed_buffer = base_buffer + TUNNEL_DATA_HEADER_LENGTH;
    u32 packed_length = server_state->platform_api->buffer_load_from_file(path,
                                                                          base_buffer + TUNNEL_DATA_HEADER_LENGTH,
                                                                          max_length);
    u32 total_length = packed_length + TUNNEL_DATA_HEADER_LENGTH;
    arena_rewind(arena, max_length - total_length);

    if (session_state->connection_args.should_dump_zone)
    {
        char dump_path[256] = {0};
        stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_S_zone_RAW.bin", global_tick_count, global_dump_count++);
        server_state->platform_api->buffer_write_to_file(dump_path, packed_buffer, packed_length);
    }

    // TODO(rhett): still only one client for now
    gateway_tunnel_data_send(server_state, session_state, base_buffer, total_length);
}

internal void zone_packet_handle(App_State *server_state,
                                 Session_State *session_state,
                                 u8 *data,
                                 u32 data_length)
{
    Zone_Packet_Kind packet_kind;

    __time64_t timer;
    _time64(&timer);

    printf("\n");

    if (data_length == 0)
    {
        printf(MESSAGE_CONCAT_WARN("Empty zone packet????\n\n"));
        return;
    }

    u32 packet_temp;
    u32 packet_id = *data;
    u8 *sub_packet_id = &data[1];
    u32 packet_iter;

    if (data_length > 0)
    {
        for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
        {
            if (data[0] == zone_registered_ids[packet_iter])
            {
                packet_id = *data;
                goto packet_id_switch;
            }
        }
    }

    if (data_length > 1)
    {
        packet_temp = (((0ul | data[0]) << 8) | data[1]);
        for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
        {
            if (packet_temp == zone_registered_ids[packet_iter])
            {
                packet_id = packet_temp;
                goto packet_id_switch;
            }
        }
    }

    if (data_length > 2)
    {
        packet_temp = ((0ul | data[0]) << 16) | endian_read_u16_little(data + 1);
        for (packet_iter = Zone_Packet_Kind_Unhandled + 1; packet_iter < Zone_Packet_Kind__End; packet_iter++)
        {
            if (packet_temp == zone_registered_ids[packet_iter])
            {
                packet_id = packet_temp;
                goto packet_id_switch;
            }
        }
    }

    goto packet_id_fail;

packet_id_switch:
    switch (packet_id)
    {
    case ZONE_CLIENTISREADY_ID:
    {
        packet_kind = Zone_Packet_Kind_ClientIsReady;
        printf("[Zone] Handling ZONE_CLIENTISREADY_ID\n");

        Zone_Packet_ClientUpdate_DoneSendingPreloadCharacters preload_done =
            {
                .is_done = true,
            };

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(30), Zone_Packet_Kind_ClientUpdate_DoneSendingPreloadCharacters, &preload_done);
        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ZoneDoneSendingInitialData, 0);
        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_NetworkProximityUpdatesComplete, 0);

        Zone_Packet_Character_CharacterStateDelta character_state_delta =
            {
                .guid_1 = session_state->character_id,
                .guid_2 = 0,
                .guid_3 = 0x40000000,
                .guid_4 = 0,
                .game_time = timer & 0x7fffffff,
            };

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_CharacterStateDelta, &character_state_delta);

        break;
    }
    case ZONE_CLIENTFINISHEDLOADING_ID:
    {
        if (session_state->finished_loading == false)
        {

            packet_kind = Zone_Packet_Kind_ClientFinishedLoading;
            printf("[Zone] Handling ClientFinishedLoading\n");

            Zone_Packet_Character_WeaponStance weapon_stance =
                {
                    .character_id = session_state->character_id,
                    .stance = 1,
                };

            Zone_Packet_Equipment_SetCharacterEquipment set_character_equipment =
                {
                    .length_1_length = 1,
                    .length_1 =
                        (struct length_1_s[1]){
                            [0] = {
                                .profile_id = 5,
                                .character_id = session_state->character_id,
                            },
                        },
                    .unk_dword_1 = 0,
                    .unk_string_1_length = 7,
                    .unk_string_1 = "Default",
                    .unk_string_2_length = 1,
                    .unk_string_2 = "#",

                    .equipment_slot_array_count = 1,
                    .equipment_slot_array = (struct equipment_slot_array_s[1]){
                        [0] = {
                            .equipment_slot_id_1 = 0,
                            .length_2_length = 1,
                            .length_2 = (struct length_2_s[1]){
                                [0] = {
                                    .equipment_slot_id_2 = 0,
                                    .guid = 0, // keep guid as a 0
                                    .tint_alias_length = 7,
                                    .tint_alias = "Default",
                                    .decal_alias_length = 1,
                                    .decal_alias = "#",
                                },
                            },
                        },
                    },

                    .attachments_data_1_count = 1,
                    .attachments_data_1 = (struct attachments_data_1_s[1]){
                        [0] = {
                            .model_name_length = 0,
                            .model_name = "",
                            .texture_alias_length = 0,
                            .texture_alias = "",
                            .tint_alias_length = 7,
                            .tint_alias = "Default",
                            .decal_alias_length = 1,
                            .decal_alias = "#",
                            .slot_id = 0,
                        },
                    },

                    .unk_bool_2 = true,
                };

            Zone_Packet_Loadout_SetLoadoutSlots ldt_setldtslots = {
                .character_id = 0x133742069,
                .loadout_id = 0,
                .loadout_slot_data_count = 1,
                .loadout_slot_data =
                    (struct loadout_slot_data_s[1]){
                        [0] = {
                            .hotbar_slot_id = 0,
                            .loadout_id_1 = 0,
                            .slot_id = 0,
                            .item_def_id1 = 0,
                            .loadout_item_guid = 0x0,
                            .unk_byte_1 = 255,
                            .unk_dword_1 = 0,
                        },
                    },

                .current_slot_id = 0,
            };

            Zone_Packet_Command_AddWorldCommand command_help =
                {
                    .command_length = 5,
                    .command = "/help",
                };

            Zone_Packet_Command_RunSpeed run_speed =
                {
                    .run_speed = 10.0f,
                };

            Zone_Packet_Character_StartMultiStateDeath multi_state_dth = {
                .character_id = 0x0000000000000000ull,
                .unk_byte_1 = 0,
                .unk_byte_2 = 1,
                .unk_byte_3 = 0,
            };

            session_state->first_login = false;
            zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Command_AddWorldCommand, &command_help);
            zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_WeaponStance, &weapon_stance);
            zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Equipment_SetCharacterEquipment, &set_character_equipment);
            zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Loadout_SetLoadoutSlots, &ldt_setldtslots);
            zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Command_RunSpeed, &run_speed);
            zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_StartMultiStateDeath, &multi_state_dth);

            Zone_Packet_ClientUpdate_ModifyMovementSpeed modifyMovement =
                {
                    .speed = 10,
                    .movementVersion = 6,
                };
            zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_ModifyMovementSpeed, &modifyMovement);
            session_state->is_ready = true;
            session_state->finished_loading = true;
        }

        break;
    }
    case ZONE_STATICVIEWREQUEST_ID:
    {
        packet_kind = Zone_Packet_Kind_StaticViewRequest;
        printf("[Zone] Handling StaticViewRequest\n");

        Zone_Packet_StaticViewRequest *viewReq = (Zone_Packet_StaticViewRequest *)malloc(sizeof(Zone_Packet_StaticViewRequest));
        // zone_packet_unpack(data, data_length, packet_kind, &viewReq, &server_state->arena_per_tick);

        staticViewReply(server_state, session_state, viewReq);
        free(viewReq);

        break;
    }
    case ZONE_PLAYERWORLDTRANSFERREQUEST_ID:
    {
        packet_kind = Zone_Packet_Kind_PlayerWorldTransferRequest;
        printf("[Zone] Zoning into Z2!\n");

        Zone_Packet_PlayerWorldTransferReply reply = {
            .world_id_reply = 1,
        };
        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_PlayerWorldTransferReply, &reply);

        Zone_Packet_ClientUpdate_UpdateLocation update_loc = {
            .position = {-32.26f, 506.41f, 280.21f, 1.0f},
            .rotation = {-0.11f, -0.58f, -0.08f, 1.0f},
            .trigger_loading_screen = true,
            .unk_u8_1 = 0,
            .unk_bool = false,
        };
        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_UpdateLocation, &update_loc);

        Zone_Packet_ClientBeginZoning begin_zoning = {
            .zone_name_length = 2,
            .zone_name = "Z2",
            .zone_type = 4,
            .pos = {-229.88f, 506.44f, -4885.03f, 1.0f},
            .rot = {0.10f, -0.50f, 0.00f, 1.0f},

            // set skydata
            .overcast = 0,
            .fogDensity = 0,
            .fogFloor = 14.8f,
            .fogGradient = 0.0144f,
            .globalPrecipitation = 0,
            .temperature = 75,
            .skyClarity = 0,
            .cloudWeight0 = 0.16f,
            .cloudWeight1 = 0.16f,
            .cloudWeight2 = 0.13f,
            .cloudWeight3 = 0.13f,
            .transitionTime = 0,
            .sunAxisX = 40,
            .sunAxisY = 0,
            .sunAxisZ = 0,
            .windDirX = -1.0f,
            .windDirY = -0.5f,
            .windDirZ = 1.0f,
            .wind = 3,
            .rainMinStrength = 0,
            .rainRampUpTimeSeconds = 0,
            .cloudFile_length = 16,
            .cloudFile = "sky_Z_clouds.dds",
            .stratusCloudTiling = 0.2f,
            .stratusCloudScrollU = -0.002f,
            .stratusCloudScrollV = 0,
            .stratusCloudHeight = 1000,
            .cumulusCloudTiling = 0.2f,
            .cumulusCloudScrollU = 0,
            .cumulusCloudScrollV = 0.002f,
            .cumulusCloudHeight = 8000,
            .cloudAnimationSpeed = 0,
            .cloudSilverLiningThickness = 0.39f,
            .cloudSilverLiningBrightness = 0.5f,
            .cloudShadows = 0.2f,

            .unk_byte_1 = 5,
            .zone_id_1 = 5,
            .zone_id_2 = 0,
            .name_id = 7699,
            .unk_dword_1 = 674234378,
            .unk_bool_1 = false,
            .wait_for_zone_ready = false,
            .unk_bool_2 = true,
        };
        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientBeginZoning, &begin_zoning);

        Zone_Packet_Equipment_SetCharacterEquipment set_character_equipment =
            {
                .length_1_length = 1,
                .length_1 =
                    (struct length_1_s[1]){
                        [0] = {
                            .profile_id = 5,
                            .character_id = 0x133742069,
                        },
                    },
                .unk_dword_1 = 0,
                .unk_string_1_length = 7,
                .unk_string_1 = "Default",
                .unk_string_2_length = 1,
                .unk_string_2 = "#",

                .equipment_slot_array_count = 1,
                .equipment_slot_array = (struct equipment_slot_array_s[1]){
                    [0] = {
                        .equipment_slot_id_1 = 0,
                        .length_2_length = 1,
                        .length_2 = (struct length_2_s[1]){
                            [0] = {
                                .equipment_slot_id_2 = 0,
                                .guid = 0, // keep guid as a 0
                                .tint_alias_length = 7,
                                .tint_alias = "Default",
                                .decal_alias_length = 1,
                                .decal_alias = "#",
                            },
                        },
                    },
                },

                .attachments_data_1_count = 1,
                .attachments_data_1 = (struct attachments_data_1_s[1]){
                    [0] = {
                        .model_name_length = 0,
                        .model_name = "",
                        .texture_alias_length = 0,
                        .texture_alias = "",
                        .tint_alias_length = 7,
                        .tint_alias = "Default",
                        .decal_alias_length = 1,
                        .decal_alias = "#",
                        .slot_id = 0,
                    },
                },

                .unk_bool_2 = true,
            };
        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Equipment_SetCharacterEquipment, &set_character_equipment);

        Zone_Packet_Loadout_SetLoadoutSlots ldt_setldtslots = {
            .character_id = 0x133742069,
            .loadout_id = 0,
            .loadout_slot_data_count = 1,
            .loadout_slot_data =
                (struct loadout_slot_data_s[1]){
                    [0] = {
                        .hotbar_slot_id = 0,
                        .loadout_id_1 = 0,
                        .slot_id = 0,
                        .item_def_id1 = 0,
                        .loadout_item_guid = 0x0,
                        .unk_byte_1 = 255,
                        .unk_dword_1 = 0,
                    },
                },

            .current_slot_id = 0,
        };
        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Loadout_SetLoadoutSlots, &ldt_setldtslots);

        break;
    }
    case ZONE_LOBBYGAMEDEFINITION_DEFINITIONSREQUEST_ID:
    {
        packet_kind = Zone_Packet_Kind_LobbyGameDefinition_DefinitionsRequest;
        printf("[Zone] Handling LobbyGameDefinition.DefinitionsRequest\n");

        Zone_Packet_LobbyGameDefinition_DefinitionsResponse lobby_def_reply =
            {
                .definitions_data =
                    (struct definitions_data_s[1]){
                        [0] =
                            {
                                .data_length = 0,
                                .data = "",
                            },
                    },
            };

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_LobbyGameDefinition_DefinitionsResponse, &lobby_def_reply);

        break;
    }
    case ZONE_REFERENCEDATAWEAPONDEFINITIONS_ID:
    {
        packet_kind = Zone_Packet_Kind_ReferenceDataWeaponDefinitions;
        printf("[Zone] Handling Weapon Definitions!\n");

        Zone_Packet_ReferenceDataWeaponDefinitions weaponDefs = {0};
        zone_packet_unpack(data, data_length, packet_kind, &weaponDefs, &server_state->arena_per_tick);
        break;
    }
    case ZONE_CHARACTER_RESPAWN_ID:
    {
        packet_kind = Zone_Packet_Kind_Character_Respawn;
        printf("[Zone] Handling Character.Respawn\n");

        Zone_Packet_Character_Respawn result = {0};
        zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

        session_state->is_loading = true;
        session_state->character_released = false;
        // (doggo)input last login date here
        session_state->is_alive = true;
        session_state->is_running = false;
        session_state->is_respawning = false;
        session_state->is_in_air = false;

        Zone_Packet_Character_RespawnReply respawn_reply =
            {
                .character_id_1_1 = session_state->character_id,
                .status = 1,
            };

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_RespawnReply, &respawn_reply);

        break;
    }
    case ZONE_CLIENTLOGOUT_ID:
    {
        packet_kind = Zone_Packet_Kind_ClientLogout;
        printf("[Zone] Handling ClientLogout\n");

        /*
        char local_message[36] = { 0 };

        (doggo) not sure how to include the character's name, for this, will comment out for now
        stbsp_snprintf(local_message, sizeof(local_message), "%s left the server", character_name);

        Zone_Packet_ClientUpdate_TextAlert text_alert =
        {
            .message_length = util_string_length(local_message),
            .message 		= local_message,
        };

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_TextAlert, &text_alert);
        */

        break;
    }
    case ZONE_INGAMEPURCHASEBASE_ID:
    {
        packet_kind = Zone_Packet_Kind_InGamePurchaseBase;
        printf("[Zone] Handling InGamePurchaseBase\n");

        break;
    }
    case ZONE_CLIENTLOG_ID:
    {
        packet_kind = Zone_Packet_Kind_ClientLog;
        printf("[Zone] Handling ClientLog\n");

        break;
    }
    case ZONE_CHAT_CHAT_ID:
    {
        packet_kind = Zone_Packet_Kind_Chat_Chat;

        // Zone_Packet_Chat_Chat result = { 0 };
        // zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

        // Zone_Packet_Chat_ChatText packet =
        // {
        // 	.message_length = result.message_length,
        // 	.message = result.message,
        // };

        // zone_packet_send(server_state,session_state, &server_state->arena_per_tick, KB(30), Zone_Packet_Kind_Chat_ChatText, &packet);

        break;
    }
    case ZONE_GAMETIMESYNC_ID:
    {
        packet_kind = Zone_Packet_Kind_GameTimeSync;
        printf("[Zone] Handling GameTimeSync\n");

        Zone_Packet_GameTimeSync time_sync =
            {
                .time = timer,
                .cycle_speed = 12.0f,
                .unk_bool = false,
            };

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_GameTimeSync, &time_sync);

        break;
    }
    case ZONE_SETLOCALE_ID:
    {
        packet_kind = Zone_Packet_Kind_SetLocale;
        printf("[Zone] Handling SetLocale\n");

        Zone_Packet_SetLocale setLocale =
            {
                .locale_length = 5,
                .locale = "en_US",
            };
        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_SetLocale, &setLocale);

        break;
    }
    case ZONE_CLIENTINITIALIZATIONDETAILS_ID:
    {
        packet_kind = Zone_Packet_Kind_ClientInitializationDetails;
        printf("[Zone] Handling ClientInitializationDetails\n");

        break;
    }

    case ZONE_WALLOFDATA_UIEVENT_ID:
    {
        packet_kind = Zone_Packet_Kind_WallOfData_UIEvent;
        printf("[Zone] Handling WallOfData.UIEvent\n");

        Zone_Packet_WallOfData_UIEvent result = {0};
        // zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

        break;
    }

    case ZONE_CHARACTER_FULLCHARACTERDATAREQUEST_ID:
    {
        packet_kind = Zone_Packet_Kind_Character_FullCharacterDataRequest;
        printf("[Zone] Handling Character.FullCharacterDataRequeso\n");

        Zone_Packet_Character_FullCharacterDataRequest full_data_request = {
            .character_id = session_state->character_id,
        };

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_Character_FullCharacterDataRequest, &full_data_request);

        break;
    }
    case ZONE_COMMAND_ITEMDEFINITIONREQUEST_ID:
    {
        packet_kind = Zone_Packet_Kind_Command_ItemDefinitionRequest;
        printf("[Zone] Handling Command.ItemDefinitionRequest\n");

        Zone_Packet_Command_ItemDefinitionRequest request = {0};
        zone_packet_unpack(data, data_length, packet_kind, &request, &server_state->arena_per_tick);

        u32 defsCount = 0;
        Zone_Packet_CommandItemDefinitions defs[5000] = {0};

        for (u32 i = 0; i < 5000; i++)
        {
            u32 item_id = request.id;

            switch (item_id)
            {
            case 1:
            case 9:
            case 1728:
            case 1730:
            case 2595:
            case 2675:
                defs[defsCount].item_def_reply_2->item_defs[i].defs_id = item_id;
                defs[defsCount].item_def_reply_2->item_defs[i].hud_image_set_id = defs->item_def_reply_2->item_defs->image_set_id;
                defs[defsCount].item_def_reply_2->item_defs[i].item_type_1 = defs->item_def_reply_2->item_defs->item_type_1;
                defs[defsCount].item_def_reply_2->item_defs[i].bitflags1 = defs->item_def_reply_2->item_defs->bitflags1;
                defs[defsCount].item_def_reply_2->item_defs[i].bitflags2 = defs->item_def_reply_2->item_defs->bitflags2;
                defs[defsCount].item_def_reply_2->item_defs[i].stats_item_def_2 = NULL;
                defsCount++;
                break;
            }
        }

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(500), Zone_Packet_Kind_CommandItemDefinitions, defs);

        break;
    }
    case ZONE_WALLOFDATA_CLIENTSYSTEMINFO_ID:
    {
        packet_kind = Zone_Packet_Kind_WallOfData_ClientSystemInfo;
        printf("[Zone] Handling WallOfData.ClientSystemInfo\n");

        Zone_Packet_WallOfData_ClientSystemInfo result = {0};
        // zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

        break;
    }
    case ZONE_WALLOFDATA_CLIENTTRANSITION_ID:
    {
        packet_kind = Zone_Packet_Kind_WallOfData_ClientTransition;
        printf("[Zone] Handling WallOfData.ClientTransition\n");

        Zone_Packet_WallOfData_ClientTransition result = {0};
        // zone_packet_unpack(data, data_length, packet_kind, &result, &server_state->arena_per_tick);

        break;
    }
    case ZONE_CLIENTUPDATE_MONITORTIMEDRIFT_ID:
    {
        packet_kind = Zone_Packet_Kind_ClientUpdate_MonitorTimeDrift;
        printf("[Zone] Handling ClientUpdate.MonitorTimeDrift\n");

        Zone_Packet_ClientUpdate_MonitorTimeDrift time_drift =
            {
                .time_drift = 0,
            };

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_MonitorTimeDrift, &time_drift);

        break;
    }
    case ZONE_GETCONTINENTBATTLEINFO_ID:
    {
        packet_kind = Zone_Packet_Kind_GetContinentBattleInfo;
        printf("[Zone] Handling GetContinentBattleInfo\n");

        Zone_Packet_ContinentBattleInfo battle_info =
            {
                .zones_count = 1,
                .zones =
                    (struct zones_s[1]){
                        [0] =
                            {
                                .continent_id = 1,
                                .info_name_id = 1,
                                .zone_description_id = 1,

                                .zone_name_length = 9,
                                .zone_name = "LoginZone",
                                .hex_size = 100,
                                .is_production_zone = 1,
                            }}};

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ContinentBattleInfo, &battle_info);

        break;
    }
    case ZONE_RESOURCEEVENTBASE_ID:
    {
        packet_kind = Zone_Packet_Kind_ResourceEventBase;
        printf("[Zone] Handling ResourceEventBase\n");

        /*
        Zone_Packet_ResourceEventBase rsrc_event_base =
        {
            .gametime = timer32,
            .variabletype8 =
            (struct set_character_resources_1_s[1]) {
                [0] =
                {
                    .character_id_1 = session_state->character_id,

                    .character_resources_1_count = 1,
                    .character_resources_1 =
                        (struct character_resources_1_s[1]) {
                        [0] =
                        {
                            .resource_type_1 = 3,

                            .resource_id_1 = session_state->resource_id,
                            .resource_type_2 = session_state->resource_type ? session_state->resource_type : session_state->resource_id,
                            .value = 1000,
                        },
                    },
                },
            },
            (struct set_character_resources_2_s[1]) {
                [0] =
                {
                    .character_id_2 = session_state->character_id,

                    .character_resources_2_count = 1,
                    .character_resources_2 =
                        (struct character_resources_2_s[1]) {
                        [0] =
                        {
                            .resource_type_1 = 3,

                            .resource_id = session_state->resource_id,
                            .resource_type_2 = session_state->resource_type ? session_state->resource_type : session_state->resource_id,
                            .value = 1000,
                        },
                    },
                },
            },
            (struct updt_character_resources_s[1]) {
                [0] =
                {
                    .character_id_3 = session_state->character_id,
                    .resource_id_2 = session_state->resource_id,
                    .resource_type_3 = session_state->resource_type ? session_state->resource_type : session_state->resource_id,
                    .initial_value = 1000 >= 0 ? 1000 : 0,
                },
            },
        };

        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, sizeof(rsrc_event_base), Zone_Packet_Kind_ResourceEventBase, &rsrc_event_base);
        */

        break;
    }
    case ZONE_CLIENTUPDATE_UPDATEBATTLEYEREGISTRATION_ID:
    {
        packet_kind = Zone_Packet_Kind_ClientUpdate_UpdateBattlEyeRegistration;
        printf("[Zone] Handling ClientUpdate.UpdateBattlEyeRegistration\n");

        // (doggo)keep empty, don't need this

        break;
    }
    case ZONE_KEEPALIVE_ID:
    {
        packet_kind = Zone_Packet_Kind_KeepAlive;
        printf("[Zone] Handling KeepAlive\n");

        Zone_Packet_KeepAlive keep_alive = {0};
        zone_packet_unpack(data, data_length, packet_kind, &keep_alive, &server_state->arena_per_tick);

        Zone_Packet_AddLightweightPc *lightPC = malloc(sizeof(Zone_Packet_AddLightweightPc));
        lightPC->character_id = 0x1ull,
        lightPC->actorModelId = 9240 || 9474,
        lightPC->rotation.x = 0.0f,
        lightPC->rotation.y = 0.0f,
        lightPC->rotation.z = 0.0f,
        lightPC->rotation.w = 1.0f,
        zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_KeepAlive, &lightPC);

        Zone_Packet_ClientUpdate_UpdateLocation *updateLocation = malloc(sizeof(Zone_Packet_ClientUpdate_UpdateLocation));
        updateLocation->trigger_loading_screen = false,

        free(updateLocation);
        free(lightPC);

        break;
    }
    case ZONE_PLAYERUPDATEPOSITION_ID:
    {
        packet_kind = Zone_Packet_Kind_PlayerUpdatePosition;
        printf("[Zone] Updating the player's position!\n");

        readPositionUpdateData(server_state, session_state, data, data_length);
        break;
    }
    default:
    {
    packet_id_fail:
        packet_kind = Zone_Packet_Kind_Unhandled;
        printf(MESSAGE_CONCAT_WARN("Unhandled zone packet %#x %#x\n"), packet_id, *sub_packet_id);

        if (session_state->connection_args.should_dump_zone)
        {
            char dump_path[256] = {0};
            stbsp_snprintf(dump_path, 256, "packets\\%llu_%llu_C_zone_%s.bin", global_tick_count, global_dump_count++, zone_packet_names[packet_kind]);
            server_state->platform_api->buffer_write_to_file(dump_path, data, data_length);
        }
    }
    }
}