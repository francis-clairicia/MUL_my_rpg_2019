/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_view
*/

#include "topdown.h"

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

void update_topdown_view(tool_t *tool, topdown_t *topdown)
{
    if (topdown->camera == CENTERED)
        sfView_setCenter(tool->view, topdown->boat->body.pos);
    else
        update_topdown_view_borders(tool, topdown);
    sfRenderWindow_setView(tool->window, tool->view);
}