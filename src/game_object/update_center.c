/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_center
*/

#include "game_object.h"

void update_game_object_center(game_obj_t *obj)
{
    if (!obj)
        return;
    obj->body.center = get_game_objet_center(obj);
}