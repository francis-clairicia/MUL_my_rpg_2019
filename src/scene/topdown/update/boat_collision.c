/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** boat_collision
*/

#include "update_topdown.h"

static void boat_collision_damage(game_obj_t *boat)
{
    play_game_object_sound(boat, HIT_SOUND);
    if (!has_comp(boat, LIFE))
        return;
    boat->comp[find_comp(boat, LIFE)]->i -= 5;
    update_topdown_boat_state(boat);
}

static sfBool boat_resolve_collision(rigid_body_t *b1, rigid_body_t *b2,
                                                            float overlap)
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

sfBool boat_border(game_obj_t *boat, sfVector2f map_size)
{
    sfBool collided = sfFalse;

    if (boat->body.pos.x < 0 || boat->body.pos.x > map_size.x) {
        boat->body.vel.x *= -1;
        collided |= sfTrue;
    }
    if (boat->body.pos.y < 0 || boat->body.pos.y > map_size.y) {
        collided |= sfTrue;
        boat->body.vel.y *= -1;
    }
    return (collided);
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
    if (collided)
        boat_collision_damage(boat);
    return (collided);
}