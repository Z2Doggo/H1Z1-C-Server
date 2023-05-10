internal 
char* lightweight_get_head_actor(u32 model_id) {
    switch (model_id) {
        case 9240:
            return "SurvivorMale_Head_01.adr";
        case 9474:
            return "SurvivorFemale_Head_01.adr";
        case 9510: {
            i32 r = rand() % 2 + 1;
            char* result = (char*)malloc(sizeof(char) * 25);
            sprintf(result, "ZombieFemale_Head_0%d.adr", r);
            return result;
        }
        case 9634: {
            i32 r = rand() % 3 + 1;
            char* result = (char*)malloc(sizeof(char) * 25);
            sprintf(result, "ZombieMale_Head_0%d.adr", r);
            return result;
        }
        default:
            return "";
    }
}

internal 
Zone_Packet_AddLightweightNpc lightweight_spawn_npc(u32 model_id, vec3 position)
{
    char* actor_name = lightweight_get_head_actor(model_id);

    Zone_Packet_AddLightweightNpc lightweightnpc =
	{
		.characterId 			= timer,            // todo: server func to generate and store id
		.transientId 			= 1,                // todo: server func to generate and store id
		.scale 					= { 1, 1, 1, 1},
		.rotation 				= { 0, 0, 0, 0 },
		.position_x 			= position.x,
		.position_y 			= position.y + 10,
		.position_z 			= position.z,
		.unknownFloatVector4 	= { 1, 1, 1, 1 },
		.isLightweight 			= TRUE,
		.actorModelId 			= model_id,
		.headActor_length 		= 26,
		.headActor 				= actor_name,
	};
}