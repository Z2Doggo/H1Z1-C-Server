#define TRANSIENT_LENGTH 16
#define MAX_GUIDS 2048

u32 generate_transient_id() {
    u32 transient_id = 0;
    u32 random_num;
    srand((unsigned) time(NULL));
    for (int i = 0; i < TRANSIENT_LENGTH; i++) {
        random_num = (u32)rand() % 16;
        transient_id |= (random_num << (4 * (TRANSIENT_LENGTH - i - 1)));
    }
    transient_id &= 0x7FFF; // ensure the transient_id is non-negative and within u32 range
    return transient_id;
}

u32 get_transient_id() {
    // Initialize array to hold guids
    static u32 transient_ids[MAX_GUIDS] = {0};
    // Find an empty slot to store guid
    int i = 0;
    while (transient_ids[i] != 0 && i < MAX_GUIDS) {
        i++;
    }
    if (i >= MAX_GUIDS) {
        fprintf(stderr, "No more slots available to store guid\n");
        return 0;
    }
    // Generate guid and store it in the array
    if (transient_ids[i] == 0) {
        transient_ids[i] = generate_transient_id();
    }
    return transient_ids[i];
}

void delete_transient_id(int delete_status) {
    // If delete_status is true, delete all stored guids
    if (delete_status == 1) {
        static u32 transient_ids[MAX_GUIDS] = {0};
        memset(transient_ids, 0, sizeof(transient_ids)); // use memset to clear the array
    }
}