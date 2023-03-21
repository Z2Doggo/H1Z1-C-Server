// note(doggo): enums from the javascript h1emu server converted to c

typedef struct Stances
{
	int STANDING = 1089;
	int MOVE_STANDING_SPRINTING = 66565;
	int MOVE_STANDING_FORWARD = 66561;
	int MOVE_STANDING_BACKWARDS = 33793;
	int MOVE_STANDING_LEFT = 132097;
	int MOVE_STANDING_RIGHT = 263169;

	int CROUCHING = 1091;
	int MOVE_CROUCHING_FORWARD = 66563;
	int MOVE_CROUCHING_BACKWARDS = 33795;
	int MOVE_CROUCHING_LEFT = 132099;
	int MOVE_CROUCHING_RIGHT = 263171;

	int PRONING = 5185;
	int MOVE_PRONING_FORWARD = 70657;
	int MOVE_PRONING_BACKWARDS = 37889;
	int MOVE_PRONING_LEFT = 136193;
	int MOVE_PRONING_RIGHT = 267265;

	int JUMPING_STANDING = 1105;
	int JUMPING_FORWARD_SPRINTING = 66581;
	int JUMPING_WORWARD = 66577;
	int JUMPING_BACKWARDS = 33809;
	int JUMPING_LEFT = 132113;
	int JUMPING_RIGHT = 263185;
	int JUMPING_FORWARD_LEFT = 197649;
	int JUMPING_FORWARD_LEFT_SPRINTING = 197653;
	int JUMPING_FORWARD_RIGHT = 328721;
	int JUMPING_FORWARD_RIGHT_SPRINTING = 328725;
	int JUMPING_BACKWARDS_LEFT = 164881;
	int JUMPING_BACKWARDS_RIGHT = 295953;

	int SITTING = 525377;
	int STANCE_XS = 525393;
	int STANCE_XS_FP = 2622545;
} Stances;

typedef struct ItemUseOptions
{
	int EAT = 1;
	int DRINK = 2;
	int USE = 3;
	int DROP = 4;
	int SHRED = 6;
	int UNLOAD = 7;
	int IGNITE = 11;
	int REFUEL = 17;
	int SLICE = 18;
	int USE_MEDICAL = 52;
	int EQUIP = 60;
	int DROP_BATTERY = 73;
	int DROP_SPARKS = 79;
	int SALVAGE = 87;
} ItemUseOptions;

typedef struct ConstructionErrors
{
	int UNKNOWN = 0;
	int OVERLAP = 1;
	int	BUILD_PERMISSION = 2;
	int	DEMOLISH_PERMISSION = 3;
	int	UNKNOWN_PARENT = 4;
	int	UNKNOWN_SLOT = 5;
	int	UNKNOWN_CONSTRUCTION = 6;
} ConstructionErrors;

typedef struct ConstructionPermissionIds
{
	int BUILD = 1;
	int DEMOLISH = 2;
	int CONTAINERS = 3;
	int VISIT = 4;
} ConstructionPermissionIds;

typedef struct StringIds
{
	int TAKE_ITEM = 29;
	int OPEN = 31;
	int SEARCH = 1191;
	int OPEN_AND_LOCK = 8944;
	int UNDO_PLACEMENT = 12001;
	int OPEN_TARGET = 12156;
	int PERMISSIONS_TARGET = 12982;
	int OFFROADER = 16;
	int PICKUP_TRUCK = 12537;
	int ATV = 12552;
	int POLICE_CAR = 12538;
	int CORN = 628;
	int WHEAT = 1184;
	int USE_IGNITABLE = 9224;
} StringIds;

typedef struct MovementModifiers
{
	float RESTED = 1.1;
	float SWIZZLE = 1.1;
	float SNARED = 0.5;
	float BOOTS = 1.15;
} MovementModifiers;

