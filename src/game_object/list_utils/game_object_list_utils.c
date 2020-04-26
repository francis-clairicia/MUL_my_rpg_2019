/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_object_list_utils
*/

#include "game_object.h"

void game_object_list(list_t *list,
                            void (*func)(game_obj_t *, void *),
                            void *data)
{
    game_obj_t *tmp = NULL;

    if (!func || !list || !data)
        return ;
    for (; list && list->data; list = list->next) {
        tmp = NODE_DATA(list, game_obj_t *);
        func(tmp, data);
    }
}