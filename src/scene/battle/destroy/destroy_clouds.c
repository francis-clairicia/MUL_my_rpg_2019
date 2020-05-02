/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_clouds
*/

#include "battle.h"

void destroy_battle_clouds(battle_t *battle)
{
    if (battle->clouds)
        my_free_list(&(battle->clouds), free_game_object);
}