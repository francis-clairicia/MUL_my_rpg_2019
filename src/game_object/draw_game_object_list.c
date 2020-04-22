/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_game_object_list
*/

#include "game_object.h"

void draw_game_object_list(sfRenderWindow *window, list_t *list)
{
    for (; list && list->data; list = list->next) {
        draw_game_object(window, (game_obj_t *)list->data);
    }
}