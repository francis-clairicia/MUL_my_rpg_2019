/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sat_collision
*/

#include <stdlib.h>
#include "physic_engine.h"
#include "math_process.h"

static sfBool projection_conflict(rigid_body_t *b1, rigid_body_t *b2,
                                        sfVector2f axis, float *overlap)
{
    register size_t i = 0;
    float dot_product = 0;
    sfVector2f max = VEC2F(__FLT_MIN__, __FLT_MIN__);
    sfVector2f min = VEC2F(__FLT_MAX__, __FLT_MAX__);

    for (i = 0; i < 4; i += 1) {
        dot_product = vec_dot(b1->obb[i], axis);
        min.x = MIN(min.x, dot_product);
        max.x = MAX(max.x, dot_product);
    }
    for (i = 0; i < 4; i += 1) {
        dot_product = vec_dot(b2->obb[i], axis);
        min.y = MIN(min.y, dot_product);
        max.y = MAX(max.y, dot_product);
    }
    *overlap = MIN(MIN(max.x, max.y) - MAX(min.x, min.y), *overlap);
    if (!(max.y >= min.x && max.x >= min.y))
        return (sfFalse);
    return (sfTrue);
}

sfBool collision_sat(rigid_body_t *body1, rigid_body_t *body2,
                sfBool (*res_func)(rigid_body_t *, rigid_body_t *, float))
{
    register size_t i = 0;
    rigid_body_t *b1 = body1;
    rigid_body_t *b2 = body2;
    sfVector2f axis = {0, 0};
    float overlap = __FLT_MAX__;
    int shape = 0;

    for (shape = 0; shape < 2; shape += 1) {
        if (shape) {
            b1 = body2;
            b2 = body1;
        }
        for (i = 0; i < 4; i += 1) {
            axis.x = -(b1->obb[(i + 1) % 4].y - b1->obb[i].y);
            axis.y = b1->obb[(i + 1) % 4].x - b1->obb[i].x;
            if (!projection_conflict(b1, b2, axis, &overlap))
                return (sfFalse);
        }
    }
    return (res_func(body1, body2, overlap));
}