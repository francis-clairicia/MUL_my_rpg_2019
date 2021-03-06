/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_rigid_body
*/

#include "physic_engine.h"
#include "math_process.h"

void update_body(rigid_body_t *body, float dtime)
{
    body->angle_vel += body->torque;
    body->angle += body->angle_vel * dtime;
    body->vel = vec_add(body->vel, body->acc);
    body->pos = vec_add(body->pos, vec_mult(body->vel, dtime));
    body->acc = VEC2F(0, 0);
    body->torque = 0;
    update_obb(body);
}