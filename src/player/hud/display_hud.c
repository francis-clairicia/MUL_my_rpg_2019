/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_hud.c
*/

#include "hud.h"

static const hud_t display_infos[] = {
    display_pseudo,
    display_level,
    display_xp,
    display_xp_bar,
    NULL
};

static sfBool init_box(sfRectangleShape **shape, tool_t *tool, sfVector2f scale)
{
    sfVector2f view_size = sfView_getSize(tool->view);
    sfVector2f pos = sfView_getCenter(tool->view);

    *shape = sfRectangleShape_create();
    if (!(*shape))
        return (sfFalse);
    sfRectangleShape_setSize(*shape, VEC2F(view_size.x / 3, view_size.y / 4));
    set_rect_origin(*shape, 1, 0);
    pos.x += (view_size.x / 2) - (20 * scale.x);
    pos.y += (-view_size.y / 2) + (20 * scale.y);
    sfRectangleShape_setPosition(*shape, pos);
    sfRectangleShape_setFillColor(*shape, sfColor_fromRGB(33, 170, 217));
    sfRectangleShape_setOutlineColor(*shape, sfWhite);
    sfRectangleShape_setOutlineThickness(*shape, 3 * scale.x);
    return (sfTrue);
}

void display_hud(tool_t *tool)
{
    sfRectangleShape *box = NULL;
    sfFloatRect box_rect;
    sfFloatRect rect;
    sfVector2f view_size;
    sfVector2f scale;

    if (!tool || !(tool->window) || !(tool->view))
        return;
    view_size = sfView_getSize(tool->view);
    scale = VEC2F(view_size.x / tool->size.x, view_size.y / tool->size.y);
    if (!init_box(&box, tool, scale))
        return;
    sfRenderWindow_drawRectangleShape(tool->window, box, NULL);
    box_rect = sfRectangleShape_getGlobalBounds(box);
    rect = box_rect;
    for (int i = 0; display_infos[i] != NULL; i += 1)
        rect = display_infos[i](tool, scale, rect, box_rect);
    sfRectangleShape_destroy(box);
}