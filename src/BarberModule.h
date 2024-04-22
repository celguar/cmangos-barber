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

        GOSSIP_BARBER_GREET = 50404,
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

    private:
        uint32 hairstyle;
        uint32 haircolor;
        uint32 facialfeature;
        bool   helmetShown;
    };
}
#endif