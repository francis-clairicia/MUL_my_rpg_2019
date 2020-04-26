/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** apply_force
*/

#include "physic_engine.h"

void apply_force(rigid_body_t *body, sfVector2f force)
{
    if (!body)
        return ;
    force = vec_mult(force, 1 / body->mass);
    body->acc = vec_add(force, body->acc);
}

void apply_force_ptr(rigid_body_t *body, void *data)
{
    sfVector2f force;

    if (!body || !data)
        return ;
    force = *(sfVector2f *)data;
    force = vec_mult(force, 1 / body->mass);
    body->acc = vec_add(force, body->acc);
}