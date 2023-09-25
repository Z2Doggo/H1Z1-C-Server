// this packet is so damn complicated, that it basically needs it own file!

u32 getResourceType(ResourceIds resourceId)
{
    switch (resourceId)
    {
    case HEALTH:
        return RESOURCE_HEALTH;
    case HUNGER:
        return RESOURCE_HUNGER;
    case HYDRATION:
        return RESOURCE_HYDRATION;
    case STAMINA:
        return RESOURCE_STAMINA;
    case VIRUS:
        return RESOURCE_VIRUS;
    case BLEEDING:
        return RESOURCE_BLEEDING;
    case COMFORT:
        return RESOURCE_COMFORT;
    case FUEL:
        return RESOURCE_FUEL;
    case CONDITION:
        return RESOURCE_CONDITION;
    default:
        return 0;
    };
};

u32 getGender(u32 actorModelId)
{
    switch (actorModelId)
    {
    case 9240:
        return 1; // male
    case 9474:
        return 2; // female
    default:
        return 0;
    }
}

char *getHeadActor(u32 actorModelId)
{
    char *headActor;

    switch (actorModelId)
    {
    case 9240:
        headActor = "SurvivorMale_Head_01.adr";
        printf("Male Head Actor Selected!\n");
        break;
    case 9474:
        headActor = "SurvivorFemale_Head_01.adr";
        printf("Female Head Actor Selected!\n");
        break;
    default:
        headActor = "";
        break;
    }

    return headActor;
}

u32 getHeadActorLength(char *headActor)
{
    if (headActor)
    {
        return (u32)strlen(headActor);
    }
    else
    {
        printf("Head Actor Length IS ZERO!\n");
        return 0;
    }
}

char *getHairModel(u32 actorModelId)
{
    char *hairModel;

    switch (actorModelId)
    {
    case 9240:
        hairModel = "SurvivorMale_Hair_MediumMessy.adr";
        printf("Male Hair Model Selected!\n");
        break;
    case 9474:
        hairModel = "SurvivorFemale_Hair_ShortBun.adr";
        printf("Female Hair Model Selected!\n");
        break;
    default:
        hairModel = "";
        break;
    }

    return hairModel;
}

u32 getHairModelLength(char *hairModel)
{
    if (hairModel)
    {
        return (u32)strlen(hairModel);
    }
    else
    {
        printf("Hair Model Length IS ZERO!\n");
        return 0;
    }
}

void sendSelfTest(App_State *app, Session_State *session)
{
    Zone_Packet_SendSelfToClient sendSelf = {0};

    sendSelf.payload_self = malloc(sizeof(struct payload_self_s));

    if (sendSelf.payload_self == NULL)
    {
        printf("Failed to allocate memory to SendSelfToClient!\n");
        return;
    }

    char *headActor = getHeadActor(sendSelf.payload_self[0].actor_model_id);
    u32 headActorLength = getHeadActorLength(headActor);

    u32 gender = getGender(sendSelf.payload_self[0].actor_model_id);
    char *hairModel = getHairModel(sendSelf.payload_self[0].actor_model_id);
    u32 hairModelLength = getHairModelLength(hairModel);

    sendSelf.payload_self[0] = (struct payload_self_s){
        .guid = 0x1ull,
        .character_id = 0x1ull,
        .transient_id.value = 52,
        .position = session->position.y++,
        .rotation = {0.0f, 0.0f, 0.0f, 1.0f},
        .actor_model_id = 9474,
        .head_actor = headActor,
        .head_actor_length = headActorLength,
        .hair_model = hairModel,
        .hair_model_length = hairModelLength,
        .is_respawning = false,
        .character_name_length = 4,
        .character_name = "test",
        .gender1 = gender,
        .creation_date = 0x0ull,
        .last_login_date = 0x0ull,
        .loadout_id = 3,
        .loadout_slots_array_count = 1,
        .loadout_slots_array = (struct loadout_slots_array_s[1]){
            [0] = {
                .hotbar_slot_id = 0,
                .loadout_id = 0,
                .slot_id = 0,
                .item_def_id4 = 0,
                .loadout_item_guid = 0x0,
                .unk_byte_17 = 255,
                .unk_dword_111 = 0,
            },
        },
        .current_slot_id = 7,
        .equipment_slots_count = 1,
        .equipment_slots = (struct equipment_slots_s[1]){
            [0] = {
                .unk_dword_7199 = 0,
                .unk_dword_890 = 0,
                .unk_string_4_length = 0,
                .unk_string_4 = "",
                .unk_string_2_length = 0,
                .unk_string_2 = "",
                .equipment_slot_id2 = 0,
                .equipment_slot_id3 = 0,
                .guid = 0x0ull,
                .tint_alias_length = 7,
                .tint_alias = "Default",
                .decal_alias_length = 1,
                .decal_alias = "#",
            },
        },
        .character_resources_count = 1, // 1 for now, until I figure some other stuff out with the loginpackets
        .character_resources = (struct character_resources_s[1]){
            [0] = {
                .resource_type1 = 1,
                .resource_id = 1,
                .resource_type2 = 1,
                .value = 10000,
                .unk_array_22866_count = 1,
                .unk_array_22866 = (struct unk_array_22866_s[1]){
                    [0] = {
                        .unk_dword_129 = 10000,
                        .unk_dword_294 = 10000,
                        .unk_dword_359 = 10000,
                        .unk_dword_430 = 10000,
                    },
                },
            },
        },
        .containers_count = 1,
        .containers = (struct containers_s[1]){
            [0] = {
                .loadout_slot_id = 0,
                .guid = 0x1ull,
                .def_id = 0,
                .associated_character_id = 0x1ull,
                .slots = 0,
                .items2_count = 1,
                .items2 = (struct items2_s[1]){
                    [0] = {
                        .item_def_id5 = 0,
                        .item_def_id6 = 0,
                        .tint_id = 0,
                        .guid = 0x1ull,
                        .count = 1,
                        .unk_qword_43 = 0,
                        .unk_dword_132 = 0,
                        .unk_dword_296 = 0,
                        .container_guid = 0,
                        .container_def_id = 0,
                        .container_slot_id = 0,
                        .base_durability = 0,
                        .current_durability = 0,
                        .max_durability_from_def = 0,
                        .unk_bool_116 = false,
                        .owner_character_id = 0x1ull,
                        .unk_dword_9 = 0,
                        .show_bulk = true,
                        .max_bulk = 0,
                        .unk_dword_133 = 0,
                        .bulk_used = 0,
                        .has_bulk_limit = true,
                    },
                },
            },
        },
        .is_admin = true,
    };

    zone_packet_send(app, session, &app->arena_per_tick, KB(500), Zone_Packet_Kind_SendSelfToClient, &sendSelf);

    free(sendSelf.payload_self);
}