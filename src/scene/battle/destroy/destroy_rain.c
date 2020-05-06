/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_rain
*/

#include "battle.h"

void destroy_battle_water(battle_t *battle)
{
    my_free_list(&(battle->rain), free_game_object);
}