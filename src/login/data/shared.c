internal void *
addDummyDataToCharacters(struct characters_s *characters)
{
    characters->payload4->loadout_id = 3;
    characters->payload4->unknown_dword = 22;
    characters->payload4->unknown_byte_1 = 1;
}

internal void
CharacterSelectInfo(App_State *app, Session_State *session)
{
    Login_Packet_CharacterSelectInfoReply reply = {0};
    reply.characters = malloc(sizeof(struct characters_s));

    reply.character_status = 1;
    reply.can_bypass_server_lock = true;
    reply.characters_count = 1;
    reply.characters[0].payload4[0].loadout_id = 3;
    reply.characters[0].payload4[0].unknown_dword = 22;
    reply.characters[0].payload4[0].unknown_byte_1 = 1;
    reply.characters[0].character_id = 0x1ull;
    reply.characters[0].server_id = 1;
    reply.characters[0].payload4[0].name = "doggo";
    reply.characters[0].payload4[0].name_length = (u32)strlen("doggo");
    reply.characters[0].payload4[0].model_id = 9240 || 9474;
    reply.characters[0].payload4[0].gender = 1 || 2;

    login_packet_send(app, session, &app->arena_per_tick, KB(10), false, Login_Packet_Kind_CharacterSelectInfoReply, &reply);
    free(reply.characters);
}

/*
void CharacterSelectInfoRequest(App_State *app, Session_State *session)
{
    Login_Packet_CharacterSelectInfoReply selectInfoReply = {0};
    selectInfoReply.characters = malloc(sizeof(struct characters_s));

    // CharacterModelData data;
    for (u32 headType = 0; headType < HEAD_TYPES; headType++)
    {
        // getCharacterModelData(headType, &data);
    }

    selectInfoReply.character_status = 1;
    selectInfoReply.can_bypass_server_lock = true;

    selectInfoReply.characters[0] = (struct characters_s){
        .character_id = session->character_id,
        .server_id = 1,
    };

    selectInfoReply.characters[0].payload4 = malloc(sizeof(struct payload4_s));
    *selectInfoReply.characters[0].payload4 = (struct payload4_s){
        .name = NULL,     // name hardcoded
        .name_length = 0, // name length hardcoded
        .model_id = 9240, // probably should make the struct in session state a pointer?
        .gender = 1,      // this too?
        .head_id = 9587,
    };

    login_packet_send(app, session, &app->arena_per_tick, KB(10), false, Login_Packet_Kind_CharacterSelectInfoReply, &selectInfoReply);

    free(selectInfoReply.characters[0].payload4);
    free(selectInfoReply.characters);
}
*/