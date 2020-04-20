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

sfBool set_view_box(game_obj_t *obj, sfIntRect *rect)
{
    register size_t index = 0;

    if (!obj || !(obj->texture) || !(obj->frame_nb) || !rect)
        return (sfFalse);
    while (rect[index].left != -1 && rect[index].top != -1
        && rect[index].width != -1 && rect[index].height != -1) {
            index += 1;
    }
    obj->view_box = malloc(sizeof(sfIntRect) * index);
    if (!(obj->view_box))
        return (sfFalse);
    my_memcpy(obj->view_box, rect, sizeof(sfIntRect) * index);
    return (sfTrue);
}

sfBool set_frame_nb(game_obj_t *obj, unsigned int nb)
{
    obj->frame_nb = nb;
    if (!(obj->frame_nb))
        return (sfFalse);
    return (sfTrue);
}

sfBool set_origin(game_obj_t *obj, sfVector2f origin)
{
    if (!obj || !(obj->sprite))
        return (sfFalse);
    if (origin.x <= 0 && origin.y <= 0) {
        origin.x = obj->view_box[0].left + (obj->view_box[0].width / -origin.x);
        origin.y = obj->view_box[0].top + (obj->view_box[0].height / -origin.y);
    }
    sfSprite_setOrigin(obj->sprite, origin);
    return (sfTrue);
}