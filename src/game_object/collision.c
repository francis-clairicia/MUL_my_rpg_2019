/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** AABB collision resolution
*/

#include <stdbool.h>
#include "math_process.h"
#include "game_object.h"

static sfBool game_object_special_collision_solving(game_obj_t *obj1,
                                                    game_obj_t *obj2,
                                                    sfVector2f depth)
{
    if (obj1->body.mass == __FLT_MAX__ && obj2->body.mass == __FLT_MAX__)
        return (sfFalse);
    if (obj1->body.mass == __FLT_MAX__) {
        obj2->body.acc = vec_add(obj2->body.acc, vec_mult(depth, -1));
    } else if (obj2->body.mass == __FLT_MAX__) {
        obj1->body.acc = vec_add(obj1->body.acc, depth);
    }
    return (sfTrue);
}

static sfBool game_object_collision_solving(game_obj_t *obj1,
                                                game_obj_t *obj2)
{
    sfVector2f rv = vec_sub(obj2->body.vel, obj1->body.vel);
    float rv_magn = vec_mag(rv);
    float j = 0;
    sfVector2f impulse;
    sfVector2f normal = vec_norm(rv);

    j = -(1 + 0.8) * rv_magn;
    j /= (1 / obj1->body.mass) + (1 / obj2->body.mass);
    impulse = vec_mult(normal, j);
    obj1->body.vel = vec_sub(obj1->body.vel,
            vec_mult(impulse, 1 / obj1->body.mass));
    return (sfTrue);
}

sfBool game_object_aabb_collision(game_obj_t *obj1, game_obj_t *obj2)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(obj1->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(obj2->sprite);

    if (!obj1 || !obj2)
        return (sfFalse);
    if (sfFloatRect_intersects(&rect1, &rect2, NULL)) {
        return (game_object_collision_solving(obj1, obj2));
    }
    return (sfFalse);
}