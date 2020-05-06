/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** update_level.c
*/

#include "topdown.h"
#include "update_topdown.h"

static void fill_boat_player_data(game_obj_t *boat, player_t *player)
{
    if (has_comp(boat, XP))
        player->data.xp = comp_value(boat, XP)->i;
    if (has_comp(boat, LVL))
        player->data.lvl = comp_value(boat, LVL)->i;
    if (has_comp(boat, DAMAGE))
        player->data.damage = comp_value(boat, DAMAGE)->i;
    if (has_comp(boat, CANNON_NB))
        player->data.cannon_nb = comp_value(boat, CANNON_NB)->i;
    if (has_comp(boat, DEAD_COUNTER))
        player->data.dead_counter = comp_value(boat, DEAD_COUNTER)->i;
    if (has_comp(boat, ATTACK_SPEED))
        player->data.attack_speed = comp_value(boat, ATTACK_SPEED)->f;
    player->data.pos = boat->body.pos;
    player->max_xp = comp_value(boat, MAX_XP)->i;
}

static void update_xp(game_obj_t *boat)
{
    int level = comp_value(boat, LVL)->i;
    int xp = comp_value(boat, XP)->i;
    int xp_for_level_up = round(10 + 5 * sqrt(level - 1));

    comp_value(boat, MAX_XP)->i = xp_for_level_up;
    if (xp / xp_for_level_up > 0) {
        comp_value(boat, XP)->i = xp % xp_for_level_up;
        comp_value(boat, LVL)->i += (xp / xp_for_level_up);
        comp_value(boat, LIFE)->i = comp_value(boat, MAX_LIFE)->i;
        comp_value(boat, CANNON_NB)->i = (comp_value(boat, LVL)->i / 5) + 1;
        play_game_object_sound(boat, LVL_UP_SOUND);
        update_topdown_boat_state(boat);
    } else if (comp_value(boat, EARN_XP)->i)
        play_game_object_sound(boat, XP_SOUND);
    comp_value(boat, EARN_XP)->i = false;
}

void update_topdown_level(tool_t *tool, topdown_t *topdown)
{
    if (!topdown || !(topdown->boat) ||
        !has_comp(topdown->boat, XP) || !has_comp(topdown->boat, LVL))
        return;
    update_xp(topdown->boat);
    fill_boat_player_data(topdown->boat, &tool->player);
}