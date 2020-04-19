/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_draw.c
*/

#include "include/struct.h"

void draw_button(button_t button, sfRenderWindow *window)
{
    enum BUTTON_STATE state = button.invisible->state;
    sfFloatRect rect;
    sfVector2f middle;

    button.invisible->rect = sfRectangleShape_getGlobalBounds(button.rect);
    rect = button.invisible->rect;
    middle.x = rect.left + rect.width / 2;
    middle.y = rect.top + rect.height / 2;
    sfRectangleShape_setFillColor(button.rect, button.color[state]);
    sfRenderWindow_drawRectangleShape(window, button.rect, NULL);
    sfText_setPosition(button.text.object, middle);
    draw_text(button.text, window);
}