/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy
*/

#include "destroy_battle.h"

void destroy_battle(battle_t *battle)
{
    if (!battle)
        return;
    destroy_battle_background(battle);
    destroy_battle_ennemy(battle);
    destroy_battle_water(battle);
    destroy_battle_clouds(battle);
    destroy_player(battle->player, false);
}