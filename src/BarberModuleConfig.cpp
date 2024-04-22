#include "TbcBoostModuleConfig.h"

namespace cmangos_module
{
    TbcBoostModuleConfig::TbcBoostModuleConfig()
    : ModuleConfig("tbcboost.conf")
    , enabled(false)
    , cost(0U)
    {
    
    }

    bool TbcBoostModuleConfig::OnLoad()
    {
        enabled = config.GetBoolDefault("TbcBoost.Enable", false);
        cost = config.GetIntDefault("TbcBoost.Cost", 10000U);
        return true;
    }
}