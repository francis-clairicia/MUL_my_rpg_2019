/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** boat_attack
*/

#include "topdown.h"

static void set_bullet_team(game_obj_t *boat, game_obj_t *bullet)
{
    if (boat->type == BOAT1 || boat->type == BOAT4)
        bullet->comp[find_comp(bullet, ALLY)]->i = 1;
    else
        bullet->comp[find_comp(bullet, ALLY)]->i = 0;
}

static game_obj_t *init_bullet(game_obj_t *boat, int index,
                        sfBool side, sfVector2f flank)
{
    size_t bullet_nb = boat->comp[find_comp(boat, CANNON_NB)]->i;
    sfVector2f impulse = vec_norm(vec_normal(flank));
    game_obj_t *new_bullet = create_game_obj(BULLET);

    if (!new_bullet)
        return (NULL);
    set_game_object_pos(new_bullet, vec_add(boat->body.obb[3 - side],
                vec_mult(flank, (float)(index + 1) / (float)(bullet_nb + 1))));
    if (!side)
        impulse = vec_mult(impulse, -1);
    impulse = vec_mult(impulse, 10000);
    new_bullet->comp[find_comp(new_bullet, DAMAGE)]->i =
                    boat->comp[find_comp(boat, DAMAGE)]->i;
    apply_force(&(new_bullet->body), impulse);
    set_bullet_team(boat, new_bullet);
    return (new_bullet);
}

static void play_attack_sound(game_obj_t *boat)
{
    sfSound *sound = NULL;

    if (!has_comp(boat, FIRE_SOUND))
        return;
    sound = boat->comp[find_comp(boat, FIRE_SOUND)]->sound;
    if (!sound)
        return;
    sfSound_play(sound);
}

void boat_attack(game_obj_t *boat, list_t **bullets, sfBool side)
{
    register size_t index = 0;
    size_t bullet_nb = boat->comp[find_comp(boat, CANNON_NB)]->i;
    sfVector2f flank = VEC2F(0, 0);

    update_game_object_center(boat);
    update_obb(&(boat->body));
    if (side)
        flank = vec_sub(boat->body.obb[1], boat->body.obb[2]);
    else
        flank = vec_sub(boat->body.obb[0], boat->body.obb[3]);
    if (!bullets || !bullet_nb)
        return ;
    for (; index < bullet_nb; index += 1) {
        MY_APPEND_TO_LIST(bullets, init_bullet(boat, index, side, flank));
    }
    play_attack_sound(boat);
}