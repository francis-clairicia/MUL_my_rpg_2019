/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_boat
*/

#include "update_topdown.h"
#include "math_process.h"

static void redirect_boat_ia(game_obj_t *boat, topdown_t *topdown)
{
    if (boat->type == BOAT2)
        update_topdown_boat_ia(boat, topdown->ally_boat, topdown->boat,
                                            &(topdown->bullets));
    if (boat->type == BOAT3)
        update_topdown_boat_ia(boat, topdown->ally_boat, topdown->boat,
                                            &(topdown->bullets));
    if (boat->type == BOAT4) {
        update_topdown_boat_ally_ia(boat, topdown->ennemy_boat, topdown->boat,
                                            &(topdown->bullets));
        update_topdown_boat_ally_ia(boat, topdown->mercenary_boat, topdown->boat,
                                            &(topdown->bullets));
    }
}

static void update_boat(float dtime, list_t *boat_list, topdown_t *topdown)
{
    game_obj_t *boat = NULL;

    for (; boat_list && boat_list->data; boat_list = boat_list->next) {
        boat = NODE_DATA(boat_list, game_obj_t *);
        if (!boat)
            continue;
        redirect_boat_ia(boat, topdown);
        boat_collision(boat, topdown->map);
        boat->body.angle_vel = MAX(boat->body.angle_vel, -180);
        boat->body.angle_vel = MIN(boat->body.angle_vel, 180);
        boat->body.angle_vel = boat->body.angle_vel * 0.95;
        boat->body.vel = vec_lim(boat->body.vel,
                                    VEC2F(40, 40), VEC2F(-40, -40));
        update_body(&(boat->body), dtime);
        boat_border(boat, topdown->map_size);
    }
}

static void update_player_s_boat(tool_t *tool, topdown_t *topdown)
{
    game_obj_t *boat = topdown->boat;

    control_boat(tool, topdown);
    boat_collision(boat, topdown->map);
    boat_border(boat, topdown->map_size);
    boat->body.angle_vel = MAX(boat->body.angle_vel, -180);
    boat->body.angle_vel = MIN(boat->body.angle_vel, 180);
    boat->body.angle_vel = boat->body.angle_vel * 0.95;
    boat->body.vel = vec_lim(boat->body.vel, VEC2F(50, 50), VEC2F(-50, -50));
    friction_force(&(boat->body), 250);
    update_obb(&(boat->body));
    update_body(&(boat->body), tool->dtime);
}

void update_topdown_boat(tool_t *tool, topdown_t *topdown)
{
    update_player_s_boat(tool, topdown);
    update_boat(tool->dtime, topdown->ally_boat, topdown);
    update_boat(tool->dtime, topdown->ennemy_boat, topdown);
    update_boat(tool->dtime, topdown->mercenary_boat, topdown);
    update_boat(tool->dtime, topdown->golden_boat, topdown);
}