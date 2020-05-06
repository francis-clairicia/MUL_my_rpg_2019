/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_xp_bar.c
*/

#include "hud.h"

static sfBool init_xp_bar(sfRectangleShape *xp_bar[], sfVector2f scale)
{
    xp_bar[0] = sfRectangleShape_create();
    xp_bar[1] = sfRectangleShape_create();
    xp_bar[2] = sfRectangleShape_create();
    if (!xp_bar[0] || !xp_bar[1] || !xp_bar[2])
        return (sfFalse);
    sfRectangleShape_setFillColor(xp_bar[0], sfBlack);
    sfRectangleShape_setFillColor(xp_bar[1], sfGreen);
    sfRectangleShape_setFillColor(xp_bar[2], sfTransparent);
    sfRectangleShape_setOutlineColor(xp_bar[2], sfColor_fromRGB(128, 128, 128));
    sfRectangleShape_setOutlineThickness(xp_bar[2], 3 * scale.x);
    return (sfTrue);
}

static void setup_xp_bar(int xp, int max_xp, sfFloatRect rect,
    sfRectangleShape *xp_bar[])
{
    sfVector2f max_xp_size = {rect.width, rect.height};
    sfVector2f xp_size = {max_xp_size.x * xp / max_xp, max_xp_size.y};
    sfVector2f pos = {rect.left, rect.top};

    sfRectangleShape_setSize(xp_bar[0], max_xp_size);
    sfRectangleShape_setSize(xp_bar[1], xp_size);
    sfRectangleShape_setSize(xp_bar[2], max_xp_size);
    sfRectangleShape_setPosition(xp_bar[0], pos);
    sfRectangleShape_setPosition(xp_bar[1], pos);
    sfRectangleShape_setPosition(xp_bar[2], pos);
}

sfFloatRect display_xp_bar(tool_t *tool, sfVector2f scale,
    sfFloatRect rect, sfFloatRect box_rect)
{
    sfRectangleShape *xp_bar[3] = {NULL, NULL, NULL};
    sfFloatRect bar_rect;

    if (!init_xp_bar(xp_bar, scale))
        return (rect);
    bar_rect.left = box_rect.left + (30 * scale.x);
    bar_rect.top = rect.top + rect.height + (30 * scale.y);
    bar_rect.width = box_rect.width - (60 * scale.x);
    bar_rect.height = 20 * scale.y;
    setup_xp_bar(tool->player.data.xp, tool->player.max_xp, bar_rect, xp_bar);
    for (int i = 0; i < 3; i += 1) {
        sfRenderWindow_drawRectangleShape(tool->window, xp_bar[i], NULL);
        sfRectangleShape_destroy(xp_bar[i]);
    }
    return (bar_rect);
}