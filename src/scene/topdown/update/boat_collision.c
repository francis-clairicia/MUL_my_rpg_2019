/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** boat_collision
*/

#include "update_topdown.h"

sfBool boat_resolve_collision(rigid_body_t *b1, rigid_body_t *b2, float overlap)
{
    sfVector2f rel_pos = vec_sub(b2->center, b1->center);
    float dist = vec_mag(rel_pos);
    sfVector2f impulse = vec_div(vec_mult(rel_pos, overlap), dist);
    float mass_summ = b1->mass + b2->mass;

    if (!b1->mass || !(b2->mass))
        return (sfFalse);
    if (b2->mass == __FLT_MAX__) {
        body_add_acc(b1, vec_mult(impulse, -1));
    } else {
        body_add_acc(b1, vec_mult(impulse, -b1->mass / mass_summ));
        body_add_acc(b2, vec_mult(impulse, b1->mass / mass_summ));
    }
    return (sfTrue);
}

sfBool boat_collision(game_obj_t *boat, list_t *list)
{
    game_obj_t *obj = NULL;
    sfBool collided = sfFalse;

    for (; list && boat; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        if (obj->type == SAND || obj->type == DIRT)
            collided |= game_object_collision(boat, obj,
                                boat_resolve_collision);
    }
    return (collided);
}