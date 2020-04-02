/*
** EPITECH PROJECT, 2020
** launch_menu
** File description:
** launch all function link to menu and dispay it ine the window
*/

#include "rpg.h"

static int check_event(tool_t *tools, int state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(tools->window, &event)) {
        if (event.type == sfEvtClosed)
            return (NO_SCENE);
    }
    return (state);
}

static void draw_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->background->sprite, NULL);
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