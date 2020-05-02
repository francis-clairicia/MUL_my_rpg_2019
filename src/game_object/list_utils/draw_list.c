/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_game_object_list
*/

#include "game_object.h"

void draw_game_object_list(sfRenderWindow *window, list_t *list)
{
    game_obj_t *obj = NULL;

    for (; list && list->data; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        draw_game_object(window, obj);
    }
}