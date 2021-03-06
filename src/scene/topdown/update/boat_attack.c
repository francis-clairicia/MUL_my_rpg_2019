/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** boat_attack
*/

#include "topdown.h"

static game_obj_t *init_bullet(game_obj_t *boat, int index,
                        sfBool side, sfVector2f flank)
{
    size_t bullet_nb = comp_value(boat, CANNON_NB)->i;
    sfVector2f impulse = vec_norm(vec_normal(flank));
    game_obj_t *bullet = create_game_obj(BULLET);

    if (!bullet)
        return (NULL);
    set_game_object_pos(bullet, vec_add(boat->body.obb[3 - side],
                vec_mult(flank, (float)(index + 1) / (float)(bullet_nb + 1))));
    if (!side)
        impulse = vec_mult(impulse, -1);
    impulse = vec_mult(impulse, 10000);
    comp_value(bullet, DAMAGE)->i = comp_value(boat, DAMAGE)->i;
    apply_force(&(bullet->body), impulse);
    comp_value(bullet, ALLY)->i = (boat->type == BOAT1 || boat->type == BOAT4);
    return (bullet);
}

void boat_attack(game_obj_t *boat, list_t **bullets, sfBool side)
{
    register size_t index = 0;
    size_t bullet_nb = comp_value(boat, CANNON_NB)->i;
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
    play_game_object_sound(boat, FIRE_SOUND);
}