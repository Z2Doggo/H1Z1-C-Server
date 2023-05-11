#define TRANSIENT_LENGTH 16
#define MAX_GUIDS 2048

uint2b generate_transient_id() {
    uint2b transient_id = {0, 0};
    uint2b random_num;
    srand((unsigned) time(NULL));
    for (int i = 0; i < TRANSIENT_LENGTH; i++) {
        random_num.value = (u32)rand() % 16;
        random_num.length = 4;
        transient_id.value |= (random_num.value << (4 * (TRANSIENT_LENGTH - i - 1)));
    }
    transient_id.value &= 0x7FFF; // ensure the transient_id is non-negative and within uint2b range
    transient_id.length = 16; // set length to 16 bits
    return transient_id;
}

uint2b get_transient_id() {
    // Initialize array to hold guids
    static uint2b transient_ids[MAX_GUIDS] = {{0, 0}};
    // Find an empty slot to store guid
    int i = 0;
    while (transient_ids[i].value != 0 && i < MAX_GUIDS) {
        i++;
    }
    if (i >= MAX_GUIDS) {
        fprintf(stderr, "No more slots available to store guid\n");
        return (uint2b){0, 0};
    }
    // Generate guid and store it in the array
    if (transient_ids[i].value == 0) {
        transient_ids[i] = generate_transient_id();
    }
    return transient_ids[i];
}

void delete_transient_id(int delete_status) {
    // If delete_status is true, delete all stored guids
    if (delete_status == 1) {
        static uint2b transient_ids[MAX_GUIDS] = {{0, 0}};
        memset(transient_ids, 0, sizeof(transient_ids)); // use memset to clear the array
    }
}