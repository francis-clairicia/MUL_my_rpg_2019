/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update
*/

#include "update_topdown.h"

static scene_t keyboard_event(tool_t *tool)
{
    if (tool->event.key.code == sfKeyEscape)
        return (launch_settings(tool, TOPDOWN));
    if (tool->event.key.code == sfKeyF12)
        return (BATTLE);
    return (TOPDOWN);
}

static scene_t check_event(tool_t *tool, scene_t state)
{
    while (sfRenderWindow_pollEvent(tool->window, &tool->event)) {
        if (tool->event.type == sfEvtClosed)
            return (NO_SCENE);
        if (tool->event.type == sfEvtKeyPressed)
            return (keyboard_event(tool));
    }
    return (state);
}

void update_topdown(tool_t *tool, topdown_t *topdown, scene_t *state)
{
    update_topdown_boat(tool, topdown);
    update_topdown_bullet(tool, topdown);
    check_topdown_player_death(topdown->boat, state);
    update_topdown_view(tool, topdown);
    update_topdown_buoys(tool, topdown);
    clean_topdown_dead_boats(tool, topdown);
    *state = check_event(tool, *state);
}