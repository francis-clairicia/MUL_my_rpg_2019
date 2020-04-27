/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** add_pos
*/

#include "game_object.h"

void add_game_object_pos(game_obj_t *obj, sfVector2f pos)
{
    if (!obj)
        return ;
    obj->body.pos = vec_add(obj->body.pos, pos);
    update_sprite(obj);
}

void add_game_object_pos_ptr(game_obj_t *obj, void *data)
{
    sfVector2f pos;

    if (!obj || !data)
        return ;
    pos = *(sfVector2f *)data;
    obj->body.pos = vec_add(obj->body.pos, pos);
    update_sprite(obj);
}