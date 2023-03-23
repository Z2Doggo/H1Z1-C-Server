#define LOCAL_PORT         1117
#define MAX_FRAGMENTS      12000
#define MAX_PACKET_LENGTH  512
#define DATA_HEADER_LENGTH 4
#define MAX_SESSIONS_COUNT 2

#include "shared/protocol/stream.h"
#include "shared/protocol/fragment_pool.c"
#include "shared/protocol/input_stream.c"
#include "shared/protocol/output_stream.c"
#include "shared/protocol/core_protocol.h"
#include "shared/connection.h"
#include "shared/session.h"
#include "shared/packet_queue.h"
#include "shared/packet_queue.c"

global u64 global_packet_dump_count;

struct Server_State
{
	Platform_Api* platform_api;
	Memory_Arena arena_per_tick;

	Platform_Socket socket;

	u8 rc4_key_decoded[256];
	i32 rc4_key_decoded_length;
	Connection_Args connection_args;

	i32 sessions_capacity;
	Session_State sessions[MAX_SESSIONS_COUNT];
};

internal void gateway_on_login(Server_State* server_state, Session_State* session_state, u64 character_id);
internal void gateway_on_tunnel_data_from_client(Server_State* server_state, Session_State* session_state, u8* data, u32 data_length);
internal INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data);

#include "shared/protocol/core_protocol.c"
#include "game/external_gateway_api_3.c"
#include "../schema/output/client_protocol_298.c"
#include "game/client_protocol_298.c"

