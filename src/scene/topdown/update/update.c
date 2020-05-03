/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update
*/

#include "update_topdown.h"

static scene_t keyboard_event(tool_t *tool, topdown_t *topdown)
{
    if (tool->event.key.code == sfKeyEscape) {
        sfView_reset(tool->view, FRECT(0, 0, 1920, 1080));
        sfRenderWindow_setView(tool->window, tool->view);
        return (launch_settings(tool, TOPDOWN));
    }
    if (tool->event.key.code == sfKeyF12)
        return (BATTLE);
    if (tool->event.key.code == tool->player.control.keys[CONTROL_CAMERA])
        topdown->camera = !(topdown->camera);
    return (TOPDOWN);
}

static scene_t check_event(tool_t *tool, topdown_t *topdown, scene_t state)
{
    while (sfRenderWindow_pollEvent(tool->window, &tool->event)) {
        if (tool->event.type == sfEvtClosed)
            return (NO_SCENE);
        if (tool->event.type == sfEvtKeyPressed)
            return (keyboard_event(tool, topdown));
    }
    return (state);
}

void update_topdown(tool_t *tool, topdown_t *topdown, scene_t *state)
{
    *state = check_event(tool, topdown, *state);
    update_topdown_boat(tool, topdown);
    update_topdown_bullet(tool, topdown);
    check_topdown_player_death(topdown->boat, state);
    update_topdown_view(tool, topdown);
    update_topdown_buoys(tool, topdown);
    update_topdown_level(tool, topdown);
    clean_topdown_dead_boats(topdown);
}