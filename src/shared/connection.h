typedef struct Connection_Args Connection_Args;
struct Connection_Args {
    u32 crc_seed;
    u8 crc_length;
    u8 compression;
    u32 udp_length;
    u8 encryption;
    b32 should_dump_core;
    b32 should_dump_login;
    b32 should_dump_tunnel;
    b32 should_dump_gateway;
    b32 should_dump_zone;
};