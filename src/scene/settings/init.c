/*
** EPITECH PROJECT, 2020
** init_option
** File description:
** initialisation of the menu
*/

#include "rpg.h"

static button_t init_settings_button(char const *message, sfVector2f pos, int size)
{
    text_t text = init_text(message, FONT_FOLDER "skull.ttf", size);
    sfColor default_color = sfColor_fromRGB(33, 170, 217);
    sfColor hover_color = sfColor_fromRGB(0, 220, 255);
    sfColor active_color = sfColor_fromRGB(100, 100, 100);
    button_t button = create_button(text, default_color);

    button.color[BUTTON_HOVER] = hover_color;
    button.color[BUTTON_ACTIVE] = active_color;
    set_button_origin(button, 0.5, 0.5);
    move_button(button, pos);
    return (button);
}

static sfRectangleShape *create_box(void)
{
    sfRectangleShape *box = sfRectangleShape_create();
    sfVector2f pos = init_vector2f(500, 200);
    sfVector2f size = init_vector2f(1000, 800);

    sfRectangleShape_setFillColor(box, init_color(0, 31, 139, 255));
    sfRectangleShape_setOutlineColor(box, init_color(9, 214, 248, 255));
    sfRectangleShape_setPosition(box, pos);
    sfRectangleShape_setSize(box, size);
    return (box);
}

sfBool init_settings(settings_t *settings) 
{
    if (settings == NULL)
        return (sfFalse);
    settings->box = create_box();
    if (!settings->box)
        return (sfFalse);
    return (sfTrue);
}

void destroy_settings(settings_t *settings)
{
    sfRectangleShape_destroy(settings->box);
}