/*
** EPITECH PROJECT, 2020
** init_menu
** File description:
** initialisation of the menu
*/

#include "rpg.h"
#include "vector_engine.h"

static button_t init_menu_button(char const *message, sfVector2f pos)
{
    text_t text = init_text(message, FONT_FOLDER "skull.ttf", 100);
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

sfBool init_menu(menu_t *menu)
{
    int x = 400;
    int y = 400;

    if (menu == NULL)
        return (sfFalse);
    menu->background = create_object(IMG_FOLDER "background_menu.jpeg", NULL);
    if (!(menu->background))
        return (sfFalse);
    menu->nb_buttons = sizeof(menu->buttons) / sizeof(menu->buttons[0]);
    menu->buttons[MENU_PLAY] = init_menu_button("Play", VEC2F(x, y));
    menu->buttons[MENU_QUIT] = init_menu_button("Quit", VEC2F(x, y + 200));
    return (sfTrue);
}

void destroy_menu(menu_t *menu)
{
    int i = 0;

    if (menu == NULL)
        return;
    destroy_object(menu->background);
    for (i = 0; i < menu->nb_buttons; i += 1)
        destroy_button(menu->buttons[i]);
}