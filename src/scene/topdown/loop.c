/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop
*/

#include "topdown.h"
#include "hud.h"

scene_t launch_topdown(tool_t *tool, scene_t state)
{
    topdown_t topdown;

    if (!tool || !init_topdown(tool, &topdown))
        return (MENU);
    while (state == TOPDOWN) {
        sfRenderWindow_clear(tool->window, sfBlack);
        update_tool(tool);
        update_topdown(tool, &topdown, &state);
        draw_topdown(tool, topdown);
        display_hud(tool);
        sfRenderWindow_display(tool->window);
    }
    set_tool_view(tool, FRECT(0, 0, 1920, 1080));
    destroy_topdown(&topdown);
    return (state);
}