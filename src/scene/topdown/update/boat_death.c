/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** boat_death
*/

#include "topdown.h"

void check_topdown_player_death(game_obj_t *boat, scene_t *state)
{

    if (!boat || !state)
        return ;
    if (!has_comp(boat, LIFE))
        return;
    if (comp_value(boat, LIFE)->i <= 0) {
        *state = MENU;
        play_game_object_sound(boat, DEATH_SOUND);
    }
}