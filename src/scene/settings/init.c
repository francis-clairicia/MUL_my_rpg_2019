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

static void create_box(sfRectangleShape *box, text_t *title)
{
    sfVector2f pos = init_vector2f(500, 200);
    sfVector2f pos_txt = init_vector2f(pos.x / 2 - 100, 210);
    sfVector2f size = init_vector2f(1000, 800);

    box = sfRectangleShape_create();
    sfRectangleShape_setFillColor(box, init_color(0, 31, 139, 255));
    sfRectangleShape_setOutlineColor(box, init_color(9, 214, 248, 255));
    sfRectangleShape_setPosition(box, pos);
    sfRectangleShape_setSize(box, size);
    // *title = init_text("SETTINGS", FONT_FOLDER "skull.ttf", 200);
    // sfText_setPosition(title->object, pos_txt);
}

sfBool init_settings(settings_t *settings) 
{
    if (settings == NULL)
        return (sfFalse);
    create_box(settings->box, &settings->title);
    if (!settings->box || !settings->title.object)
        return (sfFalse);
    return (sfTrue);
}

void destroy_settings(settings_t *settings)
{
    sfRectangleShape_destroy(settings->box);
    // destroy_text(settings->title);
}