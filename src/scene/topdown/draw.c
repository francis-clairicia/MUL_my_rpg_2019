/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw
*/

#include "topdown.h"

void draw_topdown(tool_t *tool, topdown_t topdown)
{
    draw_game_object_list(tool->window, topdown.map);
    draw_game_object(tool->window, topdown.boat);
    draw_game_object_list(tool->window, topdown.ally_boat);
    draw_game_object_list(tool->window, topdown.ennemy_boat);
    draw_game_object_list(tool->window, topdown.mercenary_boat);
    draw_game_object_list(tool->window, topdown.golden_boat);
}