/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy_boat
*/

#include "topdown.h"

static void fill_boat_player_data(game_obj_t *boat, player_t *player)
{
    if (has_comp(boat, XP))
        player->p_data.xp = boat->comp[find_comp(boat, XP)]->i;
    if (has_comp(boat, LVL))
        player->p_data.lvl = boat->comp[find_comp(boat, LVL)]->i;
    if (has_comp(boat, DAMAGE))
        player->p_data.damage = boat->comp[find_comp(boat, DAMAGE)]->i;
    if (has_comp(boat, CANNON_NB))
        player->p_data.cannon_nb = boat->comp[find_comp(boat, CANNON_NB)]->i;
    if (has_comp(boat, DEAD_COUNTER))
        player->p_data.dead_counter =
                                boat->comp[find_comp(boat, DEAD_COUNTER)]->i;
    if (has_comp(boat, ATTACK_SPEED))
        player->p_data.attack_speed =
                                boat->comp[find_comp(boat, ATTACK_SPEED)]->f;
}

void destroy_topdown_boat(tool_t *tool, topdown_t *topdown)
{
    if (topdown->boat) {
        fill_boat_player_data(topdown->boat, &(tool->player));
        free_game_object(topdown->boat);
    }
    if (topdown->ally_boat)
        my_free_list(&(topdown->ally_boat), free_game_object);
    if (topdown->golden_boat)
        my_free_list(&(topdown->golden_boat), free_game_object);
    if (topdown->ennemy_boat)
        my_free_list(&(topdown->ennemy_boat), free_game_object);
    if (topdown->mercenary_boat)
        my_free_list(&(topdown->mercenary_boat), free_game_object);
}