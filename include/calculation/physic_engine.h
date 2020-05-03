/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** physic_engine
*/

#ifndef PHYSIC_ENGINE_H_
#define PHYSIC_ENGINE_H_

#include <math.h>
#include "vector_engine.h"

#define GRAVITY (9.8)

#define RAD(degree) (degree * M_PI / 180)
#define DEG(radian) (radian * 180 / M_PI)

typedef struct rigid_body_s
{
    float ray;
    float mass;
    float angle;
    float angle_vel;
    float torque;
    sfVector2f size;
    sfVector2f pos;
    sfVector2f center;
    sfVector2f vel;
    sfVector2f acc;
    sfVector2f obb[4];
} rigid_body_t;

void update_obb(rigid_body_t *body);

void apply_force(rigid_body_t *body, sfVector2f force);
void apply_force_ptr(rigid_body_t *body, void *data);

void body_add_acc(rigid_body_t *body, sfVector2f vec);
void body_add_acc_ptr(rigid_body_t *body, void *data);

void traction_force(rigid_body_t *body, float intensity);
void traction_force_ptr(rigid_body_t *body, void *data);

void friction_force(rigid_body_t *body, float intensity);
void friction_force_ptr(rigid_body_t *body, void *data);

sfBool collision_sat(rigid_body_t *body1, rigid_body_t *body2,
                sfBool (*res_func)(rigid_body_t *, rigid_body_t *, float));

void update_body(rigid_body_t *body, float dtime);

#endif /* !PHYSIC_ENGINE_H_ */