// TODO(rhett): hardcoded in gateway protocol for now
internal void gateway_on_login(Server_State* server_state, Session_State* session_state, u64 character_id)
{
	printf("[!] Character %llxh trying to login to zone server\n", character_id);

	Zone_Packet_InitializationParameters init_params =
	{
		.environment_length = 4,
		.environment = "LIVE",
		.unk_string_1_length = 0,
		.unk_string_1 = "",
	};

	Zone_Packet_SendZoneDetails send_zone_details =
	{
		.zone_name_length 	= 2,
		.zone_name 			= "Z1",
		.zone_type 			= 4,
		.unk_bool 			= FALSE,

		// todo: set sky_data
		.name				= "sky_Z_clouds.dds",

		.color_gradient		= 0.,
		.color_gradient		= 0.,
		.unknown_dword8		= 0.05,
		.unknown_dword10	= 0.05,
		.unknown_dword11	= 0.15,
		.wind			 	= 3,
		.unknown_dword21 	= 1,
		.unknown_dword22 	= 0.3,
		.unknown_dword23 	= -0.002,
		.unknown_dword24 	= 0,
		.unknown_dword25 	= 1000,
		.unknown_dword26 	= 0.2,
		.unknown_dword28 	= 0.002,
		.unknown_dword29 	= 8000,
		.ao_size 			= 0,
		.ao_gamma 			= 0.25,
		.ao_blackpoint 		= 7,
		.unknown_dword33 	= 0.5,

		.zone_id			= 5,
		.zone_id_2			= 5,
		.name_id			= 7699,
		.unk_bool2			= TRUE,
		.lighting			= "Lighting.txt",
		.unk_bool3			= FALSE,
	};

	Zone_Packet_CommandItemDefinitions item_defs = 
	{
		.item_def_reply_2 =
			(struct item_def_reply_2_s[1]) {
			[0] =
			{
				.item_defs_count = 1,
				.item_defs =
					(struct item_defs_s[1]) {
					[0] =
					{
						.defs_id = 0,
						
						.bitflags1 = 0,
						.bitflags2 = 0,

						.name_id = 0,
						.description_id = 0,
						.content_id = 0,
						.image_set_id = 0,
						.tint_id = 0,
						.hud_image_set_id = 0,
						.unk_dword_1 = 921,
						.unk_dword_2 = 922,
						.cost = 0,
						.item_class = 0,
						.profile_override = 0,

						.model_name_length = 0,

						.texture_alias_length = 0,

						.gender_usage = 0,
						.item_type = 0,
						.category_id = 0,
						.weapon_trail_effect_id = 0,
						.composite_effect_id = 0,
						.power_rating = 0,
						.min_profile_rank = 0,
						.rarity = 0,
						.activatable_ability_id = 0,
						.activatable_ability_set_id = 0,
						.passive_ability_id = 0,
						.passive_ability_set_id = 0,
						.max_stack_size = 0,
						.min_stack_size = 0,

						.tint_alias_length = 0,

						.tint_group_id = 0,
						.member_discount = 0,
						.vip_rank_required = 0,
						.race_set_id = 0,
						.ui_model_camera_id_1 = 0,
						.equip_count_max = 0,
						.curreny_type = 0,
						.datasheet_id = 0,
						.item_type_1 = 0,
						.skill_set_id = 0,

						.overlay_texture_length = 0,

						.decal_slot_length = 0,

						.overlay_adjustment = 0,
						.trial_duration_sec = 0,
						.next_trial_delay_sec = 0,
						.client_use_requirement = 0,

						.override_appearance_length = 0,

						.override_camera_id = 0,
						.unk_dword_3 = 28,
						.unk_dword_4 = 28,
						.unk_dword_5 = 28,
						.bulk = 0,
						.active_equip_slot_id = 0,
						.passive_equip_slot_id = 0,
						.passive_equip_slot_group_id = 0,
						.unk_dword_6 = 927,
						.grinder_reward_set_id = 0,
						.build_bar_group_id = 0,

						.unk_string_1_length = 13,
						.unk_string_1 = "testStringAAA",

						.unk_bool_1 = TRUE,
						.is_armor = FALSE,
						.unk_dword_7 = 28,
						.param1 = 0,
						.param2 = 0,
						.param3 = 0,

						.string_param1_length = 0,
							
						.ui_model_camera_id_2 = 0,
						.unk_dword_8 = 932,
						.scrap_value_override = 0,

						.stats_item_def_2_count = 1,
						.stats_item_def_2 =
							(struct stats_item_def_2_s[1]) {
							[0] =
							{
								.unk_dword_9 = 0,

								.stat_id = 0,
								.base = 0,
								.modifier = 0,

								.unk_dword_10 = 0,
							},
						},
					},
				},
			},
		},
	};

	Zone_Packet_ReferenceDataWeaponDefinitions weapon_defs =
	{
		.weapon_byteswithlength =
		(struct weapon_byteswithlength_s[1]) {
			[0] = 
			{
				.weapon_defs_count = 1,
				.weapon_defs = 
				(struct weapon_defs_s[1]) {
					[0] = 
					{
						.id1 = 0,
						.id2 = 0,
						.weapon_group_id = 0,
						.flags1 = 0,
						.equip_ms = 0,
						.unequip_ms = 0,
						.from_passive_ms = 0,
						.to_passive_ms = 0,
						.xp_category = 0,
						.to_iron_sights_ms = 0,
						.from_iron_sights_ms = 0,
						.to_iron_sights_anim_ms = 0,
						.from_iron_sights_anim_ms = 0,
						.sprint_recovery_ms = 0,
						.next_use_delay_msec = 0,
						.turn_rate_modifier = 0,
						.movement_speed_modifier = 0,
						.propulsion_type = 0,
						.heat_bleed_off_rate = 0,
						.heat_capacity = 0,
						.overheat_penalty_ms = 0,
						.range_string_id = 0,
						.melee_detect_width = 0,
						.melee_detect_height = 0,

						.anim_set_name_length = 0,

						.vehicle_fp_camera_id = 0,
						.vehicle_tp_camera_id = 0,
						.overheat_effect_id = 0,
						.min_pitch = 0,
						.max_pitch = 0,
						.audio_game_object = 0,

						.ammo_slots_count = 1,
						.ammo_slots = 
						(struct ammo_slots_s[1]) {
							[0] = 
							{
								.ammo_id = 0,
								.clip_size = 0,
								.capacity = 0,
								.start_empty = FALSE,
								.refill_ammo_per_tick = 0,
								.refill_ammo_delay_ms = 0,
								.clip_attachment_slot = 0,
								.clip_model_name_length = 0,
								.reload_weapon_bone_length = 0,
								.reload_character_bone_length = 0,
							},
						},

						.fire_groups_count = 1,
						.fire_groups = 
						(struct fire_groups_s[1]) {
							[0] = 
							{
								.fire_group_id = 0,
							},
						},
					},
				},

				.fire_group_defs_count = 1,
				.fire_group_defs = 
				(struct fire_group_defs_s[1]) {
					[0] =
					{
						.id3 = 0,
						.id4 = 0,

						.fire_mode_list_count = 1,
						.fire_mode_list = 
						(struct fire_mode_list_s[1]) {
							[0] = 
							{
								.fire_mode_1 = 0,
							},
						},

						.flags2 = 0,
						.chamber_duration_ms = 0,
						.image_set_override = 0,
						.transition_duration_ms = 0,
						.anim_actor_slot_override = 0,
						.deployable_id = 0,
						.spin_up_time_ms = 0,
						.spin_up_movement_modifier = 0,
						.spin_up_turn_rate_modifier = 0,
						.spool_up_time_ms = 0,
						.spool_up_initial_refire_ms = 0,
					},
				},

				.fire_mode_defs_count = 1,
				.fire_mode_defs =
				(struct fire_mode_defs_s[1]) {
					[0] = 
					{
						.id5 = 0,
						.id6 = 0,
						.flag1 = 0,
						.flag2 = 0,
						.flag3 = 0,
						.type = 0,
						.ammo_item_id = 0,
						.ammo_slot = 0,
						.burst_count = 0,
						.fire_duration_ms = 0,
						.fire_cooldown_duration_ms = 0,
						.refire_time_ms = 0,
						.auto_fire_time_ms = 0,
						.cook_time_ms = 0,
						.range = 0,
						.ammo_per_shot = 0,
						.reload_time_ms = 0,
						.reload_chamber_time_ms = 0,
						.reload_ammo_fill_time_ms = 0,
						.reload_loop_start_time_ms = 0,
						.reload_loop_end_time_ms = 0,
						.pellets_per_shot = 0,
						.pellet_spread = 0,
						.cof_recoil = 0,
						.cof_scalar = 0,
						.cof_scalar_moving = 0,
						.cof_override = 0,
						.recoil_angle_min = 0,
						.recoil_angle_max = 0,
						.recoil_horizontal_tolerance = 0,
						.recoil_horizontal_min = 0,
						.recoil_horizontal_max = 0,
						.recoil_magnitude_min = 0,
						.recoil_magnitude_max = 0,
						.recoil_recovery_delay_ms = 0,
						.recoil_recovery_rate = 0,
						.recoil_recovery_acceleration = 0,
						.recoil_shots_at_min_magnitude = 0,
						.recoil_max_total_magnitude = 0,
						.recoil_increase = 0,
						.recoil_increase_crouched = 0,
						.recoil_first_shot_modifier = 0,
						.recoil_horizontal_min_increase = 0,
						.recoil_horizontal_max_increase = 0,
						.fire_detect_range = 0,
						.effect_group = 0,
						.player_state_group_id = 0,
						.movement_modifier = 0,
						.turn_modifier = 0,
						.lock_on_icon_id = 0,
						.lock_on_angle = 0,
						.lock_on_radius = 0,
						.lock_on_range = 0,
						.lock_on_range_close = 0,
						.lock_on_range_far = 0,
						.lock_on_acquire_time_ms = 0,
						.lock_on_acquire_time_close_ms = 0,
						.lock_on_acquire_time_far_ms = 0,
						.lock_on_lose_time_ms = 0,
						.default_zoom = 0,
						.fp_offset_x = 0,
						.fp_offset_y = 0,
						.fp_offset_z = 0,
						.reticle_id = 0,
						.full_screen_effect = 0,
						.heat_per_shot = 0,
						.heat_threshold = 0,
						.heat_recovery_delay_ms = 0,
						.sway_amplitude_x = 0,
						.sway_amplitude_y = 0,
						.sway_period_x = 0,
						.sway_period_y = 0,
						.sway_initial_y_offset = 0,
						.arms_fov_scalar = 0,
						.anim_kick_magnitude = 0,
						.anim_recoil_magnitude = 0,
						.description_id = 0,
						.indirect_effect = 0,
						.bullet_arc_kick_angle = 0,
						.projectile_speed_override = 0,
						.inherit_from_id = 0,
						.inherit_from_charge_power = 0,
						.hud_image_id = 0,
						.target_requirement = 0,
						.fire_anim_duration_ms = 0,
						.sequential_fire_anim_start = 0,
						.sequential_fire_anim_count = 0,
						.cylof_recoil = 0,
						.cylof_scalar = 0,
						.cylof_scalar_moving = 0,
						.cylof_override = 0,
						.melee_composite_effect_id = 0,
						.melee_ability_id = 0,
						.sway_crouch_scalar = 0,
						.sway_prone_scalar = 0,
						.launch_pitch_additive_degrees = 0,
						.tp_force_camera_overrides = FALSE,
						.tp_camera_look_offset_x = 0,
						.tp_camera_look_offset_y = 0,
						.tp_camera_look_offset_z = 0,
						.tp_camera_position_offset_x = 0,
						.tp_camera_position_offset_y = 0,
						.tp_camera_position_offset_z = 0,
						.tp_camera_fov = 0,
						.fp_force_camera_overrides = FALSE,
						.tp_extra_lead_from_pitch_a = 0,
						.tp_extra_lead_from_pitch_b = 0,
						.tp_extra_lead_pitch_a = 0,
						.tp_extra_lead_pitch_b = 0,
						.tp_extra_height_from_pitch_a = 0,
						.tp_extra_height_from_pitch_b = 0,
						.tp_extra_height_pitch_a = 0,
						.tp_extra_height_pitch_b = 0,
						.fp_camera_fov = 0,
						.tp_cr_camera_look_offset_x = 0,
						.tp_cr_camera_look_offset_y = 0,
						.tp_cr_camera_look_offset_z = 0,
						.tp_cr_camera_position_offset_x = 0,
						.tp_cr_camera_position_offset_y = 0,
						.tp_cr_camera_position_offset_z = 0,
						.tp_pr_camera_look_offset_x = 0,
						.tp_pr_camera_look_offset_y = 0,
						.tp_pr_camera_look_offset_z = 0,
						.tp_pr_camera_position_offset_x = 0,
						.tp_pr_camera_position_offset_y = 0,
						.tp_pr_camera_position_offset_z = 0,
						.tp_cr_extra_lead_from_pitch_a = 0,
						.tp_cr_extra_lead_from_pitch_b = 0,
						.tp_cr_extra_lead_pitch_a = 0,
						.tp_cr_extra_lead_pitch_b = 0,
						.tp_cr_extra_height_from_pitch_a = 0,
						.tp_cr_extra_height_from_pitch_b = 0,
						.tp_cr_extra_height_pitch_a = 0,
						.tp_cr_extra_height_pitch_b = 0,
						.tp_pr_extra_lead_from_pitch_a = 0,
						.tp_pr_extra_lead_from_pitch_b = 0,
						.tp_pr_extra_lead_pitch_a = 0,
						.tp_pr_extra_lead_pitch_b = 0,
						.tp_pr_extra_height_from_pitch_a = 0,
						.tp_pr_extra_height_from_pitch_b = 0,
						.tp_pr_extra_height_pitch_a = 0,
						.tp_pr_extra_height_pitch_b = 0,
						.tp_camera_distance = 0,
						.tp_cr_camera_distance = 0,
						.tp_pr_camera_distance = 0,
						.tp_cr_camera_fov = 0,
						.tp_pr_camera_fov = 0,
						.fp_cr_camera_fov = 0,
						.fp_pr_camera_fov = 0,
						.force_fp_scope = FALSE, // note(doggo): might need to change this to TRUE later.. 
						.aim_assist_config = 0,
						.allow_depth_adjustment = FALSE,
						.tp_extra_draw_from_pitch_a = 0,
						.tp_extra_draw_from_pitch_b = 0,
						.tp_extra_draw_pitch_a = 0,
						.tp_extra_draw_pitch_b = 0,
						.tp_cr_extra_draw_from_pitch_a = 0,
						.tp_cr_extra_draw_from_pitch_b = 0,
						.tp_cr_extra_draw_pitch_a = 0,
						.tp_cr_extra_draw_pitch_b = 0,
						.tp_camera_pos_offset_y_mov = 0,
						.tp_camera_look_offset_y_mov = 0,
						.tp_cr_camera_pos_offset_y_mov = 0,
						.tp_cr_camera_look_offset_y_mov = 0,
						.tp_allow_move_heights = FALSE,
					},
				},

				.player_state_group_defs_count = 1,
				.player_state_group_defs =
				(struct player_state_group_defs_s[1]) {
					[0] =
					{
						.id7 = 0,
						._id8 = 0,

						.player_state_properties_count = 1,
						.player_state_properties =
						(struct player_state_properties_s[1]) {
							[0] = 
							{
								.group_id = 0,
								.id9 = 0,
								.flags3 = 0,
								.min_cof = 0,
								.max_cof = 0,
								.cof_recovery_rate = 0,
								.cof_turn_penalty = 0,
								.shots_before_cof_penalty = 0,
								.cof_recovery_delay_threshold = 0,
								.cof_recovery_delay_ms = 0,
								.cof_grow_rate = 0,
								.min_cyl_of_fire = 0,
								.max_cyl_of_fire = 0,
								.cylof_recovery_rate = 0,
								.cylof_turn_penalty = 0,
								.shots_before_cylof_penalty = 0,
								.cylof_recovery_delay_threshold = 0,
								.cylof_recovery_delay_ms = 0,
								.cylof_grow_rate = 0,
							},
						},
					},
				},

				.fire_mode_projectile_mapping_data_count = 1,
				.fire_mode_projectile_mapping_data =
				(struct fire_mode_projectile_mapping_data_s[1]) {
					[0] = 
					{
						.id10 = 0,
						.id11 = 0,
						.index = 0,
						.projectile_definition_id = 0,
					},
				},

				.aim_assist_defs_count = 1,
				.aim_assist_defs = 
				(struct aim_assist_defs_s[1]) {
					[0] = 
					{
						.id12 = 0,
						.cone_angle = 0,
						.cone_range = 0,
						.fall_off_cone_range = 0,
						.magnet_cone_angle = 0,
						.magnet_cone_range = 0,
						.target_override_delay = 0,
						.target_oos_delay = 0,
						.arrive_time = 0,
						.target_motion_update_time = 0,
						.weight = 0,
						.min_input_weight_delay_in = 0,
						.max_input_weight_delay_in = 0,
						.min_input_weight_delay_out = 0,
						.max_input_weight_delay_out = 0,
						.min_input_actor = 0,
						.max_input_actor = 0,
						.requirement_id = 0,
						.magnet_min_angle = 0,
						.magnet_dist_for_min_angle = 0,
						.magnet_max_angle = 0,
						.magnet_dist_for_max_angle = 0,
						.min_input_strafe_arrive_time = 0,
						.max_input_strafe_arrive_time = 0,
					},
				},
			},
		},
	};

	Zone_Packet_ClientGameSettings game_settings =
	{
		.interact_glow_and_dist 	= 16,
		.unk_bool 					= TRUE,
		.timescale 					= 1.0,
		.enable_weapons 			= 1,
		.unk_u32_2					= 1,
		.unk_float2 				= 15.,
		.damage_multiplier 			= 11.,
	};

	/*
	(doggo)todo: unfinished.. going to redo sendself

	Zone_Packet_SendSelfToClient send_self = 
	{
		.payload_self =
			(struct payload_self_s[1]) {
			[0] =
			{
				.guid_1 = 0x66778899,
				.character_id_1 = 0xaabbccdd11223344,
				.unk_uint2b.value = 52,
				.actor_model_id = 176,
				.head_actor_length = 25,
				.head_actor = "Head_Female_Caucasian.adr",
				.head_id = 5,
			},
		},
	};
	*/

	Zone_Packet_ContainerInitEquippedContainers init_equipped_containers = 
	{
		.ignore_this = 0,
		.character_id = session_state->character_id,

		.container_list_count = 1,
		.container_list = 
		(struct container_list_s[1]) {
			[0] =
			{
				.loadout_slot_id = 0,

				.guid_1 = session_state->character_id,
				.defs_id = 0,
				.associated_character_id = session_state->character_id,
				.slots = 0,

				.items_list_count = 1,
				.items_list = 
				(struct items_list_s[1]) {
					[0] = 
					{
						.item_defs_id_1 = 0,

						.item_defs_id_2 = 0,
						.tint_id = 0,
						.guid_2 = session_state->character_id,
						.count = 1,

						.unk_qword_1 = 0,
						.unk_dword_1 = 0,
						.unk_dword_2 = 0,

						.container_guid = 0,
						.contain_def_id = 0,
						.container_slot_id = 0,
						.base_durability = 0,
						.current_durability = 0,
						.max_durability_from_defs = 0,
						.unk_bool_1 = FALSE,
						.owner_character_id = session_state->character_id,
						.unk_dword_3 = 0,
					},
				},

				.show_bulk = TRUE,
				.max_bulk = 0,
				.unk_dword_4 = 0,
				.bulk_used = 0,
				.has_bulk_limit = TRUE,
			},
		},
	};

	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_InitializationParameters, &init_params);
	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_SendZoneDetails, &send_zone_details);
	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_CommandItemDefinitions, &item_defs);
	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(40), Zone_Packet_Kind_ReferenceDataWeaponDefinitions, &weapon_defs);
	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ClientGameSettings, &game_settings);
	//zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(40), Zone_Packet_Kind_SendSelfToClient, &send_self);
	zone_packet_send(server_state, session_state, &server_state->arena_per_tick, KB(10), Zone_Packet_Kind_ContainerInitEquippedContainers, &init_equipped_containers);

	//zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "1.bin");
	//zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "2.bin");
	//zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(40), "C:\\Users\\Lane\\Desktop\\send_self\\" "3.bin");
	//zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "4.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(40), "C:\\Users\\Lane\\Desktop\\send_self\\" "5.bin");
	//zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "6.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "7.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "8.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "9.bin");
	zone_packet_raw_file_send(server_state, session_state, &server_state->arena_per_tick, KB(10), "C:\\Users\\Lane\\Desktop\\send_self\\" "10.bin");
}

