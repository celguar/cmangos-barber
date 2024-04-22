#ifndef CMANGOS_MODULE_TBCBOOST_H
#define CMANGOS_MODULE_TBCBOOST_H

#include "Module.h"
#include "TbcBoostModuleConfig.h"

#include <unordered_map>

namespace cmangos_module
{
    enum TbcBoostEnums
    {
        SPELL_APPRENTICE_RIDING = 33389,
        SPELL_JOURNEYMAN_RIDING = 33392,
        SPELL_ARTISAN_RIDING = 34093,
        SPELL_ARTISAN_FIRST_AID = 10847,
        SPELL_MASTER_FIRST_AID = 27029,
        SPELL_HEAVY_RUNECLOTH_BAND = 18632,
        SPELL_NETHER_BAND = 27032,
        SPELL_HEAVY_NETHER_BAND = 27033,
        SPELL_TELEPORT_VISUAL = 41236,

        GOSSIP_MENU_MAIN = 50200, // also contains other unscripted options - Contact Us, Donating, Reporting Bugs, Cheating Policy, etc.
        GOSSIP_MENU_BOOST_CONFIRM = 50402,
        GOSSIP_MENU_CONTACT = 50205,
        GOSSIP_MENU_WHAT_IS_LV = 50201,
        GOSSIP_MENU_DONATING = 50202,
        GOSSIP_MENU_BUG_REPORT = 50203,
        GOSSIP_MENU_CHEATING = 50204,

        GOSSIP_MENU_OVERLORD_MAIN = 50414,

        GAME_EVENT_INSTANT_58 = 211,

        NPC_TEST_REALM_OVERLORD = 101000
    };

    enum TbcBoostEnums2
    {
        SPELL_CYCLONE_VISUAL_SPAWN = 8609,

        GOSSIP_TEXT_ENLIST_GREET = 50403,
        GOSSIP_TEXT_ENLIST_REFUSE_LOW = 50404,
        GOSSIP_TEXT_ENLIST_REFUSE_HIGH = 50405,
        GOSSIP_TEXT_ENLIST_PET_MENU = 50406,
        GOSSIP_TEXT_GREET_70 = 50407,
        GOSSIP_TEXT_REFUSE_LOW_70 = 50408,
        GOSSIP_TEXT_PICK_SPEC = 50409,
        GOSSIP_TEXT_PICK_GEAR_1 = 50411,
        GOSSIP_TEXT_PICK_GEAR_2 = 50412,
        GOSSIP_TEXT_PICK_GEAR_3 = 50413,
        
        GOSSIP_TEXT_CRYSTAL = 50400,
        GOSSIP_TEXT_CRYSTAL_2 = 50401,

        GOSSIP_SENDER_OPTION = 50,
        GOSSIP_SENDER_SUBOPTION = 51,

        SAY_GREET = -1800999,
        SAY_GREET_70 = -1800998,

        SET_ID_PRIMARY = 0,
        SET_ID_SECONDARY = 1,
        SET_ID_TERTIARY = 2,
        SET_ID_INSTANT_58 = 3,

        NPC_ALLIANCE_OFFICER = 100501, // instant 58
        NPC_HORDE_OFFICER = 100502, // instant 58
        NPC_MASTER_PROVISIONER = 100503, // instant 70
        NPC_ENCHANTMENT_CRYSTAL = 100504, // enchanter
        NPC_BARBER              = 100505, // barber

        GO_BARBER_CHAIR = 164767,

        NPC_PET_BAT = 8600, // Plaguebat
        NPC_PET_BEAR = 7443, // Shardtooth Mauler
        NPC_PET_BOAR = 5992, // Ashmane Boar
        NPC_PET_CARRION = 1809, // Carrion Vulture
        NPC_PET_CAT = 1713, // Elder Shadowmaw Panther
        NPC_PET_CRAB = 1088, // Monstrous Crawler
        NPC_PET_CROC = 1087, // Sawtooth Snapper
        NPC_PET_GORILLA = 6516, // Un'Goro Thunderer
        NPC_PET_HYENA = 5986, // Rabid Snickerfang
        NPC_PET_OWL = 7455, // Winterspring Owl
        NPC_PET_RAPTOR = 687,  // Jungle Stalker
        NPC_PET_STRIDER = 4725, // Crazed Sandstrider
        NPC_PET_SCORPID = 9695, // Deathlash Scorpid
        NPC_PET_SPIDER = 8933, // Cave Creeper
        NPC_PET_SERPENT = 5308, // Rogue Vale Screecher
        NPC_PET_TURTLE = 6369, // Coralshell Tortoise
        NPC_PET_WOLF = 9697  // Giant Ember Worg

