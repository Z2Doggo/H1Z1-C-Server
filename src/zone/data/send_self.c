// this packet is so damn complicated, that it basically needs it own file!

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

char *
getHeadActor(u32 model_id)
{
    switch (model_id)
    {
    case 9240:
        return "SurvivorMale_Head_01.adr";
    case 9474:
        return "SurvivorFemale_Head_01.adr";
    default:
        return "";
    }
}

char *
getHairModel(u32 actorModelId)
{
    switch (actorModelId)
    {
    case 9240:
        printf("Male Hair Model Selected!\n");
        return "SurvivorMale_Hair_MediumMessy.adr";
    case 9474:
        printf("Female Hair Model Selected!\n");
        return "SurvivorFemale_Hair_ShortBun.adr";
    default:
        return "";
    }
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
    Zone_Packet_SendSelfToClient *sendSelf = calloc(1, sizeof(Zone_Packet_SendSelfToClient));
    sendSelf->payload_self = calloc(1, sizeof(struct payload_self_s));

    if (sendSelf && sendSelf->payload_self == NULL)
    {
        printf("Failed to allocate memory to SendSelfToClient!\n");

        free(sendSelf->payload_self);
        free(sendSelf);

        return;
    }

    sendSelf->payload_self->character_id = 0x1ull;
    sendSelf->payload_self->guid = 0x1ull;
    sendSelf->payload_self->transient_id.value = 52; // temp value
    sendSelf->payload_self->actor_model_id = 9240;
    sendSelf->payload_self->gender1 = 1; // idk
    sendSelf->payload_self->head_actor = "SurvivorMale_Head_01.adr";
    sendSelf->payload_self->head_actor_length = 24;
    sendSelf->payload_self->hair_model = "SurvivorMale_Hair_MediumMessy.adr";
    sendSelf->payload_self->hair_model_length = 33;
    sendSelf->payload_self->is_respawning = false;
    sendSelf->payload_self->creation_date = 0x0ull;
    sendSelf->payload_self->last_login_date = 0x0ull;
    sendSelf->payload_self->character_name = "doggo";
    sendSelf->payload_self->character_name_length = 5;
    sendSelf->payload_self->is_admin = true;

    zone_packet_send(app, session, &app->arena_per_tick, KB(500), Zone_Packet_Kind_SendSelfToClient, sendSelf);

    free(sendSelf->payload_self);
    free(sendSelf);
}