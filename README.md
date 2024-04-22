# Dual Spec
Dual Specialization module for cmangos vanilla and tbc cores which will allow the players to purchase and change between specializations

The dual specialization npc will be located in Stormwind Mage Tower and in Orgrimmar Valley of Spirits.

# Available Cores
Classic and TBC

# How to install
1. Follow the instructions in https://github.com/davidonete/cmangos-modules?tab=readme-ov-file#how-to-install
2. Enable the `BUILD_MODULE_DUALSPEC` flag in cmake and run cmake. The module should be installed in `src/modules/dualspec`
3. Copy the configuration file from `src/modules/dualspec/src/dualspec.conf.dist.in` and place it where your mangosd executable is. Also rename it to `dualspec.conf`.
4. Remember to edit the config file and modify the options you want to use.
5. Lastly you will have to install the database changes located in the `src/modules/dualspec/sql/install` folder, each folder inside represents where you should execute the queries. E.g. The queries inside of `src/modules/dualspec/sql/install/world` will need to be executed in the world/mangosd database, the ones in `src/modules/dualspec/sql/install/characters` in the characters database, etc...

# How to uninstall
To remove the dual spec from your server you have multiple options, the first and easiest is to disable it from the `dualspec.conf` file. The second option is to completely remove it from the server and db:
1. Remove the `BUILD_MODULE_DUALSPEC` flag from your cmake configuration and recompile the game
2. Execute the sql queries located in the `src/modules/dualspec/sql/uninstall` folder. Each folder inside represents where you should execute the queries. E.g. The queries inside of `src/modules/dualspec/sql/uninstall/world` will need to be executed in the world/mangosd database, the ones in `src/modules/dualspec/sql/uninstall/characters` in the characters database, etc...
