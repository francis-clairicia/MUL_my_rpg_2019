/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** AABB collision resolution
*/

#include <stdbool.h>
#include "math_process.h"
#include "game_object.h"

static sfBool game_object_collision_solving(game_obj_t *obj1,
                                                game_obj_t *obj2)
{
    sfVector2f n = vec_sub(obj2->body.pos, obj1->body.pos);
    float a_extent = obj1->view_box[obj1->state].width / 2;
    float b_extent = obj2->view_box[obj2->state].width / 2;
    float x_overlap = a_extent + b_extent - ABS(n.x);
    sfVector2f normal = VEC2F(0, 0);
    float penetration = 0;

    if (x_overlap > 0) {
        a_extent = obj1->view_box[obj1->state].height / 2;
        b_extent = obj2->view_box[obj2->state].height / 2;
        float y_overlap = a_extent + b_extent - ABS(n.x);
        if (y_overlap > 0) {
            if (x_overlap > y_overlap) {
                if (n.x < 0)
                    normal = VEC2F(-1, 0);
                else
                    normal = VEC2F(0, 0);
                penetration = x_overlap;
            }
            else
            {
                if (n.y < 0)
                    normal = VEC2F(0, -1);
                else
                    normal = VEC2F(0, 1);
                penetration = y_overlap;
            }
        }

    sfVector2f impulse = vec_mult(normal, penetration );
    obj1->body.vel = vec_add(impulse, obj2->body.vel);
    printf("impulse : %f %f\n", impulse.x, impulse.y);
    }
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