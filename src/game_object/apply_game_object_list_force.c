/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** applay_game_object_list_force
*/

#include "game_object.h"

void apply_game_object_list_force(list_t *list, sfVector2f force)
{
    for (; list && list->data; list = list->next) {
        apply_force(&(NODE_DATA(list, game_obj_t *)->body), force);
    }
}