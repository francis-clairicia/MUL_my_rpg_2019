/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_weather
*/

#include "battle.h"

void destroy_battle_weather(battle_t *battle)
{
    free_game_object(battle->weather);
}