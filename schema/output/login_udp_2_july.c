#define LOGIN_LOGINREQUEST_ID 0x1
#define LOGIN_LOGINREPLY_ID 0x2
#define LOGIN_LOGOUT_ID 0x3
#define LOGIN_FORCEDISCONNECT_ID 0x4
#define LOGIN_CHARACTERCREATEREQUEST_ID 0x5
#define LOGIN_CHARACTERCREATEREPLY_ID 0x6
#define LOGIN_CHARACTERLOGINREQUEST_ID 0x7
#define LOGIN_CHARACTERLOGINREPLY_ID 0x8
#define LOGIN_CHARACTERDELETEREQUEST_ID 0x9
#define LOGIN_TUNNELAPPPACKETCLIENTTOSERVER_ID 0x10
#define LOGIN_TUNNELAPPPACKETSERVERTOCLIENT_ID 0x11
#define LOGIN_CHARACTERTRANSFERREQUEST_ID 0x12
#define LOGIN_CHARACTERTRANSFERREPLY_ID 0x13
#define LOGIN_CHARACTERDELETEREPLY_ID 0xa
#define LOGIN_CHARACTERSELECTINFOREQUEST_ID 0xb
#define LOGIN_CHARACTERSELECTINFOREPLY_ID 0xc
#define LOGIN_SERVERLISTREQUEST_ID 0xd
#define LOGIN_SERVERLISTREPLY_ID 0xe
#define LOGIN_SERVERUPDATE_ID 0xf

#define LOGIN_PACKET_KINDS \
LOGIN_PACKET_KIND(Login_Packet_Kind_Unhandled, "Unhandled"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_LoginRequest, "LoginRequest"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_LoginReply, "LoginReply"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_Logout, "Logout"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_ForceDisconnect, "ForceDisconnect"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterCreateRequest, "CharacterCreateRequest"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterCreateReply, "CharacterCreateReply"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterLoginRequest, "CharacterLoginRequest"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterLoginReply, "CharacterLoginReply"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterDeleteRequest, "CharacterDeleteRequest"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_TunnelAppPacketClientToServer, "TunnelAppPacketClientToServer"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_TunnelAppPacketServerToClient, "TunnelAppPacketServerToClient"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterTransferRequest, "CharacterTransferRequest"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterTransferReply, "CharacterTransferReply"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterDeleteReply, "CharacterDeleteReply"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterSelectInfoRequest, "CharacterSelectInfoRequest"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_CharacterSelectInfoReply, "CharacterSelectInfoReply"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_ServerListRequest, "ServerListRequest"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_ServerListReply, "ServerListReply"), \
LOGIN_PACKET_KIND(Login_Packet_Kind_ServerUpdate, "ServerUpdate"), \
LOGIN_PACKET_KIND(Login_Packet_Kind__End, "")

typedef enum Login_Packet_Kind
{
#define LOGIN_PACKET_KIND(e, s) e
LOGIN_PACKET_KINDS
#undef LOGIN_PACKET_KIND
} Login_Packet_Kind;

char* login_packet_names[Login_Packet_Kind__End + 1] =
{
#define LOGIN_PACKET_KIND(e, s) s
LOGIN_PACKET_KINDS
#undef LOGIN_PACKET_KIND
};


u32 login_registered_ids[] =
{
[Login_Packet_Kind_LoginRequest] = 0x1,
[Login_Packet_Kind_LoginReply] = 0x2,
[Login_Packet_Kind_Logout] = 0x3,
[Login_Packet_Kind_ForceDisconnect] = 0x4,
[Login_Packet_Kind_CharacterCreateRequest] = 0x5,
[Login_Packet_Kind_CharacterCreateReply] = 0x6,
[Login_Packet_Kind_CharacterLoginRequest] = 0x7,
[Login_Packet_Kind_CharacterLoginReply] = 0x8,
[Login_Packet_Kind_CharacterDeleteRequest] = 0x9,
[Login_Packet_Kind_TunnelAppPacketClientToServer] = 0x10,
[Login_Packet_Kind_TunnelAppPacketServerToClient] = 0x11,
[Login_Packet_Kind_CharacterTransferRequest] = 0x12,
[Login_Packet_Kind_CharacterTransferReply] = 0x13,
[Login_Packet_Kind_CharacterDeleteReply] = 0xa,
[Login_Packet_Kind_CharacterSelectInfoRequest] = 0xb,
[Login_Packet_Kind_CharacterSelectInfoReply] = 0xc,
[Login_Packet_Kind_ServerListRequest] = 0xd,
[Login_Packet_Kind_ServerListReply] = 0xe,
[Login_Packet_Kind_ServerUpdate] = 0xf,
};


typedef struct Login_Packet_LoginRequest Login_Packet_LoginRequest;
struct Login_Packet_LoginRequest
{
u32 session_id_length;
char* session_id;
u32 system_fingerprint_length;
char* system_fingerprint;
u32 locale;
u32 third_party_auth_ticket;
u32 third_party_user_id;
u32 third_party_id;
};


typedef struct Login_Packet_LoginReply Login_Packet_LoginReply;
struct Login_Packet_LoginReply
{
b8 is_logged_in;
u32 status;
u32 result_code;
b8 is_member;
b8 is_internal;
u32 namespace_name_length;
char* namespace_name;
u32 account_features_count;
struct account_features_s
{
u32 key;
u32 id;
b8 active;
u32 remaining_count;
u32 raw_data_length;
u8* raw_data;
}* account_features;
u32 application_payload_length;
u8* application_payload;
u32 error_details_count;
struct error_details_s
{
u32 unknown_dword1;
u32 name_length;
char* name;
u32 value_length;
char* value;
}* error_details;
u32 ip_country_code_length;
char* ip_country_code;
};


typedef struct Login_Packet_CharacterCreateRequest Login_Packet_CharacterCreateRequest;
struct Login_Packet_CharacterCreateRequest
{
u32 server_id;
u32 unk_u32;
u32 payload_length;
struct payload_s
{
b8 empire_id;
u32 head_type;
u32 profile_type;
u32 gender;
u32 character_name_length;
char* character_name;
}* payload;
};


typedef struct Login_Packet_CharacterCreateReply Login_Packet_CharacterCreateReply;
struct Login_Packet_CharacterCreateReply
{
u32 status;
u64 character_id;
};


typedef struct Login_Packet_CharacterLoginRequest Login_Packet_CharacterLoginRequest;
struct Login_Packet_CharacterLoginRequest
{
u64 character_id;
u32 server_id;
u32 status;
u32 payload2_length;
struct payload2_s
{
u32 locale_length;
char* locale;
u32 locale_id;
u32 preferred_gateway_id;
}* payload2;
};


typedef struct Login_Packet_CharacterLoginReply Login_Packet_CharacterLoginReply;
struct Login_Packet_CharacterLoginReply
{
u64 character_id;
u32 server_id;
u32 last_login;
u32 status;
u32 login_payload_length;
struct login_payload_s
{
u32 server_address_length;
char* server_address;
u32 server_ticket_length;
char* server_ticket;
u32 encryption_key_length;
u8* encryption_key;
u32 soe_protocol_version;
u64 character_id;
u64 unk_u64;
u32 station_name_length;
char* station_name;
u32 character_name_length;
char* character_name;
u32 unk_str_length;
char* unk_str;
u64 server_feature_bit;
}* login_payload;
};


typedef struct Login_Packet_CharacterDeleteRequest Login_Packet_CharacterDeleteRequest;
struct Login_Packet_CharacterDeleteRequest
{
u64 character_id;
};


typedef struct Login_Packet_TunnelAppPacketClientToServer Login_Packet_TunnelAppPacketClientToServer;
struct Login_Packet_TunnelAppPacketClientToServer
{
u32 server_id;
u32 unk1;
u32 data_client_length;
struct data_client_s
{
b8 tunnel_op_code;
b8 sub_op_code;
u32 character_name_length;
char* character_name;
}* data_client;
};


typedef struct Login_Packet_TunnelAppPacketServerToClient Login_Packet_TunnelAppPacketServerToClient;
struct Login_Packet_TunnelAppPacketServerToClient
{
u32 server_id;
u32 unk1;
u32 data_server_length;
struct data_server_s
{
b8 tunnel_op_code;
b8 sub_op_code;
u32 character_name_length;
char* character_name;
u32 character_name2_length;
char* character_name2;
u32 status;
}* data_server;
};


typedef struct Login_Packet_CharacterDeleteReply Login_Packet_CharacterDeleteReply;
struct Login_Packet_CharacterDeleteReply
{
u64 character_id;
u32 status;
u32 payload3_length;
u8* payload3;
};


typedef struct Login_Packet_CharacterSelectInfoReply Login_Packet_CharacterSelectInfoReply;
struct Login_Packet_CharacterSelectInfoReply
{
u32 character_status;
b8 can_bypass_server_lock;
u32 characters_count;
struct characters_s
{
u64 character_id;
u32 server_id;
u64 last_login_date;
u32 null_field;
u32 status;
u32 payload4_length;
struct payload4_s
{
u32 name_length;
char* name;
u8 empire_id;
u32 battle_rank;
u32 next_battle_rank_percent;
u32 head_id;
u32 model_id;
u32 gender;
u32 profile_id;
u32 unknown_dword;
u32 loadout_id;
u32 unknown_dword_1;
u8 unknown_byte_1;
u32 unknown_dword_2;
u32 unknown_dword_3;
u32 loadout_name_length;
char* loadout_name;
u32 tint_item_id;
u32 unknown_dword_4;
u32 decal_item_id;
u32 loadout_slots_count;
struct loadout_slots_s
{
u32 slot_id;
u32 index;
u32 item_line_id;
u8 flags;
u32 attachments_count;
struct attachments_s
{
u32 attachment_id;
}* attachments;
u32 attachment_classes_count;
struct attachment_classes_s
{
u32 class_id;
u32 attachment_id;
}* attachment_classes;
u32 tint_item_id;
u32 item_slot;
}* loadout_slots;
u32 item_definitions_count;
struct item_definitions_s
{
u32 item_id;
u32 item_id_2;
u8 flags_1;
u8 flags_2;
u32 name_id;
u32 description_id;
u32 unknown_dword_1;
u32 icon_id;
u32 unknown_dword_2;
u32 hudImageSetId;
u32 hud_image_set_id;
u32 unknown_dword_4;
u32 cost;
u32 item_class;
u32 unknown_dword_5;
u32 item_slot;
u32 slot_override_key;
u8 unknown_dword6;
u32 model_name_length;
char* model_name;
u32 unknown_string_length;
char* unknown_string;
u8 unknown_byte_1;
u32 item_type;
u32 category_id;
u32 unknown_dword_7;
u32 unknown_dword_8;
u32 unknown_dword_9;
u32 unknown_dword_10;
u32 unknown_dword_11;
u32 activatable_ability_id;
u32 passive_ability_id;
u32 unknown_dword_12;
u32 max_stack_size;
u32 tint_name_length;
char* tint_name;
u32 unknown_dword_13;
u32 unknown_dword_14;
u32 unknown_dword_15;
u32 unknown_dword_16;
u32 ui_model_camera;
u32 equip_count_max;
u32 currency_type;
u32 unknown_dword_17;
u32 client_item_type;
u32 skill_set_id;
u32 overlay_texture_length;
char* overlay_texture;
u32 decal_slot_length;
char* decal_slot;
u32 unknown_dword_18;
u32 trial_duration_sec;
u32 trial_exclusion_sec;
u32 client_use_requirement_id;
u32 override_appearance_length;
char* override_appearance;
u32 unknown_dword_19;
u32 client_use_requirement_id_2;
}* item_definitions;
u32 attachment_definitions_count;
struct attachment_definitions_s
{
u32 attachment_id;
u32 attachment_id_2;
u32 group_id;
u32 item_line_id;
u32 flags;
u32 classes_count;
struct classes_s
{
u32 element_type;
}* classes;
}* attachment_definitions;
u64 last_use_date;
}* payload4;
}* characters;
};


typedef struct Login_Packet_ServerListReply Login_Packet_ServerListReply;
struct Login_Packet_ServerListReply
{
u32 servers_count;
struct servers_s
{
u32 id;
u32 state;
b8 is_locked;
u32 name_length;
char* name;
u32 name_id;
u32 description_length;
char* description;
u32 description_id;
u32 req_feature_id;
u32 server_info_length;
char* server_info;
u32 population_level;
u32 population_data_length;
char* population_data;
u32 access_expression_length;
char* access_expression;
b8 is_access_allowed;
}* servers;
};


