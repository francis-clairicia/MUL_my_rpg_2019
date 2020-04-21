/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_state
*/

#include "game_object.h"

sfBool update_game_object_state(game_obj_t *obj, unsigned int state)
{
    if (!obj)
        return (sfFalse);
    obj->state = state;
    sfSprite_setOrigin(obj->sprite, obj->origin[state]);
    return (sfTrue);
}