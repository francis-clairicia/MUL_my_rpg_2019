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
    update_boats(tool, battle->player->boat);
    update_battle_player(tool, battle);
    buoyancy_boat_water(tool->player.boat, battle->water);
}