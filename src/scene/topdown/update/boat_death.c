/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** boat_death
*/

#include "topdown.h"

static void play_boat_death_sound(game_obj_t *boat)
{
    sfSound *sound = NULL;

    if (has_comp(boat, DEATH_SOUND)) {
        sound = boat->comp[find_comp(boat, DEATH_SOUND)]->sound;
        if (sound)
            sfSound_play(sound);
    }
}

void check_topdown_player_death(game_obj_t *boat, scene_t *state)
{

    if (!boat || !state)
        return ;
    if (!has_comp(boat, LIFE))
        return;
    if (boat->comp[find_comp(boat, LIFE)]->i <= 0) {
        *state = MENU;
        play_boat_death_sound(boat);
    }
}