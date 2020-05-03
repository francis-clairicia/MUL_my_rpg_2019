/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init.c
*/

#include "save_chooser.h"
#include "vector_engine.h"

static button_t init_chooser_button(char const *message, sfVector2f pos)
{
    text_t text = init_text(message, FONT_FOLDER "skull.ttf", 100);
    sfColor default_color = sfColor_fromRGB(33, 170, 217);
    button_t button = create_button(text, default_color);

    move_button(button, pos);
    set_text_origin(button.text, 0.5, 0.75);
    return (button);
}

void set_button_color_for_saves(button_t buttons[3], save_t saves[3])
{
    sfColor default_color = sfColor_fromRGB(33, 170, 217);
    sfColor hover_color = sfColor_fromRGB(0, 220, 255);
    sfColor active_color = sfColor_fromRGB(100, 100, 100);
    sfColor disabled_color = sfColor_fromRGB(175, 175, 175);
    sfColor disabled_hover_color = sfColor_fromRGB(200, 200, 200);
    sfColor disabled_active_color = sfColor_fromRGB(100, 100, 100);

    for (int i = 0; buttons != NULL && saves != NULL && i < 3; i += 1) {
        if (saves[i].used) {
            buttons[i].color[BUTTON_NORMAL] = default_color;
            buttons[i].color[BUTTON_HOVER] = hover_color;
            buttons[i].color[BUTTON_ACTIVE] = active_color;
        } else {
            buttons[i].color[BUTTON_NORMAL] = disabled_color;
            buttons[i].color[BUTTON_HOVER] = disabled_hover_color;
            buttons[i].color[BUTTON_ACTIVE] = disabled_active_color;
        }
    }
}

sfBool init_save_chooser(save_chooser_t *chooser)
{
    sfVector2f pos[3] = {VEC2F(100, 100), VEC2F(100, 300), VEC2F(100, 500)};
    char const *messages[3] = {"Save 01", "Save 02", "Save 03"};

    int i = 0;

    if (chooser == NULL)
        return (false);
    chooser->background = sfColor_fromRGB(31, 133, 222);
    for (i = 0; i < 3; i += 1)
        chooser->saves[i] = init_chooser_button(messages[i], pos[i]);
    chooser->menu = init_chooser_button("Menu", VEC2F(1900, 980));
    chooser->menu.color[BUTTON_HOVER] = sfColor_fromRGB(0, 220, 255);
    chooser->menu.color[BUTTON_ACTIVE] = sfColor_fromRGB(100, 100, 100);
    set_button_origin(chooser->menu, 1, 1);
    return (true);
}

void destroy_save_chooser(save_chooser_t *chooser)
{
    int i = 0;

    if (chooser == NULL)
        return;
    for (i = 0; i < 3; i += 1)
        destroy_button(chooser->saves[i]);
    destroy_button(chooser->menu);
}