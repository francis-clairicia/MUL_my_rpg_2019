/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_water
*/

#include "battle.h"

void destroy_battle_water(battle_t *battle)
{
    my_free_list(&(battle->water), free_game_object);
}