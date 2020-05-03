/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_boat
*/

#include "update_topdown.h"
#include "math_process.h"

static void update_boat(float dtime, list_t *boat_list, list_t *map)
{
    game_obj_t *boat = NULL;

    for (; boat_list && boat_list->data; boat_list = boat_list->next) {
        boat = NODE_DATA(boat_list, game_obj_t *);
        boat_collision(boat, map);
        update_body(&(boat->body), dtime);
    }
}

static void update_player_s_boat(tool_t *tool, topdown_t *topdown)
{
    game_obj_t *boat = topdown->boat;

    control_boat(tool, topdown);
    boat_collision(boat, topdown->map);
    boat->body.angle_vel = MAX(boat->body.angle_vel, -180);
    boat->body.angle_vel = MIN(boat->body.angle_vel, 180);
    boat->body.angle_vel = boat->body.angle_vel * 0.99;
    boat->body.vel = vec_lim(boat->body.vel, VEC2F(50, 50), VEC2F(-50, -50));
    friction_force(&(boat->body), 250);
    update_obb(&(boat->body));
    update_body(&(boat->body), tool->dtime);
}

void abb(list_t *list, float dtime)
{
    game_obj_t *obj = NULL;

    for (; list; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        update_body(&(obj->body), dtime);
    }
}

void update_topdown_boat(tool_t *tool, topdown_t *topdown)
{
    update_player_s_boat(tool, topdown);
    update_boat(tool->dtime, topdown->ally_boat, topdown->map);
    update_boat(tool->dtime, topdown->ennemy_boat, topdown->map);
    update_boat(tool->dtime, topdown->mercenary_boat, topdown->map);
    update_boat(tool->dtime, topdown->golden_boat, topdown->map);
    abb(topdown->bullets, tool->dtime);
}