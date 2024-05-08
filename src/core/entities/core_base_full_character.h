typedef enum Items {
    // #region WEAPONS
    WEAPON_AR15 = 10,
    WEAPON_AK47 = 2229,
    WEAPON_SHOTGUN = 2663,
    WEAPON_CROWBAR = 82,
    WEAPON_COMBATKNIFE = 84,
    WEAPON_MACHETE01 = 83,
    WEAPON_KATANA = 2961,
    WEAPON_BAT_WOOD = 1724,
    WEAPON_GUITAR = 1733,
    WEAPON_AXE_WOOD = 58,
    WEAPON_AXE_FIRE = 1745,
    WEAPON_HAMMER = 1536,
    WEAPON_HATCHET = 3,
    WEAPON_PIPE = 1448,
    WEAPON_BAT_ALUM = 1721,
    WEAPON_BOW_MAKESHIFT = 113,
    WEAPON_BOW_WOOD = 1720,
    WEAPON_BOW_RECURVE = 1986,
    WEAPON_1911 = 2,
    WEAPON_M9 = 1997,
    WEAPON_308 = 1373,
    WEAPON_BINOCULARS = 1542,
    WEAPON_CROSSBOW = 2246,
    WEAPON_R380 = 1991,
    WEAPON_MOLOTOV = 14,
    WEAPON_MAGNUM = 1718,
    WEAPON_FLASHLIGHT = 1380,
    WEAPON_WRENCH = 1538,
    WEAPON_BRANCH = 1725,
    WEAPON_FISTS = 85,
    WEAPON_FROSTBITE = 3445,
    WEAPON_BLAZE = 3446,
    WEAPON_NAGAFENS_RAGE = 3448,
    WEAPON_PURGE = 3449,
    WEAPON_REAPER = 3450,
    WEAPON_HAMMER_DEMOLITION = 1903,
    WEAPON_TORCH = 5,
    WEAPON_TORCH_ETHANOL = 1389,
    WEAPON_HATCHET_MAKESHIFT = 1708,
    WEAPON_AK47_MODIFIED = 2399,
    WEAPON_SPEAR = 1382,
    WEAPON_REMOVER = 1776,
    // #endregion

    // #region AMMO
    AMMO_223 = 1429,
    AMMO_12GA = 1511,
    AMMO_45 = 1428,
    AMMO_9MM = 1998, // TODO = assign it to a spawner
    AMMO_308 = 1469,
    AMMO_380 = 1992,
    AMMO_762 = 2325,
    AMMO_44 = 1719,
    AMMO_ARROW = 112,
    AMMO_ARROW_EXPLOSIVE = 138,
    AMMO_ARROW_FLAMING = 1434,
    // #endregion

    // #region PERISHABLE
    ANTIBIOTICS = 1388,
    VITAMINS = 1512,
    IMMUNITY_BOOSTERS = 1471,
    FIRST_AID = 78,
    BANDAGE = 24,
    BANDAGE_DRESSED = 2214,
    GAUZE = 1751,
    SWIZZLE = 1709,
    GROUND_COFFEE = 56, // TODO = expand with more canned food types
    CANNED_FOOD01 = 7,
    CANNED_FOOD02 = 1393,
    CANNED_FOOD03 = 1394,
    CANNED_FOOD04 = 1391,
    CANNED_FOOD05 = 1392,
    CANNED_FOOD06 = 1396,
    CANNED_FOOD07 = 1397,
    CANNED_FOOD08 = 1398,
    CANNED_FOOD09 = 1399,
    CANNED_FOOD10 = 1400,
    CANNED_FOOD11 = 1401,
    CANNED_FOOD25 = 1431,
    CANNED_FOOD21 = 1395,
    CANNED_FOOD26 = 2536,
    BLACKBERRY = 105,
    BLACKBERRY_JUICE = 1361,
    BLACKBERRY_PIE = 1706,
    BLACKBERRY_PIE_SLICE = 1726,
    BLACKBERRY_HANDFUL = 3214,
    WATER_PURE = 1371,
    WATER_STAGNANT = 1535,
    WATER_DIRTY = 1368,
    MRE_APPLE = 1402, // TODO = add other MRE types
    MRE01 = 1403,
    MRE02 = 1404,
    MRE03 = 1405,
    MRE04 = 1406,
    MRE05 = 1407,
    MRE06 = 1409,
    MRE07 = 1408,
    MRE08 = 1410,
    MRE09 = 1411,
    MRE10 = 1412,
    MRE11 = 1413,
    MRE12 = 1414,
    SANDWICH_BEAR = 1459,
    STEAK_BEAR = 1451,
    SURVIVAL_BREAD = 1456,
    MEAT_BEAR = 1450,
    COFFEE = 55,
    COFFEE_SUGAR = 71,
    STEAK_RABBIT = 117,
    MEAT_RABBIT = 116,
    SANDWICH_RABBIT = 1457,
    STEW_RABBIT = 118,
    CORN = 107,
    CORN_ROASTED = 1387,
    JERKY_DEER = 21,
    MEAT_VENISON = 20,
    SANDWICH_DEER = 1460,
    STEAK_DEER = 61,
    HONEY = 2192,
    MOONSHINE = 1386,
    COLD_MEDICINE = 1742,
    SURVIVAL_BORSCHT = 1379,
    SANDWICH_WOLF = 1458,
    STEAK_WOLF = 1343,
    MEAT_WOLF = 1342,
    MEAT_ROTTEN = 1381,
    // #endregion

    // #region CONSTRUCTION
    GROUND_TAMPER = 124,
    SHACK = 1433,
    SHACK_SMALL = 1440,
    SHACK_BASIC = 1468,
    SHELTER = 150,
    SHELTER_LARGE = 153,
    SHELTER_UPPER_LARGE = 1897,
    SHELTER_UPPER = 1898,
    FOUNDATION = 1378,
    FOUNDATION_EXPANSION = 2336,
    FOUNDATION_RAMP = 2269,
    FOUNDATION_STAIRS = 2270,
    METAL_GATE = 148,
    DOOR_METAL = 1881,
    DOOR_WOOD = 1435,
    METAL_WALL = 149,
    METAL_WALL_UPPER = 1896,
    DOOR_BASIC = 1470,
    LANDMINE = 74,
    IED = 1699,
    PUNJI_STICKS = 98,
    PUNJI_STICK_ROW = 3580,
    SNARE = 1415,
    ANIMAL_TRAP = 91,
    BARBED_WIRE = 108,
    BARBEQUE = 1447,
    BEE_BOX = 2034,
    CAMPFIRE = 15,
    CANDLE = 1904,
    DEW_COLLECTOR = 97,
    FURNACE = 64,
    LOOKOUT_TOWER = 2272,
    METAL_DOORWAY = 1969,
    REPAIR_BOX = 2792,
    SLEEPING_MAT = 51,
    STORAGE_BOX = 1982,
    STRUCTURE_STAIRS = 154,
    STRUCTURE_STAIRS_UPPER = 1900,
    WORKBENCH = 1891,
    WORKBENCH_WEAPON = 3778,
    BARRICADE = 122,
    // #endregion

    // #region COMPONENT
    SHARD_METAL = 114,
    SHARD_BRASS = 3780,
    SHARD_PLASTIC = 3775,
    GUNPOWDER_REFINED = 3805,
    ALLOY_LEAD = 3779,
    PROTOTYPE_MECHANISM = 3455,
    PROTOTYPE_TRIGGER_ASSEMBLY = 3456,
    PROTOTYPE_RECEIVER = 3457,
    NAIL = 135,
    BACKPACK_FRAME = 1466,
    METAL_BRACKET = 141,
    ANIMAL_FAT = 72,
    FLOUR = 1455,
    WAX = 2193,
    HONEYCOMB = 2203,
    PHONE_DEAD = 2635,
    PHONE_BATTERY = 2637,
    PHONE_CHARGED = 2636,
    CORN_MASH = 1385,
    YEAST = 1445,
    DEER_SCENT = 1462,
    DEER_BLADDER = 1463,
    DUCT_TAPE = 134,
    TRAP_IGNITION_KIT = 2831,
    SALINE = 77,
    WHEAT = 1438,
    TWINE = 142,
    GUN_PART = 1890,
    REPAIR_KIT_GUN = 1895,
    UPGRADE_KIT_GUN = 2419,
    CHARCOAL = 26,
    METAL_BAR = 39,
    // #endregion

    // #region Quest Items
    ANTI_VIRAL_BOTTLE = 2671,
    HANDWRITTEN_NOTE_CAROLINE = 2611,
    ANTI_VIRAL_BOTTLE_EMPTY = 2612,
    GRENADE_SONIC_BROKEN = 3040,
    VIAL_H1Z1_B_PLASMA = 3041,
    VIAL_H1Z1_REDUCER = 2498,
    BATTERIES_AA = 2833,
    BRAIN_TREATED = 2643,
    BRAIN_INFECTED = 2642,
    SYRINGE_INFECTED_BLOOD = 1510,
    EMPTY_SPECIMEN_BAG = 2641,
    DEAD_CELL_PHONE = 2635,
    WEAK_CELL_PHONE_BATTERY = 2637,
    CRACKED_CLIPBOARD = 2610,
    DOCTORS_FILE = 2631,
    WEICHS_WALLET = 2703,
    WEICHS_REPORT = 2633,
    KLAVISK_NOTE = 2632,
    REFRIGERATOR_NOTE = 3075,
    DOCTORS_MEMO = 3076,
    // #endregion

    // #region Traps
    TRAP_FIRE = 2812,
    TRAP_FLASH = 2810,
    TRAP_GAS = 2811,
    TRAP_SHOCK = 2832,
    // #endregion

    // #region
    BACKPACK_FRAMED = 2111,
    BACKPACK_SATCHEL = 1432,
    BACKPACK_MILITARY_TAN = 2124,
    BACKPACK_BLUE_ORANGE = 2038,
    HELMET_MOTORCYCLE = 2170, // TODO = expand with other default helmet colors
    HAT_CAP = 12,             // TODO = expand with other cap colors
    SHIRT_DEFAULT = 2088,     // TODO = expand with other default shirts
    PANTS_DEFAULT = 2177,     // TODO = expand with other default pants
    SHIRT_SCRUBS_BLUE = 2553,
    PANTS_SCRUBS_BLUE = 2557,
    SURGEON_MASK_AQUA = 2569,
    CAP_SCRUBS_BLUE = 2560,

    CONVEYS_BLUE = 2217, // TODO = expand with other convey colors
    HAT_BEANIE = 2162,
    SUGAR = 57,
    BATTERY = 1696,
    SPARKPLUGS = 1701,
    SALT = 22,
    LIGHTER = 1436,
    BOW_DRILL = 1452,
    WATER_EMPTY = 1353,
    FUEL_BIOFUEL = 73,
    FUEL_ETHANOL = 1384,
    WOOD_PLANK = 109,
    METAL_SHEET = 46,
    METAL_SCRAP = 48,
    BROKEN_METAL_ITEM = 1354,
    TARP = 155,
    WOOD_LOG = 16,
    WOOD_STICK = 111,
    GROUND_TILLER = 1383,
    FERTILIZER = 25,
    SEED_CORN = 1987,
    SEED_WHEAT = 1988,
    VIAL_EMPTY = 2510,
    SYRINGE_EMPTY = 1508,
    GHILLIE_SUIT = 92,
    GHILLIE_SUIT_TAN = 2570,
    HELMET_TACTICAL = 2172,
    RESPIRATOR = 2148,
    NV_GOGGLES = 1700,
    ALL_PURPOSE_GOGGLES = 1693,
    GUNPOWDER = 11,
    KEVLAR_DEFAULT = 2271,
    ARMOR_PLATED = 2205,
    ARMOR_WOODEN = 2204,
    CLOTH = 23,
    METAL_PIPE = 47,
    GRENADE_SMOKE = 2236,
    GRENADE_FLASH = 2235,
    GRENADE_GAS = 2237,
    GRENADE_HE = 65,
    GRENADE_SCREAM = 3022,
    MAP = 1985,
    COMPASS = 1441,
    FLARE = 1804,
    FLARE_PARACHUTE = 1906,
    FLARE_SMOKE = 1672,
    BACKPACK_RASTA = 2393,
    WAIST_PACK = 1803,
    FANNY_PACK_DEV = 1,
    VEHICLE_KEY = 3460,
    CODED_MESSAGE = 2722,
    AIRDROP_CODE = 2675,
    BANDANA_BASIC = 2323,
    GLOVES_FINGERLESS = 2324,
    HAND_SHOVEL = 1697,
    COMPASS_IMPROVISED = 1444,
    SKINNING_KNIFE = 110,
    RIGGED_LIGHT = 1748,
    SYRINGE_H1Z1_REDUCER = 1464,
    LOCKER_KEY_F1 = 2645,
    LOCKER_KEY_F2 = 2646,
    LOCKER_KEY_F3 = 2647,
    LOCKER_KEY_F4 = 2648,
    EMERGENCY_RADIO = 2273,
    GUN_REPAIR_KIT = 1895,
    WEAPON_REPAIR_KIT = 1467,

    HEADLIGHTS_OFFROADER = 9,
    HEADLIGHTS_PICKUP = 1728,
    HEADLIGHTS_POLICE = 1730,
    HEADLIGHTS_ATV = 2595,

    TURBO_OFFROADER = 90,
    TURBO_PICKUP = 1729,
    TURBO_POLICE = 1731,
    TURBO_ATV = 2727,

    VEHICLE_HOTWIRE = 3458,
    VEHICLE_MOTOR_OFFROADER = 1344,
    VEHICLE_MOTOR_PICKUP = 1712,
    VEHICLE_MOTOR_POLICECAR = 1722,
    VEHICLE_MOTOR_ATV = 2594,

    VEHICLE_HORN = 1858,
    VEHICLE_HORN_POLICECAR = 1735,
    VEHICLE_SIREN_POLICECAR = 1732,

    CONTAINER_VEHICLE_OFFROADER = 1541,
    CONTAINER_VEHICLE_PICKUP = 1783,
    CONTAINER_VEHICLE_POLICECAR = 1723,
    CONTAINER_VEHICLE_ATV = 2728,

    CONTAINER_DROPPED_ITEMS = 3089,

    CONTAINER_STORAGE = 1506,
    CONTAINER_WRECKED_VAN = 1476,
    CONTAINER_WRECKED_CAR = 1474,
    CONTAINER_WRECKED_TRUCK = 1475,
    CONTAINER_WEAPONS_LOCKER = 1705,
    CONTAINER_DESK = 1503,

    CONTAINER_TOOL_CABINETS = 1507,
    CONTAINER_DUMPSTER = 1490,
    CONTAINER_FILE_CABINET = 1504,
    CONTAINER_LOCKER = 1704,
    CONTAINER_FRIDGE = 1472,
    CONTAINER_OTTOMAN = 1497,
    CONTAINER_DRESSER = 1493,
    CONTAINER_ARMOIRE = 1491,

    // COMBINE THESE
    CONTAINER_CABINETS = 1480,
    CONTAINER_CABINETS_BATHROOM = 1480,
    CONTAINER_CABINETS_CUBE = 1480,
    CONTAINER_CABINETS_KITCHEN = 1480,

    CONTAINER_GARBAGE_CAN = 1500,
    CONTAINER_FURNACE = 1711,
    CONTAINER_BARBEQUE = 1477,
    CONTAINER_CAMPFIRE = 1473,
    CONTAINER_DEW_COLLECTOR = 1540,
    CONTAINER_ANIMAL_TRAP = 1539,
    CONTAINER_BEE_BOX = 2035,
    CONTAINER_DRUG_CABINET = 2525,
    CONTAINER_MEDICAL_STATION = 2524,
    CONTAINER_HOSPITAL_DESK = 2677,
    CONTAINER_GROSSING_STATION = 2529,
    CONTAINER_HOSPITAL_REFRIGERATOR = 1472,
    CONTAINER_HOSPITAL_CABINET = 2676,
    CONTAINER_MILITARY_CRATE = 1501,

    // Skin ref
    CAMO_TAN_FLANNEL_SHIRT = 2030,
    BLUE_FLANNEL_SHIRT = 2054,
    BROWN_FLANNEL_SHIRT = 2055,
    GREEN_FLANNEL_SHIRT = 2056,
    RED_FLANNEL_SHIRT = 2057,
    PAISLEY_FLANNEL_SHIRT = 2184,
    CAMO_GREEN_FLANNEL_SHIRT = 2187,
    POLICE_SHIRT = 2346,
    BASIC_HOODIE = 2373,
    BLACK_ORANGE_HOODIE = 2374,
    TWITCH_HOODIE = 2375,
    BLUE_BLACK_HOODIE = 2376,
    DOA_HOODIE = 2377,
    PRO_GRAMER_HOODIE = 2378,
    PARAMEDIC_UNIFORM = 2535,
    DRAGON_LODGE_PARKA = 3033,
    FLOWER_PRINT_PANTS = 2280,
    POLICE_SLACKS = 2347,
    LEGGINGS = 2364,
    BONE_LEGGINGS = 2365,
    MUSCLE_LEGGINGS = 2366,
    PARAMEDIC_SLACKS = 2534,
    TWIN_GALAXIES_PANTS = 3875,
    STARS_STRIPES_SHORTS = 2404,
    AVIATOR_CAP = 2058,
    BLACK_BEANIE = 2162,
    POLICE_HAT = 2344,
    TOXIC_BODY_ARMOR = 2477,
    DEAD_END_ARMOR = 2860,
    EZW_ARMORED_CHAMPIONSHIP_BELT = 3125,
    EZW_ARMORED_SHOULDERPADS = 3126,
    POLICE_BODY_ARMOR = 2274,
    GORILLA_WARFARE = 3631,
    ARACHNID = 3721,
    DEFAULT = 2170,
    INFERNAL_DEMON_MASK = 3862,
    HOLIDAY_HAT = 2887,
    MASK_OF_JESTER = 3366,
    PATCHWORK_RUDOLPH_HELMET = 2817,
    WASTELAND_SKULL_HELMET = 3064,
    EZW_SPIKED_HELMET = 3124,
    DRAGON_MOTORCYCLE_HELMET = 2828,
    CIGAR_HOG_MASK = 2396,
    WHITE_UNICORN_FULL_HELMET = 3439,
    STAR_SPANGLED_HAT = 3470,
    PUMPKIN_MASK = 2745,
    SCARECROW_MASK = 2750,
    MILITARY_DEFAULT = 2124,
    RASTA_BACKPACK = 2393,
    PINK_SKULLS_SURVIVOR_BACKPACK = 3046,
    SNIPER_MILITARY_BACKPACK = 3169,
    FULLY_GEARED_EXPLORER_BACKPACK = 4009,
    EVIL_CLOWN_GLASSES = 2253,
    DEFAULT_GOGGLES = 1693,
    WHITE_BIKER_GLASSES = 2252,
    STEAMPUNK_GOGGLES = 2954,
    HAPPY_SKULL_SCRUBS_SHIRT = 2802,
    HAPPY_SKULL_SCRUBS_PANTS = 2808,
    PINK_GATORS = 2567,
    DOOMED_PUFFY_JACKET = 3977
} Items;