        // different list of pets for 70?
    };

    const std::vector<uint32> Level1StartingGear = { 25,35,36,37,39,40,43,44,47,48,51,52,55,56,57,59,117,120,121,129,139,140,147,153,159,1395,1396,2070,2092,2101,2102,2361,2362,2504,2508,2512,2516,3661,4536,4540,4604,6098,6116,6118,6119,6121,6122,6123,6124,6126,6127,6129,6135,6137,6138,6139,6140,6144,12282,20857,20891,20892,20893,20894,20895,20896,20898,20899,20900,20980,20981,20982,20983,23322,23344,23346,23347,23348,23474,23475,23477,23478,23479,24145,24146,25861,28979 };

    struct CustomTeleportLocation
    {
        uint32 map;
        float x, y, z, o;
        uint32 area;
    };

    static const CustomTeleportLocation teleLocs[] =
    {
        {0, -11792.108398f, -3226.608154f, -29.721224f, 2.613495f, 0},  // Dark Portal - Alliance
        {0, -11774.694336f, -3184.537598f, -28.923182f, 2.749808f, 0},  // Dark Portal - Horde
        {530, -1982.2641f, 5073.6987f, 7.388187f, 1.227539f, 3703},     // Shattrath City - Alliance
        {530, -1992.693726f, 5078.106934f, 7.165706f, 0.944797f, 3703}, // Shattrath City - Horde

        {0, -8931.93f, -132.83f, 82.88f, 3.26f, 0},                     // Northshire (Human)
        {0, -6213.47f, 330.64f, 383.68f, 3.15f, 0},                     // Coldridge Valley (Dwarf and Gnome)
        {1, 10317.40f, 821.00f, 1326.37f, 2.15f, 0},                    // Shadowglen (Night Elf)
        {530, -3983.02f, -13898.48f, 96.30f, 5.32f, 0},                 // Ammen Vale (Draenei)

        {1, -607.47f, -4248.13f, 38.95f, 3.27f, 0},                     // Valley of Trials (Orc and Troll)
        {0, 1656.367f, 1682.592f, 120.78681f, 0.06632f, 0},             // Deathknell (Undead)
        {1, -2913.71f, -254.67f, 52.94f, 3.70f, 0},                     // Camp Narache (Tauren)
        {530, 10354.33f, -6370.34f, 36.04f, 1.92f, 0},                  // Sunstrider Isle (Blood Elf)
    };

    // Instant 70
//                                                          head    shoulders   chest   hands   legs
    const std::vector<uint32> PlatePrimaryGear = { 12423,  12407,      15141,  14694,  32171 };
    //                                                          head    shoulders   chest   hands   legs
    const std::vector<uint32> LeatherPrimaryGear = { 16156,  4728,       1170,   26227,  13776 };
    //                                                          head    shoulders   chest   hands   legs
    const std::vector<uint32> ClothPrimaryGear = { 32129,  28016,      26082,  30288,  30921 };
    //                                                          head    shoulders   chest   hands   legs
    const std::vector<uint32> MailPrimaryGear = { 26388,  32137,      29899,  32149,  25551 };

    //                                                          back    ring1   ring2   neck   trinket1
    const std::vector<uint32> SharedSecondaryGear = { 14701,  7466,   7466,   27228, 4031 };
    //                                                          wrist   waist   boots
    const std::vector<uint32> PlateSecondaryGear = { 16512,  20324,  16030 };
    //                                                          wrist   waist   boots
    const std::vector<uint32> ClothSecondaryGear = { 32977,  18341,  26097 };
    //                                                          wrist   waist   boots
    const std::vector<uint32> LeatherSecondaryGear = { 26015,  20789,  26225 };
    //                                                          wrist   waist   boots
    const std::vector<uint32> MailSecondaryGear = { 32968,  25794,  28011 };

