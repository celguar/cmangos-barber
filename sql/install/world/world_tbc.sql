SET @Entry := 190012;

DELETE FROM creature_template WHERE entry IN (@Entry);
INSERT INTO creature_template (Entry, Name, SubName, MinLevel, MaxLevel, ModelId1, ModelId2, ModelId3, ModelId4, Faction, Scale, Family, CreatureType, InhabitType, RegenerateStats, RacialLeader, NpcFlags, UnitFlags, DynamicFlags, ExtraFlags, CreatureTypeFlags, SpeedWalk, SpeedRun, Detection, CallForHelp, Pursuit, Leash, Timeout, UnitClass, `Rank`, HealthMultiplier, PowerMultiplier, DamageMultiplier, DamageVariance, ArmorMultiplier, ExperienceMultiplier, MinLevelHealth, MaxLevelHealth, MinLevelMana, MaxLevelMana, MinMeleeDmg, MaxMeleeDmg, MinRangedDmg, MaxRangedDmg, Armor, MeleeAttackPower, RangedAttackPower, MeleeBaseAttackTime, RangedBaseAttackTime, DamageSchool, MinLootGold, MaxLootGold, LootId, PickpocketLootId, SkinningLootId, KillCredit1, KillCredit2, MechanicImmuneMask, SchoolImmuneMask, ResistanceHoly, ResistanceFire, ResistanceNature, ResistanceFrost, ResistanceShadow, ResistanceArcane, PetSpellDataId, MovementType, TrainerType, TrainerSpell, TrainerClass, TrainerRace, TrainerTemplateId, VendorTemplateId, EquipmentTemplateId, GossipMenuId, AIName) VALUES
(@Entry,'Shav Cutiss','The Barber','60','60','23766','23766','23766','23766','35','1','0','7','3','3','0','1','0','0','0','0','1','1.14286','20','0','0','0','0','1','0','1','1','1','1','1','1','42','42','0','0','2','2','0','0','7','11','0','2000','2000','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',@Entry,'0','');

DELETE FROM creature_equip_template WHERE entry IN (@Entry);
INSERT INTO creature_equip_template (entry, equipentry1, equipentry2, equipentry3) VALUES
(@Entry,5278,0,0); -- Monster - Dagger, Bowie Knife

DELETE FROM npc_text WHERE id BETWEEN 50404 AND 50422;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`) VALUES
('50404','Welcome, friend, to the barbershop! Come for a cut? A coloring? Something else, perhaps?$B$BWe can groom facial hair, perform piercings, ink night elf tattoos, and even reshape draenei horns and tendrils!$B$BHave a seat and we\'ll get right to work. You\'re only a few coins away from a new, more attractive you...','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50405','Cut my hair, barber!','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50406','You need 0 copper to pay me.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50407','Please sit down!','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50408','Next one!','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50409','Previous one!','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50410','I\'ll have this one.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50411','I want to change my hair style.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50412','I want to change my hair color.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50413','I want to change my facial hair style.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50414','I want to change my horns.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50415','I want to change my horn color.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50416','I want to change my piercings.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50417','I want to change my earrings.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50418','I want to change my markings.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50419','I want to change my face.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50420','I want to change my hair.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50421','I want to change my tusks.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50422','I want to change my tentacles.','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0'),
('50423','Welcome, friend, to the barbershop! Come for a cut? A coloring? Something else, perhaps?$B$BWe can groom facial hair, perform piercings, reshape tusks and horns, and even modify undead features!$B$BHave a seat and we\'ll get right to work. You\'re only a few coins away from a new, more attractive you...','','0','1','0','1','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0','','','0','0','0','0','0','0','0','0');


-- Wooden Chairs
DELETE FROM `gameobject` WHERE id IN (164767);
-- Replace 4 chairs in Stormwind Trade District
UPDATE `gameobject` SET `id`=164767 WHERE `guid`=26391;
UPDATE `gameobject` SET `id`=164767 WHERE `guid`=26394;
UPDATE `gameobject` SET `id`=164767 WHERE `guid`=26392;
UPDATE `gameobject` SET `id`=164767 WHERE `guid`=26393;
-- Orgrimmar
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecsmin`, `spawntimesecsmax`) VALUES (164767, 1, 1, 1716.75000000000000000000, -4206.86000000000000000000, 51.65410000000000000000, 3.15883000000000000000, 0.00000000000000000000, 0.00000000000000000000, 0.99996300000000000000, -0.00861996000000000000, 25, 25);
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecsmin`, `spawntimesecsmax`) VALUES (164767, 1, 1, 1713.81000000000000000000, -4209.67000000000000000000, 51.65430000000000000000, 1.54877000000000000000, 0.00000000000000000000, 0.00000000000000000000, 0.69927500000000000000, 0.71485300000000000000, 25, 25);
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecsmin`, `spawntimesecsmax`) VALUES (164767, 1, 1, 1710.72000000000000000000, -4206.31000000000000000000, 51.65340000000000000000, 5.89202000000000000000, 0.00000000000000000000, 0.00000000000000000000, 0.19433800000000000000, -0.98093500000000000000, 25, 25);
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecsmin`, `spawntimesecsmax`) VALUES (164767, 1, 1, 1713.30000000000000000000, -4203.88000000000000000000, 51.65340000000000000000, 5.02809000000000000000, 0.00000000000000000000, 0.00000000000000000000, 0.58716000000000000000, -0.80947100000000000000, 25, 25);

DELETE FROM creature WHERE id IN (@Entry);
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecsmin`, `spawntimesecsmax`, `spawndist`, `MovementType`) VALUES (@Entry, 0, 1, -8748.08000000000000000000, 651.95000000000000000000, 105.43000000000000000000, 1.82255000000000000000, 25, 25, 0, 0);
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecsmin`, `spawntimesecsmax`, `spawndist`, `MovementType`) VALUES (@Entry, 1, 1, 1713.69000000000000000000, -4207.01000000000000000000, 51.65330000000000000000, 3.97408000000000000000, 25, 25, 0, 0);
