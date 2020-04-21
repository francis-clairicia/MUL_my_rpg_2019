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
    sfFloatRect rect1 = sfSprite_getGlobalBounds(obj1->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(obj2->sprite);
    sfVector2f mid1 = VEC2F(rect1.left + (rect1.width / 2),
                            rect1.top + (rect1.height / 2));
    sfVector2f mid2 = VEC2F(rect2.left + (rect2.width / 2),
                            rect2.top + (rect2.height / 2));
    sfVector2f diff = VEC2F(mid2.x - mid1.x, mid2.y - mid1.y);
    sfVector2f dpth = VEC2F(((rect1.width / 2) + (rect2.width / 2)) - diff.x,
                            ((rect1.height / 2) + (rect2.height / 2)) - diff.y);

    if (obj1->body.mass == 0 && obj2->body.mass == 0)
        return (sfFalse);
    dpth = vec_mult(dpth, 0.0005);
    if (obj1->body.mass == __FLT_MAX__ || obj2->body.mass == __FLT_MAX__)
        return (game_object_special_collision_solving(obj1, obj2, dpth));
    obj1->body.acc = vec_add(obj1->body.acc,vec_mult(dpth, obj2->body.mass /
                                        (obj1->body.mass + obj2->body.mass)));
    obj2->body.acc = vec_add(obj2->body.acc, vec_mult(dpth, -(obj1->body.mass /
                                        (obj1->body.mass + obj2->body.mass))));
    return (true);
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