internal u32
login_packet_pack(Login_Packet_Kind packet_kind, void* packet_ptr, u8* buffer)
{
u32 offset = 0;

printf("\n");
switch(packet_kind)
{
case Login_Packet_Kind_LoginRequest:
{
printf("[*] Packing LoginRequest...\n");
Login_Packet_LoginRequest* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x1);
offset += sizeof(u8);

// string session_id
endian_write_u32_little(buffer + offset, packet->session_id_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->session_id_length, (u64)packet->session_id_length, (f64)packet->session_id_length);
for (u32 session_id_iter = 0; session_id_iter < packet->session_id_length; session_id_iter++)
{
endian_write_i8_little(buffer + offset, packet->session_id[session_id_iter]);
offset++;
}

// string system_fingerprint
endian_write_u32_little(buffer + offset, packet->system_fingerprint_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->system_fingerprint_length, (u64)packet->system_fingerprint_length, (f64)packet->system_fingerprint_length);
for (u32 system_fingerprint_iter = 0; system_fingerprint_iter < packet->system_fingerprint_length; system_fingerprint_iter++)
{
endian_write_i8_little(buffer + offset, packet->system_fingerprint[system_fingerprint_iter]);
offset++;
}

// u32 locale
endian_write_u32_little(buffer + offset, packet->locale);
offset += sizeof(u32);
printf("-- locale                  \t%lld\t%llxh\t%f\n", (i64)packet->locale, (u64)packet->locale, (f64)packet->locale);

// u32 third_party_auth_ticket
endian_write_u32_little(buffer + offset, packet->third_party_auth_ticket);
offset += sizeof(u32);
printf("-- third_party_auth_ticket \t%lld\t%llxh\t%f\n", (i64)packet->third_party_auth_ticket, (u64)packet->third_party_auth_ticket, (f64)packet->third_party_auth_ticket);

// u32 third_party_user_id
endian_write_u32_little(buffer + offset, packet->third_party_user_id);
offset += sizeof(u32);
printf("-- third_party_user_id     \t%lld\t%llxh\t%f\n", (i64)packet->third_party_user_id, (u64)packet->third_party_user_id, (f64)packet->third_party_user_id);

// u32 third_party_id
endian_write_u32_little(buffer + offset, packet->third_party_id);
offset += sizeof(u32);
printf("-- third_party_id          \t%lld\t%llxh\t%f\n", (i64)packet->third_party_id, (u64)packet->third_party_id, (f64)packet->third_party_id);

} break;

case Login_Packet_Kind_LoginReply:
{
printf("[*] Packing LoginReply...\n");
Login_Packet_LoginReply* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x2);
offset += sizeof(u8);

// b8 is_logged_in
endian_write_b8_little(buffer + offset, packet->is_logged_in);
offset += sizeof(b8);
printf("-- is_logged_in            \t%lld\t%llxh\t%f\n", (i64)packet->is_logged_in, (u64)packet->is_logged_in, (f64)packet->is_logged_in);

// u32 status
endian_write_u32_little(buffer + offset, packet->status);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// u32 result_code
endian_write_u32_little(buffer + offset, packet->result_code);
offset += sizeof(u32);
printf("-- result_code             \t%lld\t%llxh\t%f\n", (i64)packet->result_code, (u64)packet->result_code, (f64)packet->result_code);

// b8 is_member
endian_write_b8_little(buffer + offset, packet->is_member);
offset += sizeof(b8);
printf("-- is_member               \t%lld\t%llxh\t%f\n", (i64)packet->is_member, (u64)packet->is_member, (f64)packet->is_member);

// b8 is_internal
endian_write_b8_little(buffer + offset, packet->is_internal);
offset += sizeof(b8);
printf("-- is_internal             \t%lld\t%llxh\t%f\n", (i64)packet->is_internal, (u64)packet->is_internal, (f64)packet->is_internal);

// string namespace_name
endian_write_u32_little(buffer + offset, packet->namespace_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->namespace_name_length, (u64)packet->namespace_name_length, (f64)packet->namespace_name_length);
for (u32 namespace_name_iter = 0; namespace_name_iter < packet->namespace_name_length; namespace_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->namespace_name[namespace_name_iter]);
offset++;
}

// list account_features
endian_write_u32_little(buffer + offset, packet->account_features_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->account_features_count, (u64)packet->account_features_count, (f64)packet->account_features_count);

for (u32 account_features_iter = 0; account_features_iter < packet->account_features_count; account_features_iter++)
{
// u32 key
endian_write_u32_little(buffer + offset, packet->account_features[account_features_iter].key);
offset += sizeof(u32);
printf("-- key                     \t%lld\t%llxh\t%f\n", (i64)packet->account_features[account_features_iter].key, (u64)packet->account_features[account_features_iter].key, (f64)packet->account_features[account_features_iter].key);

// u32 id
endian_write_u32_little(buffer + offset, packet->account_features[account_features_iter].id);
offset += sizeof(u32);
printf("-- id                      \t%lld\t%llxh\t%f\n", (i64)packet->account_features[account_features_iter].id, (u64)packet->account_features[account_features_iter].id, (f64)packet->account_features[account_features_iter].id);

// b8 active
endian_write_b8_little(buffer + offset, packet->account_features[account_features_iter].active);
offset += sizeof(b8);
printf("-- active                  \t%lld\t%llxh\t%f\n", (i64)packet->account_features[account_features_iter].active, (u64)packet->account_features[account_features_iter].active, (f64)packet->account_features[account_features_iter].active);

// u32 remaining_count
endian_write_u32_little(buffer + offset, packet->account_features[account_features_iter].remaining_count);
offset += sizeof(u32);
printf("-- remaining_count         \t%lld\t%llxh\t%f\n", (i64)packet->account_features[account_features_iter].remaining_count, (u64)packet->account_features[account_features_iter].remaining_count, (f64)packet->account_features[account_features_iter].remaining_count);

// bytes raw_data
endian_write_u32_little(buffer + offset, packet->account_features[account_features_iter].raw_data_length);
offset += sizeof(u32);
printf("-- BYTES_LENGTH            \t%lld\t%llxh\t%f\n", (i64)packet->account_features[account_features_iter].raw_data_length, (u64)packet->account_features[account_features_iter].raw_data_length, (f64)packet->account_features[account_features_iter].raw_data_length);
for (u32 raw_data_iter = 0; raw_data_iter < packet->account_features[account_features_iter].raw_data_length; raw_data_iter++)
{
endian_write_u8_little(buffer + offset, packet->account_features[account_features_iter].raw_data[raw_data_iter]);
offset++;
}

} // account_features

// bytes application_payload
endian_write_u32_little(buffer + offset, packet->application_payload_length);
offset += sizeof(u32);
printf("-- BYTES_LENGTH            \t%lld\t%llxh\t%f\n", (i64)packet->application_payload_length, (u64)packet->application_payload_length, (f64)packet->application_payload_length);
for (u32 application_payload_iter = 0; application_payload_iter < packet->application_payload_length; application_payload_iter++)
{
endian_write_u8_little(buffer + offset, packet->application_payload[application_payload_iter]);
offset++;
}

// list error_details
endian_write_u32_little(buffer + offset, packet->error_details_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->error_details_count, (u64)packet->error_details_count, (f64)packet->error_details_count);

for (u32 error_details_iter = 0; error_details_iter < packet->error_details_count; error_details_iter++)
{
// u32 unknown_dword1
endian_write_u32_little(buffer + offset, packet->error_details[error_details_iter].unknown_dword1);
offset += sizeof(u32);
printf("-- unknown_dword1          \t%lld\t%llxh\t%f\n", (i64)packet->error_details[error_details_iter].unknown_dword1, (u64)packet->error_details[error_details_iter].unknown_dword1, (f64)packet->error_details[error_details_iter].unknown_dword1);

// string name
endian_write_u32_little(buffer + offset, packet->error_details[error_details_iter].name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->error_details[error_details_iter].name_length, (u64)packet->error_details[error_details_iter].name_length, (f64)packet->error_details[error_details_iter].name_length);
for (u32 name_iter = 0; name_iter < packet->error_details[error_details_iter].name_length; name_iter++)
{
endian_write_i8_little(buffer + offset, packet->error_details[error_details_iter].name[name_iter]);
offset++;
}

// string value
endian_write_u32_little(buffer + offset, packet->error_details[error_details_iter].value_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->error_details[error_details_iter].value_length, (u64)packet->error_details[error_details_iter].value_length, (f64)packet->error_details[error_details_iter].value_length);
for (u32 value_iter = 0; value_iter < packet->error_details[error_details_iter].value_length; value_iter++)
{
endian_write_i8_little(buffer + offset, packet->error_details[error_details_iter].value[value_iter]);
offset++;
}

} // error_details

// string ip_country_code
endian_write_u32_little(buffer + offset, packet->ip_country_code_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->ip_country_code_length, (u64)packet->ip_country_code_length, (f64)packet->ip_country_code_length);
for (u32 ip_country_code_iter = 0; ip_country_code_iter < packet->ip_country_code_length; ip_country_code_iter++)
{
endian_write_i8_little(buffer + offset, packet->ip_country_code[ip_country_code_iter]);
offset++;
}

} break;

case Login_Packet_Kind_Logout:
{
printf("[*] Packing Logout...\n");
endian_write_u8_little(buffer + offset, 0x3);
offset += sizeof(u8);

} break;

case Login_Packet_Kind_ForceDisconnect:
{
printf("[*] Packing ForceDisconnect...\n");
endian_write_u8_little(buffer + offset, 0x4);
offset += sizeof(u8);

} break;

case Login_Packet_Kind_CharacterCreateRequest:
{
printf("[*] Packing CharacterCreateRequest...\n");
Login_Packet_CharacterCreateRequest* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x5);
offset += sizeof(u8);

// u32 server_id
endian_write_u32_little(buffer + offset, packet->server_id);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 unk_u32
endian_write_u32_little(buffer + offset, packet->unk_u32);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// stream payload
void* payload_length_ptr = buffer + offset;
offset += sizeof(u32);
printf("-- STREAM_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->payload_length, (u64)packet->payload_length, (f64)packet->payload_length);

u32 will_pack_payload = packet->payload_length == ~(u32)0 ? 0 : 1;
for (u32 payload_iter = 0; payload_iter < will_pack_payload; payload_iter++)
{
// b8 empire_id
endian_write_b8_little(buffer + offset, packet->payload[payload_iter].empire_id);
offset += sizeof(b8);
printf("-- empire_id               \t%lld\t%llxh\t%f\n", (i64)packet->payload[payload_iter].empire_id, (u64)packet->payload[payload_iter].empire_id, (f64)packet->payload[payload_iter].empire_id);

// u32 head_type
endian_write_u32_little(buffer + offset, packet->payload[payload_iter].head_type);
offset += sizeof(u32);
printf("-- head_type               \t%lld\t%llxh\t%f\n", (i64)packet->payload[payload_iter].head_type, (u64)packet->payload[payload_iter].head_type, (f64)packet->payload[payload_iter].head_type);

// u32 profile_type
endian_write_u32_little(buffer + offset, packet->payload[payload_iter].profile_type);
offset += sizeof(u32);
printf("-- profile_type            \t%lld\t%llxh\t%f\n", (i64)packet->payload[payload_iter].profile_type, (u64)packet->payload[payload_iter].profile_type, (f64)packet->payload[payload_iter].profile_type);

// u32 gender
endian_write_u32_little(buffer + offset, packet->payload[payload_iter].gender);
offset += sizeof(u32);
printf("-- gender                  \t%lld\t%llxh\t%f\n", (i64)packet->payload[payload_iter].gender, (u64)packet->payload[payload_iter].gender, (f64)packet->payload[payload_iter].gender);

// string character_name
endian_write_u32_little(buffer + offset, packet->payload[payload_iter].character_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->payload[payload_iter].character_name_length, (u64)packet->payload[payload_iter].character_name_length, (f64)packet->payload[payload_iter].character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->payload[payload_iter].character_name_length; character_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->payload[payload_iter].character_name[character_name_iter]);
offset++;
}

} // payload
endian_write_u32_little((u8*)payload_length_ptr, (u32)((uptr)buffer + (uptr)offset - (uptr)payload_length_ptr - sizeof(u32)));

} break;

case Login_Packet_Kind_CharacterCreateReply:
{
printf("[*] Packing CharacterCreateReply...\n");
Login_Packet_CharacterCreateReply* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x6);
offset += sizeof(u8);

// u32 status
endian_write_u32_little(buffer + offset, packet->status);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

} break;

case Login_Packet_Kind_CharacterLoginRequest:
{
printf("[*] Packing CharacterLoginRequest...\n");
Login_Packet_CharacterLoginRequest* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x7);
offset += sizeof(u8);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 server_id
endian_write_u32_little(buffer + offset, packet->server_id);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 status
endian_write_u32_little(buffer + offset, packet->status);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// stream payload2
void* payload2_length_ptr = buffer + offset;
offset += sizeof(u32);
printf("-- STREAM_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->payload2_length, (u64)packet->payload2_length, (f64)packet->payload2_length);

u32 will_pack_payload2 = packet->payload2_length == ~(u32)0 ? 0 : 1;
for (u32 payload2_iter = 0; payload2_iter < will_pack_payload2; payload2_iter++)
{
// string locale
endian_write_u32_little(buffer + offset, packet->payload2[payload2_iter].locale_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->payload2[payload2_iter].locale_length, (u64)packet->payload2[payload2_iter].locale_length, (f64)packet->payload2[payload2_iter].locale_length);
for (u32 locale_iter = 0; locale_iter < packet->payload2[payload2_iter].locale_length; locale_iter++)
{
endian_write_i8_little(buffer + offset, packet->payload2[payload2_iter].locale[locale_iter]);
offset++;
}

// u32 locale_id
endian_write_u32_little(buffer + offset, packet->payload2[payload2_iter].locale_id);
offset += sizeof(u32);
printf("-- locale_id               \t%lld\t%llxh\t%f\n", (i64)packet->payload2[payload2_iter].locale_id, (u64)packet->payload2[payload2_iter].locale_id, (f64)packet->payload2[payload2_iter].locale_id);

// u32 preferred_gateway_id
endian_write_u32_little(buffer + offset, packet->payload2[payload2_iter].preferred_gateway_id);
offset += sizeof(u32);
printf("-- preferred_gateway_id    \t%lld\t%llxh\t%f\n", (i64)packet->payload2[payload2_iter].preferred_gateway_id, (u64)packet->payload2[payload2_iter].preferred_gateway_id, (f64)packet->payload2[payload2_iter].preferred_gateway_id);

} // payload2
endian_write_u32_little((u8*)payload2_length_ptr, (u32)((uptr)buffer + (uptr)offset - (uptr)payload2_length_ptr - sizeof(u32)));

} break;