    //                                                          mainhand    shield  trinket2    ranged
    const std::vector<uint32> ProtWarriorTertiaryGear = { 26797,      26559,  35772,      29210 };
    //                                                          mainhand    offhand trinket2    ranged
    const std::vector<uint32> FuryWarriorTertiaryGear = { 26797,      23232,  35771,      29210 };
    //                                                          2hand   trinket2    ranged
    const std::vector<uint32> ArmsWarriorTertiaryGear = { 1311,   35771,      29210 };
    //                                                          mainhand    shield  trinket2    libram
    const std::vector<uint32> HolyPaladinTertiaryGear = { 19359,      26559,  35773,      23201 };
    //                                                          2hand   trinket2    libram
    const std::vector<uint32> RetPaladinTertiaryGear = { 1311,   35771,      31033 };
    //                                                          mainhand    shield  trinket2    libram
    const std::vector<uint32> ProtPaladinTertiaryGear = { 20811,      26559,  35772,      27917 };
    //                                                          mainhand    offhand trinket2    idol
    const std::vector<uint32> BalanceDruidTertiaryGear = { 32177,      26573,  35770,      23197 };
    //                                                          2hand   trinket2    idol
    const std::vector<uint32> FeralDruidTertiaryGear = { 20522,  35771,      28064 };
    //                                                          mainhand    offhand trinket2    idol
    const std::vector<uint32> RestoDruidTertiaryGear = { 19359,      26573,  35773,      22398 };
    //                                                          mainhand    offhand trinket2    wand
    const std::vector<uint32> DiscHolyPriestTertiaryGear = { 19359,      26573,  35773,      32482 };
    //                                                          mainhand    offhand trinket2    wand
    const std::vector<uint32> CasterDPSTertiaryGear = { 32177,      26573,  35770,      32482 }; // warlock, shadow priest, mage
    //                                                          mainhand    offhand trinket2    totem
    const std::vector<uint32> EnhanceShamanTertiaryGear = { 26797,      26797,  35771,      22395 };
    //                                                          mainhand    shield  trinket2    totem
    const std::vector<uint32> ElementalShamanTertiaryGear = { 32177,      26559,  35770,      23199 };
    //                                                          mainhand    shield  trinket2    totem
    const std::vector<uint32> RestoShamanTertiaryGear = { 19359,      26559,  35773,      23200 };
    //                                                          2hand   trinket2    ranged  quiver
    const std::vector<uint32> HunterTertiaryGear = { 1311,   35771,      20313,  1281 };
    //                                                          mainhand    offhand trinket2    ranged
    const std::vector<uint32> CombatSubRogueTertiaryGear = { 23232,      23232,  35771,      29210 };
    //                                                          mainhand    offhand trinket2    ranged
    const std::vector<uint32> AssassinRogueTertiaryGear = { 12767,      12767,  35771,      29210 };