typedef struct ContainerErrors 
{
	int NONE = 0;
	int IN_USE = 1;
	int	WRONG_ITEM_TYPE = 2;
	int	UNKNOWN_CONTAINER = 3;
	int	UNKNOWN_SLOT = 4;
	int	NO_ITEM_IN_SLOT = 5;
	int	INTERACTION_VALIDATION = 6;
	int	UNKNOWN = 99;

	// note(doggo): h1emu custom errors, not sure if need

	int	DOES_NOT_ACCEPT_ITEMS = 7;
	int	NOT_MUTABLE = 8;
	int	NOT_CONSTRUCTED = 9;
	int NO_SPACE = 10;
	int	INVALID_LOADOUT_SLOT = 11;
	int	NO_PERMISSION = 12;
	int	UNACCEPTED_ITEM = 13;
} ContainerErrors;

typedef struct FilterIds
{
	int	COOKING = 2;
	int	FURNACE = 4;
	int	WEAPONS = 5;
	int	HOUSING = 6;
	int	SURVIVAL = 7;
	int	COMPONENT = 8;
	int	DEW_COLLECTOR = 9;
	int	ANIMAL_TRAP = 10;
} FilterIds;

typedef struct ItemClasses
{
	int	WEAPONS_LONG = 25036;
	int	WEAPONS_PISTOL = 4096;
	int	WEAPONS_MELEES = 4098;
	int	WEAPONS_MELEES0 = 25037;
	int	WEAPONS_GENERIC = 25054;
	int	WEAPONS_CROSSBOW = 25047;
	int	WEAPONS_BOW = 25038;
} ItemClasses;

typedef struct VehicleIds
{
	int	OFFROADER = 1;
	int	PICKUP = 2;
	int	POLICECAR = 3;
	int	ATV = 5;
	int	PARACHUTE = 13;
	int	SPECTATE = 1337;
} VehicleIds;

typedef struct Characters 
{
	int MALE_WHITE = 1;
	int MALE_WHITE_BALD = 2;
	int FEMALE_WHITE_YOUNG = 3;
	int FEMALE_WHITE = 4;
	int MALE_BLACK = 5;
	int FEMALE_BLACK = 6;
} Characters;

typedef struct LoadoutIds 
{
	int CHARACTER = 3;
	int VEHICLE_OFFROADER = 4;
	int VEHICLE_PICKUP = 6;
	int VEHICLE_POLICECAR = 8;
	int VEHICLE_ATV = 14;
} LoadoutIds;

typedef struct LoadoutSlots 
{
	int PRIMARY = 1;
	int SECONDARY = 3;
	int TERTIARY = 4;
	int FISTS = 7;
	int HEAD = 11;
	int ARMOR = 38;
	int RADIO = 39;
	int ITEM2 = 41;
} LoadoutSlots;

typedef struct EquipSlots 
{
	int HEAD = 1;
	int HANDS = 2;
	int CHEST = 3;
	int LEGS = 4;
	int FEET = 5;
	int RHAND = 7;
	int BACKPACK = 10;
	int HAIR = 27;
	int FACE = 28;
	int EYES = 29;
	int ARMOR = 100;
} EquipSlots;

typedef struct EntityTypes 
{
	int INVALID;
	int NPC;
	int VEHICLE;
	int PLAYER;
	int OBJECT;
	int DOOR;
	int EXPLOSIVE;
	int CONSTRUCTION_FOUNDATION;
	int CONSTRUCTION_DOOR;
	int CONSTRUCTION_SIMPLE;
	int LOOTABLE_CONSTRUCTION;
	int LOOTABLE_PROP;
	int WORLD_LOOTABLE_CONSTRUCTION;
	int WORLD_CONSTRUCTION_SIMPLE;
	int PLANT;
	int TRAP;
	int TASK_PROP;
	int CRATE;
} EntityTypes;

typedef struct ResourceIds 
{
	int HEALTH = 1;
	int HUNGER = 4;
	int HYDRATION = 5;
	int STAMINA = 6;
	int VIRUS = 12;
	int BLEEDING = 21;
	int COMFORT = 68;
	int FUEL = 396;
	int CONDITION = 561;
	int CONSTRUCTION_CONDITION = 567;
} ResourceIds;

