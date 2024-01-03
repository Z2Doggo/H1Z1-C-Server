vec3 updatePosition(vec3 position)
{
    for (int idx = 0; idx < 3; idx++)
    {
        position.x++;
        position.y++;
        position.z++;
    }

    return position;
}

void staticViewReply(App_State *app, Session_State *session, Zone_Packet_StaticViewRequest *viewReq)
{
    viewReq->viewpoint_length = (u32)strlen(viewReq->viewpoint);

    if (strcmp(viewReq->viewpoint, "kotkdefault") == 0)
    {
        Zone_Packet_StaticViewReply viewReply = {
            .state = 0,
            .position = {74.8f, 201.5f, 458.1f, 99.01f},
            .rotation = {199.99f, 289.99999f, 370.17f, 6.79f},
            .lookAt = {69.81f, 56.0f, 0.0f, 0.0f},
            .unk_byte_1 = 255,
            .unk_bool_1 = true,
        };
        zone_packet_send(app, session, &app->arena_per_tick, KB(10), Zone_Packet_Kind_StaticViewReply, &viewReply);

        Zone_Packet_ClientUpdate_UpdateLocation updateLocation = {
            .position = {-32.26f, 506.41f, 280.21f, 1.0f},
            .rotation = {-0.11f, -0.58f, -0.08f, 1.0f},
            .trigger_loading_screen = true,
            .unk_u8_1 = 0,
            .unk_bool = false,
        };
        zone_packet_send(app, session, &app->arena_per_tick, KB(10), Zone_Packet_Kind_ClientUpdate_UpdateLocation, &updateLocation);
    }
}