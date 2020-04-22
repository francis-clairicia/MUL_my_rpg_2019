/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_boats
*/

#include "battle.h"

void update_boats(list_t *list)
{
    for (; list && list->data; list = list->next) {
        body_add_acc(&(NODE_DATA(list, game_obj_t *)->body), VEC2F(0, 0.0005));
        update_body(&(NODE_DATA(list, game_obj_t *)->body));
    }
}