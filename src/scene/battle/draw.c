/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw
*/

#include "battle.h"

void draw_battle(tool_t *tool, battle_t battle)
{
    draw_game_object(tool->window, battle.background);
    draw_game_object_list(tool->window, battle.player->boat);
    draw_game_object_list(tool->window, battle.water);
    draw_game_object_list(tool->window, battle.player->crew);
    draw_game_object_list(tool->window, battle.clouds);
    // draw_game_object_list(tool->window, battle.rain);
    draw_rain(tool, battle.rain);
}