case Login_Packet_Kind_CharacterLoginReply:
{
printf("[*] Packing CharacterLoginReply...\n");
Login_Packet_CharacterLoginReply* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x8);
offset += sizeof(u8);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 server_id
endian_write_u32_little(buffer + offset, packet->server_id);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 last_login
endian_write_u32_little(buffer + offset, packet->last_login);
offset += sizeof(u32);
printf("-- last_login              \t%lld\t%llxh\t%f\n", (i64)packet->last_login, (u64)packet->last_login, (f64)packet->last_login);

// u32 status
endian_write_u32_little(buffer + offset, packet->status);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// stream login_payload
void* login_payload_length_ptr = buffer + offset;
offset += sizeof(u32);
printf("-- STREAM_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->login_payload_length, (u64)packet->login_payload_length, (f64)packet->login_payload_length);

u32 will_pack_login_payload = packet->login_payload_length == ~(u32)0 ? 0 : 1;
for (u32 login_payload_iter = 0; login_payload_iter < will_pack_login_payload; login_payload_iter++)
{
// string server_address
endian_write_u32_little(buffer + offset, packet->login_payload[login_payload_iter].server_address_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].server_address_length, (u64)packet->login_payload[login_payload_iter].server_address_length, (f64)packet->login_payload[login_payload_iter].server_address_length);
for (u32 server_address_iter = 0; server_address_iter < packet->login_payload[login_payload_iter].server_address_length; server_address_iter++)
{
endian_write_i8_little(buffer + offset, packet->login_payload[login_payload_iter].server_address[server_address_iter]);
offset++;
}

// string server_ticket
endian_write_u32_little(buffer + offset, packet->login_payload[login_payload_iter].server_ticket_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].server_ticket_length, (u64)packet->login_payload[login_payload_iter].server_ticket_length, (f64)packet->login_payload[login_payload_iter].server_ticket_length);
for (u32 server_ticket_iter = 0; server_ticket_iter < packet->login_payload[login_payload_iter].server_ticket_length; server_ticket_iter++)
{
endian_write_i8_little(buffer + offset, packet->login_payload[login_payload_iter].server_ticket[server_ticket_iter]);
offset++;
}

// bytes encryption_key
endian_write_u32_little(buffer + offset, packet->login_payload[login_payload_iter].encryption_key_length);
offset += sizeof(u32);
printf("-- BYTES_LENGTH            \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].encryption_key_length, (u64)packet->login_payload[login_payload_iter].encryption_key_length, (f64)packet->login_payload[login_payload_iter].encryption_key_length);
for (u32 encryption_key_iter = 0; encryption_key_iter < packet->login_payload[login_payload_iter].encryption_key_length; encryption_key_iter++)
{
endian_write_u8_little(buffer + offset, packet->login_payload[login_payload_iter].encryption_key[encryption_key_iter]);
offset++;
}

// u32 soe_protocol_version
endian_write_u32_little(buffer + offset, packet->login_payload[login_payload_iter].soe_protocol_version);
offset += sizeof(u32);
printf("-- soe_protocol_version    \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].soe_protocol_version, (u64)packet->login_payload[login_payload_iter].soe_protocol_version, (f64)packet->login_payload[login_payload_iter].soe_protocol_version);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->login_payload[login_payload_iter].character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].character_id, (u64)packet->login_payload[login_payload_iter].character_id, (f64)packet->login_payload[login_payload_iter].character_id);

// u64 unk_u64
endian_write_u64_little(buffer + offset, packet->login_payload[login_payload_iter].unk_u64);
offset += sizeof(u64);
printf("-- unk_u64                 \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].unk_u64, (u64)packet->login_payload[login_payload_iter].unk_u64, (f64)packet->login_payload[login_payload_iter].unk_u64);

// string station_name
endian_write_u32_little(buffer + offset, packet->login_payload[login_payload_iter].station_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].station_name_length, (u64)packet->login_payload[login_payload_iter].station_name_length, (f64)packet->login_payload[login_payload_iter].station_name_length);
for (u32 station_name_iter = 0; station_name_iter < packet->login_payload[login_payload_iter].station_name_length; station_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->login_payload[login_payload_iter].station_name[station_name_iter]);
offset++;
}

// string character_name
endian_write_u32_little(buffer + offset, packet->login_payload[login_payload_iter].character_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].character_name_length, (u64)packet->login_payload[login_payload_iter].character_name_length, (f64)packet->login_payload[login_payload_iter].character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->login_payload[login_payload_iter].character_name_length; character_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->login_payload[login_payload_iter].character_name[character_name_iter]);
offset++;
}

// string unk_str
endian_write_u32_little(buffer + offset, packet->login_payload[login_payload_iter].unk_str_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].unk_str_length, (u64)packet->login_payload[login_payload_iter].unk_str_length, (f64)packet->login_payload[login_payload_iter].unk_str_length);
for (u32 unk_str_iter = 0; unk_str_iter < packet->login_payload[login_payload_iter].unk_str_length; unk_str_iter++)
{
endian_write_i8_little(buffer + offset, packet->login_payload[login_payload_iter].unk_str[unk_str_iter]);
offset++;
}

// u64 server_feature_bit
endian_write_u64_little(buffer + offset, packet->login_payload[login_payload_iter].server_feature_bit);
offset += sizeof(u64);
printf("-- server_feature_bit      \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].server_feature_bit, (u64)packet->login_payload[login_payload_iter].server_feature_bit, (f64)packet->login_payload[login_payload_iter].server_feature_bit);

} // login_payload
endian_write_u32_little((u8*)login_payload_length_ptr, (u32)((uptr)buffer + (uptr)offset - (uptr)login_payload_length_ptr - sizeof(u32)));

} break;

case Login_Packet_Kind_CharacterDeleteRequest:
{
printf("[*] Packing CharacterDeleteRequest...\n");
Login_Packet_CharacterDeleteRequest* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x9);
offset += sizeof(u8);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

} break;

case Login_Packet_Kind_TunnelAppPacketClientToServer:
{
printf("[*] Packing TunnelAppPacketClientToServer...\n");
Login_Packet_TunnelAppPacketClientToServer* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x10);
offset += sizeof(u8);

// u32 server_id
endian_write_u32_little(buffer + offset, packet->server_id);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 unk1
endian_write_u32_little(buffer + offset, packet->unk1);
offset += sizeof(u32);
printf("-- unk1                    \t%lld\t%llxh\t%f\n", (i64)packet->unk1, (u64)packet->unk1, (f64)packet->unk1);

// stream data_client
void* data_client_length_ptr = buffer + offset;
offset += sizeof(u32);
printf("-- STREAM_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->data_client_length, (u64)packet->data_client_length, (f64)packet->data_client_length);

u32 will_pack_data_client = packet->data_client_length == ~(u32)0 ? 0 : 1;
for (u32 data_client_iter = 0; data_client_iter < will_pack_data_client; data_client_iter++)
{
// b8 tunnel_op_code
endian_write_b8_little(buffer + offset, packet->data_client[data_client_iter].tunnel_op_code);
offset += sizeof(b8);
printf("-- tunnel_op_code          \t%lld\t%llxh\t%f\n", (i64)packet->data_client[data_client_iter].tunnel_op_code, (u64)packet->data_client[data_client_iter].tunnel_op_code, (f64)packet->data_client[data_client_iter].tunnel_op_code);

// b8 sub_op_code
endian_write_b8_little(buffer + offset, packet->data_client[data_client_iter].sub_op_code);
offset += sizeof(b8);
printf("-- sub_op_code             \t%lld\t%llxh\t%f\n", (i64)packet->data_client[data_client_iter].sub_op_code, (u64)packet->data_client[data_client_iter].sub_op_code, (f64)packet->data_client[data_client_iter].sub_op_code);

// string character_name
endian_write_u32_little(buffer + offset, packet->data_client[data_client_iter].character_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->data_client[data_client_iter].character_name_length, (u64)packet->data_client[data_client_iter].character_name_length, (f64)packet->data_client[data_client_iter].character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->data_client[data_client_iter].character_name_length; character_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->data_client[data_client_iter].character_name[character_name_iter]);
offset++;
}

} // data_client
endian_write_u32_little((u8*)data_client_length_ptr, (u32)((uptr)buffer + (uptr)offset - (uptr)data_client_length_ptr - sizeof(u32)));

} break;

case Login_Packet_Kind_TunnelAppPacketServerToClient:
{
printf("[*] Packing TunnelAppPacketServerToClient...\n");
Login_Packet_TunnelAppPacketServerToClient* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0x11);
offset += sizeof(u8);

// u32 server_id
endian_write_u32_little(buffer + offset, packet->server_id);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 unk1
endian_write_u32_little(buffer + offset, packet->unk1);
offset += sizeof(u32);
printf("-- unk1                    \t%lld\t%llxh\t%f\n", (i64)packet->unk1, (u64)packet->unk1, (f64)packet->unk1);

// stream data_server
void* data_server_length_ptr = buffer + offset;
offset += sizeof(u32);
printf("-- STREAM_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->data_server_length, (u64)packet->data_server_length, (f64)packet->data_server_length);

u32 will_pack_data_server = packet->data_server_length == ~(u32)0 ? 0 : 1;
for (u32 data_server_iter = 0; data_server_iter < will_pack_data_server; data_server_iter++)
{
// b8 tunnel_op_code
endian_write_b8_little(buffer + offset, packet->data_server[data_server_iter].tunnel_op_code);
offset += sizeof(b8);
printf("-- tunnel_op_code          \t%lld\t%llxh\t%f\n", (i64)packet->data_server[data_server_iter].tunnel_op_code, (u64)packet->data_server[data_server_iter].tunnel_op_code, (f64)packet->data_server[data_server_iter].tunnel_op_code);

// b8 sub_op_code
endian_write_b8_little(buffer + offset, packet->data_server[data_server_iter].sub_op_code);
offset += sizeof(b8);
printf("-- sub_op_code             \t%lld\t%llxh\t%f\n", (i64)packet->data_server[data_server_iter].sub_op_code, (u64)packet->data_server[data_server_iter].sub_op_code, (f64)packet->data_server[data_server_iter].sub_op_code);

// string character_name
endian_write_u32_little(buffer + offset, packet->data_server[data_server_iter].character_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->data_server[data_server_iter].character_name_length, (u64)packet->data_server[data_server_iter].character_name_length, (f64)packet->data_server[data_server_iter].character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->data_server[data_server_iter].character_name_length; character_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->data_server[data_server_iter].character_name[character_name_iter]);
offset++;
}

// string character_name2
endian_write_u32_little(buffer + offset, packet->data_server[data_server_iter].character_name2_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->data_server[data_server_iter].character_name2_length, (u64)packet->data_server[data_server_iter].character_name2_length, (f64)packet->data_server[data_server_iter].character_name2_length);
for (u32 character_name2_iter = 0; character_name2_iter < packet->data_server[data_server_iter].character_name2_length; character_name2_iter++)
{
endian_write_i8_little(buffer + offset, packet->data_server[data_server_iter].character_name2[character_name2_iter]);
offset++;
}

// u32 status
endian_write_u32_little(buffer + offset, packet->data_server[data_server_iter].status);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->data_server[data_server_iter].status, (u64)packet->data_server[data_server_iter].status, (f64)packet->data_server[data_server_iter].status);

} // data_server
endian_write_u32_little((u8*)data_server_length_ptr, (u32)((uptr)buffer + (uptr)offset - (uptr)data_server_length_ptr - sizeof(u32)));

} break;

case Login_Packet_Kind_CharacterTransferRequest:
{
printf("[*] Packing CharacterTransferRequest...\n");
endian_write_u8_little(buffer + offset, 0x12);
offset += sizeof(u8);

} break;

case Login_Packet_Kind_CharacterTransferReply:
{
printf("[*] Packing CharacterTransferReply...\n");
endian_write_u8_little(buffer + offset, 0x13);
offset += sizeof(u8);

} break;

case Login_Packet_Kind_CharacterDeleteReply:
{
printf("[*] Packing CharacterDeleteReply...\n");
Login_Packet_CharacterDeleteReply* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0xa);
offset += sizeof(u8);

