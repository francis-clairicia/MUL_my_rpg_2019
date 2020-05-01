/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_sprite
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
