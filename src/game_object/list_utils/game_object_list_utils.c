/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_object_list_utils
*/

#include "game_object.h"

void game_object_list_vec2f(list_t *list,
                            void (*vec2f_func)(game_obj_t *, sfVector2f),
                            sfVector2f vec)
{
    game_obj_t *tmp = NULL;

    if (!vec2f_func || !list)
        return ;
    for (; list && list->data; list = list->next) {
        tmp = NODE_DATA(list, game_obj_t *);
        (*vec2f_func)(tmp, vec);
    }
}