// u64 character_id
endian_write_u64_little(buffer + offset, packet->character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 status
endian_write_u32_little(buffer + offset, packet->status);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// bytes payload3
endian_write_u32_little(buffer + offset, packet->payload3_length);
offset += sizeof(u32);
printf("-- BYTES_LENGTH            \t%lld\t%llxh\t%f\n", (i64)packet->payload3_length, (u64)packet->payload3_length, (f64)packet->payload3_length);
for (u32 payload3_iter = 0; payload3_iter < packet->payload3_length; payload3_iter++)
{
endian_write_u8_little(buffer + offset, packet->payload3[payload3_iter]);
offset++;
}

} break;

case Login_Packet_Kind_CharacterSelectInfoRequest:
{
printf("[*] Packing CharacterSelectInfoRequest...\n");
endian_write_u8_little(buffer + offset, 0xb);
offset += sizeof(u8);

} break;

case Login_Packet_Kind_CharacterSelectInfoReply:
{
printf("[*] Packing CharacterSelectInfoReply...\n");
Login_Packet_CharacterSelectInfoReply* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0xc);
offset += sizeof(u8);

// u32 character_status
endian_write_u32_little(buffer + offset, packet->character_status);
offset += sizeof(u32);
printf("-- character_status        \t%lld\t%llxh\t%f\n", (i64)packet->character_status, (u64)packet->character_status, (f64)packet->character_status);

// b8 can_bypass_server_lock
endian_write_b8_little(buffer + offset, packet->can_bypass_server_lock);
offset += sizeof(b8);
printf("-- can_bypass_server_lock  \t%lld\t%llxh\t%f\n", (i64)packet->can_bypass_server_lock, (u64)packet->can_bypass_server_lock, (f64)packet->can_bypass_server_lock);

// list characters
endian_write_u32_little(buffer + offset, packet->characters_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->characters_count, (u64)packet->characters_count, (f64)packet->characters_count);

for (u32 characters_iter = 0; characters_iter < packet->characters_count; characters_iter++)
{
// u64 character_id
endian_write_u64_little(buffer + offset, packet->characters[characters_iter].character_id);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].character_id, (u64)packet->characters[characters_iter].character_id, (f64)packet->characters[characters_iter].character_id);

// u32 server_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].server_id);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].server_id, (u64)packet->characters[characters_iter].server_id, (f64)packet->characters[characters_iter].server_id);

// u64 last_login_date
endian_write_u64_little(buffer + offset, packet->characters[characters_iter].last_login_date);
offset += sizeof(u64);
printf("-- last_login_date         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].last_login_date, (u64)packet->characters[characters_iter].last_login_date, (f64)packet->characters[characters_iter].last_login_date);

// u32 null_field
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].null_field);
offset += sizeof(u32);
printf("-- null_field              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].null_field, (u64)packet->characters[characters_iter].null_field, (f64)packet->characters[characters_iter].null_field);

// u32 status
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].status);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].status, (u64)packet->characters[characters_iter].status, (f64)packet->characters[characters_iter].status);

// stream payload4
void* payload4_length_ptr = buffer + offset;
offset += sizeof(u32);
printf("-- STREAM_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4_length, (u64)packet->characters[characters_iter].payload4_length, (f64)packet->characters[characters_iter].payload4_length);

u32 will_pack_payload4 = packet->characters[characters_iter].payload4_length == ~(u32)0 ? 0 : 1;
for (u32 payload4_iter = 0; payload4_iter < will_pack_payload4; payload4_iter++)
{
// string name
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].name_length, (u64)packet->characters[characters_iter].payload4[payload4_iter].name_length, (f64)packet->characters[characters_iter].payload4[payload4_iter].name_length);
for (u32 name_iter = 0; name_iter < packet->characters[characters_iter].payload4[payload4_iter].name_length; name_iter++)
{
endian_write_i8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].name[name_iter]);
offset++;
}

// u8 empire_id
endian_write_u8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].empire_id);
offset += sizeof(u8);
printf("-- empire_id               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].empire_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].empire_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].empire_id);

// u32 battle_rank
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].battle_rank);
offset += sizeof(u32);
printf("-- battle_rank             \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].battle_rank, (u64)packet->characters[characters_iter].payload4[payload4_iter].battle_rank, (f64)packet->characters[characters_iter].payload4[payload4_iter].battle_rank);

// u32 next_battle_rank_percent
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].next_battle_rank_percent);
offset += sizeof(u32);
printf("-- next_battle_rank_percent\t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].next_battle_rank_percent, (u64)packet->characters[characters_iter].payload4[payload4_iter].next_battle_rank_percent, (f64)packet->characters[characters_iter].payload4[payload4_iter].next_battle_rank_percent);

// u32 head_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].head_id);
offset += sizeof(u32);
printf("-- head_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].head_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].head_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].head_id);

// u32 model_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].model_id);
offset += sizeof(u32);
printf("-- model_id                \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].model_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].model_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].model_id);

// u32 gender
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].gender);
offset += sizeof(u32);
printf("-- gender                  \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].gender, (u64)packet->characters[characters_iter].payload4[payload4_iter].gender, (f64)packet->characters[characters_iter].payload4[payload4_iter].gender);

// u32 profile_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].profile_id);
offset += sizeof(u32);
printf("-- profile_id              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].profile_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].profile_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].profile_id);

// u32 unknown_dword
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].unknown_dword);
offset += sizeof(u32);
printf("-- unknown_dword           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword);

// u32 loadout_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_id);
offset += sizeof(u32);
printf("-- loadout_id              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_id);

// u32 unknown_dword_1
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_1);
offset += sizeof(u32);
printf("-- unknown_dword_1         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_1);

// u8 unknown_byte_1
endian_write_u8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].unknown_byte_1);
offset += sizeof(u8);
printf("-- unknown_byte_1          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_byte_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_byte_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_byte_1);

// u32 unknown_dword_2
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_2);
offset += sizeof(u32);
printf("-- unknown_dword_2         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_2);

// u32 unknown_dword_3
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_3);
offset += sizeof(u32);
printf("-- unknown_dword_3         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_3, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_3, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_3);

// string loadout_name
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_name_length, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_name_length, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_name_length);
for (u32 loadout_name_iter = 0; loadout_name_iter < packet->characters[characters_iter].payload4[payload4_iter].loadout_name_length; loadout_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_name[loadout_name_iter]);
offset++;
}

// u32 tint_item_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].tint_item_id);
offset += sizeof(u32);
printf("-- tint_item_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].tint_item_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].tint_item_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].tint_item_id);

// u32 unknown_dword_4
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_4);
offset += sizeof(u32);
printf("-- unknown_dword_4         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_4, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_4, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_4);

// u32 decal_item_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].decal_item_id);
offset += sizeof(u32);
printf("-- decal_item_id           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].decal_item_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].decal_item_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].decal_item_id);

// list loadout_slots
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots_count, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots_count, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots_count);

for (u32 loadout_slots_iter = 0; loadout_slots_iter < packet->characters[characters_iter].payload4[payload4_iter].loadout_slots_count; loadout_slots_iter++)
{
// u32 slot_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].slot_id);
offset += sizeof(u32);
printf("-- slot_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].slot_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].slot_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].slot_id);

// u32 index
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].index);
offset += sizeof(u32);
printf("-- index                   \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].index, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].index, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].index);

// u32 item_line_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_line_id);
offset += sizeof(u32);
printf("-- item_line_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_line_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_line_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_line_id);

// u8 flags
endian_write_u8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].flags);
offset += sizeof(u8);
printf("-- flags                   \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].flags, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].flags, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].flags);

// list attachments
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments_count, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments_count, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments_count);

for (u32 attachments_iter = 0; attachments_iter < packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments_count; attachments_iter++)
{
// u32 attachment_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments[attachments_iter].attachment_id);
offset += sizeof(u32);
printf("-- attachment_id           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments[attachments_iter].attachment_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments[attachments_iter].attachment_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments[attachments_iter].attachment_id);

} // attachments

// list attachment_classes
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes_count, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes_count, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes_count);

for (u32 attachment_classes_iter = 0; attachment_classes_iter < packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes_count; attachment_classes_iter++)
{
// u32 class_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].class_id);
offset += sizeof(u32);
printf("-- class_id                \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].class_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].class_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].class_id);

// u32 attachment_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].attachment_id);
offset += sizeof(u32);
printf("-- attachment_id           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].attachment_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].attachment_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].attachment_id);

} // attachment_classes

// u32 tint_item_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].tint_item_id);
offset += sizeof(u32);
printf("-- tint_item_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].tint_item_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].tint_item_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].tint_item_id);

// u32 item_slot
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_slot);
offset += sizeof(u32);
printf("-- item_slot               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_slot, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_slot, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_slot);

} // loadout_slots

// list item_definitions
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions_count, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions_count, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions_count);

for (u32 item_definitions_iter = 0; item_definitions_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions_count; item_definitions_iter++)
{
// u32 item_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id);
offset += sizeof(u32);
printf("-- item_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id);

// u32 item_id_2
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id_2);
offset += sizeof(u32);
printf("-- item_id_2               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id_2);

// u8 flags_1
endian_write_u8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_1);
offset += sizeof(u8);
printf("-- flags_1                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_1);

// u8 flags_2
endian_write_u8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_2);
offset += sizeof(u8);
printf("-- flags_2                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_2);

// u32 name_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].name_id);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].name_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].name_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].name_id);

// u32 description_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].description_id);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].description_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].description_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].description_id);

// u32 unknown_dword_1
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_1);
offset += sizeof(u32);
printf("-- unknown_dword_1         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_1);

// u32 icon_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].icon_id);
offset += sizeof(u32);
printf("-- icon_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].icon_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].icon_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].icon_id);

// u32 unknown_dword_2
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_2);
offset += sizeof(u32);
printf("-- unknown_dword_2         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_2);

// u32 hudImageSetId
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hudImageSetId);
offset += sizeof(u32);
printf("-- hudImageSetId           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hudImageSetId, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hudImageSetId, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hudImageSetId);

// u32 hud_image_set_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hud_image_set_id);
offset += sizeof(u32);
printf("-- hud_image_set_id        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hud_image_set_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hud_image_set_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hud_image_set_id);

// u32 unknown_dword_4
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_4);
offset += sizeof(u32);
printf("-- unknown_dword_4         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_4, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_4, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_4);

// u32 cost
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].cost);
offset += sizeof(u32);
printf("-- cost                    \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].cost, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].cost, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].cost);

// u32 item_class
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_class);
offset += sizeof(u32);
printf("-- item_class              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_class, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_class, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_class);

// u32 unknown_dword_5
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_5);
offset += sizeof(u32);
printf("-- unknown_dword_5         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_5, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_5, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_5);

// u32 item_slot
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_slot);
offset += sizeof(u32);
printf("-- item_slot               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_slot, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_slot, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_slot);

// u32 slot_override_key
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].slot_override_key);
offset += sizeof(u32);
printf("-- slot_override_key       \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].slot_override_key, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].slot_override_key, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].slot_override_key);

// u8 unknown_dword6
endian_write_u8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword6);
offset += sizeof(u8);
printf("-- unknown_dword6          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword6, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword6, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword6);

// string model_name
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name_length, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name_length, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name_length);
for (u32 model_name_iter = 0; model_name_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name_length; model_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name[model_name_iter]);
offset++;
}

// string unknown_string
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string_length, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string_length, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string_length);
for (u32 unknown_string_iter = 0; unknown_string_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string_length; unknown_string_iter++)
{
endian_write_i8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string[unknown_string_iter]);
offset++;
}