typedef struct LoadoutKitEntry {
    Items item;
    u32 count;
} LoadoutKitEntry;

LoadoutKitEntry* InitializeCharacterDefaultLoadout() {
    LoadoutKitEntry* kitEntry = malloc(sizeof(LoadoutKitEntry));
    if (!kitEntry) {
        fprintf(stderr, "Failed to allocate memory to LoadoutKitEntry struct in "
                        "InitializeCharacterDefaultLoadout function!\n");

        return NULL;
    }

    kitEntry[0].item = WEAPON_FISTS;
    kitEntry[1].item = WEAPON_FLASHLIGHT;
    kitEntry[2].item = SHIRT_DEFAULT;
    kitEntry[3].item = WAIST_PACK;
    kitEntry[4].item = PANTS_DEFAULT;

    kitEntry[5].item = MAP;
    kitEntry[6].item = COMPASS;
    kitEntry[7].item = GAUZE;
    kitEntry[7].count = 5;

    return kitEntry;
}

LoadoutKitEntry* CharacterDefaultLoadout() {
    LoadoutKitEntry* kitEntry = malloc(sizeof(LoadoutKitEntry));
    if (!kitEntry) {
        fprintf(stderr, "Failed to allocate memory to LoadoutKitEntry struct in "
                        "CharacterDefaultLoadout function!\n");

        return NULL;
    }

    kitEntry[0].item = WEAPON_FISTS;
    kitEntry[1].item = WEAPON_FLASHLIGHT;
    kitEntry[2].item = SHIRT_DEFAULT;
    kitEntry[3].item = WAIST_PACK;
    kitEntry[4].item = PANTS_DEFAULT;

    kitEntry[5].item = MAP;
    kitEntry[6].item = COMPASS;
    kitEntry[7].item = GAUZE;
    kitEntry[7].count = 5;

    return kitEntry;
}

