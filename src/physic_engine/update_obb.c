/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_obb
*/

#include "physic_engine.h"

static sfVector2f rotate_pt(sfVector2f point, float angle)
{
    sfVector2f new_pt;

    new_pt.x = point.x * cos(RAD(angle)) - point.y * sin(RAD(angle));
    new_pt.y = point.x * sin(RAD(angle)) + point.y * cos(RAD(angle));
    return (new_pt);
}

void update_obb(rigid_body_t *body)
{
    if (!body)
        return ;
    body->obb[0] = rotate_pt(VEC2F(body->size.x / 2, body->size.y / 2),
                                                            body->angle);
    body->obb[1] = rotate_pt(VEC2F(-(body->size.x / 2), body->size.y / 2),
                                                            body->angle);
    body->obb[2] = rotate_pt(VEC2F(-(body->size.x / 2), -(body->size.y / 2)),
                                                            body->angle);
    body->obb[3] = rotate_pt(VEC2F(body->size.x / 2, -(body->size.y / 2)),
                                                            body->angle);
    body->obb[0] = vec_add(body->obb[0], body->pos);
    body->obb[1] = vec_add(body->obb[1], body->pos);
    body->obb[2] = vec_add(body->obb[2], body->pos);
    body->obb[3] = vec_add(body->obb[3], body->pos);
}