/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** AABB collision resolution
*/

#include <stdbool.h>
#include "math_process.h"
#include "game_object.h"

sfBool is_game_object_collision(game_obj_t *obj1, game_obj_t *obj2)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(obj1->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(obj2->sprite);

    if (!obj1 || !obj2)
        return (sfFalse);
    return (sfFloatRect_intersects(&rect1, &rect2, NULL));
}

sfBool game_object_collision(game_obj_t *obj1, game_obj_t *obj2,
                                sfBool (*res_func)
                                (rigid_body_t *, rigid_body_t *, float))
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(obj1->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(obj2->sprite);

    if (!obj1 || !obj2)
        return (sfFalse);
    if (sfFloatRect_intersects(&rect1, &rect2, NULL)) {
        update_game_object_center(obj1);
        update_game_object_center(obj2);
        update_obb(&(obj1->body));
        update_obb(&(obj2->body));
        return (collision_sat(&(obj1->body), &(obj2->body), res_func));
    }
    return (sfFalse);
}