internal void gateway_on_tunnel_data_from_client(Server_State* server_state, Session_State* session_state, u8* data, u32 data_length)
{
	zone_packet_handle(server_state, session_state, data, data_length);
}

internal INPUT_STREAM_CALLBACK_DATA(on_ping_input_stream_data)
{
	//ping_packet_handle(server, session, data, data_length);
}

internal INPUT_STREAM_CALLBACK_ACK(on_input_stream_ack)
{
	Session_State* session_state = session;
	session_state->ack_next = ack;
}

internal INPUT_STREAM_CALLBACK_DATA(on_input_stream_data)
{
	gateway_packet_handle(server, session, data, data_length);
}

internal OUTPUT_STREAM_CALLBACK_DATA(on_output_stream_data)
{
	Server_State* server_state = server;
	Session_State* session_state = session;

	Data packet =
	{
		.sequence = (u16)sequence,
		.data = data,
		.data_length = data_length,
	};

	if (!is_fragment)
	{
		core_packet_send(server_state->socket, server_state->platform_api, session_state->address.ip, session_state->address.port, &session_state->connection_args, Core_Packet_Kind_Data, &packet);
	}
	else
	{
		core_packet_send(server_state->socket, server_state->platform_api, session_state->address.ip, session_state->address.port, &session_state->connection_args, Core_Packet_Kind_Data_Fragment, &packet);
	}
}

