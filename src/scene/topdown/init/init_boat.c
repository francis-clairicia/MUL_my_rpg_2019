/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_boat
*/

#include "topdown.h"

static void load_boat_player_data(player_t player, game_obj_t *boat)
{
    if (has_comp(boat, XP) && player.p_data.xp)
        boat->comp[find_comp(boat, XP)]->i = player.p_data.xp;
    if (has_comp(boat, LVL) && player.p_data.lvl)
        boat->comp[find_comp(boat, LVL)]->i = player.p_data.lvl;
    if (has_comp(boat, DAMAGE) && player.p_data.damage)
        boat->comp[find_comp(boat, DAMAGE)]->i = player.p_data.damage;
    if (has_comp(boat, CANNON_NB) && player.p_data.cannon_nb)
        boat->comp[find_comp(boat, CANNON_NB)]->i = player.p_data.cannon_nb;
    if (has_comp(boat, DEAD_COUNTER) && player.p_data.dead_counter)
        boat->comp[find_comp(boat, DEAD_COUNTER)]->i = player.p_data.dead_counter;
    if (has_comp(boat, ATTACK_SPEED) && player.p_data.attack_speed)
        boat->comp[find_comp(boat, ATTACK_SPEED)]->f = player.p_data.attack_speed;
}

sfBool init_topdown_boat(player_t player, topdown_t *topdown)
{
    topdown->boat = create_game_obj(BOAT1);
    if (!(topdown->boat))
        return (sfFalse);
    if (player.new_player)
        load_boat_player_data(player, topdown->boat);
    if (!(player.pos.x) || !(player.pos.y))
        set_game_object_pos(topdown->boat, VEC2F(100, 100));
    else
        set_game_object_pos(topdown->boat, player.pos);
    return (sfTrue);
}