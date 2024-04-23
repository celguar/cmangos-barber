#ifndef CMANGOS_MODULE_BARBER_H
#define CMANGOS_MODULE_BARBER_H

#include "Module.h"
#include "BarberModuleConfig.h"

#include <unordered_map>

namespace cmangos_module
{
    enum BarberEnums
    {
        NPC_BARBER = 190012,
        GO_BARBER_CHAIR = 164767,

        GOSSIP_BARBER_GREET_ALLIANCE = 50404,
        GOSSIP_BARBER_GREET_HORDE = 50423,
        GOSSIP_BARBER_CUT_HAIR = 50405,
        GOSSIP_BARBER_NEED_MONEY = 50406,
        GOSSIP_BARBER_SIT_DOWN = 50407,
        GOSSIP_BARBER_NEXT = 50408,
        GOSSIP_BARBER_PREV = 50409,
        GOSSIP_BARBER_CHOOSE = 50410,
        GOSSIP_BARBER_HAIR_STYLE = 50411,
        GOSSIP_BARBER_HAIR_COLOR = 50412,
        GOSSIP_BARBER_FACIAL_HAIR = 50413,
        GOSSIP_BARBER_HORNS = 50414,
        GOSSIP_BARBER_HORN_COLOR = 50415,
        GOSSIP_BARBER_PIERCINGS = 50416,
        GOSSIP_BARBER_EARRINGS = 50417,
        GOSSIP_BARBER_MARKINGS = 50418,
        GOSSIP_BARBER_FACE = 50419,
        GOSSIP_BARBER_HAIR = 50420,
        GOSSIP_BARBER_TUSKS = 50421,
        GOSSIP_BARBER_TENTACLES = 50422,
        GOSSIP_SENDER_OPTION = 50,
        GOSSIP_SENDER_SUBOPTION = 51,
    };

    typedef struct maxStyles_struct {
        uint8 maxMale;
        uint8 maxFemale;
    } maxStyles_t;

    class BarberModule : public Module
    {
    public:
        BarberModule();
        const BarberModuleConfig* GetConfig() const override;

        // Module Hooks
        void OnInitialize() override;

        // Player Hooks
        bool OnPreGossipHello(Player* player, Creature* creature) override;
        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action, const std::string& code, uint32 gossipListId) override;

        // NPC hooks
        void OnAddToWorld(Creature* creature) override;

    private:
        // Barber
        void SelectFacialFeature(Player* player, Creature* creature, int change);
        void SelectHairColor(Player* player, Creature* creature, int change);
        void SelectHairStyle(Player* player, Creature* creature, int change);
        void ChangeEffect(Player* player);
        std::string GetGossipText(Player* player, uint32 textId);

    private:
        uint32 hairstyle;
        uint32 haircolor;
        uint32 facialfeature;
        bool   helmetShown;
    };
}
#endif