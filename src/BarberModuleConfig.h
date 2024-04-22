#pragma once
#include "ModuleConfig.h"

namespace cmangos_module
{
    class BarberModuleConfig : public ModuleConfig
    {
    public:
        BarberModuleConfig();
        bool OnLoad() override;

    public:
        bool enabled;
    };
}