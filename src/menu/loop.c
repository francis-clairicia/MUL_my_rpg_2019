/*
** EPITECH PROJECT, 2020
** launch_menu
** File description:
** launch all function link to menu and dispay it ine the window
*/

#include "rpg.h"


static void draw_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->background->sprite, NULL);
}

int launch_menu(tool_t *tool, int state)
{
    while (state == MENU) {
        sfRenderWindow_clear(tool->window, sfBlack);
        draw_menu(tool->window, &tool->menu);
        sfRenderWindow_display(tool->window);
    }
    return (MENU);
}