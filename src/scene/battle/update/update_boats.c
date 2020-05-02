/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_boats
*/

#include "update_battle.h"

void update_battle_boats(tool_t *tool, battle_t *battle)
{
    rigid_body_t *body = NULL;
    list_t *boat = battle->player->boat;

    for (; boat && boat->data; boat = boat->next) {
        body = &(NODE_DATA(boat, game_obj_t *)->body);
        friction_force(body, 100);
        body->vel = vec_lim(body->vel, VEC2F(100, 100), VEC2F(-100, -100));
        update_body(body, tool->dtime);
    }
}