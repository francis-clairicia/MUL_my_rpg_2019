/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loop
*/

#include "topdown.h"

scene_t launch_topdown(tool_t *tool, scene_t state)
{
    topdown_t topdown;

    if (!tool || !init_topdown(&topdown))
        return (MENU);
    while (sfRenderWindow_isOpen(tool->window) && state == TOPDOWN) {
        sfRenderWindow_clear(tool->window, sfBlack);
        update_tool(tool);
        update_topdown(tool, &topdown, &state);
        draw_topdown(tool, topdown);
        sfRenderWindow_display(tool->window);
    }
    sfView_reset(tool->view, FRECT(0, 0, 1920, 1080));
    sfRenderWindow_setView(tool->window, tool->view);
    destroy_topdown(&topdown);
    return (state);
}