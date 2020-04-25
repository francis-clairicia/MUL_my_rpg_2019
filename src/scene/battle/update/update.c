/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update
*/

#include "rpg.h"
#include "battle.h"

void update_battle(tool_t *tool, battle_t *battle)
{
    update_boats(tool, battle->player->boat_bg);
    buoyancy_boat_water(battle->player->boat_bg, battle->water);
}