// u8 unknown_byte_1
endian_write_u8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_byte_1);
offset += sizeof(u8);
printf("-- unknown_byte_1          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_byte_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_byte_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_byte_1);

// u32 item_type
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_type);
offset += sizeof(u32);
printf("-- item_type               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_type, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_type, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_type);

// u32 category_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].category_id);
offset += sizeof(u32);
printf("-- category_id             \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].category_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].category_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].category_id);

// u32 unknown_dword_7
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_7);
offset += sizeof(u32);
printf("-- unknown_dword_7         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_7, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_7, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_7);

// u32 unknown_dword_8
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_8);
offset += sizeof(u32);
printf("-- unknown_dword_8         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_8, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_8, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_8);

// u32 unknown_dword_9
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_9);
offset += sizeof(u32);
printf("-- unknown_dword_9         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_9, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_9, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_9);

// u32 unknown_dword_10
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_10);
offset += sizeof(u32);
printf("-- unknown_dword_10        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_10, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_10, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_10);

// u32 unknown_dword_11
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_11);
offset += sizeof(u32);
printf("-- unknown_dword_11        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_11, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_11, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_11);

// u32 activatable_ability_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].activatable_ability_id);
offset += sizeof(u32);
printf("-- activatable_ability_id  \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].activatable_ability_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].activatable_ability_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].activatable_ability_id);

// u32 passive_ability_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].passive_ability_id);
offset += sizeof(u32);
printf("-- passive_ability_id      \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].passive_ability_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].passive_ability_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].passive_ability_id);

// u32 unknown_dword_12
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_12);
offset += sizeof(u32);
printf("-- unknown_dword_12        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_12, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_12, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_12);

// u32 max_stack_size
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].max_stack_size);
offset += sizeof(u32);
printf("-- max_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].max_stack_size, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].max_stack_size, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].max_stack_size);

// string tint_name
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name_length, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name_length, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name_length);
for (u32 tint_name_iter = 0; tint_name_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name_length; tint_name_iter++)
{
endian_write_i8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name[tint_name_iter]);
offset++;
}

// u32 unknown_dword_13
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_13);
offset += sizeof(u32);
printf("-- unknown_dword_13        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_13, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_13, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_13);

// u32 unknown_dword_14
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_14);
offset += sizeof(u32);
printf("-- unknown_dword_14        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_14, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_14, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_14);

// u32 unknown_dword_15
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_15);
offset += sizeof(u32);
printf("-- unknown_dword_15        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_15, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_15, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_15);

// u32 unknown_dword_16
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_16);
offset += sizeof(u32);
printf("-- unknown_dword_16        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_16, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_16, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_16);

// u32 ui_model_camera
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].ui_model_camera);
offset += sizeof(u32);
printf("-- ui_model_camera         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].ui_model_camera, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].ui_model_camera, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].ui_model_camera);

// u32 equip_count_max
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].equip_count_max);
offset += sizeof(u32);
printf("-- equip_count_max         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].equip_count_max, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].equip_count_max, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].equip_count_max);

// u32 currency_type
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].currency_type);
offset += sizeof(u32);
printf("-- currency_type           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].currency_type, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].currency_type, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].currency_type);

// u32 unknown_dword_17
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_17);
offset += sizeof(u32);
printf("-- unknown_dword_17        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_17, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_17, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_17);

// u32 client_item_type
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_item_type);
offset += sizeof(u32);
printf("-- client_item_type        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_item_type, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_item_type, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_item_type);

// u32 skill_set_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].skill_set_id);
offset += sizeof(u32);
printf("-- skill_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].skill_set_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].skill_set_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].skill_set_id);

// string overlay_texture
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture_length, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture_length, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture_length);
for (u32 overlay_texture_iter = 0; overlay_texture_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture_length; overlay_texture_iter++)
{
endian_write_i8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture[overlay_texture_iter]);
offset++;
}

// string decal_slot
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot_length, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot_length, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot_length);
for (u32 decal_slot_iter = 0; decal_slot_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot_length; decal_slot_iter++)
{
endian_write_i8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot[decal_slot_iter]);
offset++;
}

// u32 unknown_dword_18
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_18);
offset += sizeof(u32);
printf("-- unknown_dword_18        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_18, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_18, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_18);

// u32 trial_duration_sec
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_duration_sec);
offset += sizeof(u32);
printf("-- trial_duration_sec      \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_duration_sec, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_duration_sec, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_duration_sec);

// u32 trial_exclusion_sec
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_exclusion_sec);
offset += sizeof(u32);
printf("-- trial_exclusion_sec     \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_exclusion_sec, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_exclusion_sec, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_exclusion_sec);

// u32 client_use_requirement_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id);
offset += sizeof(u32);
printf("-- client_use_requirement_id\t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id);

// string override_appearance
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance_length, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance_length, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance_length);
for (u32 override_appearance_iter = 0; override_appearance_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance_length; override_appearance_iter++)
{
endian_write_i8_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance[override_appearance_iter]);
offset++;
}

// u32 unknown_dword_19
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_19);
offset += sizeof(u32);
printf("-- unknown_dword_19        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_19, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_19, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_19);

// u32 client_use_requirement_id_2
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id_2);
offset += sizeof(u32);
printf("-- client_use_requirement_id_2\t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id_2);

} // item_definitions

// list attachment_definitions
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions_count, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions_count, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions_count);

for (u32 attachment_definitions_iter = 0; attachment_definitions_iter < packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions_count; attachment_definitions_iter++)
{
// u32 attachment_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id);
offset += sizeof(u32);
printf("-- attachment_id           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id);

// u32 attachment_id_2
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id_2);
offset += sizeof(u32);
printf("-- attachment_id_2         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id_2);

// u32 group_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].group_id);
offset += sizeof(u32);
printf("-- group_id                \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].group_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].group_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].group_id);

// u32 item_line_id
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].item_line_id);
offset += sizeof(u32);
printf("-- item_line_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].item_line_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].item_line_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].item_line_id);

// u32 flags
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].flags);
offset += sizeof(u32);
printf("-- flags                   \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].flags, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].flags, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].flags);

// list classes
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes_count, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes_count, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes_count);

for (u32 classes_iter = 0; classes_iter < packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes_count; classes_iter++)
{
// u32 element_type
endian_write_u32_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes[classes_iter].element_type);
offset += sizeof(u32);
printf("-- element_type            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes[classes_iter].element_type, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes[classes_iter].element_type, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes[classes_iter].element_type);

} // classes

} // attachment_definitions

// u64 last_use_date
endian_write_u64_little(buffer + offset, packet->characters[characters_iter].payload4[payload4_iter].last_use_date);
offset += sizeof(u64);
printf("-- last_use_date           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].last_use_date, (u64)packet->characters[characters_iter].payload4[payload4_iter].last_use_date, (f64)packet->characters[characters_iter].payload4[payload4_iter].last_use_date);

} // payload4
endian_write_u32_little((u8*)payload4_length_ptr, (u32)((uptr)buffer + (uptr)offset - (uptr)payload4_length_ptr - sizeof(u32)));

} // characters

} break;

case Login_Packet_Kind_ServerListRequest:
{
printf("[*] Packing ServerListRequest...\n");
endian_write_u8_little(buffer + offset, 0xd);
offset += sizeof(u8);

} break;

case Login_Packet_Kind_ServerListReply:
{
printf("[*] Packing ServerListReply...\n");
Login_Packet_ServerListReply* packet = packet_ptr;

endian_write_u8_little(buffer + offset, 0xe);
offset += sizeof(u8);

// list servers
endian_write_u32_little(buffer + offset, packet->servers_count);
offset += sizeof(u32);
printf("-- LIST_COUNT              \t%lld\t%llxh\t%f\n", (i64)packet->servers_count, (u64)packet->servers_count, (f64)packet->servers_count);

for (u32 servers_iter = 0; servers_iter < packet->servers_count; servers_iter++)
{
// u32 id
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].id);
offset += sizeof(u32);
printf("-- id                      \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].id, (u64)packet->servers[servers_iter].id, (f64)packet->servers[servers_iter].id);

// u32 state
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].state);
offset += sizeof(u32);
printf("-- state                   \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].state, (u64)packet->servers[servers_iter].state, (f64)packet->servers[servers_iter].state);

// b8 is_locked
endian_write_b8_little(buffer + offset, packet->servers[servers_iter].is_locked);
offset += sizeof(b8);
printf("-- is_locked               \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].is_locked, (u64)packet->servers[servers_iter].is_locked, (f64)packet->servers[servers_iter].is_locked);

// string name
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].name_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].name_length, (u64)packet->servers[servers_iter].name_length, (f64)packet->servers[servers_iter].name_length);
for (u32 name_iter = 0; name_iter < packet->servers[servers_iter].name_length; name_iter++)
{
endian_write_i8_little(buffer + offset, packet->servers[servers_iter].name[name_iter]);
offset++;
}

// u32 name_id
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].name_id);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].name_id, (u64)packet->servers[servers_iter].name_id, (f64)packet->servers[servers_iter].name_id);

// string description
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].description_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].description_length, (u64)packet->servers[servers_iter].description_length, (f64)packet->servers[servers_iter].description_length);
for (u32 description_iter = 0; description_iter < packet->servers[servers_iter].description_length; description_iter++)
{
endian_write_i8_little(buffer + offset, packet->servers[servers_iter].description[description_iter]);
offset++;
}

// u32 description_id
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].description_id);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].description_id, (u64)packet->servers[servers_iter].description_id, (f64)packet->servers[servers_iter].description_id);

// u32 req_feature_id
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].req_feature_id);
offset += sizeof(u32);
printf("-- req_feature_id          \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].req_feature_id, (u64)packet->servers[servers_iter].req_feature_id, (f64)packet->servers[servers_iter].req_feature_id);

// string server_info
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].server_info_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].server_info_length, (u64)packet->servers[servers_iter].server_info_length, (f64)packet->servers[servers_iter].server_info_length);
for (u32 server_info_iter = 0; server_info_iter < packet->servers[servers_iter].server_info_length; server_info_iter++)
{
endian_write_i8_little(buffer + offset, packet->servers[servers_iter].server_info[server_info_iter]);
offset++;
}

// u32 population_level
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].population_level);
offset += sizeof(u32);
printf("-- population_level        \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].population_level, (u64)packet->servers[servers_iter].population_level, (f64)packet->servers[servers_iter].population_level);

// string population_data
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].population_data_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].population_data_length, (u64)packet->servers[servers_iter].population_data_length, (f64)packet->servers[servers_iter].population_data_length);
for (u32 population_data_iter = 0; population_data_iter < packet->servers[servers_iter].population_data_length; population_data_iter++)
{
endian_write_i8_little(buffer + offset, packet->servers[servers_iter].population_data[population_data_iter]);
offset++;
}

// string access_expression
endian_write_u32_little(buffer + offset, packet->servers[servers_iter].access_expression_length);
offset += sizeof(u32);
printf("-- STRING_LENGTH           \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].access_expression_length, (u64)packet->servers[servers_iter].access_expression_length, (f64)packet->servers[servers_iter].access_expression_length);
for (u32 access_expression_iter = 0; access_expression_iter < packet->servers[servers_iter].access_expression_length; access_expression_iter++)
{
endian_write_i8_little(buffer + offset, packet->servers[servers_iter].access_expression[access_expression_iter]);
offset++;
}

// b8 is_access_allowed
endian_write_b8_little(buffer + offset, packet->servers[servers_iter].is_access_allowed);
offset += sizeof(b8);
printf("-- is_access_allowed       \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].is_access_allowed, (u64)packet->servers[servers_iter].is_access_allowed, (f64)packet->servers[servers_iter].is_access_allowed);

} // servers

} break;

case Login_Packet_Kind_ServerUpdate:
{
printf("[*] Packing ServerUpdate...\n");
endian_write_u8_little(buffer + offset, 0xf);
offset += sizeof(u8);

} break;

default:
{
printf("[!] Packing %s not implemented\n", login_packet_names[packet_kind]);
}
}
return offset;
}

