#include "BarberModuleConfig.h"

namespace cmangos_module
{
    BarberModuleConfig::BarberModuleConfig()
    : ModuleConfig("barber.conf")
    , enabled(false)
    {
    
    }

    bool BarberModuleConfig::OnLoad()
    {
        enabled = config.GetBoolDefault("Barber.Enable", false);
        return true;
    }
}