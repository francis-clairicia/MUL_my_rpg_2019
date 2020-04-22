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
    list_t *ennemy_boat_fg;
    list_t *ennemy_boat_bg;
    list_t *ennemy_crew;
    game_obj_t *background;
    game_obj_t *weather;
} battle_t;

sfBool init_battle(player_t *player, battle_t *battle);

void draw_battle(tool_t *tool, battle_t battle);

list_t *load_boat_from_file(char const *file);

#endif /* !BATTLE_H_ */