
#define MAX_TRANSIENT_ID 16777215


internal
u32 server_generate_transient_id()
{
    local_persist u32 id;

    if (id < MAX_TRANSIENT_ID)
        id++;

    return id;
}