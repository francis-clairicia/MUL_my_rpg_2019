/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** body_add_acc
*/

#include "physic_engine.h"

void body_add_acc(rigid_body_t *body, sfVector2f vec)
{
    if (!body)
        return ;
    body->acc = vec_add(body->acc, vec);
}

void body_add_acc_ptr(rigid_body_t *body, void *data)
{
    sfVector2f vec;

    if (!body || !data)
        return ;
    vec = *(sfVector2f *)data;
    body->acc = vec_add(body->acc, vec);
}