LoadoutKitEntry* CharacterKitLoadout() {
    LoadoutKitEntry* kitEntry = malloc(sizeof(LoadoutKitEntry));
    if (!kitEntry) {
        fprintf(
            stderr,
            "Failed to allocate memory to LoadoutKitEntry struct in CharacterKitLoadout function!\n");

        return NULL;
    }

    kitEntry[0].item = BACKPACK_RASTA;
    kitEntry[1].item = WEAPON_308;
    kitEntry[2].item = WEAPON_SHOTGUN;
    kitEntry[3].item = WEAPON_AR15;
    kitEntry[4].item = FIRST_AID;
    kitEntry[4].count = 10;
    kitEntry[5].item = BANDAGE_DRESSED;
    kitEntry[5].count = 10;
    kitEntry[6].item = AMMO_12GA;
    kitEntry[6].count = 60;
    kitEntry[7].item = AMMO_308;
    kitEntry[7].count = 50;
    kitEntry[8].item = AMMO_223;
    kitEntry[8].count = 120;
    kitEntry[9].item = KEVLAR_DEFAULT;
    kitEntry[10].item = HELMET_MOTORCYCLE;
    kitEntry[11].item = CONVEYS_BLUE;

    return kitEntry;
}

LoadoutKitEntry* CharacterSkinsLoadout() {
    LoadoutKitEntry* kitEntry = malloc(sizeof(LoadoutKitEntry));
    if (!kitEntry) {
        fprintf(
            stderr,
            "Failed to allocate memory to LoadoutKitEntry struct in CharacterSkinsLoadout function!\n");

        return NULL;
    }

    kitEntry[0].item = CAMO_TAN_FLANNEL_SHIRT;
    kitEntry[1].item = BLUE_FLANNEL_SHIRT;
    kitEntry[2].item = BROWN_FLANNEL_SHIRT;
    kitEntry[3].item = GREEN_FLANNEL_SHIRT;
    kitEntry[4].item = RED_FLANNEL_SHIRT;
    kitEntry[5].item = PAISLEY_FLANNEL_SHIRT;
    kitEntry[6].item = CAMO_GREEN_FLANNEL_SHIRT;
    kitEntry[7].item = POLICE_SHIRT;
    kitEntry[8].item = BASIC_HOODIE;
    kitEntry[9].item = BLACK_ORANGE_HOODIE;
    kitEntry[10].item = TWITCH_HOODIE;
    kitEntry[11].item = BLUE_BLACK_HOODIE;
    kitEntry[12].item = DOA_HOODIE;
    kitEntry[13].item = PRO_GRAMER_HOODIE;
    kitEntry[14].item = PARAMEDIC_UNIFORM;
    kitEntry[15].item = DRAGON_LODGE_PARKA;
    kitEntry[16].item = FLOWER_PRINT_PANTS;
    kitEntry[17].item = POLICE_SLACKS;
    kitEntry[18].item = LEGGINGS;
    kitEntry[19].item = BONE_LEGGINGS;
    kitEntry[20].item = MUSCLE_LEGGINGS;
    kitEntry[21].item = PARAMEDIC_SLACKS;
    kitEntry[22].item = TWIN_GALAXIES_PANTS;
    kitEntry[23].item = STARS_STRIPES_SHORTS;
    kitEntry[24].item = AVIATOR_CAP;
    kitEntry[25].item = BLACK_BEANIE;
    kitEntry[26].item = POLICE_HAT;
    kitEntry[27].item = TOXIC_BODY_ARMOR;
    kitEntry[28].item = DEAD_END_ARMOR;
    kitEntry[29].item = EZW_ARMORED_CHAMPIONSHIP_BELT;
    kitEntry[30].item = EZW_ARMORED_SHOULDERPADS;
    kitEntry[31].item = POLICE_BODY_ARMOR;
    kitEntry[32].item = GORILLA_WARFARE;
    kitEntry[33].item = ARACHNID;
    kitEntry[34].item = DEFAULT;
    kitEntry[35].item = INFERNAL_DEMON_MASK;
    kitEntry[36].item = HOLIDAY_HAT;
    kitEntry[37].item = MASK_OF_JESTER;
    kitEntry[38].item = PATCHWORK_RUDOLPH_HELMET;
    kitEntry[39].item = WASTELAND_SKULL_HELMET;
    kitEntry[40].item = EZW_SPIKED_HELMET;
    kitEntry[41].item = DRAGON_MOTORCYCLE_HELMET;
    kitEntry[42].item = CIGAR_HOG_MASK;
    kitEntry[43].item = WHITE_UNICORN_FULL_HELMET;
    kitEntry[44].item = STAR_SPANGLED_HAT;
    kitEntry[45].item = PUMPKIN_MASK;
    kitEntry[46].item = SCARECROW_MASK;
    kitEntry[47].item = EVIL_CLOWN_GLASSES;
    kitEntry[48].item = DEFAULT_GOGGLES;
    kitEntry[49].item = WHITE_BIKER_GLASSES;
    kitEntry[50].item = STEAMPUNK_GOGGLES;
    kitEntry[51].item = HAPPY_SKULL_SCRUBS_SHIRT;
    kitEntry[52].item = PINK_GATORS;
    kitEntry[53].item = DOOMED_PUFFY_JACKET;
    kitEntry[54].item = MILITARY_DEFAULT;
    kitEntry[55].item = RASTA_BACKPACK;
    kitEntry[56].item = PINK_SKULLS_SURVIVOR_BACKPACK;
    kitEntry[57].item = SNIPER_MILITARY_BACKPACK;
    kitEntry[58].item = FULLY_GEARED_EXPLORER_BACKPACK;

    return kitEntry;
}

LoadoutKitEntry* CharacterVehicleKit() {
    LoadoutKitEntry* kitEntry = malloc(sizeof(LoadoutKitEntry));
    if (!kitEntry) {
        fprintf(
            stderr,
            "Failed to allocate memory to LoadoutKitEntry struct in CharacterVehicleKit function!\n");

        return NULL;
    }

    kitEntry[0].item = SPARKPLUGS;
    kitEntry[1].item = VEHICLE_KEY;
    kitEntry[2].item = BATTERY;

    return kitEntry;
}

void CharacterBuildKitLoadout() {
    // TODO: FINISH THIS FUNCTION!
}
