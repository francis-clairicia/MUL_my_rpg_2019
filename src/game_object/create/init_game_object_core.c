/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_game_object_core
*/

#include <stdlib.h>
#include "my.h"
#include "game_object.h"

sfBool set_sprite(game_obj_t *obj)
{
    if (!obj || !(obj->texture))
        return (sfFalse);
    obj->sprite = sfSprite_create();
    if (!(obj->sprite)) {
        my_printf("Set sprite failed for game_object %d\n", obj->type);
        return (sfFalse);
    }
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->view_box[0]);
    return (sfTrue);
}

sfBool set_texture(game_obj_t *obj, char *path)
{
    if (!obj || !path)
        return (sfFalse);
    obj->texture = sfTexture_createFromFile(path, NULL);
    if (!(obj->texture)) {
        my_printf("Set texture failed for game_object %d\n", obj->type);
        return (sfFalse);
    }
    return (sfTrue);
}

sfBool set_view_box(game_obj_t *obj, sfIntRect *rect, size_t size)
{
    if (!obj || !(obj->texture) || !(obj->frame_nb) || !rect)
        return (sfFalse);
    obj->view_box = malloc(sizeof(sfIntRect) * size);
    if (!(obj->view_box))
        return (sfFalse);
    my_memcpy(obj->view_box, rect, sizeof(sfIntRect) * size);
    return (sfTrue);
}

sfBool set_frame_nb(game_obj_t *obj, unsigned int *nb, size_t size)
{
    register size_t index = 0;

    obj->frame_nb = malloc(sizeof(int) * size);
    if (!(obj->frame_nb))
        return (sfFalse);
    for (index = 0; index < size; index += 1) {
        obj->frame_nb[index] = nb[index];
        if (!(obj->frame_nb[index])) {
            my_printf("Game object frame_nb must be > 1\n");
            return (sfFalse);
        }
    }
    return (sfTrue);
}

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
        if (origin[idx].x <= 0 && origin[idx].y <= 0) {
            obj->origin[idx].x = obj->view_box[0].left;
            obj->origin[idx].x += (obj->view_box[0].width / -origin[idx].x);
            obj->origin[idx].y = obj->view_box[0].top;
            obj->origin[idx].y += (obj->view_box[0].height / -origin[idx].y);
        }
    }
    sfSprite_setOrigin(obj->sprite, obj->origin[0]);
    return (sfTrue);
}