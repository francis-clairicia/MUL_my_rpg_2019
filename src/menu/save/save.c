/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** save.c
*/

#include "rpg.h"

static const int button_scenes[][2] = {
    {MENU_QUIT, NO_SCENE}
};

static int button_event(button_t *buttons, sfEvent event, int state)
{
    int nb_buttons_scenes = sizeof(button_scenes) / sizeof(button_scenes[0]);
    int i = 0;

    for (i = 0; i < nb_buttons_scenes; i += 1) {
        if (is_button_clicked(buttons[button_scenes[i][0]], event))
            return (button_scenes[i][1]);
    }
    return (state);
}

static int check_event(tool_t *tools, int state)
{
    menu_t menu = tools->menu;
    sfEvent event;

    while (sfRenderWindow_pollEvent(tools->window, &event)) {
        if (event.type == sfEvtClosed)
            return (NO_SCENE);
        state = button_event(menu.buttons, event, state);
    }
    return (state);
}

static void draw_menu(sfRenderWindow *window, menu_t *menu)
{
    int i = 0;

    draw_object(menu->background, window);
    for (i = 0; i < menu->nb_buttons; i += 1)
        draw_button(menu->buttons[i], window);
}

int save_chooser(tool_t *tool, int state)
{
    button_t saves[3];

    while (state == SAVE_CHOOSE) {
        sfRenderWindow_clear(tool->window, sfBlack);
        update_tool(tool);
        draw_menu(tool->window, &tool->menu);
        sfRenderWindow_display(tool->window);
        state = check_event(tool, state);
    }
    return (state);
}