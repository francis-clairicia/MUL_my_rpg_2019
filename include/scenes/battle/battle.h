/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** battle
*/

#ifndef BATTLE_H_
#define BATTLE_H_

#include "game_object.h"
#include "tools.h"
#include "boat.h"

typedef struct battle_s
{
    player_t *player;
    list_t *ennemy_boat;
    list_t *ennemy_crew;
    list_t *water;
    game_obj_t *background;
    game_obj_t *weather;
} battle_t;

sfBool init_battle(tool_t *tool, battle_t *battle);
void destroy_battle(battle_t *battle);

void update_boat_size(list_t *boat);

void update_battle(tool_t *tool, battle_t *battle, scene_t *state);

list_t *load_boat_from_file(char const *file);

void draw_battle(tool_t *tool, battle_t battle);

void update_boats(tool_t *tool, list_t *list);

void update_battle_player(tool_t *tool, battle_t *battle);

void buoyancy_boat_water(list_t *boat, list_t *water);

void control_player(game_obj_t *pirate, list_t *boat_list,
                                        control_t control);

sfBool pirate_collision_solving(rigid_body_t *b1, rigid_body_t *b2,
                                                            float overlap);
void pirate_boat_interact(tool_t *tool, list_t *boat_list);

#endif /* !BATTLE_H_ */