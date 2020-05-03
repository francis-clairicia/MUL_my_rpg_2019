/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update
*/

#include "rpg.h"
#include "update_battle.h"

static scene_t keyboard_event(tool_t *tool)
{
    if (tool->event.key.code == sfKeyEscape)
        return (launch_settings(tool, BATTLE));
    if (tool->event.key.code == sfKeyF12)
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

void update_battle(tool_t *tool, battle_t *battle, scene_t *state)
{
    update_battle_boats(tool, battle);
    update_battle_player(tool, battle);
    update_battle_clouds(tool, battle);
    *state = check_event(tool, *state);
}