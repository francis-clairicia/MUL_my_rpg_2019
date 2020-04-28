/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** find_game_object
*/

#include "game_object.h"

game_obj_t *find_game_object(list_t *list, elem_t type)
{
    game_obj_t *obj = NULL;

    if (!list)
        return (NULL);
    for (; list && list->data; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (obj->type == type)
            return (obj);
    }
    return (NULL);
}