    // "Best In Slot"
    const std::vector<uint32> Lvl60BiS_ShamanResto = { 22466, 21712, 22467, 21583, 22464, 22471, 22465, 22469, 22470, 22468, 23065, 21620, 23047, 19395, 23056, 22819, 22396 };
    const std::vector<uint32> Lvl60BiS_ShamanEnhancement = { 18817, 18404, 21684, 23045, 21374, 21602, 21624, 21586, 21651, 21705, 17063, 23038, 22321, 19289, 22798, 22395 };
    const std::vector<uint32> Lvl60BiS_ShamanElemental = { 19375, 22943, 21376, 23050, 21671, 21464, 21585, 22730, 21375, 21373, 21707, 21709, 19379, 23046, 22988, 23049, 23199 };
    const std::vector<uint32> Lvl60BiS_PriestShadow = { 23035, 18814, 22983, 22731, 23220, 21611, 19133, 21585, 19400, 19131, 21709, 19434, 19379, 23046, 22988, 23049, 22820 };
    const std::vector<uint32> Lvl60BiS_PriestDiscHoly = { 21615, 21712, 22515, 22960, 22512, 21604, 22513, 22517, 21582, 22516, 23061, 22939, 23027, 23047, 23056, 23048, 23009 };
    const std::vector<uint32> Lvl60BiS_PaladinHoly = { 19375, 23057, 22429, 23050, 22425, 21604, 22427, 20264, 21582, 22430, 23066, 19382, 19395, 23047, 23056, 23075, 23006 };
    const std::vector<uint32> Lvl60BiS_PaladinRetribution = { 21387, 18404, 21391, 23045, 21389, 22936, 21623, 23219, 21390, 21388, 23038, 17063, 22321, 19289, 22691, 23203, 17182 };
    const std::vector<uint32> Lvl60BiS_PaladinProtection = { 21387, 22732, 21639, 22938, 21389, 20616, 21674, 21598, 19855, 21706, 19376, 21601, 19431, 18406, 22988, 23043, 22401, 19019 };
    const std::vector<uint32> Lvl60BiS_WarriorFuryArms = { 12640, 23053, 21330, 23045, 23000, 22936, 21581, 23219, 23068, 19387, 18821, 23038, 22954, 23041, 23054, 23577, 17076, 22812 };
    const std::vector<uint32> Lvl60BiS_WarriorProtection = { 22418, 22732, 22419, 22938, 22416, 22423, 22421, 22422, 22417, 22420, 23059, 21601, 19431, 19406, 19019, 23043, 19368 };
    const std::vector<uint32> Lvl60BiS_DruidFeralCat = { 8345, 19377, 21665, 21710, 23226, 21602, 21672, 21586, 23071, 21493, 23038, 19432, 19406, 23041, 22988, 22632, 22397, 13385 };
    const std::vector<uint32> Lvl60BiS_DruidFeralBear = { 21693, 22732, 19389, 22938, 23226, 21602, 21605, 21675, 20627, 19381, 21601, 23018, 13966, 11811, 943, 23198 };
    const std::vector<uint32> Lvl60BiS_DruidBalance = { 19375, 23057, 22983, 23050, 19682, 23021, 21585, 22730, 19683, 19684, 23025, 21709, 19379, 23046, 22988, 23049, 23197 };
    const std::vector<uint32> Lvl60BiS_DruidResto = { 20628, 21712, 22491, 22960, 22488, 21604, 22493, 21582, 22489, 22492, 22939, 21620, 23047, 23027, 23056, 22632, 22399, 23048 };
    const std::vector<uint32> Lvl60BiS_Rogue = { 22478, 19377, 22479, 23045, 22476, 22483, 22477, 22481, 22482, 22480, 23060, 23038, 23041, 22954, 23054, 22802, 21126, 23577, 22812, 19019 };
    const std::vector<uint32> Lvl60BiS_Mage = { 22498, 23057, 22983, 23050, 22496, 23021, 23070, 21585, 22730, 22500, 23062, 23237, 19379, 23046, 19339, 22807, 23049, 22821 };
    const std::vector<uint32> Lvl60BiS_Hunter = { 22438, 23053, 22439, 23045, 22436, 22443, 22437, 22441, 22442, 22440, 23067, 22961, 23041, 19406, 22816, 22802, 22812 };
    const std::vector<uint32> Lvl60BiS_Warlock = { 22506, 23057, 22507, 23050, 22504, 21186, 23070, 21585, 22730, 22508, 21709, 23025, 19379, 23046, 22807, 23049, 22820 };

