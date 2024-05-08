void OnLogin(AppState* app, SessionState* session) {
    Zone_Packet_InitializationParameters init_params = {
        .environment = "LIVE_KOTK",
        .environment_length = STRLEN("LIVE_KOTK"),
    };
    ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_InitializationParameters,
                   &init_params);

    Zone_Packet_SendZoneDetails send_zone_details = {
        .zone_name = "LoginZone",
        .zone_name_length = STRLEN("LoginZone"),
        .zone_type = 4,
        .unk_bool = false,

        .overcast = 0,
        .fogDensity = 0,
        .fogFloor = 14.8f,
        .fogGradient = 15.25f,
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
        .rainRampUpTimeSeconds = 1,
        .cloudFile = "sky_Z_Clouds.xml",
        .cloudFile_length = STRLEN("sky_Z_Clouds.xml"),
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

        .zone_id = 5,
        .zone_id_2 = 5,
        .name_id = 7699,
        .unk_bool2 = true,
        .lighting = "Lighting_Z2.txt",
        .lighting_length = STRLEN("Lighting_Z2.txt"),
        .unk_bool3 = false,
        .unk_bool4 = false,
    };
    ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_SendZoneDetails,
                   &send_zone_details);

    Zone_Packet_ClientGameSettings game_settings = {
        .interact_glow_and_dist = 16,
        .unk_bool = true,
        .timescale = 1.0,
        .enable_weapons = 1,
        .unk_u32_2 = 1,
        .unk_float2 = 15.,
        .damage_multiplier = 11.,
    };
    ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_ClientGameSettings,
                   &game_settings);

    Zone_Packet_UpdateWeatherData updt_weather_data = {
        .overcast = 0,
        .fogDensity = 0,
        .fogFloor = 14.8f,
        .fogGradient = 15.25f,
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
        .rainRampUpTimeSeconds = 1,
        .cloudFile = "sky_Z_Clouds.xml",
        .cloudFile_length = STRLEN("sky_Z_Clouds.xml"),
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
    };
    ZonePacketSend(app, session, &app->arenaPerTick, KB(10), Zone_Packet_Kind_UpdateWeatherData,
                   &updt_weather_data);

    SendSelfToClient(app, session);
}