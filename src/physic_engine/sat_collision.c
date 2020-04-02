/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sat_collision
*/

#include <stdlib.h>
#include "physic_engine.h"

static sfBool projection_conflict(rigid_body_t *b1, rigid_body_t *b2,
                                                    sfVector2f axis)
{
    register size_t i = 0;
    float dot_product = 0;
    sfVector2f max = VEC2F(__FLT_MIN__, __FLT_MIN__);
    sfVector2f min = VEC2F(__FLT_MAX__, __FLT_MAX__);

    for (i = 0; i < 4; i += 1) {
        dot_product = vec_dot(b1->obb[i], axis);
        min.x = min.x > dot_product ? dot_product : min.x;
        max.x = max.x < dot_product ? dot_product : max.x;
    }
    for (i = 0; i < 4; i += 1) {
        dot_product = vec_dot(b2->obb[i], axis);
        min.y = min.y > dot_product ? dot_product : min.y;
        max.y = max.y < dot_product ? dot_product : max.y;
    }
    if (!(max.y >= min.x && max.x >= min.y))
        return (sfFalse);
    return (sfTrue);
}

sfBool collision_sat(rigid_body_t *body1, rigid_body_t *body2)
{
    rigid_body_t *b1 = body1;
    rigid_body_t *b2 = body2;
    sfVector2f axis = {0, 0};
    int shape = 0;
    int i = 0;

    for (shape = 0; shape < 2; shape +=1) {
        if (shape) {
            b1 = body2;
            b2 = body1;
        }
        for (i = 0; i < 4; i += 1) {
            axis = vec_normal(vec_sub(b1->obb[(i + 1) % 4], b1->obb[i]));
            if (projection_conflict(b1, b2, axis))
                return (sfFalse);
        }
    }
    return (sfTrue);
}