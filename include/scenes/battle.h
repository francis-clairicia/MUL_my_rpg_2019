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

typedef struct boat_s
{
    list_t *fg;
    list_t *bg;
} boat_t;

typedef struct battle_s
{
    boat_t ally;
    boat_t ennemy;
    game_obj_t *background;
    game_obj_t *weather;
} battle_t;

sfBool init_battle(save_t save, battle_t *battle);

void draw_battle(tool_t *tool, battle_t battle);

list_t *load_boat_from_file(char const *file);

#endif /* !BATTLE_H_ */