typedef struct ResourceTypes 
{
	int HEALTH = 1;
	int HUNGER = 4;
	int HYDRATION = 5;
	int STAMINA = 6;
	int VIRUS = 12;
	int BLEEDING = 21;
	int COMFORT = 68;
	int FUEL = 50;
	int CONDITION = 1;
} ResourceTypes;

typedef struct Items 
{
	//#region WEAPONS
	int WEAPON_AR15 = 10;
	int WEAPON_AK47 = 2229;
	int WEAPON_SHOTGUN = 2663;
	int WEAPON_CROWBAR = 82;
	int WEAPON_COMBATKNIFE = 84;
	int WEAPON_MACHETE01 = 83;
	int WEAPON_KATANA = 2961;
	int WEAPON_BAT_WOOD = 1724;
	int WEAPON_GUITAR = 1733;
	int WEAPON_AXE_WOOD = 58;
	int WEAPON_AXE_FIRE = 1745;
	int WEAPON_HAMMER = 1536;
	int WEAPON_HATCHET = 3;
	int WEAPON_PIPE = 1448;
	int WEAPON_BAT_ALUM = 1721;
	int WEAPON_BOW_MAKESHIFT = 113;
	int WEAPON_BOW_WOOD = 1720;
	int WEAPON_BOW_RECURVE = 1986;
	int WEAPON_1911 = 2;
	int WEAPON_M9 = 1997;
	int WEAPON_308 = 1373;
	int WEAPON_BINOCULARS = 1542;
	int WEAPON_CROSSBOW = 2246;
	int WEAPON_R380 = 1991;
	int WEAPON_MOLOTOV = 14;
	int WEAPON_MAGNUM = 1718;
	int WEAPON_FLASHLIGHT = 1380;
	int WEAPON_WRENCH = 1538;
	int WEAPON_BRANCH = 1725;
	int WEAPON_FISTS = 85;
	int WEAPON_FROSTBITE = 3445;
	int WEAPON_BLAZE = 3446;
	int WEAPON_NAGAFENS_RAGE = 3448;
	int WEAPON_PURGE = 3449;
	int WEAPON_REAPER = 3450;
	int WEAPON_HAMMER_DEMOLITION = 1903;
	int WEAPON_TORCH = 5;
	int WEAPON_TORCH_ETHANOL = 1389;
	int WEAPON_HATCHET_MAKESHIFT = 1708;
	int WEAPON_AK47_MODIFIED = 2399;
	int WEAPON_SPEAR = 1382;
	int WEAPON_REMOVER = 1776;
	//#endregion

	//#region AMMO
	int AMMO_223 = 1429;
	int AMMO_12GA = 1511;
	int AMMO_45 = 1428;
	int AMMO_9MM = 1998; // TODO = assign it to a spawner
	int AMMO_308 = 1469;
	int AMMO_380 = 1992;
	int AMMO_762 = 2325;
	int AMMO_44 = 1719;
	int AMMO_ARROW = 112;
	int AMMO_ARROW_EXPLOSIVE = 138;
	int AMMO_ARROW_FLAMING = 1434;
	//#endregion

	//#region PERISHABLE
	int ANTIBIOTICS = 1388;
	int VITAMINS = 1512;
	int IMMUNITY_BOOSTERS = 1471;
	int FIRST_AID = 78;
	int BANDAGE = 24;
	int BANDAGE_DRESSED = 2214;
	int GAUZE = 1751;
	int SWIZZLE = 1709;
	int GROUND_COFFEE = 56; // TODO = expand with more canned food types
	int CANNED_FOOD01 = 7;
	int BLACKBERRY = 105;
	int BLACKBERRY_JUICE = 1361;
	int BLACKBERRY_PIE = 1706;
	int BLACKBERRY_PIE_SLICE = 1726;
	int BLACKBERRY_HANDFUL = 3214;
	int WATER_PURE = 1371;
	int WATER_STAGNANT = 1535;
	int WATER_DIRTY = 1368;
	int MRE_APPLE = 1402; // TODO = add other MRE types
	int SANDWICH_BEAR = 1459;
	int STEAK_BEAR = 1451;
	int SURVIVAL_BREAD = 1456;
	int MEAT_BEAR = 1450;
	int COFFEE = 55;
	int COFFEE_SUGAR = 71;
	int STEAK_RABBIT = 117;
	int MEAT_RABBIT = 116;
	int SANDWICH_RABBIT = 1457;
	int STEW_RABBIT = 118;
	int CORN = 107;
	int CORN_ROASTED = 1387;
	int JERKY_DEER = 21;
	int MEAT_VENISON = 20;
	int SANDWICH_DEER = 1460;
	int STEAK_DEER = 61;
	int HONEY = 2192;
	int MOONSHINE = 1386;
	int COLD_MEDICINE = 1742;
	int SURVIVAL_BORSCHT = 1379;
	int SANDWICH_WOLF = 1458;
	int STEAK_WOLF = 1343;
	int MEAT_WOLF = 1342;
	int MEAT_ROTTEN = 1381;
	//#endregion

	//#region CONSTRUCTION
	int GROUND_TAMPER = 124;
	int SHACK = 1433;
	int SHACK_SMALL = 1440;
	int SHACK_BASIC = 1468;
	int SHELTER = 150;
	int SHELTER_LARGE = 153;
	int SHELTER_UPPER_LARGE = 1897;
	int SHELTER_UPPER = 1898;
	int FOUNDATION = 1378;
	int FOUNDATION_EXPANSION = 2336;
	int FOUNDATION_RAMP = 2269;
	int FOUNDATION_STAIRS = 2270;
	int METAL_GATE = 148;
	int DOOR_METAL = 1881;
	int DOOR_WOOD = 1435;
	int METAL_WALL = 149;
	int METAL_WALL_UPPER = 1896;
	int DOOR_BASIC = 1470;
	int LANDMINE = 74;
	int IED = 1699;
	int PUNJI_STICKS = 98;
	//PUNJI_STICK_ROW = // NEED TO FIND THIS IN ITEM DEFINITIONS
	int SNARE = 1415;
	int ANIMAL_TRAP = 91;
	int BARBED_WIRE = 108;
	int BARBEQUE = 1447;
	int BEE_BOX = 2034;
	int CAMPFIRE = 15;
	int CANDLE = 1904;
	int DEW_COLLECTOR = 97;
	int FURNACE = 64;
	int LOOKOUT_TOWER = 2272;
	int METAL_DOORWAY = 1969;
	int REPAIR_BOX = 2792;
	int SLEEPING_MAT = 51;
	int STORAGE_BOX = 1982;
	int STRUCTURE_STAIRS = 154;
	int STRUCTURE_STAIRS_UPPER = 1900;
	int WORKBENCH = 1891;
	int WORKBENCH_WEAPON = 3778;
	int BARRICADE = 122;
	//#endregion

	//#region COMPONENT
	int SHARD_METAL = 114;
	int SHARD_BRASS = 3780;
	int SHARD_PLASTIC = 3775;
	int GUNPOWDER_REFINED = 3805;
	int ALLOY_LEAD = 3779;
	int PROTOTYPE_MECHANISM = 3455;
	int PROTOTYPE_TRIGGER_ASSEMBLY = 3456;
	int PROTOTYPE_RECEIVER = 3457;
	int NAIL = 135;
	int BACKPACK_FRAME = 1466;
	int METAL_BRACKET = 141;
	int ANIMAL_FAT = 72;
	int FLOUR = 1455;
	int WAX = 2193;
	int PHONE_DEAD = 2635;
	int PHONE_BATTERY = 2637;
	int PHONE_CHARGED = 2636;
	int CORN_MASH = 1385;
	int YEAST = 1445;
	int DEER_SCENT = 1462;
	int DEER_BLADDER = 1463;
	int DUCT_TAPE = 134;
	int TRAP_IGNITION_KIT = 2831;
	int SALINE = 77;
	int WHEAT = 1438;
	int TWINE = 142;
	int GUN_PART = 1890;
	int REPAIR_KIT_GUN = 1895;
	int UPGRADE_KIT_GUN = 2419;
	int CHARCOAL = 26;
	int METAL_BAR = 39;
	int ANTI_VIRAL_BOTTLE = 2671;
	int HANDWRITTEN_NOTE_CAROLINE = 2611;
	int ANTI_VIRAL_BOTTLE_EMPTY = 2612;
	int GRENADE_SONIC_BROKEN = 3040;
	int VIAL_H1Z1_B_PLASMA = 3041;
	int VIAL_H1Z1_REDUCER = 2498;
	int BATTERIES_AA = 2833;
	int BRAIN_TREATED = 2643;
	int BRAIN_INFECTED = 2642;
	int SYRINGE_INFECTED_BLOOD = 1510;
	int EMPTY_SPECIMEN_BAG = 2641;
	//#endregion

	int TRAP_FIRE = 2812;
	int TRAP_FLASH = 2810;
	int TRAP_GAS = 2811;
	int TRAP_SHOCK = 2832;

	int BACKPACK_FRAMED = 2111;
	int BACKPACK_SATCHEL = 1432;
	int BACKPACK_MILITARY_TAN = 2124;
	int BACKPACK_BLUE_ORANGE = 2038;
	int HELMET_MOTORCYCLE = 2170; // TODO = expand with other default helmet colors
	int HAT_CAP = 12; // TODO = expand with other cap colors
	int SHIRT_DEFAULT = 2088; // TODO = expand with other default shirts
	int PANTS_DEFAULT = 2177; // TODO = expand with other default pants
	int SHIRT_SCRUBS_BLUE = 2553;
	int PANTS_SCRUBS_BLUE = 2557;
	int SURGEON_MASK_AQUA = 2569;
	int CAP_SCRUBS_BLUE = 2560;

	int CONVEYS_BLUE = 2217; // TODO = expand with other convey colors
	int HAT_BEANIE = 2162;
	int SUGAR = 57;
	int BATTERY = 1696;
	int SPARKPLUGS = 1701;
	int SALT = 22;
	int LIGHTER = 1436;
	int BOW_DRILL = 1452;
	int WATER_EMPTY = 1353;
	int FUEL_BIOFUEL = 73;
	int FUEL_ETHANOL = 1384;
	int WOOD_PLANK = 109;
	int METAL_SHEET = 46;
	int METAL_SCRAP = 48;
	int BROKEN_METAL_ITEM = 1354;
	int TARP = 155;
	int WOOD_LOG = 16;
	int WOOD_STICK = 111;
	int GROUND_TILLER = 1383;
	int FERTILIZER = 25;
	int SEED_CORN = 1987;
	int SEED_WHEAT = 1988;
	int VIAL_EMPTY = 2510;
	int SYRINGE_EMPTY = 1508;
	int GHILLIE_SUIT = 92;
	int GHILLIE_SUIT_TAN = 2570;
	int HELMET_TACTICAL = 2172;
	int RESPIRATOR = 2148;
	int NV_GOGGLES = 1700;
	int ALL_PURPOSE_GOGGLES = 1693;
	int GUNPOWDER = 11;
	int KEVLAR_DEFAULT = 2271;
	int ARMOR_PLATED = 2205;
	int ARMOR_WOODEN = 2204;
	int CLOTH = 23;
	int METAL_PIPE = 47;
	int GRENADE_SMOKE = 2236;
	int GRENADE_FLASH = 2235;
	int GRENADE_GAS = 2237;
	int GRENADE_HE = 65;
	int GRENADE_SCREAM = 3022;
	int MAP = 1985;
	int COMPASS = 1441;
	int FLARE = 1804;
	int FLARE_PARACHUTE = 1906;
	int FLARE_SMOKE = 1672;
	int BACKPACK_RASTA = 2393;
	int WAIST_PACK = 1803;
	int FANNY_PACK_DEV = 1;
	int VEHICLE_KEY = 3460;
	int CODED_MESSAGE = 2722;
	int AIRDROP_CODE = 2675;
	int BANDANA_BASIC = 2323;
	int GLOVES_FINGERLESS = 2324;
	int HAND_SHOVEL = 1697;
	int COMPASS_IMPROVISED = 1444;
	int SKINNING_KNIFE = 110;
	int RIGGED_LIGHT = 1748;
	int SYRINGE_H1Z1_REDUCER = 1464;
	int LOCKER_KEY_F1 = 2645;
	int LOCKER_KEY_F2 = 2646;
	int LOCKER_KEY_F3 = 2647;
	int LOCKER_KEY_F4 = 2648;
	int EMERGENCY_RADIO = 2273;

	int HEADLIGHTS_OFFROADER = 9;
	int HEADLIGHTS_PICKUP = 1728;
	int HEADLIGHTS_POLICE = 1730;
	int HEADLIGHTS_ATV = 2595;

	int TURBO_OFFROADER = 90;
	int TURBO_PICKUP = 1729;
	int TURBO_POLICE = 1731;
	int TURBO_ATV = 2727;

	int VEHICLE_HOTWIRE = 3458;
	int VEHICLE_MOTOR_OFFROADER = 1344;
	int VEHICLE_MOTOR_PICKUP = 1712;
	int VEHICLE_MOTOR_POLICECAR = 1722;
	int VEHICLE_MOTOR_ATV = 2594;

	int VEHICLE_HORN = 1858;
	int VEHICLE_HORN_POLICECAR = 1735;
	int VEHICLE_SIREN_POLICECAR = 1732;

	// NOT USED FOR NOW
	int VEHICLE_CONTAINER_OFFROADER = 1541;
	int VEHICLE_CONTAINER_PICKUP = 1783;
	int VEHICLE_CONTAINER_POLICECAR = 1723;
	int VEHICLE_CONTAINER_ATV = 2728;

	int CONTAINER_DROPPED_ITEMS = 5001;
	int CONTAINER_VEHICLE_OFFROADER = 5002;
	int CONTAINER_VEHICLE_PICKUP = 5003;
	int CONTAINER_VEHICLE_POLICECAR = 5004;
	int CONTAINER_VEHICLE_ATV = 5005;
	int CONTAINER_STORAGE = 5006;
	int CONTAINER_WRECKED_VAN = 5007;
	int CONTAINER_WRECKED_CAR = 5008;
	int CONTAINER_WRECKED_TRUCK = 5009;
	int CONTAINER_WEAPONS_LOCKER = 5010;
	int CONTAINER_DESK = 5011;
	int CONTAINER_CABINETS = 5012;
	int CONTAINER_TOOL_CABINETS = 5013;
	int CONTAINER_DUMPSTER = 5014;
	int CONTAINER_FILE_CABINET = 5015;
	int CONTAINER_LOCKER = 5016;
	int CONTAINER_FRIDGE = 5017;
	int CONTAINER_OTTOMAN = 5018;
	int CONTAINER_DRESSER = 5019;
	int CONTAINER_ARMOIRE = 5020;
	int CONTAINER_CABINETS_BATHROOM = 5021;
	int CONTAINER_CABINETS_CUBE = 5022;
	int CONTAINER_CABINETS_KITCHEN = 5023;
	int CONTAINER_GARBAGE_CAN = 5024;
	int CONTAINER_FURNACE = 5025;
	int CONTAINER_BARBEQUE = 5026;
	int CONTAINER_CAMPFIRE = 5027;
	int CONTAINER_DEW_COLLECTOR = 5028;
	int CONTAINER_ANIMAL_TRAP = 5029;
	int CONTAINER_BEE_BOX = 5030;
} Items;

