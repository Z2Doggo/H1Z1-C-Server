// (doggo) just going to say this right now, this is a whole file dedicated to sending the packet "SendSelfToClient", nothing here other than the data that I send from the server to the game, also, fuck this packet!

internal void sendself_on_login(App_State *app_state, Session_State *session_state) 
{
    Zone_Packet_SendSelfToClient send_self = 
	{ 
		.payload_self =
		(struct payload_self_s[1])
		{
			[0] = 
			{ 
				.guid = session_state->character_id,
				.transient_id.value = session_state->transient_id.value,
				.actor_model_id = 9474,
				.head_actor_length = 26,
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
						.loadout_id = 3,
						.slot_id = 0,
						.item_def_id4 = 1 || 0,
						.loadout_item_guid = 0x01 || 0,
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
						.unk_dword_7199 = 0,
						.unk_dword_890 = 0,
						.equipment_slot_id2 = 0,
						.equipment_slot_id3 = 0,
						.guid = 0x0,
						.decal_alias_length = 1,
						.decal_alias = "#" },
				},
				.character_resources_count = 1,
				.character_resources =
				(struct character_resources_s[1])
				{ 	
					[0] = 
					{ 
						.resource_type1 = 1,
						.resource_id = 1,
						.resource_type2 = 1,
						.value = 10000,
					},
				},
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
						.slots = 14,
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
								.count = 14,
								.container_guid = 0x133742069,
								.container_def_id = 14,
								.container_slot_id = 0,
								.base_durability = 10,
								.current_durability = 10 ? 15 : 0,
								.max_durability_from_def = 10,
								.unk_bool_116 = TRUE,
								.owner_character_id = 0x0000000000000001,
								.unk_dword_9 = 1,
								// (doggo)put weapon data here from sendself later...
								.show_bulk = TRUE,
								.unk_dword_133 = 28,
							},
						},
					},
				},
				.is_admin = TRUE,
			},
		},
	};
    
	// (doggo)if this packet was a person, I would beat the ever-living shit out of it!
	zone_packet_send(app_state, session_state, &app_state->arena_per_tick, KB(10), Zone_Packet_Kind_SendSelfToClient, &send_self);
}