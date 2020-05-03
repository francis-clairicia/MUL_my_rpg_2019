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
        update_tool(tool);
        update_battle(tool, &battle, &state);
        sfRenderWindow_clear(tool->window, sfBlack); 
        draw_battle(tool, battle);
        sfRenderWindow_display(tool->window);
    }
    destroy_battle(&battle);
    return (state);
}