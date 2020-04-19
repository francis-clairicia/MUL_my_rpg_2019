/*
** EPITECH PROJECT, 2020
** init_button
** File description:
** function related to buttons
*/

#include "include/struct.h"

button_t create_button(text_t text, sfColor background)
{
    button_t button;
    sfFloatRect text_rect = sfText_getGlobalBounds(text.object);
    sfVector2f size = {text_rect.width + 10, text_rect.height + 20};
    sfFloatRect rect = {0, 0, size.x, size.y};

    button.rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button.rect, size);
    sfRectangleShape_setOutlineThickness(button.rect, 3);
    button.invisible = create_invisible_button(&rect);
    button.color[BUTTON_NORMAL] = background;
    button.color[BUTTON_HOVER] = background;
    button.color[BUTTON_ACTIVE] = background;
    button.text = text;
    set_text_origin(text, 0.5, 0.5);
    return (button);
}

void destroy_button(button_t button)
{
    sfRectangleShape_destroy(button.rect);
    destroy_invisible_button(button.invisible);
    destroy_text(button.text);
}

void set_button_origin(button_t button, float x, float y)
{
    sfFloatRect rect = sfRectangleShape_getLocalBounds(button.rect);
    sfVector2f origin = {rect.width, rect.height};

    origin.x *= x;
    origin.y *= y;
    sfRectangleShape_setOrigin(button.rect, origin);
}