internal void
login_packet_unpack(u8* data, u32 data_length, Login_Packet_Kind packet_kind, void* packet_ptr, Memory_Arena* arena)
{
u32 offset = 0;

printf("\n");
switch (packet_kind)
{
case Login_Packet_Kind_LoginRequest:
{
printf("[*] Unpacking LoginRequest...\n");
Login_Packet_LoginRequest* packet = packet_ptr;

// string session_id
packet->session_id_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->session_id = memory_arena_push_length(arena, packet->session_id_length);
printf("-- STRING_LENGTH           \t%d\n", packet->session_id_length);
for (u32 session_id_iter = 0; session_id_iter < packet->session_id_length; session_id_iter++)
{
packet->session_id[session_id_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string system_fingerprint
packet->system_fingerprint_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->system_fingerprint = memory_arena_push_length(arena, packet->system_fingerprint_length);
printf("-- STRING_LENGTH           \t%d\n", packet->system_fingerprint_length);
for (u32 system_fingerprint_iter = 0; system_fingerprint_iter < packet->system_fingerprint_length; system_fingerprint_iter++)
{
packet->system_fingerprint[system_fingerprint_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 locale
packet->locale = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- locale                  \t%lld\t%llxh\t%f\n", (i64)packet->locale, (u64)packet->locale, (f64)packet->locale);

// u32 third_party_auth_ticket
packet->third_party_auth_ticket = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- third_party_auth_ticket \t%lld\t%llxh\t%f\n", (i64)packet->third_party_auth_ticket, (u64)packet->third_party_auth_ticket, (f64)packet->third_party_auth_ticket);

// u32 third_party_user_id
packet->third_party_user_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- third_party_user_id     \t%lld\t%llxh\t%f\n", (i64)packet->third_party_user_id, (u64)packet->third_party_user_id, (f64)packet->third_party_user_id);

// u32 third_party_id
packet->third_party_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- third_party_id          \t%lld\t%llxh\t%f\n", (i64)packet->third_party_id, (u64)packet->third_party_id, (f64)packet->third_party_id);

} break;

case Login_Packet_Kind_LoginReply:
{
printf("[*] Unpacking LoginReply...\n");
Login_Packet_LoginReply* packet = packet_ptr;

// b8 is_logged_in
packet->is_logged_in = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- is_logged_in            \t%lld\t%llxh\t%f\n", (i64)packet->is_logged_in, (u64)packet->is_logged_in, (f64)packet->is_logged_in);

// u32 status
packet->status = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// u32 result_code
packet->result_code = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- result_code             \t%lld\t%llxh\t%f\n", (i64)packet->result_code, (u64)packet->result_code, (f64)packet->result_code);

// b8 is_member
packet->is_member = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- is_member               \t%lld\t%llxh\t%f\n", (i64)packet->is_member, (u64)packet->is_member, (f64)packet->is_member);

// b8 is_internal
packet->is_internal = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- is_internal             \t%lld\t%llxh\t%f\n", (i64)packet->is_internal, (u64)packet->is_internal, (f64)packet->is_internal);

// string namespace_name
packet->namespace_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->namespace_name = memory_arena_push_length(arena, packet->namespace_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->namespace_name_length);
for (u32 namespace_name_iter = 0; namespace_name_iter < packet->namespace_name_length; namespace_name_iter++)
{
packet->namespace_name[namespace_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// list account_features
packet->account_features_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->account_features = memory_arena_push_length(arena, packet->account_features_count * sizeof(packet->account_features[0]));
printf("-- LIST_COUNT              \t%d\n", packet->account_features_count);
for (u32 account_features_iter = 0; account_features_iter < packet->account_features_count; account_features_iter++)
{
// u32 key
packet->account_features[account_features_iter].key = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- key                     \t%lld\t%llxh\t%f\n", (i64)packet->account_features[account_features_iter].key, (u64)packet->account_features[account_features_iter].key, (f64)packet->account_features[account_features_iter].key);

// u32 id
packet->account_features[account_features_iter].id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id                      \t%lld\t%llxh\t%f\n", (i64)packet->account_features[account_features_iter].id, (u64)packet->account_features[account_features_iter].id, (f64)packet->account_features[account_features_iter].id);

// b8 active
packet->account_features[account_features_iter].active = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- active                  \t%lld\t%llxh\t%f\n", (i64)packet->account_features[account_features_iter].active, (u64)packet->account_features[account_features_iter].active, (f64)packet->account_features[account_features_iter].active);

// u32 remaining_count
packet->account_features[account_features_iter].remaining_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- remaining_count         \t%lld\t%llxh\t%f\n", (i64)packet->account_features[account_features_iter].remaining_count, (u64)packet->account_features[account_features_iter].remaining_count, (f64)packet->account_features[account_features_iter].remaining_count);

// bytes raw_data
packet->account_features[account_features_iter].raw_data_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->account_features[account_features_iter].raw_data = memory_arena_push_length(arena, packet->account_features[account_features_iter].raw_data_length);
printf("-- BYTES_LENGTH            \t%d\n", packet->account_features[account_features_iter].raw_data_length);
for (u32 raw_data_iter = 0; raw_data_iter < packet->account_features[account_features_iter].raw_data_length; raw_data_iter++)
{
packet->account_features[account_features_iter].raw_data[raw_data_iter] = *(u8*)((uptr)data + offset);
offset++;
}

} // account_features

// bytes application_payload
packet->application_payload_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->application_payload = memory_arena_push_length(arena, packet->application_payload_length);
printf("-- BYTES_LENGTH            \t%d\n", packet->application_payload_length);
for (u32 application_payload_iter = 0; application_payload_iter < packet->application_payload_length; application_payload_iter++)
{
packet->application_payload[application_payload_iter] = *(u8*)((uptr)data + offset);
offset++;
}

// list error_details
packet->error_details_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->error_details = memory_arena_push_length(arena, packet->error_details_count * sizeof(packet->error_details[0]));
printf("-- LIST_COUNT              \t%d\n", packet->error_details_count);
for (u32 error_details_iter = 0; error_details_iter < packet->error_details_count; error_details_iter++)
{
// u32 unknown_dword1
packet->error_details[error_details_iter].unknown_dword1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword1          \t%lld\t%llxh\t%f\n", (i64)packet->error_details[error_details_iter].unknown_dword1, (u64)packet->error_details[error_details_iter].unknown_dword1, (f64)packet->error_details[error_details_iter].unknown_dword1);

// string name
packet->error_details[error_details_iter].name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->error_details[error_details_iter].name = memory_arena_push_length(arena, packet->error_details[error_details_iter].name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->error_details[error_details_iter].name_length);
for (u32 name_iter = 0; name_iter < packet->error_details[error_details_iter].name_length; name_iter++)
{
packet->error_details[error_details_iter].name[name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string value
packet->error_details[error_details_iter].value_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->error_details[error_details_iter].value = memory_arena_push_length(arena, packet->error_details[error_details_iter].value_length);
printf("-- STRING_LENGTH           \t%d\n", packet->error_details[error_details_iter].value_length);
for (u32 value_iter = 0; value_iter < packet->error_details[error_details_iter].value_length; value_iter++)
{
packet->error_details[error_details_iter].value[value_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} // error_details

// string ip_country_code
packet->ip_country_code_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->ip_country_code = memory_arena_push_length(arena, packet->ip_country_code_length);
printf("-- STRING_LENGTH           \t%d\n", packet->ip_country_code_length);
for (u32 ip_country_code_iter = 0; ip_country_code_iter < packet->ip_country_code_length; ip_country_code_iter++)
{
packet->ip_country_code[ip_country_code_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} break;

case Login_Packet_Kind_CharacterCreateRequest:
{
printf("[*] Unpacking CharacterCreateRequest...\n");
Login_Packet_CharacterCreateRequest* packet = packet_ptr;

// u32 server_id
packet->server_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 unk_u32
packet->unk_u32 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk_u32                 \t%lld\t%llxh\t%f\n", (i64)packet->unk_u32, (u64)packet->unk_u32, (f64)packet->unk_u32);

// stream payload
packet->payload_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->payload = memory_arena_push_length(arena, packet->payload_length * sizeof(packet->payload[0]));
printf("-- STREAM_LENGTH           \t%d\n", packet->payload_length);
for (u32 payload_iter = 0; payload_iter < (packet->payload_length > (u32)0 ? (u32)1 : (u32)0); payload_iter++)
{
// b8 empire_id
packet->payload[payload_iter].empire_id = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- empire_id               \t%lld\t%llxh\t%f\n", (i64)packet->payload[payload_iter].empire_id, (u64)packet->payload[payload_iter].empire_id, (f64)packet->payload[payload_iter].empire_id);

// u32 head_type
packet->payload[payload_iter].head_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- head_type               \t%lld\t%llxh\t%f\n", (i64)packet->payload[payload_iter].head_type, (u64)packet->payload[payload_iter].head_type, (f64)packet->payload[payload_iter].head_type);

// u32 profile_type
packet->payload[payload_iter].profile_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- profile_type            \t%lld\t%llxh\t%f\n", (i64)packet->payload[payload_iter].profile_type, (u64)packet->payload[payload_iter].profile_type, (f64)packet->payload[payload_iter].profile_type);

// u32 gender
packet->payload[payload_iter].gender = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- gender                  \t%lld\t%llxh\t%f\n", (i64)packet->payload[payload_iter].gender, (u64)packet->payload[payload_iter].gender, (f64)packet->payload[payload_iter].gender);

// string character_name
packet->payload[payload_iter].character_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->payload[payload_iter].character_name = memory_arena_push_length(arena, packet->payload[payload_iter].character_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->payload[payload_iter].character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->payload[payload_iter].character_name_length; character_name_iter++)
{
packet->payload[payload_iter].character_name[character_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} // payload

} break;

case Login_Packet_Kind_CharacterCreateReply:
{
printf("[*] Unpacking CharacterCreateReply...\n");
Login_Packet_CharacterCreateReply* packet = packet_ptr;

// u32 status
packet->status = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

} break;

case Login_Packet_Kind_CharacterLoginRequest:
{
printf("[*] Unpacking CharacterLoginRequest...\n");
Login_Packet_CharacterLoginRequest* packet = packet_ptr;

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 server_id
packet->server_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 status
packet->status = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// stream payload2
packet->payload2_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->payload2 = memory_arena_push_length(arena, packet->payload2_length * sizeof(packet->payload2[0]));
printf("-- STREAM_LENGTH           \t%d\n", packet->payload2_length);
for (u32 payload2_iter = 0; payload2_iter < (packet->payload2_length > (u32)0 ? (u32)1 : (u32)0); payload2_iter++)
{
// string locale
packet->payload2[payload2_iter].locale_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->payload2[payload2_iter].locale = memory_arena_push_length(arena, packet->payload2[payload2_iter].locale_length);
printf("-- STRING_LENGTH           \t%d\n", packet->payload2[payload2_iter].locale_length);
for (u32 locale_iter = 0; locale_iter < packet->payload2[payload2_iter].locale_length; locale_iter++)
{
packet->payload2[payload2_iter].locale[locale_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 locale_id
packet->payload2[payload2_iter].locale_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- locale_id               \t%lld\t%llxh\t%f\n", (i64)packet->payload2[payload2_iter].locale_id, (u64)packet->payload2[payload2_iter].locale_id, (f64)packet->payload2[payload2_iter].locale_id);

// u32 preferred_gateway_id
packet->payload2[payload2_iter].preferred_gateway_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- preferred_gateway_id    \t%lld\t%llxh\t%f\n", (i64)packet->payload2[payload2_iter].preferred_gateway_id, (u64)packet->payload2[payload2_iter].preferred_gateway_id, (f64)packet->payload2[payload2_iter].preferred_gateway_id);

} // payload2

} break;

case Login_Packet_Kind_CharacterLoginReply:
{
printf("[*] Unpacking CharacterLoginReply...\n");
Login_Packet_CharacterLoginReply* packet = packet_ptr;

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 server_id
packet->server_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 last_login
packet->last_login = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- last_login              \t%lld\t%llxh\t%f\n", (i64)packet->last_login, (u64)packet->last_login, (f64)packet->last_login);

// u32 status
packet->status = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// stream login_payload
packet->login_payload_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->login_payload = memory_arena_push_length(arena, packet->login_payload_length * sizeof(packet->login_payload[0]));
printf("-- STREAM_LENGTH           \t%d\n", packet->login_payload_length);
for (u32 login_payload_iter = 0; login_payload_iter < (packet->login_payload_length > (u32)0 ? (u32)1 : (u32)0); login_payload_iter++)
{
// string server_address
packet->login_payload[login_payload_iter].server_address_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->login_payload[login_payload_iter].server_address = memory_arena_push_length(arena, packet->login_payload[login_payload_iter].server_address_length);
printf("-- STRING_LENGTH           \t%d\n", packet->login_payload[login_payload_iter].server_address_length);
for (u32 server_address_iter = 0; server_address_iter < packet->login_payload[login_payload_iter].server_address_length; server_address_iter++)
{
packet->login_payload[login_payload_iter].server_address[server_address_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string server_ticket
packet->login_payload[login_payload_iter].server_ticket_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->login_payload[login_payload_iter].server_ticket = memory_arena_push_length(arena, packet->login_payload[login_payload_iter].server_ticket_length);
printf("-- STRING_LENGTH           \t%d\n", packet->login_payload[login_payload_iter].server_ticket_length);
for (u32 server_ticket_iter = 0; server_ticket_iter < packet->login_payload[login_payload_iter].server_ticket_length; server_ticket_iter++)
{
packet->login_payload[login_payload_iter].server_ticket[server_ticket_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// bytes encryption_key
packet->login_payload[login_payload_iter].encryption_key_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->login_payload[login_payload_iter].encryption_key = memory_arena_push_length(arena, packet->login_payload[login_payload_iter].encryption_key_length);
printf("-- BYTES_LENGTH            \t%d\n", packet->login_payload[login_payload_iter].encryption_key_length);
for (u32 encryption_key_iter = 0; encryption_key_iter < packet->login_payload[login_payload_iter].encryption_key_length; encryption_key_iter++)
{
packet->login_payload[login_payload_iter].encryption_key[encryption_key_iter] = *(u8*)((uptr)data + offset);
offset++;
}

// u32 soe_protocol_version
packet->login_payload[login_payload_iter].soe_protocol_version = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- soe_protocol_version    \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].soe_protocol_version, (u64)packet->login_payload[login_payload_iter].soe_protocol_version, (f64)packet->login_payload[login_payload_iter].soe_protocol_version);

// u64 character_id
packet->login_payload[login_payload_iter].character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].character_id, (u64)packet->login_payload[login_payload_iter].character_id, (f64)packet->login_payload[login_payload_iter].character_id);

// u64 unk_u64
packet->login_payload[login_payload_iter].unk_u64 = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- unk_u64                 \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].unk_u64, (u64)packet->login_payload[login_payload_iter].unk_u64, (f64)packet->login_payload[login_payload_iter].unk_u64);

// string station_name
packet->login_payload[login_payload_iter].station_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->login_payload[login_payload_iter].station_name = memory_arena_push_length(arena, packet->login_payload[login_payload_iter].station_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->login_payload[login_payload_iter].station_name_length);
for (u32 station_name_iter = 0; station_name_iter < packet->login_payload[login_payload_iter].station_name_length; station_name_iter++)
{
packet->login_payload[login_payload_iter].station_name[station_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string character_name
packet->login_payload[login_payload_iter].character_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->login_payload[login_payload_iter].character_name = memory_arena_push_length(arena, packet->login_payload[login_payload_iter].character_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->login_payload[login_payload_iter].character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->login_payload[login_payload_iter].character_name_length; character_name_iter++)
{
packet->login_payload[login_payload_iter].character_name[character_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string unk_str
packet->login_payload[login_payload_iter].unk_str_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->login_payload[login_payload_iter].unk_str = memory_arena_push_length(arena, packet->login_payload[login_payload_iter].unk_str_length);
printf("-- STRING_LENGTH           \t%d\n", packet->login_payload[login_payload_iter].unk_str_length);
for (u32 unk_str_iter = 0; unk_str_iter < packet->login_payload[login_payload_iter].unk_str_length; unk_str_iter++)
{
packet->login_payload[login_payload_iter].unk_str[unk_str_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u64 server_feature_bit
packet->login_payload[login_payload_iter].server_feature_bit = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- server_feature_bit      \t%lld\t%llxh\t%f\n", (i64)packet->login_payload[login_payload_iter].server_feature_bit, (u64)packet->login_payload[login_payload_iter].server_feature_bit, (f64)packet->login_payload[login_payload_iter].server_feature_bit);

} // login_payload

} break;

case Login_Packet_Kind_CharacterDeleteRequest:
{
printf("[*] Unpacking CharacterDeleteRequest...\n");
Login_Packet_CharacterDeleteRequest* packet = packet_ptr;

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

} break;

case Login_Packet_Kind_TunnelAppPacketClientToServer:
{
printf("[*] Unpacking TunnelAppPacketClientToServer...\n");
Login_Packet_TunnelAppPacketClientToServer* packet = packet_ptr;

// u32 server_id
packet->server_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 unk1
packet->unk1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk1                    \t%lld\t%llxh\t%f\n", (i64)packet->unk1, (u64)packet->unk1, (f64)packet->unk1);

// stream data_client
packet->data_client_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->data_client = memory_arena_push_length(arena, packet->data_client_length * sizeof(packet->data_client[0]));
printf("-- STREAM_LENGTH           \t%d\n", packet->data_client_length);
for (u32 data_client_iter = 0; data_client_iter < (packet->data_client_length > (u32)0 ? (u32)1 : (u32)0); data_client_iter++)
{
// b8 tunnel_op_code
packet->data_client[data_client_iter].tunnel_op_code = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- tunnel_op_code          \t%lld\t%llxh\t%f\n", (i64)packet->data_client[data_client_iter].tunnel_op_code, (u64)packet->data_client[data_client_iter].tunnel_op_code, (f64)packet->data_client[data_client_iter].tunnel_op_code);

// b8 sub_op_code
packet->data_client[data_client_iter].sub_op_code = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- sub_op_code             \t%lld\t%llxh\t%f\n", (i64)packet->data_client[data_client_iter].sub_op_code, (u64)packet->data_client[data_client_iter].sub_op_code, (f64)packet->data_client[data_client_iter].sub_op_code);

// string character_name
packet->data_client[data_client_iter].character_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->data_client[data_client_iter].character_name = memory_arena_push_length(arena, packet->data_client[data_client_iter].character_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->data_client[data_client_iter].character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->data_client[data_client_iter].character_name_length; character_name_iter++)
{
packet->data_client[data_client_iter].character_name[character_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

} // data_client

} break;

case Login_Packet_Kind_TunnelAppPacketServerToClient:
{
printf("[*] Unpacking TunnelAppPacketServerToClient...\n");
Login_Packet_TunnelAppPacketServerToClient* packet = packet_ptr;

// u32 server_id
packet->server_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->server_id, (u64)packet->server_id, (f64)packet->server_id);

// u32 unk1
packet->unk1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unk1                    \t%lld\t%llxh\t%f\n", (i64)packet->unk1, (u64)packet->unk1, (f64)packet->unk1);

// stream data_server
packet->data_server_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->data_server = memory_arena_push_length(arena, packet->data_server_length * sizeof(packet->data_server[0]));
printf("-- STREAM_LENGTH           \t%d\n", packet->data_server_length);
for (u32 data_server_iter = 0; data_server_iter < (packet->data_server_length > (u32)0 ? (u32)1 : (u32)0); data_server_iter++)
{
// b8 tunnel_op_code
packet->data_server[data_server_iter].tunnel_op_code = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- tunnel_op_code          \t%lld\t%llxh\t%f\n", (i64)packet->data_server[data_server_iter].tunnel_op_code, (u64)packet->data_server[data_server_iter].tunnel_op_code, (f64)packet->data_server[data_server_iter].tunnel_op_code);

// b8 sub_op_code
packet->data_server[data_server_iter].sub_op_code = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- sub_op_code             \t%lld\t%llxh\t%f\n", (i64)packet->data_server[data_server_iter].sub_op_code, (u64)packet->data_server[data_server_iter].sub_op_code, (f64)packet->data_server[data_server_iter].sub_op_code);

// string character_name
packet->data_server[data_server_iter].character_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->data_server[data_server_iter].character_name = memory_arena_push_length(arena, packet->data_server[data_server_iter].character_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->data_server[data_server_iter].character_name_length);
for (u32 character_name_iter = 0; character_name_iter < packet->data_server[data_server_iter].character_name_length; character_name_iter++)
{
packet->data_server[data_server_iter].character_name[character_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string character_name2
packet->data_server[data_server_iter].character_name2_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->data_server[data_server_iter].character_name2 = memory_arena_push_length(arena, packet->data_server[data_server_iter].character_name2_length);
printf("-- STRING_LENGTH           \t%d\n", packet->data_server[data_server_iter].character_name2_length);
for (u32 character_name2_iter = 0; character_name2_iter < packet->data_server[data_server_iter].character_name2_length; character_name2_iter++)
{
packet->data_server[data_server_iter].character_name2[character_name2_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 status
packet->data_server[data_server_iter].status = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->data_server[data_server_iter].status, (u64)packet->data_server[data_server_iter].status, (f64)packet->data_server[data_server_iter].status);

} // data_server

} break;

case Login_Packet_Kind_CharacterDeleteReply:
{
printf("[*] Unpacking CharacterDeleteReply...\n");
Login_Packet_CharacterDeleteReply* packet = packet_ptr;

// u64 character_id
packet->character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->character_id, (u64)packet->character_id, (f64)packet->character_id);

// u32 status
packet->status = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->status, (u64)packet->status, (f64)packet->status);

// bytes payload3
packet->payload3_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->payload3 = memory_arena_push_length(arena, packet->payload3_length);
printf("-- BYTES_LENGTH            \t%d\n", packet->payload3_length);
for (u32 payload3_iter = 0; payload3_iter < packet->payload3_length; payload3_iter++)
{
packet->payload3[payload3_iter] = *(u8*)((uptr)data + offset);
offset++;
}

} break;

case Login_Packet_Kind_CharacterSelectInfoReply:
{
printf("[*] Unpacking CharacterSelectInfoReply...\n");
Login_Packet_CharacterSelectInfoReply* packet = packet_ptr;

// u32 character_status
packet->character_status = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- character_status        \t%lld\t%llxh\t%f\n", (i64)packet->character_status, (u64)packet->character_status, (f64)packet->character_status);

// b8 can_bypass_server_lock
packet->can_bypass_server_lock = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- can_bypass_server_lock  \t%lld\t%llxh\t%f\n", (i64)packet->can_bypass_server_lock, (u64)packet->can_bypass_server_lock, (f64)packet->can_bypass_server_lock);

// list characters
packet->characters_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters = memory_arena_push_length(arena, packet->characters_count * sizeof(packet->characters[0]));
printf("-- LIST_COUNT              \t%d\n", packet->characters_count);
for (u32 characters_iter = 0; characters_iter < packet->characters_count; characters_iter++)
{
// u64 character_id
packet->characters[characters_iter].character_id = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- character_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].character_id, (u64)packet->characters[characters_iter].character_id, (f64)packet->characters[characters_iter].character_id);

// u32 server_id
packet->characters[characters_iter].server_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- server_id               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].server_id, (u64)packet->characters[characters_iter].server_id, (f64)packet->characters[characters_iter].server_id);

// u64 last_login_date
packet->characters[characters_iter].last_login_date = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- last_login_date         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].last_login_date, (u64)packet->characters[characters_iter].last_login_date, (f64)packet->characters[characters_iter].last_login_date);

// u32 null_field
packet->characters[characters_iter].null_field = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- null_field              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].null_field, (u64)packet->characters[characters_iter].null_field, (f64)packet->characters[characters_iter].null_field);

// u32 status
packet->characters[characters_iter].status = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- status                  \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].status, (u64)packet->characters[characters_iter].status, (f64)packet->characters[characters_iter].status);

// stream payload4
packet->characters[characters_iter].payload4_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4 = memory_arena_push_length(arena, packet->characters[characters_iter].payload4_length * sizeof(packet->characters[characters_iter].payload4[0]));
printf("-- STREAM_LENGTH           \t%d\n", packet->characters[characters_iter].payload4_length);
for (u32 payload4_iter = 0; payload4_iter < (packet->characters[characters_iter].payload4_length > (u32)0 ? (u32)1 : (u32)0); payload4_iter++)
{
// string name
packet->characters[characters_iter].payload4[payload4_iter].name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].name = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].name_length);
for (u32 name_iter = 0; name_iter < packet->characters[characters_iter].payload4[payload4_iter].name_length; name_iter++)
{
packet->characters[characters_iter].payload4[payload4_iter].name[name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u8 empire_id
packet->characters[characters_iter].payload4[payload4_iter].empire_id = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- empire_id               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].empire_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].empire_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].empire_id);

// u32 battle_rank
packet->characters[characters_iter].payload4[payload4_iter].battle_rank = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- battle_rank             \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].battle_rank, (u64)packet->characters[characters_iter].payload4[payload4_iter].battle_rank, (f64)packet->characters[characters_iter].payload4[payload4_iter].battle_rank);

// u32 next_battle_rank_percent
packet->characters[characters_iter].payload4[payload4_iter].next_battle_rank_percent = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- next_battle_rank_percent\t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].next_battle_rank_percent, (u64)packet->characters[characters_iter].payload4[payload4_iter].next_battle_rank_percent, (f64)packet->characters[characters_iter].payload4[payload4_iter].next_battle_rank_percent);

// u32 head_id
packet->characters[characters_iter].payload4[payload4_iter].head_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- head_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].head_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].head_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].head_id);

// u32 model_id
packet->characters[characters_iter].payload4[payload4_iter].model_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- model_id                \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].model_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].model_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].model_id);

