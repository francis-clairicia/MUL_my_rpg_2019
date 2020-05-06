/*
** EPITECH PROJECT, 2020
** MUL_my_rpg.c
** File description:
** update_and_draw_rain
*/

#include "battle.h"

void draw_one_rain_list(tool_t *tool, game_obj_t *rain)
{
    sfVector2f size = rain->body.size;
    sfVector2f true_pos = rain->body.pos;
    sfVector2f pos_rain = init_vector2f(true_pos.x, true_pos.y - size.y);

    while (pos_rain.y < (tool->size.y + size.y)) {
        set_game_object_pos(rain, pos_rain);
        draw_game_object(tool->window, rain);
        pos_rain.y += size.y;
    }
    set_game_object_pos(rain, true_pos);
}

void draw_rain(tool_t *tool, list_t *rain_list)
{
    list_t *actual = rain_list;
    game_obj_t *rain = NULL;

    while (actual != NULL) {
        rain = NODE_DATA(actual, game_obj_t *);
        draw_one_rain_list(tool, rain);
        actual = actual->next;
    }
}