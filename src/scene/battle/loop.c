/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop
*/

#include "battle.h"

scene_t launch_battle(tool_t *tool, scene_t state)
{
    battle_t battle;

    if (!tool || !init_battle(tool, &battle))
        return (MENU);
    while (state == BATTLE) {
        sfRenderWindow_clear(tool->window, sfBlack);
        update_tool(tool);
        update_battle(tool, &battle, &state);
        draw_battle(tool, battle);
        sfRenderWindow_display(tool->window);
    }
    destroy_battle(&battle);
    return (state);
}