// u32 gender
packet->characters[characters_iter].payload4[payload4_iter].gender = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- gender                  \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].gender, (u64)packet->characters[characters_iter].payload4[payload4_iter].gender, (f64)packet->characters[characters_iter].payload4[payload4_iter].gender);

// u32 profile_id
packet->characters[characters_iter].payload4[payload4_iter].profile_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- profile_id              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].profile_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].profile_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].profile_id);

// u32 unknown_dword
packet->characters[characters_iter].payload4[payload4_iter].unknown_dword = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword);

// u32 loadout_id
packet->characters[characters_iter].payload4[payload4_iter].loadout_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- loadout_id              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_id);

// u32 unknown_dword_1
packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_1         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_1);

// u8 unknown_byte_1
packet->characters[characters_iter].payload4[payload4_iter].unknown_byte_1 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unknown_byte_1          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_byte_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_byte_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_byte_1);

// u32 unknown_dword_2
packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_2         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_2);

// u32 unknown_dword_3
packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_3 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_3         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_3, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_3, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_3);

// string loadout_name
packet->characters[characters_iter].payload4[payload4_iter].loadout_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].loadout_name = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].loadout_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].loadout_name_length);
for (u32 loadout_name_iter = 0; loadout_name_iter < packet->characters[characters_iter].payload4[payload4_iter].loadout_name_length; loadout_name_iter++)
{
packet->characters[characters_iter].payload4[payload4_iter].loadout_name[loadout_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 tint_item_id
packet->characters[characters_iter].payload4[payload4_iter].tint_item_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- tint_item_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].tint_item_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].tint_item_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].tint_item_id);

// u32 unknown_dword_4
packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_4 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_4         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_4, (u64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_4, (f64)packet->characters[characters_iter].payload4[payload4_iter].unknown_dword_4);

// u32 decal_item_id
packet->characters[characters_iter].payload4[payload4_iter].decal_item_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- decal_item_id           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].decal_item_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].decal_item_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].decal_item_id);

// list loadout_slots
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots_count * sizeof(packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[0]));
printf("-- LIST_COUNT              \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].loadout_slots_count);
for (u32 loadout_slots_iter = 0; loadout_slots_iter < packet->characters[characters_iter].payload4[payload4_iter].loadout_slots_count; loadout_slots_iter++)
{
// u32 slot_id
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].slot_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- slot_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].slot_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].slot_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].slot_id);

// u32 index
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].index = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- index                   \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].index, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].index, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].index);

// u32 item_line_id
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_line_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_line_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_line_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_line_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_line_id);

// u8 flags
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].flags = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- flags                   \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].flags, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].flags, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].flags);

// list attachments
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments_count * sizeof(packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments[0]));
printf("-- LIST_COUNT              \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments_count);
for (u32 attachments_iter = 0; attachments_iter < packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments_count; attachments_iter++)
{
// u32 attachment_id
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments[attachments_iter].attachment_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- attachment_id           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments[attachments_iter].attachment_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments[attachments_iter].attachment_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachments[attachments_iter].attachment_id);

} // attachments

// list attachment_classes
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes_count * sizeof(packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[0]));
printf("-- LIST_COUNT              \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes_count);
for (u32 attachment_classes_iter = 0; attachment_classes_iter < packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes_count; attachment_classes_iter++)
{
// u32 class_id
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].class_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- class_id                \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].class_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].class_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].class_id);