    const std::vector<uint32> Lvl70BiS_ShamanResto = { 32524, 31016, 30873, 32528, 32238, 32275, 31012, 31019, 32370, 31022, 32258, 30869, 32500, 30882, 32496, 30619, 32344, 30023 };
    const std::vector<uint32> Lvl70BiS_ShamanEnhancement = { 32323, 34912, 32510, 32497, 32335, 32234, 32376, 30900, 32260, 31024, 32346, 30864, 32946, 32945, 28830, 32505, 32332, 27815 };
    const std::vector<uint32> Lvl70BiS_ShamanElemental = { 32331, 31017, 32242, 32527, 32247, 31008, 31014, 31020, 32349, 31023, 30044, 32259, 34009, 30872, 32483, 30626, 32374, 32330 };
    const std::vector<uint32> Lvl70BiS_PriestShadow = { 32590, 31065, 32239, 32527, 32247, 31061, 31064, 30916, 30666, 31070, 32256, 30870, 32237, 30872, 32343, 32483, 28789, 32374 };
    const std::vector<uint32> Lvl70BiS_PriestDiscHoly = { 32524, 31066, 32609, 32528, 32238, 31060, 31063, 30912, 32370, 31069, 30895, 30871, 32500, 30911, 32363, 32496, 29376, 32344 };
    const std::vector<uint32> Lvl70BiS_PaladinHoly = { 32524, 30992, 32243, 32528, 32238, 30983, 30988, 30994, 32370, 30996, 30897, 30862, 32500, 30882, 32496, 29376, 28592 };
    const std::vector<uint32> Lvl70BiS_PaladinRetribution = { 32323, 30990, 32345, 32497, 32335, 32278, 32373, 32341, 32591, 30866, 30032, 30057, 33503, 32332, 28830, 32505 };
    const std::vector<uint32> Lvl70BiS_PaladinProtection = { 32331, 30991, 32245, 30083, 29297, 30985, 30987, 30995, 32362, 30998, 32342, 32279, 34009, 30909, 31856, 28789, 30620, 32368 };
    const std::vector<uint32> Lvl70BiS_WarriorFuryArms = { 32323, 30975, 32345, 32497, 32335, 32278, 32373, 32341, 32260, 30979, 30032, 30861, 32369, 30881, 30105, 32505, 28830, 32348 };
    const std::vector<uint32> Lvl70BiS_WarriorProtection = { 34010, 30976, 32268, 32261, 29297, 30970, 32521, 30978, 32362, 30980, 32333, 32232, 32254, 32375, 32325, 30620, 32501 };
    const std::vector<uint32> Lvl70BiS_DruidFeralCat = { 32323, 32252, 32366, 32497, 32266, 32347, 32235, 31044, 32260, 31048, 30106, 32324, 32257, 28830, 32505, 30883 };
    const std::vector<uint32> Lvl70BiS_DruidFeralBear = { 28660, 31042, 32593, 29279, 28792, 31034, 31039, 31044, 32362, 31048, 30879, 32324, 32658, 30620, 30021, 33509 };
    const std::vector<uint32> Lvl70BiS_DruidBalance = { 32331, 31043, 32352, 32527, 32247, 31035, 31040, 31046, 32349, 31049, 30914, 32351, 32237, 30872, 32483, 30626, 32374, 27518 };
    const std::vector<uint32> Lvl70BiS_DruidResto = { 32337, 31041, 30886, 32528, 29309, 31032, 31037, 31045, 32370, 31047, 32339, 30868, 32500, 30911, 32496, 29376, 32344, 30051 };
    const std::vector<uint32> Lvl70BiS_Rogue = { 32323, 31028, 32366, 32497, 32266, 31026, 32235, 31029, 32260, 31030, 30879, 32324, 32369, 30881, 32269, 32326, 28830, 32505 };
    const std::vector<uint32> Lvl70BiS_Mage = { 32331, 31057, 32239, 32527, 32247, 31055, 32525, 31058, 30015, 31059, 30888, 30870, 30910, 30872, 29982, 32483, 27683, 32374 };
    const std::vector<uint32> Lvl70BiS_Hunter = { 32323, 31004, 30880, 29301, 32497, 31001, 32376, 31005, 32260, 31006, 32346, 32251, 32369, 32236, 30906, 28830, 32505, 32248 };
    const std::vector<uint32> Lvl70BiS_Warlock = { 32590, 31052, 30050, 32527, 32247, 31050, 32525, 31053, 32349, 31054, 32256, 29918, 30910, 30872, 32343, 32483, 27683, 32374 };

