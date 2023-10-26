typedef struct Packet_Queue_Entry Packet_Queue_Entry;
struct Packet_Queue_Entry
{
    // i32   packet_kind;
    i32 buffer_offset;
    i32 length;
    // i32 	max_packed_length;
    void *session_state;
};

#define PACKET_QUEUE_SEND(name) void name(void *server_state, void *session_state, u8 *base_buffer, i32 total_length)
typedef PACKET_QUEUE_SEND(packet_queue_send_t);

typedef struct Packet_Queue Packet_Queue;
struct Packet_Queue
{
    Packet_Queue_Entry *entries;
    i32 entries_tail;
    i32 entries_capacity;

    u8 *buffer;
    i32 buffer_tail;
    i32 buffer_capacity;

    packet_queue_send_t *packet_queue_send;
};