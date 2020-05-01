/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_origin
*/

#include <stdlib.h>
#include "my.h"
#include "game_object.h"

sfBool set_origin(game_obj_t *obj, sfVector2f *origin, size_t size)
{
    register size_t idx = 0;

    if (!obj || !(obj->sprite))
        return (sfFalse);
    obj->origin = malloc(sizeof(sfVector2f) * size);
    if (!(obj->origin))
        return (sfFalse);
    for (idx = 0; idx < size; idx += 1) {
        obj->origin[idx] = origin[idx];
        if (origin[idx].x < 0 && origin[idx].y < 0) {
            obj->origin[idx].x = obj->view_box[0].left;
            obj->origin[idx].x += (obj->view_box[0].width / -origin[idx].x);
            obj->origin[idx].y = obj->view_box[0].top;
            obj->origin[idx].y += (obj->view_box[0].height / -origin[idx].y);
        }
    }
    sfSprite_setOrigin(obj->sprite, obj->origin[0]);
    return (sfTrue);
}