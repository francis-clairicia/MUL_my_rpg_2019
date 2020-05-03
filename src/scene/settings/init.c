/*
** EPITECH PROJECT, 2020
** init_option
** File description:
** initialisation of the menu
*/

#include "rpg.h"
#include "vector_engine.h"


static button_t init_settings_button(char const *message,
    sfColor col, sfVector2f pos)
{
    text_t text = init_text(message, FONT_FOLDER "skull.ttf", 120);
    sfColor default_color = col;
    sfColor hover_color = sfColor_fromRGB(0, 220, 255);
    sfColor active_color = sfColor_fromRGB(100, 100, 100);
    button_t button = create_button(text, default_color);

    button.color[BUTTON_HOVER] = hover_color;
    button.color[BUTTON_ACTIVE] = active_color;
    set_button_origin(button, 0.5, 0.5);
    set_text_origin(button.text, 0.5, 0.8);
    move_button(button, pos);
    return (button);
}

static sfBool create_box(settings_t *sett)
{
    sfVector2f pos = init_vector2f(500, 100);
    sfVector2f pos_txt = init_vector2f(pos.x + (pos.x / 2), pos.y);
    sfVector2f size = init_vector2f(1000, 800);

    sett->box = sfRectangleShape_create();
    if (!sett->box)
        return (sfFalse);
    sfRectangleShape_setFillColor(sett->box, sfColor_fromRGB(0, 31, 139));
    sfRectangleShape_setOutlineColor(sett->box, sfColor_fromRGB(9, 214, 248));
    sfRectangleShape_setPosition(sett->box, pos);
    sfRectangleShape_setSize(sett->box, size);
    sett->title = init_text("SETTINGS", FONT_FOLDER "skull.ttf", 100);
    if (!sett->title.object)
        return (sfFalse);
    sfText_setPosition(sett->title.object, pos_txt);
    return (sfTrue);
}

sfBool init_settings(settings_t *sett)
{
    sfFloatRect rect = {0, 0, 0, 0};
    sfColor col = sfColor_fromRGB(33, 170, 217);

    if (sett == NULL || !create_box(sett))
        return (sfFalse);
    rect = sfRectangleShape_getGlobalBounds(sett->box);
    sett->nb_buttons = sizeof(sett->buttons) / sizeof(sett->buttons[0]);
    sett->buttons[VOLUME_DOWN] = init_settings_button("-", col,
        VEC2F(rect.left + (rect.width / 4), rect.top + 200));
    sett->buttons[VOLUME_UP] = init_settings_button("+", col,
        VEC2F(rect.left + (rect.width / 4 * 3), rect.top + 200));
    sett->buttons[SAVE] = init_settings_button("SAVE", col,
        VEC2F(rect.left + (rect.width / 2), rect.top + rect.height / 2));
    sett->buttons[BACK_MENU] = init_settings_button("MENU", sfBlue,
        VEC2F(rect.left + (rect.width / 4), rect.top + (rect.height / 4 * 3)));
    sett->buttons[CLOSE] = init_settings_button("CLOSE", sfRed,
        VEC2F(rect.left + rect.width / 4 * 3, rect.top + rect.height / 4 * 3));
    return (sfTrue);
}

void destroy_settings(settings_t *settings)
{
    if (!settings)
        return;
    sfRectangleShape_destroy(settings->box);
    destroy_text(settings->title);
    for (int i = 0; i < settings->nb_buttons; i += 1)
        destroy_button(settings->buttons[i]);
}