internal void game_tick_run(Program_State* program_state)
{
	Server_State* server_state = program_state->server_state;
	if (!server_state)
	{
		//server_state = program_state->server_state = server_state_create(&program_state->persist_arena,
		                                                                 //&program_state->platform_api);
		server_state = program_state->server_state = memory_arena_push_struct(&program_state->arena_persist,
		                                                                      Server_State);
		server_state->platform_api = program_state->platform_api;
		
		usize backing_memory_length = MB(10);
		void* backing_memory = memory_arena_push_length(&program_state->arena_persist, backing_memory_length);
		server_state->arena_per_tick = memory_arena_init(backing_memory, backing_memory_length, "Tick");

		u8 rc4_key_encoded[] = "F70IaxuU8C/w7FPXY1ibXw==";
		server_state->rc4_key_decoded_length = util_base64_decode((u8*)rc4_key_encoded, sizeof(rc4_key_encoded) - 1, server_state->rc4_key_decoded);

		server_state->connection_args.crc_seed 		= 0;
		server_state->connection_args.crc_length 	= 0;
		server_state->connection_args.udp_length 	= MAX_PACKET_LENGTH;
		server_state->connection_args.encryption	= FALSE;
		
		server_state->sessions_capacity = MAX_SESSIONS_COUNT;
		server_state->socket = server_state->platform_api->socket_udp_create_and_bind(program_state->platform_state, LOCAL_PORT);
		printf("[*] Game server socket bound to port " STRINGIFY(LOCAL_PORT) "\n\n");
		server_state->platform_api->folder_create("packets");
	}


	u8 incoming_buffer[MAX_PACKET_LENGTH] = { 0 };
	u32 from_ip;
	u16 from_port;
	i32 receive_result = server_state->platform_api->receive_from(
		server_state->socket,
		incoming_buffer,
		MAX_PACKET_LENGTH,
		&from_ip,
		&from_port
	);

	if (receive_result)
	{

		Session_Address incoming_session_address =
		{
			.ip = from_ip,
			.port = from_port,
		};

		// TODO(rhett): will need cleaned up
		i32 first_free_session = -1;
		i32 known_session = -1;
		for (i32 i = 0; i < server_state->sessions_capacity; i++)
		{
			if (first_free_session == -1 && !server_state->sessions[i].address.full)
			{
				first_free_session = i;
			}

			if (known_session == -1 && incoming_session_address.full == server_state->sessions[i].address.full)
			{
				known_session = i;
			}

			if (first_free_session != -1 && known_session != -1)
			{
				break;
			}
		}

		if (core_packet_get_kind(incoming_buffer, receive_result) == Core_Packet_Kind_Session_Request)
		{
			if (known_session != -1)
			{
				printf("[*] Known client %u.%u.%u.%u:%u re-sent SessionRequest\n",
					(from_ip & 0xff000000) >> 24,
					(from_ip & 0x00ff0000) >> 16,
					(from_ip & 0x0000ff00) >> 8,
					(from_ip & 0x000000ff),
					from_port
				);
			}
			else
			{
				printf("[*] Unknown client %u.%u.%u.%u:%u sent SessionRequest. Beginning session\n",
					(from_ip & 0xff000000) >> 24,
					(from_ip & 0x00ff0000) >> 16,
					(from_ip & 0x0000ff00) >> 8,
					(from_ip & 0x000000ff),
					from_port
				);

				if (first_free_session == -1)
				{
					printf("[!] No free sessions avaliable\n");
				}
				else
				{
					known_session = first_free_session;
					server_state->sessions[first_free_session].address.full = incoming_session_address.full;
					server_state->sessions[first_free_session].ack_next = -1;
					server_state->sessions[first_free_session].ack_previous = -1;

					util_memory_copy(
						(void*)&server_state->sessions[first_free_session].connection_args,
						(void*)&server_state->connection_args,
						sizeof(server_state->connection_args)
						);

					// TODO(rhett): These fragment pools will leak memory. this whole system needs refactored
					server_state->sessions[first_free_session].input_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
					                                                                                      MAX_PACKET_LENGTH,
					                                                                                      &program_state->arena_persist);
					server_state->sessions[first_free_session].output_fragment_pool = fragment_pool_create(MAX_FRAGMENTS,
					                                                                                       MAX_PACKET_LENGTH - DATA_HEADER_LENGTH,
					                                                                                       &program_state->arena_persist);
					server_state->sessions[first_free_session].input_stream = input_stream_init(&server_state->sessions[first_free_session].input_fragment_pool,
					                                                                            server_state->rc4_key_decoded,
					                                                                            server_state->rc4_key_decoded_length,
					                                                                            FALSE);
					server_state->sessions[first_free_session].output_stream = output_stream_init(&server_state->sessions[first_free_session].output_fragment_pool,
					                                                                              server_state->rc4_key_decoded,
					                                                                              server_state->rc4_key_decoded_length,
					                                                                              FALSE);

					server_state->sessions[first_free_session].input_stream.ack_callback = on_input_stream_ack;
					server_state->sessions[first_free_session].input_stream.data_callback = on_input_stream_data;
					server_state->sessions[first_free_session].output_stream.data_callback = on_output_stream_data;
				}
			}
		}

		if (known_session != -1)
		{
			if (server_state->sessions[known_session].kind == Session_Kind_Ping_Responder)
			{
				//ping_packet_handle(server_state,
				                   //&server_state->sessions[known_session],
				                   //incoming_buffer,
				                   //receive_result);
			}
			else
			{
				core_packet_handle(server_state, server_state->platform_api, &server_state->sessions[known_session], incoming_buffer, receive_result, FALSE);
			}

			if (server_state->sessions[known_session].ack_previous != server_state->sessions[known_session].ack_next)
			{
				server_state->sessions[known_session].ack_previous = server_state->sessions[known_session].ack_next;

				Ack ack =
				{
					.sequence = (u16)server_state->sessions[known_session].ack_next
				};

				core_packet_send(server_state->socket,
				                 server_state->platform_api,
				                 server_state->sessions[known_session].address.ip,
				                 server_state->sessions[known_session].address.port,
				                 &server_state->sessions[known_session].connection_args,
				                 Core_Packet_Kind_Ack,
				                 &ack);
			}
		}
		
		////// TODO(rhett): SHELVING THIS FOR NOW
		// TODO(rhett): think about when we should process our packet queue
		// TODO(rhett): we also should have a way to time this,
		//              probably through the platform api
		// TODO(rhett): processing one normal packet per tick for now
		//if (server_state->packet_queue.entries_tail > 0)
		//{
			//packet_queue_pop_and_send(&server_state->packet_queue,
			     //                     server_state);
			     //                     //&server_state->arena_per_frame,
			     //                     //server_state->server_packet_send);
//
			////Packet_Queue_Entry normal_packet_entry = packet_queue_pop(&server_state->packet_queue);
			////zone_packet_send(server_state,
								//			//normal_packet_entry.session_state,
								//			//&server_state->arena_per_frame,
								//			//normal_packet_entry.max_packed_length,
								//			//normal_packet_entry.packet_kind,
								//			//server_state->packet_queue.buffer + normal_packet_entry.buffer_offset);
		//}
	}

	memory_arena_reset(&server_state->arena_per_tick);
}
