/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_bullets
*/

#include "topdown.h"

void destroy_topdown_bullets(topdown_t *topdown)
{
    if (topdown->bullets)
        my_free_list(&(topdown->bullets), free_game_object);
}