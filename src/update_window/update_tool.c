/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_tool
*/

#include "vector_engine.h"
#include "rpg.h"

static void update_window_anchor(tool_t *tool)
{
    tool->anchor.topleft = sfRenderWindow_mapPixelToCoords(tool->window,
                                            VEC2I(0, 0),
                                            tool->view);
    tool->anchor.topright = sfRenderWindow_mapPixelToCoords(tool->window,
                                            VEC2I(tool->size.x, 0),
                                            tool->view);
    tool->anchor.bottomleft = sfRenderWindow_mapPixelToCoords(tool->window,
                                            VEC2I(0, tool->size.y),
                                            tool->view);
    tool->anchor.bottomright = sfRenderWindow_mapPixelToCoords(tool->window,
                                            VEC2I(tool->size.x, tool->size.y),
                                            tool->view);
}

static void update_window_scale(tool_t *tool)
{
    sfVector2f view_size = sfView_getSize(tool->view);

    tool->scale.x = view_size.x / tool->size.x;
    tool->scale.y = view_size.y / tool->size.y;
}

static void update_window_size(tool_t *tool)
{
    sfVector2u window_size = sfRenderWindow_getSize(tool->window);

    tool->size = VEC2F(window_size.x, window_size.y);
}

static void update_tool_clock(tool_t *tool)
{
    sfTime time = sfClock_getElapsedTime(tool->clock);

    tool->dtime = sfTime_asSeconds(time);
    sfClock_restart(tool->clock);
}

void update_tool(tool_t *tool)
{
    update_window_size(tool);
    update_window_scale(tool);
    update_window_anchor(tool);
    update_mouse_tool(tool);
    update_tool_clock(tool);
}