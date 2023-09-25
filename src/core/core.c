u64 generate_random_guid()
{
    u64 part1 = ((u64)rand() << 32) | rand();
    u64 part2 = ((u64)rand() << 32) | rand();

    u64 result = part1 ^ part2;

    return result;
}