    // Instant 58
    //                                                          ring1   ring2   neck
    const std::vector<uint32> Instant58SharedCaster =         { 22339,  13001,  22403 };
    //                                                          ring1   ring2   neck
    const std::vector<uint32> Instant58SharedPhysical =       { 17713,  13098,  11933 };
    //                                                          back
    const std::vector<uint32> Instant58PhysicalBack =         { 13340 };
    //                                                          back
    const std::vector<uint32> Instant58MagicBack =            { 11623 };
    //                                                          bow
    const std::vector<uint32> Instant58Bow =                  { 18323 };
    //                                                          wrist   waist   boots
    const std::vector<uint32> Instant58LeatherOffpieces =     { 18375,  13252,  12553 };
    //                                                          staff
    const std::vector<uint32> Instant58Staff =                { 22335 };
    //                                                          wand    mainhand    offhand boots   waist   wrist
    const std::vector<uint32> Instant58ClothCaster =          { 13938,   13964,     22329,  18102,  18740,  18497 };
    //                                                          wrist   waist   boots
    const std::vector<uint32> Instant58MailOffpieces =        { 13135,  14614,  14616 };
    //                                                          mainhand    shield
    const std::vector<uint32> Instant58GavelAndShield =       { 18321,      22336 };
    //                                                          mainhand    offhand
    const std::vector<uint32> Instant58DualWield =            { 13286,      13286 };
    //                                                          wrist   waist   boots
    const std::vector<uint32> Instant58PlateOffpieces =       { 13400,  13142,  12555 };

    const std::vector<uint32> Instant58Hunter = { 14637, 13395, 13359, 12963, 12927, 22314, 19319, 19320, 13380 };
    const std::vector<uint32> Instant58Rogue = { 15806, 12939, 13368, 18392, 16707, 16708, 16709, 16712, 16721, 21135 };
    const std::vector<uint32> Instant58Druid = { 18420, 13944, 13258, 12927, 18736, 8345, 23198 };
    const std::vector<uint32> Instant58Mage = { 13253, 18727, 13170, 18385, 11782 };
    const std::vector<uint32> Instant58Paladin = { 15063, 14536, 22411, 13498, 12927, 22401, 18420 };
    const std::vector<uint32> Instant58Priest = { 18385, 13253, 18727, 12965, 11624 };
    const std::vector<uint32> Instant58Shaman = { 12624, 18727, 18378, 18494, 13344, 23199, 22345 };
    const std::vector<uint32> Instant58Warlock = { 18526, 22342, 18385, 22412, 13253 };
    const std::vector<uint32> Instant58Warrior = { 16730, 22411, 18380, 13166, 13162, 12602, 18520 };

    const std::vector<uint32> Instant58TaxiNodesAlliance =
    {
        // Eastern Kingdoms:
        2,     // Stormwind, Elwynn
        4,     // Sentinel Hill, Westfall
        5,     // Lakeshire, Redridge
        6,     // Ironforge, Dun Morogh
        7,     // Menethil Harbor, Wetlands
        8,     // Thelsamar, Loch Modan
        12,    // Darkshire, Duskwood
        14,    // Southshore, Hillsbrad
        16,    // Refuge Pointe, Arathi
        19,    // Booty Bay, Stranglethorn
        43,    // Aerie Peak, The Hinterlands
        45,    // Nethergarde Keep, Blasted Lands
        66,    // Chillwind Camp, Western Plaguelands
        67,    // Light's Hope Chapel, Eastern Plaguelands
        71,    // Morgan's Vigil, Burning Steppes
        74,    // Thorium Point, Searing Gorge
        // Kalimdor:
        26,    // Auberdine, Darkshore
        27,    // Rut'theran Village, Teldrassil
        28,    // Astranaar, Ashenvale
        31,    // Thalanaar, Feralas
        32,    // Theramore, Dustwallow Marsh
        33,    // Stonetalon Peak, Stonetalon Mountains
        37,    // Nijel's Point, Desolace
        39,    // Gadgetzan, Tanaris
        41,    // Feathermoon, Feralas
        49,    // Moonglade
        52,    // Everlook, Winterspring
        64,    // Talrendis Point, Azshara
        65,    // Talonbranch Glade, Felwood
        73,    // Cenarion Hold, Silithus
        79,    // Marshal's Refuge, Un'Goro Crater
        80     // Ratchet, The Barrens
    };
    const std::vector<uint32> Instant58TaxiNodesHorde =
    {
        // Eastern kingdoms:
        10,    // The Sepulcher, Silverpine Forest
        11,    // Undercity, Tirisfal
        13,    // Tarren Mill, Hillsbrad
        17,    // Hammerfall, Arathi
        18,    // Booty Bay, Stranglethorn
        20,    // Grom'gol, Stranglethorn
        21,    // Kargath, Badlands
        56,    // Stonard, Swamp of Sorrows
        68,    // Light's Hope Chapel, Eastern Plaguelands
        70,    // Flame Crest, Burning Steppes
        75,    // Thorium Point, Searing Gorge
        76,    // Revantusk Village, The Hinterlands
        // Kalimdor:
        22,    // Thunder Bluff, Mulgore
        23,    // Orgrimmar, Durotar
        25,    // Crossroads, The Barrens
        29,    // Sun Rock Retreat, Stonetalon Mountains
        30,    // Freewind Post, Thousand Needles
        38,    // Shadowprey Village, Desolace
        40,    // Gadgetzan, Tanaris
        42,    // Camp Mojache, Feralas
        44,    // Valormok, Azshara
        48,    // Bloodvenom Post, Felwood
        53,    // Everlook, Winterspring
        55,    // Brackenwall Village, Dustwallow Marsh
        58,    // Zoram'gar Outpost, Ashenvale
        61,    // Splintertree Post, Ashenvale
        69,    // Moonglade
        72,    // Cenarion Hold, Silithus
        77,    // Camp Taurajo, The Barrens
        79,    // Marshal's Refuge, Un'Goro Crater
        80     // Ratchet, The Barrens
    };

