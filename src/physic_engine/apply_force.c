/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** apply_force
*/

#include "physic_engine.h"

void traction_force(rigid_body_t *body)
{
    sfVector2f head;

    head.x = cos((RAD(body->angle + 90)));
    head.y = sin((RAD(body->angle + 90)));
    head = vec_norm(head);
    apply_force(body, head);
}

void friction_force(rigid_body_t *body, float intensity)
{
    sfVector2f friction;

    friction = vec_norm(body->vel);
    friction = vec_mult(friction, -intensity);
    apply_force(body, friction);
}

void apply_force(rigid_body_t *body, sfVector2f force)
{
    force = vec_mult(force, 1 / body->mass);
    body->acc = vec_add(force, body->acc);
}