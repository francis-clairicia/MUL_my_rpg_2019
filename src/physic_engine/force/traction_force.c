/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** traction_force
*/

#include "physic_engine.h"

void traction_force(rigid_body_t *body, float intensity)
{
    sfVector2f head;

    if (!body)
        return ;
    head.x = cos(RAD((body->angle + 90)));
    head.y = sin(RAD((body->angle + 90)));
    head = vec_norm(head);
    head = vec_mult(head, intensity);
    apply_force(body, head);
}

void traction_force_ptr(rigid_body_t *body, void *data)
{
    sfVector2f head;
    float intensity = 0;

    if (!body || !data)
        return ;
    intensity = *(float *)data;
    head.x = cos((RAD(body->angle + 90)));
    head.y = sin((RAD(body->angle + 90)));
    head = vec_norm(head);
    head = vec_mult(head, intensity);
    apply_force(body, head);
}