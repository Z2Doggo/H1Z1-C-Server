// will input character data here for stuff like respawning the player
// character and setting the resources, i.e. health, bleeding, etc;etc!

void pGetLightWeight(App_State *app_state, Session_State *session_state)
{
    Zone_Packet_AddLightweightNpc lightweightNpc =
        {
            .characterId = session_state->character_id,
            .transientId.value = session_state->transient_id.value,
            .nameId = 0,
            .actorModelId = 9240,
            .position = session_state->positionLW, // need to figure out how to make a proper update character position func for this?
            .rotation = session_state->rotation,   // as well as this too!
            .scale = {1.0f, 1.0f, 1.0f, 1.0f},
            .positionUpdateType = 0,
            .profileId = 0,
            .isLightweight = true,
            .flags1 = 0,
            .flags2 = 0,
            .flags3 = 0,
            .headActor_length = 26,
            .headActor = "SurvivorFemale_Head_02.adr",
        };
    zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_AddLightweightNpc, &lightweightNpc);
}

void loadCharacterData(App_State *app_state, Session_State *session_state)
{
    sendSelf(app_state, session_state);

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
                            .guid = 0x1ull, // keep guid as a 0
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
    zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_Equipment_SetCharacterEquipment, &set_character_equipment);

    session_state->guid = 0x665a2bff2b44c034u;
    b8 newCharacter = false;

    if (newCharacter == false || session_state->is_respawning == true)
    {
        session_state->is_loading = true;
        session_state->character_released = false;
        session_state->is_alive = true;
        session_state->is_running = false;
        session_state->is_respawning = false;
        session_state->is_in_air = false;

        if (!session_state->client.initialized)
        {
            Zone_Packet_Character_RespawnReply respawnReply = {
                .character_id_1_1 = session_state->character_id,
                .status = 1,
            };
            zone_packet_send(app_state, session_state, &app_state->arena_per_tick,
                             KB(10), Zone_Packet_Kind_Character_RespawnReply,
                             &respawnReply);
        }
    }

    Zone_Packet_ResourceEventBase resourceEvent1 = {
        .variabletype8_case = 2,
        .variabletype8 = {
            .updt_character_resources = {.character_id_3 = session_state->character_id,
                                         .resource_id_2 = HEALTH,
                                         .resource_type_3 = RESOURCE_HEALTH,
                                         .initial_value = 10000 >= 0 ? 10000 : 0},
        },
    };
    zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10),
                     Zone_Packet_Kind_ResourceEventBase, &resourceEvent1);

    Zone_Packet_ResourceEventBase resourceEvent2 = {
        .variabletype8_case = 0,
        .variabletype8 = {
            .set_character_resources_1 = {
                .character_id_1 = session_state->character_id,
                .character_resources_1_count = 1,
                .character_resources_1 = (struct character_resources_1_s[1]){
                    [0] = {
                        .resource_type_1 = RESOURCE_HEALTH,
                        .resource_id_1 = HEALTH,
                        .resource_type_2 = RESOURCE_HEALTH,
                        .value = 10000,
                        .unk_list_11_count = 1,
                        .unk_list_11 =
                            (struct unk_list_11_s[1]){
                                [0] =
                                    {
                                        .unk_dword_1 = 10000,
                                        .unk_dword_2 = 10000,
                                        .unk_dword_3 = 10000,
                                        .unk_dword_4 = 10000,
                                    }}},
                },
            },
        },
    };
    zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10),
                     Zone_Packet_Kind_ResourceEventBase, &resourceEvent2);

    Zone_Packet_ResourceEventBase resourceEvent3 = {
        .variabletype8_case = 1,
        .variabletype8 = {
            .set_character_resources_2 = {
                .character_id_2 = session_state->character_id,
                .character_resources_2_count = 1,
                .character_resources_2 = (struct character_resources_2_s[1]){
                    [0] = {
                        .resource_type_1 = RESOURCE_HEALTH,
                        .resource_id = HEALTH,
                        .resource_type_2 = RESOURCE_HEALTH,
                        .value = 10000,
                        .unk_list_22_count = 1,
                        .unk_list_22 =
                            (struct unk_list_22_s[1]){
                                [0] =
                                    {
                                        .unk_dword_1 = 10000,
                                        .unk_dword_2 = 10000,
                                        .unk_dword_3 = 10000,
                                        .unk_dword_4 = 10000,
                                    }}},
                },
            },
        },
    };
    zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_ResourceEventBase, &resourceEvent3);
    // free(resourceData);
    session_state->client.initialized = true;
}