/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_boat
*/

#include "topdown.h"

static void load_boat_player_data(player_t player, game_obj_t *boat)
{
    if (has_comp(boat, XP))
        comp_value(boat, XP)->i = player.data.xp;
    if (has_comp(boat, LVL))
        comp_value(boat, LVL)->i = player.data.lvl;
    if (has_comp(boat, LIFE))
        comp_value(boat, LIFE)->i = player.data.life;
    if (has_comp(boat, DAMAGE))
        comp_value(boat, DAMAGE)->i = player.data.damage;
    if (has_comp(boat, CANNON_NB))
        comp_value(boat, CANNON_NB)->i = player.data.cannon_nb;
    if (has_comp(boat, DEAD_COUNTER))
        comp_value(boat, DEAD_COUNTER)->i = player.data.dead_counter;
    if (has_comp(boat, ATTACK_SPEED))
        comp_value(boat, ATTACK_SPEED)->f = player.data.attack_speed;
}

sfBool init_topdown_boat(player_t player, topdown_t *topdown)
{
    topdown->boat = create_game_obj(BOAT1);
    if (!(topdown->boat))
        return (sfFalse);
    load_boat_player_data(player, topdown->boat);
    set_game_object_pos(topdown->boat, player.data.pos);
    return (sfTrue);
}