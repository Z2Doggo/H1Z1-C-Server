// shared functions for login packets as well as storing data in session state variables for use in other packets besides login packets, i.e. characterName, characterId, etc

// proper name validation func soon

struct Login_Packet_CharacterSelectInfoReply **addDummyDataToCharacters(struct Login_Packet_CharacterSelectInfoReply *characters[], u32 numCharacters)
{
    cJSON *characterItemDefinitionsDummy = cJSON_Parse("../json/characterItemDefinitionsDummy.json");
    if (!characterItemDefinitionsDummy)
    {
        printf("Error parsing Dummy Item Definitions!\n");
        return characters; // return the original characters array on error
    }

    for (u32 index = 0; index < numCharacters; index++)
    {
        // add dummy data
        struct Login_Packet_CharacterSelectInfoReply *PlayerCharacter = characters[index];
        PlayerCharacter->characters->payload4->item_definitions_count = 1;
        PlayerCharacter->characters->payload4->item_definitions = (struct item_definitions_s *)characterItemDefinitionsDummy;
        *PlayerCharacter->characters->payload4 = (struct payload4_s){
            .loadout_id = 3,
            .unknown_dword_1 = 22,
            .unknown_byte_1 = 1,
            .unknown_dword_2 = 0,
            .unknown_dword_3 = 0,
            .loadout_name = "",
            .tint_item_id = 0,
            .unknown_dword_4 = 0,
            .decal_item_id = 0,
        };
        PlayerCharacter->characters->payload4->attachment_definitions_count = 1;
        PlayerCharacter->characters->payload4->attachment_definitions = NULL;
    }

    return characters;
}

// incomplete func
void CharacterSelectInfoRequest(App_State *app, Session_State *session, u32 numCharacters)
{
    // Assuming you have a way to obtain the 'characters' data in the current scope
    Zone_Packet_SendSelfToClient characterSelf = {0};

    // Create an array to store character information
    struct Login_Packet_CharacterSelectInfoReply **characterList = malloc(numCharacters * sizeof(struct Login_Packet_CharacterSelectInfoReply *));
    if (characterList == NULL)
    {
        // Handle memory allocation error
        // You might want to free previously allocated memory before returning
        return;
    }

    for (u32 i = 0; i < numCharacters; i++)
    {
        characterList[i] = malloc(sizeof(struct Login_Packet_CharacterSelectInfoReply));
        if (characterList[i] == NULL)
        {
            // Handle memory allocation error
            // You might want to free previously allocated memory before returning
            return;
        }

        // Populate characterList[i] based on characters[i]
        characterList[i]->characters->character_id = characterSelf.payload_self->character_id;

        // Create and fill the payload4 structure
        characterList[i]->characters->payload4->name_length = strlen(characterList[i]->characters->payload4->name);
        characterList[i]->characters->payload4->name = characterList[i]->characters->payload4->name;
        characterList[i]->characters->payload4->model_id = characterList[i]->characters->payload4->model_id;
        characterList[i]->characters->payload4->gender = characterList[i]->characters->payload4->gender;

        // Continue filling other fields in the payload4 structure

        // For loadout_slots, item_definitions, attachment_definitions, etc., allocate memory and fill in the data as required
    }

    characterList = addDummyDataToCharacters(characterList, numCharacters);

    struct Login_Packet_CharacterSelectInfoReply characterSelectInfoReply = {
        .character_status = 1,
        .can_bypass_server_lock = true,
        .characters = characterList};

    login_packet_send(app, session, &app->arena_per_tick, KB(10), false, Login_Packet_Kind_CharacterSelectInfoReply, &characterSelectInfoReply);
}
