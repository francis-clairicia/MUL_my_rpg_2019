/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** friction_force
*/

#include "physic_engine.h"

void friction_force(rigid_body_t *body, float intensity)
{
    sfVector2f friction;

    if (!body)
        return ;
    friction = vec_norm(body->vel);
    friction = vec_mult(friction, -intensity);
    apply_force(body, friction);
}

void friction_force_ptr(rigid_body_t *body, void *data)
{
    float intensity = 0;
    sfVector2f friction;

    if (!body || !data)
        return ;
    intensity = *(float *)data;
    friction = vec_norm(body->vel);
    friction = vec_mult(friction, -intensity);
    apply_force(body, friction);
}