// will input character data here for stuff like respawning the player character and setting the resources, i.e. health, bleeding, etc;etc!

void loadCharacterData(App_State* app_state, Session_State* session_state)
{
    sendSelf(app_state, session_state);
    session_state->guid = 0x665a2bff2b44c034u; 
    b8 newCharacter = FALSE;

    if (newCharacter == FALSE || session_state->is_respawning == TRUE)
    {
        session_state->is_loading = TRUE;
        session_state->character_released = FALSE;
        session_state->is_alive = TRUE;
        session_state->is_running = FALSE;
        session_state->is_respawning = FALSE;
        session_state->is_in_air = FALSE;
       
        if (!session_state->clientKOTK.initialized) {
        Zone_Packet_Character_RespawnReply respawnReply = 
        {
            .character_id_1_1 = session_state->character_id,
            .status = 1,
        };
        zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(100), Zone_Packet_Kind_Character_RespawnReply, &respawnReply);
        }
    }

    Zone_Packet_ResourceEventBase resourceEvent1 = {
        .variabletype8_case = 2,
        .variabletype8 = {
            .updt_character_resources = {
                .character_id_3 = session_state->character_id,
                .resource_id_2 = HEALTH,
                .resource_type_3 = RESOURCE_HEALTH,
                .initial_value = 10000 >= 0 ? 10000 : 0
            },
        },
    };
    zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_ResourceEventBase, &resourceEvent1);
        
    Zone_Packet_ResourceEventBase resourceEvent2 = {
        .variabletype8_case = 2,
        .variabletype8 = {
            .updt_character_resources = {
                .character_id_3 = session_state->character_id,
                .resource_id_2 = BLEEDING,
                .resource_type_3 = RESOURCE_BLEEDING,
                .initial_value = (i32)-40 >= 0 ? 10000 : 0
            },
        },
    };
    zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_ResourceEventBase, &resourceEvent2);
       
    Zone_Packet_ResourceEventBase resourceEvent3 = {
        .variabletype8_case = 2,
        .variabletype8 = {
            .updt_character_resources = {
                .character_id_3 = session_state->character_id,
                .resource_id_2 = STAMINA,
                .resource_type_3 = RESOURCE_STAMINA,
                .initial_value = 10000 >= 0 ? 10000 : 0
            },
        },
    };
    zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_ResourceEventBase, &resourceEvent3);
    session_state->clientKOTK.initialized = TRUE;
}