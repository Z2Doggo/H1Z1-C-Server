ResourceIds getResourceType(ResourceIds resourceId) 
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

struct character_resources_s* getResourceData(u32* resources, u32 numResources) {
    struct character_resources_s* result = (struct character_resources_s*)malloc(numResources * sizeof(struct character_resources_s));

    for (u32 i = 0; i < numResources; i++) {
        u32 resourceId = resources[i];
        u32 resourceType = getResourceType(resourceId);
        u32 value = resources[i] > 0 ? resources[i] : 0;

        result[i].resource_type1 = resourceType;
        result[i].resource_id = resourceId;
        result[i].resource_type2 = resourceType;
        result[i].value = value;
    };
    return result;
}

void sendSelf(App_State *app_state, Session_State *session_state)
{
 	u32 resources[] = {RESOURCE_HEALTH, RESOURCE_BLEEDING, RESOURCE_COMFORT, RESOURCE_CONDITION};
    u32 numResources = sizeof(resources) / sizeof(resources[0]);
    struct character_resources_s* resourceData = getResourceData(resources, numResources);

	Zone_Packet_SendSelfToClient send_self = 
	{ 
    .payload_self =
    (struct payload_self_s[1])
    {
        [0] = 
        { 
            .guid = session_state->guid,
            .character_id = session_state->character_id,
            .transient_id.value = session_state->transient_id.value,
            .actor_model_id = 9474,
            .head_actor_length = 26,
			.position = {74.8f, 201.5f, 458.1f, 99.01f},
			.rotation = {199.99f, 289.99999f, 370.17f, 6.79f},
            .head_actor = "SurvivorFemale_Head_02.adr",
            .hair_model_length = 32,
            .hair_model = "SurvivorFemale_Hair_ShortBun.adr",
            .is_respawning = FALSE,
            .character_name_length = 5,
            .character_name = "doggo",
            .gender1 = 2,
            .creation_date = 0x133333333,
            .last_login_date = 0x133333333,
            .loadout_id = 3,
            .loadout_slots_array_count = 1,
            .loadout_slots_array = 
			(struct loadout_slots_array_s[1]) 
			{
				[0] =
				{
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
            .equipment_slots = 
			(struct equipment_slots_s[1])
			{
				[0] =
				{
					.equipment_slot_id2 = 0,
					.equipment_slot_id3 = 0,
					.guid = 0,
					.tint_alias_length = 7,
					.tint_alias = "Default",
					.decal_alias_length = 1,
					.decal_alias = "#",
				},
			},
            .character_resources_count = numResources,
            .character_resources = resourceData,
            .containers_count = 1,
            .containers = 
			(struct containers_s[1]) 
			{
				[0] =
				{
				    .loadout_slot_id = 0,
					.guid = 0x133742069,
					.def_id = 0,
					.associated_character_id = 0x133742069,
					.slots = 0,
					.items2_count = 1,
					.items2 = 
					(struct items2_s[1]) 
					{
						[0] =
						{
							.item_def_id5 = 0,
							.item_def_id6 = 0,
							.tint_id = 0,
							.guid = 0x133742069,
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
							.unk_bool_116 = FALSE,
							.owner_character_id = 0x133742069,
							.unk_dword_9 = 0,
							.show_bulk = TRUE,
							.max_bulk = 0,
							.unk_dword_133 = 0,
							.bulk_used = 0,
							.has_bulk_limit = TRUE,
						},
					},
					},
				},
            	.is_admin = TRUE,
			}, 
        },
    };
	free(resourceData);
	// (doggo)if this packet was a person, I would beat the ever-living shit out of it!
	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(100), Zone_Packet_Kind_SendSelfToClient, &send_self);
};