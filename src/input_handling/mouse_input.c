/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mouse_input
*/

#include "vector_engine.h"
#include "rpg.h"

static sfVector2f get_relative_mouse_pos(tool_t tool)
{
    sfVector2i mouse_pos;
    sfVector2f relative_mouse_pos;

    mouse_pos = sfMouse_getPositionRenderWindow(tool.window);
    relative_mouse_pos = sfRenderWindow_mapPixelToCoords(tool.window,
                        mouse_pos, tool.view);
    return (relative_mouse_pos);
}

static sfVector2f get_win_mouse_pos(tool_t tool)
{
    sfVector2i mouse_pos;

    mouse_pos = sfMouse_getPositionRenderWindow(tool.window);
    return (VEC2F(mouse_pos.x, mouse_pos.y));
}

void init_mouse_tool(tool_t *tool)
{
    tool->mouse_tool.win_pos = get_win_mouse_pos(*tool);
    tool->mouse_tool.pos = get_relative_mouse_pos(*tool);
    tool->mouse_tool.hold = sfFalse;
}

void update_mouse_tool(tool_t *tool)
{
    tool->mouse_tool.win_pos = get_win_mouse_pos(*tool);
    tool->mouse_tool.pos = get_relative_mouse_pos(*tool);
    if (!(tool->mouse_tool.hold) && sfMouse_isButtonPressed(sfMouseLeft)) {
        tool->mouse_tool.click = sfTrue;
        tool->mouse_tool.click_pos = tool->mouse_tool.pos;
    } else {
        tool->mouse_tool.click = sfFalse;
    }
    tool->mouse_tool.hold = sfMouse_isButtonPressed(sfMouseLeft);
}