typedef struct Skins_Shirt 
{
	int CAMO_TAN_FLANNEL_SHIRT = 2030;
	int BLUE_FLANNEL_SHIRT = 2054;
	int BROWN_FLANNEL_SHIRT = 2055;
	int GREEN_FLANNEL_SHIRT = 2056;
	int RED_FLANNEL_SHIRT = 2057;
	int PAISLEY_FLANNEL_SHIRT = 2184;
	int CAMO_GREEN_FLANNEL_SHIRT = 2187;
	int POLICE_SHIRT = 2346;
	int BASIC_HOODIE = 2373;
	int BLACK_ORANGE_HOODIE = 2374;
	int TWITCH_HOODIE = 2375;
	int BLUE_BLACK_HOODIE = 2376;
	int DOA_HOODIE = 2377;
	int PRO_GRAMER_HOODIE = 2378;
	int PARAMEDIC_UNIFORM = 2535;
	int SHIRT_DEFAULT = 2088;
	int Dragon_Lodge_Parka = 3033;
} Skins_Shirt;

typedef struct Skins_Pants 
{
	int FLOWER_PRINT_PANTS = 2280;
	int POLICE_SLACKS = 2347;
	int LEGGINGS = 2364;
	int BONE_LEGGINGS = 2365;
	int MUSCLE_LEGGINGS = 2366;
	int PARAMEDIC_SLACKS = 2534;
	int PANTS_DEFAULT = 2177;
	int TWIN_GALAXIES_PANTS = 3875;
	int Stars_Stripes_Shorts = 2404;
} Skins_Pants;

