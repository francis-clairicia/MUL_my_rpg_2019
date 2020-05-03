/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_boat_state
*/

#include "game_object.h"

void update_topdown_boat_state(game_obj_t *boat)
{
    int boat_life = 100;

    if (!has_comp(boat, LIFE))
        return ;
    boat_life = boat->comp[find_comp(boat, LIFE)]->i;
    if (boat_life > 70)
        set_game_object_frame(boat, 0);
    if (boat_life < 70 && boat_life > 35)
        set_game_object_frame(boat, 1);
    if (boat_life < 35 && boat_life > 5)
        set_game_object_frame(boat, 2);
    if (boat_life < 5)
        set_game_object_frame(boat, 3);
}