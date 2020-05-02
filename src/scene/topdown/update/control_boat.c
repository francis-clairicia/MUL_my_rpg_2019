/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** control_boat
*/

#include "topdown.h"

void control_boat(control_t control, game_obj_t *boat)
{
    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_LEFT]))
        boat->body.torque -= 1;
    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_RIGHT]))
        boat->body.torque += 1;
    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_UP]))
        traction_force(&(boat->body), 1000);
    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_DOWN])) {
        boat->body.angle_vel = boat->body.angle_vel * 0.9;
        friction_force(&(boat->body), 1000);
    }
}