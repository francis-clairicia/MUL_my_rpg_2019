/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pirate_collision_solving
*/

#include "game_object.h"

sfBool pirate_collision_solving(rigid_body_t *b1, rigid_body_t *b2,
                                                        float overlap)
{
    sfVector2f rel_pos = vec_sub(b2->center, b1->center);
    float dist = vec_mag(rel_pos);
    sfVector2f impulse = vec_div(vec_mult(rel_pos, overlap), dist);

    if (impulse.x > impulse.y)
        impulse.y = 0;
    else
        impulse.x = 0;
    body_add_acc(b1, vec_mult(impulse, -1));
    return (sfTrue);
}