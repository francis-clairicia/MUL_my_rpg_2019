/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw
*/

#include "battle.h"

void draw_wind(sfRenderWindow *window, sfVector2f size, sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setSize(rect, size);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void draw_battle(tool_t *tool, battle_t battle)
{
    draw_game_object(tool->window, battle.background);
    if (battle.weather == CLOUDY)
        draw_wind(tool->window, tool->size, init_color(200, 200, 200, 130));
    else if (battle.weather == RAINING)
        draw_wind(tool->window, tool->size, init_color(200, 200, 200, 180));
    draw_game_object_list(tool->window, battle.player->boat);
    draw_game_object_list(tool->window, battle.water);
    draw_game_object_list(tool->window, battle.player->crew);
    draw_game_object_list(tool->window, battle.clouds);
    if (battle.weather == RAINING) {
        draw_rain(tool, battle.rain);
    }
}