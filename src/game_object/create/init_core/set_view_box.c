/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_view_box
*/

#include <stdlib.h>
#include "my.h"
#include "game_object.h"

sfBool set_view_box(game_obj_t *obj, sfIntRect *rect, size_t size)
{
    if (!obj || !(obj->texture) || !(obj->frame_nb) || !rect)
        return (sfFalse);
    obj->view_box = malloc(sizeof(sfIntRect) * size);
    if (!(obj->view_box))
        return (sfFalse);
    my_memcpy(obj->view_box, rect, sizeof(sfIntRect) * size);
    obj->body.size = VEC2F(rect[0].width, rect[0].height);
    return (sfTrue);
}