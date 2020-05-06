/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** boat_ia
*/

#include "update_topdown.h"

static void ia_attack(game_obj_t *boat, list_t **bullets, sfBool side)
{
    if (can_game_object_attack(boat)) {
        boat_attack(boat, bullets, side);
    }
}

void update_ia_attack(game_obj_t *boat, game_obj_t *target, list_t **bullets)
{
    sfVector2f head = vec_sub(boat->body.obb[1], boat->body.obb[2]);
    sfVector2f dir = vec_sub(target->body.pos, boat->body.pos);
    float angle = vec_angle(head, dir);
    sfVector2f head_nrm = vec_normal(head);

    friction_force(&(boat->body), 1000);
    if (angle < 100 && angle > 80) {
        if (vec_angle(head_nrm, dir) > vec_angle(vec_mult(head_nrm, -1), dir))
            ia_attack(boat, bullets, 0);
        else
            ia_attack(boat, bullets, 1);
        boat->body.angle_vel *= 0.9;
        return ;
    }
    if (vec_angle(head, dir) > vec_angle(head, vec_mult(dir, -1))) {
        boat->body.torque -= 2;
    } else
        boat->body.torque += 2;
}

void update_ia_track(game_obj_t *boat, game_obj_t *target)
{
    sfVector2f head = vec_sub(boat->body.obb[1], boat->body.obb[2]);
    sfVector2f dir = vec_sub(target->body.pos, boat->body.pos);
    float angle = vec_angle(head, dir);
    sfVector2f dir_nrm = vec_normal(dir);

    if (angle < 10) {
        boat->body.angle_vel *= 0.9;
        traction_force(&(boat->body), 1000);
        return ;
    }
    if (vec_angle(head, dir_nrm) < vec_angle(head, vec_mult(dir_nrm, -1))) {
        boat->body.torque -= 2;
    } else
        boat->body.torque += 2;
}

static game_obj_t *get_closest_target(game_obj_t *boat, game_obj_t *ptarget,
                                                            list_t *boat_list)
{
    game_obj_t *l_target = find_closest_game_object(boat, boat_list);
    sfVector2f b_pos = boat->body.pos;

    if (!ptarget && !l_target)
        return (NULL);
    if (!ptarget && l_target)
        return (l_target);
    if (ptarget && !l_target)
        return (ptarget);
    if (vec_mag(vec_sub(b_pos, ptarget->body.pos)) <
        vec_mag(vec_sub(b_pos, l_target->body.pos)))
        return (ptarget);
    return (l_target);
}

void update_topdown_boat_ia(game_obj_t *boat, list_t *boat_list,
                            game_obj_t *ptarget, list_t **bullets)
{
    game_obj_t *target = NULL;
    float distance = 0;
    float fire_range = 0;
    float view_range = 0;

    if (!has_comp(boat, FIRE_RANGE) || !has_comp(boat, VIEW_RANGE))
        return ;
    target = get_closest_target(boat, ptarget, boat_list);
    if (!target)
        return ;
    fire_range = comp_value(boat, FIRE_RANGE)->i;
    view_range = comp_value(boat, VIEW_RANGE)->i;
    update_game_object_center(boat);
    update_obb(&(boat->body));
    distance = vec_mag(vec_sub(boat->body.pos, target->body.pos));
    if (distance < view_range && distance > fire_range)
        update_ia_track(boat, target);
    else if (distance < fire_range)
        update_ia_attack(boat, target, bullets);
}