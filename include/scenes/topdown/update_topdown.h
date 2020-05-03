/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_topdown
*/

#ifndef UPDATE_TOPDOWN_H_
#define UPDATE_TOPDOWN_H_

#include "topdown.h"

void update_topdown_boat(tool_t *tool, topdown_t *topdown);
void control_boat(tool_t *tool, topdown_t *topdown);
sfBool boat_collision(game_obj_t *boat, list_t *list);
void update_topdown_boat_state(game_obj_t *boat);
void check_topdown_player_death(game_obj_t *boat, scene_t *state);

#endif /* !UPDATE_TOPDOWN_H_ */