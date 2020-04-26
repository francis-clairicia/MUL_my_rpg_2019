/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** body_list_utils
*/

#include "game_object.h"

void body_list(list_t *list,
                void (*func)(rigid_body_t *, void *),
                void *data)
{
    game_obj_t *tmp = NULL;

    if (!func || !list)
        return ;
    for (; list && list->data; list = list->next) {
        tmp = NODE_DATA(list, game_obj_t *);
        func(&(tmp->body), data);
    }
}