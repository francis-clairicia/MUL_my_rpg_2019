/*
** EPITECH PROJECT, 2020
** launch_menu
** File description:
** launch all function link to menu and dispay it ine the window
*/

#include "rpg.h"

static int check_event(tool_t *tools, int state)
{
    menu_t menu = tools->menu;
    sfEvent event;

    while (sfRenderWindow_pollEvent(tools->window, &event)) {
        if (event.type == sfEvtClosed
        || is_button_clicked(menu.buttons[MENU_QUIT], event))
            return (NO_SCENE);
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

int launch_menu(tool_t *tool, int state)
{
    while (state == MENU) {
        sfRenderWindow_clear(tool->window, sfBlack);
        update_tool(tool);
        draw_menu(tool->window, &tool->menu);
        sfRenderWindow_display(tool->window);
        state = check_event(tool, state);
    }
    return (state);
}