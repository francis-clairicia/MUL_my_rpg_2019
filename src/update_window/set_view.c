/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** reset_view.c
*/

#include "tools.h"

void set_tool_view(tool_t *tool, sfFloatRect rect)
{
    if (!tool || !(tool->window) || !(tool->view))
        return;
    sfView_reset(tool->view, rect);
    sfRenderWindow_setView(tool->window, tool->view);
}