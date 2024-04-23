#include "BarberModule.h"

#include "AI/ScriptDevAI/include/sc_gossip.h"
#include "Entities/GossipDef.h"
#include "Entities/ObjectGuid.h"
#include "Entities/Player.h"
#include "Globals/ObjectMgr.h"
#include "Spells/SpellMgr.h"
#include "Grids/GridNotifiers.h"
#include "Grids/GridNotifiersImpl.h"
#include "Tools/Language.h"

#ifdef ENABLE_PLAYERBOTS
#include "playerbot/PlayerbotAI.h"
#endif

namespace cmangos_module
{
    BarberModule::BarberModule()
    : Module("Barber", new BarberModuleConfig())
    {
        
    }

    const BarberModuleConfig* BarberModule::GetConfig() const
    {
        return (BarberModuleConfig*)Module::GetConfig();
    }

    void BarberModule::OnInitialize()
    {
        helmetShown = false;
    }

    bool BarberModule::OnPreGossipHello(Player* player, Creature* creature)
    {
        if (GetConfig()->enabled)
        {
            if (player && creature)
            {
                // Check if speaking with barber npc
                if (creature->GetEntry() != NPC_BARBER)
                    return false;

#ifdef ENABLE_PLAYERBOTS
                if (sRandomPlayerbotMgr.IsFreeBot(player))
                    return false;
#endif

                player->GetPlayerMenu()->ClearMenus();

                uint8 standState = player->getStandState();
                bool sitting = true;

                if (player->IsStandState() || standState == uint8(sitting))
                    sitting = false;

                // Select a gossip text
                if (!sitting)
                {
                    creature->MonsterWhisper(GetGossipText(player, GOSSIP_BARBER_SIT_DOWN).c_str(), player);

                    float distance = 10.0f;
                    GameObjectList gameobjects;

                    MaNGOS::GameObjectInPosRangeCheck go_check(*player, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), distance);
                    MaNGOS::GameObjectListSearcher<MaNGOS::GameObjectInPosRangeCheck> checker(gameobjects, go_check);
                    Cell::VisitGridObjects(player, checker, distance);

                    if (!gameobjects.empty())
                    {
                        std::vector<GameObject*> v(gameobjects.cbegin(), gameobjects.cend());
                        std::random_device rd;
                        std::mt19937 generator(rd());
                        std::shuffle(v.begin(), v.end(), generator);

                        for (GameObject* go : v)
                        {
                            uint32 entry = go->GetEntry();
                            if (entry != GO_BARBER_CHAIR)
                                continue;

                            GameObjectInfo const* goInfo = ObjectMgr::GetGameObjectInfo(entry);
                            if (!goInfo)
                                continue;

                            float distance = player->GetDistance2d(go->GetPositionX(), go->GetPositionY());
                            // sit on close chair
                            if (distance <= 1.0f)
                            {
                                float slotX, slotY;
                                std::tie(slotX, slotY) = go->GetClosestChairSlotPosition(player);
                                player->NearTeleportTo(slotX, slotY, go->GetPositionZ(), go->GetOrientation());
                                player->SetStandState(UNIT_STAND_STATE_SIT_LOW_CHAIR + goInfo->chair.height);
                                creature->PlaySpellVisual(517);
                                sitting = true;
                            }
                        }

                        if (!sitting)
                        {
                            for (GameObject* go : v)
                            {
                                uint32 entry = go->GetEntry();
                                if (entry != GO_BARBER_CHAIR)
                                    continue;

                                GameObjectInfo const* goInfo = ObjectMgr::GetGameObjectInfo(entry);
                                if (!goInfo)
                                    continue;

                                float distance = player->GetDistance2d(go->GetPositionX(), go->GetPositionY());

                                // kick to chair
                                if (distance > 1.0f)
                                {
                                    float angle = player->GetAngle(go);
                                    player->KnockBackWithAngle(angle, 1.5f * distance, 8.0f);
                                    creature->PlaySpellVisual(517);
                                    return true;
                                }
                                // sit down
                                else
                                {
                                    float slotX, slotY;
                                    std::tie(slotX, slotY) = go->GetClosestChairSlotPosition(player);
                                    player->NearTeleportTo(slotX, slotY, go->GetPositionZ(), go->GetOrientation());
                                    player->SetStandState(UNIT_STAND_STATE_SIT_LOW_CHAIR + goInfo->chair.height);
                                    creature->PlaySpellVisual(517);
                                    sitting = true;
                                }
                            }
                        }
                    }
                }

                if (!sitting)
                    return true;

                // store values to restore if player choose to cancel
                hairstyle = player->GetByteValue(PLAYER_BYTES, 2);
                haircolor = player->GetByteValue(PLAYER_BYTES, 3);
                facialfeature = player->GetByteValue(PLAYER_BYTES_2, 0);
                if (sitting)
                {
                    if (player->GetMoney() >= 0)
                        player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_CUT_HAIR).c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    else
                        player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_NEED_MONEY).c_str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
                }
                player->SEND_GOSSIP_MENU(player->GetTeam() == ALLIANCE ? GOSSIP_BARBER_GREET_ALLIANCE : GOSSIP_BARBER_GREET_HORDE, creature->GetObjectGuid());
                return true;
            }
        }

        return false;
    }

    bool BarberModule::OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action, const std::string& code, uint32 gossipListId)
    {
        if (GetConfig()->enabled)
        {
            if (player && creature)
            {
                // Check if speaking with barber npc
                if (creature->GetEntry() != NPC_BARBER)
                    return false;

#ifdef ENABLE_PLAYERBOTS
                if (sRandomPlayerbotMgr.IsFreeBot(player))
                    return false;
#endif

                player->GetPlayerMenu()->ClearMenus();

                uint32 text1 = GOSSIP_BARBER_HAIR_STYLE;
                uint32 text2 = GOSSIP_BARBER_HAIR_COLOR;
                uint32 text3 = GOSSIP_BARBER_FACIAL_HAIR;

                if (player->getRace() == RACE_TAUREN)
                    text1 = GOSSIP_BARBER_HORNS;

                if (player->getRace() == RACE_TAUREN)
                    text2 = GOSSIP_BARBER_HORN_COLOR;

                switch (player->getRace())
                {
                case RACE_HUMAN:
                    if (player->getGender() == GENDER_FEMALE)
                        text3 = GOSSIP_BARBER_PIERCINGS;
                    break;
                case RACE_ORC:
                    if (player->getGender() == GENDER_FEMALE)
                        text3 = GOSSIP_BARBER_PIERCINGS;
                    break;
                case RACE_DWARF:
                    if (player->getGender() == GENDER_FEMALE)
                        text3 = GOSSIP_BARBER_EARRINGS;
                    break;
                case RACE_NIGHTELF:
                    if (player->getGender() == GENDER_FEMALE)
                        text3 = GOSSIP_BARBER_MARKINGS;
                    break;
                case RACE_UNDEAD:
                    text3 = GOSSIP_BARBER_FACE;
                    break;
                case RACE_TAUREN:
                    if (player->getGender() == GENDER_FEMALE)
                        text3 = GOSSIP_BARBER_HAIR;
                    break;
                case RACE_GNOME:
                    if (player->getGender() == GENDER_FEMALE)
                        text3 = GOSSIP_BARBER_EARRINGS;
                    break;
                case RACE_TROLL:
                    text3 = GOSSIP_BARBER_TUSKS;
                    break;
#if EXPANSION > 0
                case RACE_BLOODELF:
                    if (player->getGender() == GENDER_FEMALE)
                        text3 = GOSSIP_BARBER_EARRINGS;
                    break;
                case RACE_DRAENEI:
                    player->getGender() == GENDER_FEMALE ? text3 = GOSSIP_BARBER_HORNS : text3 = GOSSIP_BARBER_TENTACLES;
                    break;
#endif
                }
                // MAP
                // 1 - main menu
                // 2 - next hair style
                // 3 - prev hair style
                // 4 - next hair color
                // 5 - prev hair color
                // 6 - next facial feature
                // 7 - prev facial feature
                // 8 - not enought gold, or other close

                switch (action)
                {
                    // After player requested the action
                case GOSSIP_ACTION_INFO_DEF + 1:
                    /*if ( sender == GOSSIP_SENDER_MAIN )
                    {
                        if(player->GetMoney() >= 500000)
                            player->ModifyMoney(-500000);
                        else
                            player->SendBuyError( BUY_ERR_NOT_ENOUGHT_MONEY, creature, 0, 0);
                    }*/
                    if (helmetShown && player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM))
                    {
                        helmetShown = false;
                        player->ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM);
                    }

                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, text1).c_str(), GOSSIP_SENDER_OPTION, GOSSIP_ACTION_INFO_DEF + 2);
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, text2).c_str(), GOSSIP_SENDER_OPTION, GOSSIP_ACTION_INFO_DEF + 4);
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, text3).c_str(), GOSSIP_SENDER_OPTION, GOSSIP_ACTION_INFO_DEF + 6);
                    player->SEND_GOSSIP_MENU(50023, creature->GetObjectGuid());
                    break;
                    // hair style
                    // next - increase hair style
                case GOSSIP_ACTION_INFO_DEF + 2:
                    if (!player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM))
                    {
                        helmetShown = true;
                        player->ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM);
                    }

                    if (sender == GOSSIP_SENDER_SUBOPTION)
                        SelectHairStyle(player, creature, 1);
                    // previous - decrease it
                case GOSSIP_ACTION_INFO_DEF + 3:
                    if (action == GOSSIP_ACTION_INFO_DEF + 3 && sender == GOSSIP_SENDER_SUBOPTION)
                        SelectHairStyle(player, creature, -1);
                    // choose options again
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_NEXT).c_str(), GOSSIP_SENDER_SUBOPTION, GOSSIP_ACTION_INFO_DEF + 2);
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_PREV).c_str(), GOSSIP_SENDER_SUBOPTION, GOSSIP_ACTION_INFO_DEF + 3);
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_CHOOSE).c_str(), GOSSIP_SENDER_SUBOPTION, GOSSIP_ACTION_INFO_DEF + 1);
                    player->SEND_GOSSIP_MENU(50024, creature->GetObjectGuid());
                    break;

                    // hair color
                    // next - increase hair color
                case GOSSIP_ACTION_INFO_DEF + 4:
                    if (!player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM))
                    {
                        helmetShown = true;
                        player->ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM);
                    }

                    if (sender == GOSSIP_SENDER_SUBOPTION)
                        SelectHairColor(player, creature, 1);
                    // previous - decrease hair color
                case GOSSIP_ACTION_INFO_DEF + 5:
                    if (action == GOSSIP_ACTION_INFO_DEF + 5 && sender == GOSSIP_SENDER_SUBOPTION)
                        SelectHairColor(player, creature, -1);
                    // choose options again
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_NEXT).c_str(), GOSSIP_SENDER_SUBOPTION, GOSSIP_ACTION_INFO_DEF + 4);
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_PREV).c_str(), GOSSIP_SENDER_SUBOPTION, GOSSIP_ACTION_INFO_DEF + 5);
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_CHOOSE).c_str(), GOSSIP_SENDER_SUBOPTION, GOSSIP_ACTION_INFO_DEF + 1);
                    player->SEND_GOSSIP_MENU(50024, creature->GetObjectGuid());
                    break;

                    // facial feature
                    // next - increase hair style
                case GOSSIP_ACTION_INFO_DEF + 6:
                    if (!player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM))
                    {
                        helmetShown = true;
                        player->ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM);
                    }

                    if (sender == GOSSIP_SENDER_SUBOPTION)
                        SelectFacialFeature(player, creature, 1);
                    // previous - decrease it
                case GOSSIP_ACTION_INFO_DEF + 7:
                    if (!player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM))
                    {
                        helmetShown = true;
                        player->ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_HIDE_HELM);
                    }

                    if (action == GOSSIP_ACTION_INFO_DEF + 7 && sender == GOSSIP_SENDER_SUBOPTION)
                        SelectFacialFeature(player, creature, -1);
                    // choose options again
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_NEXT).c_str(), GOSSIP_SENDER_SUBOPTION, GOSSIP_ACTION_INFO_DEF + 6);
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_PREV).c_str(), GOSSIP_SENDER_SUBOPTION, GOSSIP_ACTION_INFO_DEF + 7);
                    player->ADD_GOSSIP_ITEM(0, GetGossipText(player, GOSSIP_BARBER_CHOOSE).c_str(), GOSSIP_SENDER_SUBOPTION, GOSSIP_ACTION_INFO_DEF + 1);
                    player->SEND_GOSSIP_MENU(50024, creature->GetObjectGuid());
                    break;

                    // cannot affort
                case GOSSIP_ACTION_INFO_DEF + 8:
                    player->GetPlayerMenu()->CloseGossip();
                    break;
                }

                return true;
            }
        }

        return false;
    }

    void BarberModule::OnAddToWorld(Creature* creature)
    {
        // Check if speaking with barber npc.
        if (creature->GetEntry() != NPC_BARBER)
            return;

        if (!GetConfig()->enabled)
        {
            creature->SetRespawnDelay(RESPAWN_ONE_DAY);
            creature->ForcedDespawn();
        }
        else
        {
            creature->Respawn();
        }
    }

    maxStyles_t maxHairStyles[MAX_RACES] =
    {
        {0,0},  //                        0
        {11,18},// RACE_HUMAN           = 1,
        {6,6},  //  RACE_ORC            = 2,
        {10,13},// RACE_DWARF           = 3,
        {6,6},  // RACE_NIGHTELF        = 4,
        {10,9}, // RACE_UNDEAD_PLAYER   = 5,
        {7,6},  //  RACE_TAUREN         = 6,
        {6,6},  // RACE_GNOME           = 7,
        {5,4},  // RACE_TROLL           = 8,
        {0,0},  // RACE_GOBLIN          = 9,
        {9,13}, //  RACE_BLOODELF       = 10,
        {7,10}, //  RACE_DRAENEI        = 11
    };

    uint8 maxHairColor[MAX_RACES] =
    {
        0,  //                        0
        9,  // RACE_HUMAN           = 1,
        7,  //  RACE_ORC            = 2,
        9,  // RACE_DWARF           = 3,
        7,  // RACE_NIGHTELF        = 4,
        9,  // RACE_UNDEAD_PLAYER   = 5,
        2,  //  RACE_TAUREN         = 6,
        8,  // RACE_GNOME           = 7,
        9,  // RACE_TROLL           = 8,
        0,  // RACE_GOBLIN          = 9,
        9,  //  RACE_BLOODELF       = 10,
        6,  //  RACE_DRAENEI        = 11
    };

    maxStyles_t maxFacialFeatures[MAX_RACES] =
    {
        {0,0},  //                        0
        {8,6},  // RACE_HUMAN           = 1,
        {10,6}, // RACE_ORC             = 2,
        {10,5}, // RACE_DWARF           = 3,
        {5,9},  // RACE_NIGHTELF        = 4,
        {16,7}, // RACE_UNDEAD_PLAYER   = 5,
        {6,4},  // RACE_TAUREN          = 6,
        {7,6},  // RACE_GNOME           = 7,
        {10,5}, // RACE_TROLL           = 8,
        {0,0},  // RACE_GOBLIN          = 9,
        {10,9}, // RACE_BLOODELF        = 10,
        {7,6},  // RACE_DRAENEI         = 11
    };

    void BarberModule::ChangeEffect(Player* player)
    {
        player->SetDisplayId(10045);
        player->SendForcedObjectUpdate();
        player->DeMorph();
    }

    void BarberModule::SelectHairStyle(Player* player, Creature* creature, int change)
    {
        uint8 max = maxHairStyles[player->getRace()].maxMale;
        if (player->getGender() == GENDER_FEMALE)
            max = maxHairStyles[player->getRace()].maxFemale;

        int current = player->GetByteValue(PLAYER_BYTES, 2);

        current += change;

        if (current > max)
            current = 0;
        else if (current < 0)
            current = max;

        // cut visual effect
        creature->PlaySpellVisual(411);
        player->PlaySpellVisual(415);

        player->SetByteValue(PLAYER_BYTES, 2, current);
        ChangeEffect(player);
    }

    void BarberModule::SelectHairColor(Player* player, Creature* creature, int change)
    {
        uint8 max = maxHairColor[player->getRace()];
        int current = player->GetByteValue(PLAYER_BYTES, 3);

        current += change;

        if (current > max)
            current = 0;
        else if (current < 0)
            current = max;

        // magic visual effect
        creature->PlaySpellVisual(425);
        player->PlaySpellVisual(304);

        player->SetByteValue(PLAYER_BYTES, 3, current);
        ChangeEffect(player);
    }

    void BarberModule::SelectFacialFeature(Player* player, Creature* creature, int change)
    {
        uint8 max = maxFacialFeatures[player->getRace()].maxMale;
        if (player->getGender() == GENDER_FEMALE)
            max = maxFacialFeatures[player->getRace()].maxFemale;

        int current = player->GetByteValue(PLAYER_BYTES_2, 0);

        current += change;

        if (current > max)
            current = 0;
        else if (current < 0)
            current = max;

        // hit visual effect
        creature->PlaySpellVisual(517);
        player->PlaySpellVisual(290);

        player->SetByteValue(PLAYER_BYTES_2, 0, current);
        ChangeEffect(player);
    }

    std::string BarberModule::GetGossipText(Player* player, uint32 textId)
    {
        int loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
        std::string Text_0[MAX_GOSSIP_TEXT_OPTIONS], Text_1[MAX_GOSSIP_TEXT_OPTIONS];
        GossipText const* gossip = sObjectMgr.GetGossipText(textId);
        Text_0[0] = gossip->Options[0].Text_0;
        Text_1[0] = gossip->Options[0].Text_1;
        sObjectMgr.GetNpcTextLocaleStringsAll(textId, loc_idx, &Text_0, &Text_1);
        return Text_0[0];
    }
}
