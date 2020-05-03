/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_ennemy_boat
*/

#include "battle.h"

void destroy_battle_ennemy(battle_t *battle)
{
    my_free_list(&(battle->ennemy_boat), free_game_object);
    my_free_list(&(battle->ennemy_crew), free_game_object);
}