/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** battle
*/

#ifndef BATTLE_H_
#define BATTLE_H_

#include "rpg.h"
#include "game_object.h"
#include "weather.h"

typedef struct battle_s
{
    player_t *player;
    list_t *ennemy_boat;
    list_t *ennemy_crew;
    list_t *water;
    list_t *clouds;
    list_t *rain;
    game_obj_t *background;
    int weather;
} battle_t;

sfBool init_battle(tool_t *tool, battle_t *battle);

void destroy_battle(battle_t *battle);

void update_battle(tool_t *tool, battle_t *battle, scene_t *state);

void draw_battle(tool_t *tool, battle_t battle);

void draw_rain(tool_t *tool, list_t *rain_list);

#endif /* !BATTLE_H_ */