typedef struct Skins_Beanie 
{
	int AVIATOR_CAP = 2058;
	int BLACK_BEANIE = 2162;
	int POLICE_HAT = 2344;
} Skins_Beanie;

typedef struct Skins_Cap 
{
	int CAMO_GREEN_OUTBACK_HAT = 2046;
	int TAN_CANVAS_OUTBACK_HAT = 2066;
	int BROWN_LEATHER_OUTBACK_HAT = 2067;
	int HAT_CAP = 12;
} Skins_Cap;

typedef struct Skins_MotorHelmet 
{
	int GORILLA_WARFARE = 3631;
	int ARACHNID = 3721;
	int DEFAULT = 2170;
	/*Infernal_Demon_Mask = 3862;
		int Holiday_Hat = 2887;
		int Mask_of_Jester = 3366;
		int Patchwork_Rudolph_Helmet = 2817;
		int Wasteland_Skull_Helmet = 3064;
		int EZW_Spiked_Helmet = 3124;
		int Dragon_Motorcycle_Helmet = 2828;
		int Cigar_Hog_Mask = 2396;
		int White_Unicorn_Full_Helmet = 3439;
		int Star_Spangled_Hat = 3470;
		int Pumpkin_Mask = 2745;
		int Scarecrow_Mask = 2750;*/
} Skins_MotorHelmet;

typedef struct Skins_Kevlar 
{
	//Toxic_Body_Armor = 2477;
	int KEVLAR_DEFAULT = 2271;
	/*Dead_End_Armor = 2860;
		int EZW_Armored_Championship_Belt = 3125;
		int EZW_Armored_Shoulderpads = 3126;*/
} Skins_Kevlar;

typedef struct Skins_Military 
{
	int Military_Default = 2124;
	int Rasta_Backpack = 2393;
	/*Pink_Skulls_Survivor_Backpack = 3046;
		int Sniper_Military_Backpack = 3169;
		int Fully_Geared_Explorer_Backpack = 4009;*/
} Skins_Military;

typedef struct Skins_Glasses 
{
	int Evil_Clown_Glasses = 2253;
	int Default_Goggles = 1693;
	int White_Biker_Glasses = 2252;
	int Steampunk_Goggles = 2954;
} Skins_Glasses;