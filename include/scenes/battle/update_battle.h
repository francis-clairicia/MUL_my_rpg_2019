/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_battle
*/

#ifndef UPDATE_BATTLE_H_
#define UPDATE_BATTLE_H_

#include "battle.h"


void update_battle_boats(tool_t *tool, battle_t *battle);
void buoyancy_boat_water(list_t *boat, list_t *water);
void update_boat_size(list_t *boat);

void update_battle_player(tool_t *tool,
                __attribute__((unused))battle_t *battle);
void control_player(game_obj_t *pirate, list_t *boat_list,
                                        control_t control);
sfBool pirate_collision_solving(rigid_body_t *b1, rigid_body_t *b2,
                                                            float overlap);
void pirate_boat_interact(tool_t *tool, list_t *boat_list);

void update_battle_clouds(tool_t *tool, battle_t *battle);
void generate_clouds(tool_t *tool, list_t **clouds);
void clean_clouds(tool_t *tool, battle_t *battle);




#endif /* !UPDATE_BATTLE_H_ */