/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_texture
*/

#include <stdlib.h>
#include "my.h"
#include "game_object.h"

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
