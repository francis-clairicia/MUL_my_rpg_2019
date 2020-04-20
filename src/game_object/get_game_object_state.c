/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_game_object_state
*/

#include "game_object.h"

int get_game_object_state(game_obj_t *obj)
{
    int index = 0;

    if (has_comp(obj, STATE)) {
        index = obj->comp[find_comp(obj, STATE)]->i;
    }
    return (index);
}