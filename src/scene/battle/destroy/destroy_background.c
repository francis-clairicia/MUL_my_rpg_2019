/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_background
*/

#include "battle.h"

void destroy_battle_background(battle_t *battle)
{
    free_game_object(battle->background);
}