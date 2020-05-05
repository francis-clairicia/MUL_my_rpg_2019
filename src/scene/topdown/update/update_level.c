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
        player->data.xp = boat->comp[find_comp(boat, XP)]->i;
    if (has_comp(boat, LVL))
        player->data.lvl = boat->comp[find_comp(boat, LVL)]->i;
    if (has_comp(boat, DAMAGE))
        player->data.damage = boat->comp[find_comp(boat, DAMAGE)]->i;
    if (has_comp(boat, CANNON_NB))
        player->data.cannon_nb = boat->comp[find_comp(boat, CANNON_NB)]->i;
    if (has_comp(boat, DEAD_COUNTER))
        player->data.dead_counter =
                                boat->comp[find_comp(boat, DEAD_COUNTER)]->i;
    if (has_comp(boat, ATTACK_SPEED))
        player->data.attack_speed =
                                boat->comp[find_comp(boat, ATTACK_SPEED)]->f;
    player->data.pos = boat->body.pos;
}

static void update_xp(game_obj_t *boat)
{
    static int last_xp = 0;
    int level = boat->comp[find_comp(boat, LVL)]->i;
    int xp = boat->comp[find_comp(boat, XP)]->i;
    int xp_for_level_up = 10 + 5 * (level);

    if (xp / xp_for_level_up > 0) {
        boat->comp[find_comp(boat, LVL)]->i += xp / xp_for_level_up;
        boat->comp[find_comp(boat, XP)]->i = xp % xp_for_level_up;
        play_game_object_sound(boat, LVL_UP_SOUND);
        update_topdown_boat_state(boat);
    } else if (last_xp != xp)
        play_game_object_sound(boat, XP_SOUND);
    last_xp = boat->comp[find_comp(boat, XP)]->i;
}

static void update_lvl(game_obj_t *boat)
{
    static int last_lvl = 0;
    int lvl = boat->comp[find_comp(boat, LVL)]->i;
    int max_hp = boat->comp[find_comp(boat, MAX_LIFE)]->i;

    if (lvl == last_lvl)
        return;
    boat->comp[find_comp(boat, LIFE)]->i = max_hp;
    if (has_comp(boat, CANNON_NB))
        boat->comp[find_comp(boat, CANNON_NB)]->i = (lvl / 5) + 1;
    last_lvl = lvl;
}

void update_topdown_level(tool_t *tool, topdown_t *topdown)
{
    if (!topdown || !(topdown->boat) ||
        !has_comp(topdown->boat, XP) || !has_comp(topdown->boat, LVL))
        return;
    update_xp(topdown->boat);
    update_lvl(topdown->boat);
    fill_boat_player_data(topdown->boat, &tool->player);
}