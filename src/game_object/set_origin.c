/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_game_object_origin
*/

#include "game_object.h"

void set_game_object_origin(game_obj_t *obj, sfVector2f origin)
{
    if (!obj)
        return ;
    obj->origin[obj->state] = origin;
    update_sprite(obj);
}

void set_game_object_origin_ptr(game_obj_t *obj, void *data)
{
    sfVector2f origin;

    if (!obj || !data)
        return ;
    origin = *(sfVector2f *)data;
    obj->origin[obj->state] = origin;
    update_sprite(obj);
}
