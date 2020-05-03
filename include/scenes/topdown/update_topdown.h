/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_topdown
*/

#ifndef UPDATE_TOPDOWN_H_
#define UPDATE_TOPDOWN_H_

#include "topdown.h"

//Update boats
void update_topdown_boat(tool_t *tool, topdown_t *topdown);
void control_boat(tool_t *tool, topdown_t *topdown);
sfBool boat_collision(game_obj_t *boat, list_t *list);
void update_topdown_boat_state(game_obj_t *boat);
void check_topdown_player_death(game_obj_t *boat, scene_t *state);
sfBool boat_border(game_obj_t *boat, sfVector2f map_size);

//Boat IA
//Set ptarget if not null else select the closest boat in boat_list
//Follow the target if boat is in view range
//Fire at target if boat is in fire range
void update_topdown_boat_ia(game_obj_t *boat, list_t *boat_list,
                            game_obj_t *ptarget, list_t **bullets);

//Update view
void update_topdown_view(tool_t *tool, topdown_t *topdown);

//Update buoys
void update_topdown_buoys(tool_t *tool, topdown_t *topdown);

//Update bullets
void update_topdown_bullet(tool_t *tool, topdown_t *topdown);

#endif /* !UPDATE_TOPDOWN_H_ */