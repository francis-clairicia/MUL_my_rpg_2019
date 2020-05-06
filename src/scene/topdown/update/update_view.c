/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_view
*/

#include "topdown.h"
#include "math_process.h"

static void update_topdown_view_borders(tool_t *tool, topdown_t *topdown)
{
    sfVector2f pos = VEC2F(0, 0);

    if (tool->anchor.topleft.x < 0)
        pos.x -= tool->anchor.topleft.x;
    else if (topdown->map_size.x - tool->anchor.bottomright.x < 0)
        pos.x -= tool->anchor.bottomright.x - topdown->map_size.x;
    if (tool->anchor.topleft.y < 0)
        pos.y -= tool->anchor.topleft.y;
    else if (topdown->map_size.y - tool->anchor.bottomright.y < 0)
        pos.y -= tool->anchor.bottomright.y - topdown->map_size.y;
    sfView_move(tool->view, pos);
    sfRenderWindow_setView(tool->window, tool->view);
}

static sfBool view_overflow_map(anchor_t anchor, sfVector2f map_size)
{
    if (anchor.topleft.x < 0 || anchor.topright.x > map_size.x)
        return (sfTrue);
    if (anchor.topleft.y < 0 || anchor.bottomleft.y > map_size.y)
        return (sfTrue);
    return (sfFalse);
}

void update_view_zoom(tool_t *tool, topdown_t *topdown)
{
    sfKeyCode code = tool->event.key.code;
    sfBool zoom_up = (code == tool->player.control.keys[CONTROL_ZOOM_UP]);
    sfBool zoom_down = (code == tool->player.control.keys[CONTROL_ZOOM_DOWN]);
    float offset = 0.1;
    float new_value = 0;
    sfVector2f view_size;

    if (!(zoom_up ^ zoom_down))
        return;
    offset *= (zoom_up) + (-zoom_down);
    new_value = topdown->zoom.actual + offset;
    if (new_value < topdown->zoom.min || new_value > topdown->zoom.max)
        return;
    sfView_zoom(tool->view, 1 - offset);
    view_size = sfView_getSize(tool->view);
    view_size.x = MIN(view_size.x, topdown->map_size.x);
    view_size.y = MIN(view_size.y, topdown->map_size.y);
    sfView_setSize(tool->view, view_size);
    topdown->zoom.actual = new_value;
}

void update_topdown_view(tool_t *tool, topdown_t *topdown)
{
    sfView_setCenter(tool->view, topdown->boat->body.pos);
    update_window_anchor(tool);
    if (view_overflow_map(tool->anchor, topdown->map_size))
        update_topdown_view_borders(tool, topdown);
    sfRenderWindow_setView(tool->window, tool->view);
}