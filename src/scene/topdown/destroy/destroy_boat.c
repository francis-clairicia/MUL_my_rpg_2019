/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_boat
*/

#include "topdown.h"

void destroy_topdown_boat(topdown_t *topdown)
{
    if (topdown->boat)
        free_game_object(topdown->boat);
    if (topdown->ally_boat)
        my_free_list(&(topdown->ally_boat), free_game_object);
    if (topdown->commercial_boat)
        my_free_list(&(topdown->commercial_boat), free_game_object);
    if (topdown->ennemy_boat)
        my_free_list(&(topdown->ennemy_boat), free_game_object);
    if (topdown->mercenary_boat)
        my_free_list(&(topdown->mercenary_boat), free_game_object);
}