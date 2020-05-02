/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_map
*/

#include "topdown.h"

void destroy_topdown_map(topdown_t *topdown)
{
    if (topdown->map)
        my_free_list(&(topdown->map), free_game_object);
}