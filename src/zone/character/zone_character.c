void loadCharacterData(App_State *app_state, Session_State *session_state)
{
    sendSelfTest(app_state, session_state);

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
                            .guid = 0x1ull, // keep guid as a 1 for now
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

    session_state->is_loading = true;
    session_state->character_released = false;
    session_state->is_alive = true;
    session_state->is_running = false;
    session_state->is_respawning = false;
    session_state->is_in_air = false;

    Zone_Packet_Character_RespawnReply respawnReply = {
        .character_id_1_1 = session_state->character_id,
        .status = 1,
    };
    zone_packet_send(app_state, session_state, &app_state->arena_per_tick,
                     KB(10), Zone_Packet_Kind_Character_RespawnReply,
                     &respawnReply);
}