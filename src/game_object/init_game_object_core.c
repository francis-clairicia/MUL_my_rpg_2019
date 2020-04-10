/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_game_object_core
*/

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
    sfSprite_setTextureRect(obj->sprite, obj->view_box);
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

sfBool set_view_box(game_obj_t *obj, sfIntRect rect)
{
    sfVector2u size = (sfVector2u){0, 0};

    if (!obj || !(obj->texture) || !(obj->frame_nb))
        return (sfFalse);
    if (rect.left || rect.top || rect.width || rect.height) {
        obj->view_box = rect;
        return (sfTrue);
    }
    size = sfTexture_getSize(obj->texture);
    obj->view_box.left = 0;
    obj->view_box.top = 0;
    obj->view_box.width = size.x / obj->frame_nb;
    obj->view_box.height = size.y;
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
        origin.x = obj->view_box.left + (obj->view_box.width / -origin.x);
        origin.y = obj->view_box.top + (obj->view_box.height / -origin.y);
    }
    sfSprite_setOrigin(obj->sprite, origin);
    return (sfTrue);
}