// u32 attachment_id
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].attachment_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- attachment_id           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].attachment_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].attachment_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].attachment_classes[attachment_classes_iter].attachment_id);

} // attachment_classes

// u32 tint_item_id
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].tint_item_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- tint_item_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].tint_item_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].tint_item_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].tint_item_id);

// u32 item_slot
packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_slot = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_slot               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_slot, (u64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_slot, (f64)packet->characters[characters_iter].payload4[payload4_iter].loadout_slots[loadout_slots_iter].item_slot);

} // loadout_slots

// list item_definitions
packet->characters[characters_iter].payload4[payload4_iter].item_definitions_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].item_definitions = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].item_definitions_count * sizeof(packet->characters[characters_iter].payload4[payload4_iter].item_definitions[0]));
printf("-- LIST_COUNT              \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].item_definitions_count);
for (u32 item_definitions_iter = 0; item_definitions_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions_count; item_definitions_iter++)
{
// u32 item_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id);

// u32 item_id_2
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_id_2               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_id_2);

// u8 flags_1
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_1 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- flags_1                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_1);

// u8 flags_2
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_2 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- flags_2                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].flags_2);

// u32 name_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].name_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].name_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].name_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].name_id);

// u32 description_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].description_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].description_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].description_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].description_id);

// u32 unknown_dword_1
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_1 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_1         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_1);

// u32 icon_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].icon_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- icon_id                 \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].icon_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].icon_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].icon_id);

// u32 unknown_dword_2
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_2         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_2);

// u32 hudImageSetId
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hudImageSetId = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- hudImageSetId           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hudImageSetId, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hudImageSetId, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hudImageSetId);

// u32 hud_image_set_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hud_image_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- hud_image_set_id        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hud_image_set_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hud_image_set_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].hud_image_set_id);

// u32 unknown_dword_4
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_4 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_4         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_4, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_4, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_4);

// u32 cost
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].cost = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- cost                    \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].cost, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].cost, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].cost);

// u32 item_class
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_class = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_class              \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_class, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_class, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_class);

// u32 unknown_dword_5
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_5 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_5         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_5, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_5, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_5);

// u32 item_slot
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_slot = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_slot               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_slot, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_slot, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_slot);

// u32 slot_override_key
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].slot_override_key = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- slot_override_key       \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].slot_override_key, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].slot_override_key, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].slot_override_key);

// u8 unknown_dword6
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword6 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unknown_dword6          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword6, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword6, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword6);

// string model_name
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name_length);
for (u32 model_name_iter = 0; model_name_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name_length; model_name_iter++)
{
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].model_name[model_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string unknown_string
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string_length);
printf("-- STRING_LENGTH           \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string_length);
for (u32 unknown_string_iter = 0; unknown_string_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string_length; unknown_string_iter++)
{
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_string[unknown_string_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u8 unknown_byte_1
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_byte_1 = endian_read_u8_little(data + offset);
offset += sizeof(u8);
printf("-- unknown_byte_1          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_byte_1, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_byte_1, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_byte_1);

// u32 item_type
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_type               \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_type, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_type, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].item_type);

// u32 category_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].category_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- category_id             \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].category_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].category_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].category_id);

// u32 unknown_dword_7
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_7 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_7         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_7, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_7, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_7);

// u32 unknown_dword_8
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_8 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_8         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_8, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_8, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_8);

// u32 unknown_dword_9
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_9 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_9         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_9, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_9, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_9);

// u32 unknown_dword_10
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_10 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_10        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_10, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_10, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_10);

// u32 unknown_dword_11
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_11 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_11        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_11, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_11, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_11);

// u32 activatable_ability_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].activatable_ability_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- activatable_ability_id  \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].activatable_ability_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].activatable_ability_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].activatable_ability_id);

// u32 passive_ability_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].passive_ability_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- passive_ability_id      \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].passive_ability_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].passive_ability_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].passive_ability_id);

// u32 unknown_dword_12
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_12 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_12        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_12, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_12, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_12);

// u32 max_stack_size
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].max_stack_size = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- max_stack_size          \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].max_stack_size, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].max_stack_size, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].max_stack_size);

// string tint_name
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name_length);
for (u32 tint_name_iter = 0; tint_name_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name_length; tint_name_iter++)
{
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].tint_name[tint_name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 unknown_dword_13
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_13 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_13        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_13, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_13, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_13);

// u32 unknown_dword_14
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_14 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_14        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_14, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_14, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_14);

// u32 unknown_dword_15
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_15 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_15        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_15, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_15, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_15);

// u32 unknown_dword_16
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_16 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_16        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_16, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_16, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_16);

// u32 ui_model_camera
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].ui_model_camera = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- ui_model_camera         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].ui_model_camera, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].ui_model_camera, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].ui_model_camera);

// u32 equip_count_max
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].equip_count_max = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- equip_count_max         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].equip_count_max, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].equip_count_max, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].equip_count_max);

// u32 currency_type
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].currency_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- currency_type           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].currency_type, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].currency_type, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].currency_type);

// u32 unknown_dword_17
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_17 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_17        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_17, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_17, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_17);

// u32 client_item_type
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_item_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- client_item_type        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_item_type, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_item_type, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_item_type);

// u32 skill_set_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].skill_set_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- skill_set_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].skill_set_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].skill_set_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].skill_set_id);

// string overlay_texture
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture_length);
printf("-- STRING_LENGTH           \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture_length);
for (u32 overlay_texture_iter = 0; overlay_texture_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture_length; overlay_texture_iter++)
{
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].overlay_texture[overlay_texture_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string decal_slot
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot_length);
printf("-- STRING_LENGTH           \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot_length);
for (u32 decal_slot_iter = 0; decal_slot_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot_length; decal_slot_iter++)
{
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].decal_slot[decal_slot_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 unknown_dword_18
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_18 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_18        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_18, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_18, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_18);

// u32 trial_duration_sec
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_duration_sec = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- trial_duration_sec      \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_duration_sec, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_duration_sec, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_duration_sec);

// u32 trial_exclusion_sec
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_exclusion_sec = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- trial_exclusion_sec     \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_exclusion_sec, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_exclusion_sec, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].trial_exclusion_sec);

// u32 client_use_requirement_id
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- client_use_requirement_id\t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id);

// string override_appearance
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance_length);
printf("-- STRING_LENGTH           \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance_length);
for (u32 override_appearance_iter = 0; override_appearance_iter < packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance_length; override_appearance_iter++)
{
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].override_appearance[override_appearance_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 unknown_dword_19
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_19 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- unknown_dword_19        \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_19, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_19, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].unknown_dword_19);

// u32 client_use_requirement_id_2
packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- client_use_requirement_id_2\t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].item_definitions[item_definitions_iter].client_use_requirement_id_2);

} // item_definitions

// list attachment_definitions
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions_count * sizeof(packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[0]));
printf("-- LIST_COUNT              \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions_count);
for (u32 attachment_definitions_iter = 0; attachment_definitions_iter < packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions_count; attachment_definitions_iter++)
{
// u32 attachment_id
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- attachment_id           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id);

// u32 attachment_id_2
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id_2 = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- attachment_id_2         \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id_2, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id_2, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].attachment_id_2);

// u32 group_id
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].group_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- group_id                \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].group_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].group_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].group_id);

// u32 item_line_id
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].item_line_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- item_line_id            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].item_line_id, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].item_line_id, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].item_line_id);

// u32 flags
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].flags = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- flags                   \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].flags, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].flags, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].flags);

// list classes
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes = memory_arena_push_length(arena, packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes_count * sizeof(packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes[0]));
printf("-- LIST_COUNT              \t%d\n", packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes_count);
for (u32 classes_iter = 0; classes_iter < packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes_count; classes_iter++)
{
// u32 element_type
packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes[classes_iter].element_type = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- element_type            \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes[classes_iter].element_type, (u64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes[classes_iter].element_type, (f64)packet->characters[characters_iter].payload4[payload4_iter].attachment_definitions[attachment_definitions_iter].classes[classes_iter].element_type);

} // classes

} // attachment_definitions

// u64 last_use_date
packet->characters[characters_iter].payload4[payload4_iter].last_use_date = endian_read_u64_little(data + offset);
offset += sizeof(u64);
printf("-- last_use_date           \t%lld\t%llxh\t%f\n", (i64)packet->characters[characters_iter].payload4[payload4_iter].last_use_date, (u64)packet->characters[characters_iter].payload4[payload4_iter].last_use_date, (f64)packet->characters[characters_iter].payload4[payload4_iter].last_use_date);

} // payload4

} // characters

} break;

case Login_Packet_Kind_ServerListReply:
{
printf("[*] Unpacking ServerListReply...\n");
Login_Packet_ServerListReply* packet = packet_ptr;

// list servers
packet->servers_count = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->servers = memory_arena_push_length(arena, packet->servers_count * sizeof(packet->servers[0]));
printf("-- LIST_COUNT              \t%d\n", packet->servers_count);
for (u32 servers_iter = 0; servers_iter < packet->servers_count; servers_iter++)
{
// u32 id
packet->servers[servers_iter].id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- id                      \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].id, (u64)packet->servers[servers_iter].id, (f64)packet->servers[servers_iter].id);

// u32 state
packet->servers[servers_iter].state = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- state                   \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].state, (u64)packet->servers[servers_iter].state, (f64)packet->servers[servers_iter].state);

// b8 is_locked
packet->servers[servers_iter].is_locked = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- is_locked               \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].is_locked, (u64)packet->servers[servers_iter].is_locked, (f64)packet->servers[servers_iter].is_locked);

// string name
packet->servers[servers_iter].name_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->servers[servers_iter].name = memory_arena_push_length(arena, packet->servers[servers_iter].name_length);
printf("-- STRING_LENGTH           \t%d\n", packet->servers[servers_iter].name_length);
for (u32 name_iter = 0; name_iter < packet->servers[servers_iter].name_length; name_iter++)
{
packet->servers[servers_iter].name[name_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 name_id
packet->servers[servers_iter].name_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- name_id                 \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].name_id, (u64)packet->servers[servers_iter].name_id, (f64)packet->servers[servers_iter].name_id);

// string description
packet->servers[servers_iter].description_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->servers[servers_iter].description = memory_arena_push_length(arena, packet->servers[servers_iter].description_length);
printf("-- STRING_LENGTH           \t%d\n", packet->servers[servers_iter].description_length);
for (u32 description_iter = 0; description_iter < packet->servers[servers_iter].description_length; description_iter++)
{
packet->servers[servers_iter].description[description_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 description_id
packet->servers[servers_iter].description_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- description_id          \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].description_id, (u64)packet->servers[servers_iter].description_id, (f64)packet->servers[servers_iter].description_id);

// u32 req_feature_id
packet->servers[servers_iter].req_feature_id = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- req_feature_id          \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].req_feature_id, (u64)packet->servers[servers_iter].req_feature_id, (f64)packet->servers[servers_iter].req_feature_id);

// string server_info
packet->servers[servers_iter].server_info_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->servers[servers_iter].server_info = memory_arena_push_length(arena, packet->servers[servers_iter].server_info_length);
printf("-- STRING_LENGTH           \t%d\n", packet->servers[servers_iter].server_info_length);
for (u32 server_info_iter = 0; server_info_iter < packet->servers[servers_iter].server_info_length; server_info_iter++)
{
packet->servers[servers_iter].server_info[server_info_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// u32 population_level
packet->servers[servers_iter].population_level = endian_read_u32_little(data + offset);
offset += sizeof(u32);
printf("-- population_level        \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].population_level, (u64)packet->servers[servers_iter].population_level, (f64)packet->servers[servers_iter].population_level);

// string population_data
packet->servers[servers_iter].population_data_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->servers[servers_iter].population_data = memory_arena_push_length(arena, packet->servers[servers_iter].population_data_length);
printf("-- STRING_LENGTH           \t%d\n", packet->servers[servers_iter].population_data_length);
for (u32 population_data_iter = 0; population_data_iter < packet->servers[servers_iter].population_data_length; population_data_iter++)
{
packet->servers[servers_iter].population_data[population_data_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// string access_expression
packet->servers[servers_iter].access_expression_length = endian_read_u32_little(data + offset);
offset += sizeof(u32);
packet->servers[servers_iter].access_expression = memory_arena_push_length(arena, packet->servers[servers_iter].access_expression_length);
printf("-- STRING_LENGTH           \t%d\n", packet->servers[servers_iter].access_expression_length);
for (u32 access_expression_iter = 0; access_expression_iter < packet->servers[servers_iter].access_expression_length; access_expression_iter++)
{
packet->servers[servers_iter].access_expression[access_expression_iter] = *(i8*)((uptr)data + offset);
offset++;
}

// b8 is_access_allowed
packet->servers[servers_iter].is_access_allowed = endian_read_b8_little(data + offset);
offset += sizeof(b8);
printf("-- is_access_allowed       \t%lld\t%llxh\t%f\n", (i64)packet->servers[servers_iter].is_access_allowed, (u64)packet->servers[servers_iter].is_access_allowed, (f64)packet->servers[servers_iter].is_access_allowed);

} // servers

} break;

default:
{
printf("[!] Unpacking %s not implemented\n", login_packet_names[packet_kind]);
}
}
}
