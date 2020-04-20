/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** comp_utils
*/

#include <stdbool.h>
#include "game_object.h"

int find_comp(game_obj_t *obj, const prop_t type)
{
    register size_t index = 0;

    if (!obj || !(obj->comp))
        return (0);
    while (obj->comp[index] && obj->comp[index]->type != type
        && index < obj->comp_nb)
        index += 1;
    if (obj->comp[index]->type != type)
        return (0);
    return (index);
}

bool has_comp(game_obj_t *obj, const prop_t type)
{
    register size_t index = 0;

    if (!obj || !(obj->comp))
        return (false);
    while (obj->comp[index] && index < obj->comp_nb) {
        if (obj->comp[index]->type == type)
            return (true);
        index += 1;
    }
    return (false);
}