    typedef struct maxStyles_struct {
        uint8 maxMale;
        uint8 maxFemale;
    } maxStyles_t;

    class TbcBoostModule : public Module
    {
    public:
        TbcBoostModule();
        const TbcBoostModuleConfig* GetConfig() const override;

        // Module Hooks
        void OnInitialize() override;

        // Player Hooks
        bool OnPreGossipHello(Player* player, Creature* creature) override;
        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action, const std::string& code, uint32 gossipListId) override;
        void OnCharacterCreated(Player* player) override;

    private:
        uint32 GetStarterMountForRace(Player* player);
        uint32 GetStarterEpicMountForRace(Player* player);

        void BoostPlayer(Player* player, uint32 targetLevel);
        void LearnAvailableClassSpells(Player* player, bool includeQuestRewards);
        void LearnWeaponSkills(Player* player);
        void LearnArmorSkills(Player* player);
        void SetMaxSkill(Player* player, uint16 id);
        void CreatePet(Player* player, Creature* creature, uint32 entry);
        void AddAmmo(Player* player);
        void AddFood(Player* player, uint32 count = 20);
        bool HasStarterSet(Player* player, std::vector<uint32> gearList);
        void RemoveStarterSet(Player* player, std::vector<uint32> gearList);
        void AddStarterSet(Player* player, Creature* creature, uint32 setId, int32 suffixOverride = 0, uint32 specId = 0);
        void GivePlayerItems(Player* recipient, Creature* creature, std::vector<uint32> gearList, uint32 setId = 0, int32 suffixOverride = 0);
        void OfferPrimarySecondaryModChoices(Player* player, uint32 actionIdBase, uint32 specId);
        void OfferTertiaryModChoices(Player* player, uint32 actionIdBase, uint32 specId);
        bool TaxiNodesKnown(Player& player) const;
        void TaxiNodesTeach(Player& player) const;

        // Barber
        void SelectFacialFeature(Player* player, Creature* creature, int change);
        void SelectHairColor(Player* player, Creature* creature, int change);
        void SelectHairStyle(Player* player, Creature* creature, int change);
        void ChangeEffect(Player* player);

    private:
        bool m_bCanGreet;
        uint32 m_uiGreetTimer;
        GuidList m_lPlayerGuids;
        std::vector<uint32> FullGearList;
        std::vector<uint32> FullGearListInstant58;
        std::vector<uint32> FullGearListBiS60;
        std::vector<uint32> FullGearListBiS70;

        uint32 hairstyle;
        uint32 haircolor;
        uint32 facialfeature;
        bool   helmetShown;
        //std::map<uint32, DualSpecPlayerTalentMap[MAX_TALENT_SPECS]> playersTalents;
        //std::map<uint32, std::string[MAX_TALENT_SPECS]> playersSpecNames;
        //std::map<uint32, DualspecPlayerStatus> playersStatus;
    };
}
#endif