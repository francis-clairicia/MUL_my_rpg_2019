/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Creates a game_object / Finds its component.
*/

#include <stdlib.h>
#include "my.h"
#include "init_game_object.h"

game_obj_t *create_game_obj(const elem_t type)
{
    game_obj_t *obj = malloc(sizeof(game_obj_t));

    if (!obj)
        return (NULL);
    my_memset(obj, 0, sizeof(game_obj_t));
    obj->type = type;
    if (!init_game_object(obj))
        return (NULL);
    return (obj);
}