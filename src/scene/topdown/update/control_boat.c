/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** control_boat
*/

#include "topdown.h"

static void control_boat_attack(tool_t *tool, topdown_t *topdown,
                                                game_obj_t *boat)
{
    if (sfKeyboard_isKeyPressed(tool->player.control.keys[CONTROL_ATTACK1])) {
        if (can_game_object_attack(boat))
            boat_attack(boat, &(topdown->bullets), 0);
    }
    if (sfKeyboard_isKeyPressed(tool->player.control.keys[CONTROL_ATTACK2])) {
        if (can_game_object_attack(boat))
            boat_attack(boat, &(topdown->bullets), 1);
    }
}

void control_boat(tool_t *tool, topdown_t *topdown)
{
    game_obj_t *boat = topdown->boat;

    if (sfKeyboard_isKeyPressed(tool->player.control.keys[CONTROL_LEFT]))
        boat->body.torque -= 1;
    if (sfKeyboard_isKeyPressed(tool->player.control.keys[CONTROL_RIGHT]))
        boat->body.torque += 1;
    if (sfKeyboard_isKeyPressed(tool->player.control.keys[CONTROL_UP]))
        traction_force(&(boat->body), 1000);
    if (sfKeyboard_isKeyPressed(tool->player.control.keys[CONTROL_DOWN])) {
        boat->body.angle_vel = boat->body.angle_vel * 0.9;
        friction_force(&(boat->body), 1000);
    }
    control_boat_attack(tool, topdown, boat);
}