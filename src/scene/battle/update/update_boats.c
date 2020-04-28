/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_boats
*/

#include "battle.h"

void update_boats(tool_t *tool, list_t *list)
{
    rigid_body_t *body = NULL;

    for (; list && list->data; list = list->next) {
        body = &(NODE_DATA(list, game_obj_t *)->body);
        body_add_acc(body, VEC2F(0, GRAVITY));
        update_body(body, tool->dtime);
    }
}