/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_game_object_scale
*/

#include "game_object.h"

void set_game_object_scale(game_obj_t *obj, sfVector2f scale)
{
    if (!obj)
        return ;
    sfSprite_setScale(obj->sprite, scale);
}

void set_game_object_scale_ptr(game_obj_t *obj, void *data)
{
    sfVector2f scale;

    if (!obj || !data)
        return ;
    scale = *(sfVector2f *)data;
    sfSprite_setScale(obj->sprite, scale);
}