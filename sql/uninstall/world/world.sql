SET @Entry := 190012;

DELETE FROM creature_template WHERE entry IN (@Entry);
DELETE FROM npc_text WHERE id IN (50404);
DELETE FROM creature WHERE id IN (@Entry);

-- Restore Wooden Chair IDs in Stormwind
UPDATE `gameobject` SET `id`=24500 WHERE `guid`=26391;
UPDATE `gameobject` SET `id`=24501 WHERE `guid`=26394;
UPDATE `gameobject` SET `id`=24502 WHERE `guid`=26392;
UPDATE `gameobject` SET `id`=24503 WHERE `guid`=26393;

DELETE FROM gameobject WHERE id IN (164767);
