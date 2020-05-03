/*
** EPITECH PROJECT, 2020
** launch_menu
** File description:
** launch all function link to menu and dispay it ine the window
*/

#include "rpg.h"
#include "game_object.h"

static const int button_scenes[][2] = {
    {MENU_PLAY, SAVE_CHOOSE},
    {MENU_SETT, SETTINGS},
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
    menu_t *menu = &tools->menu;

    while (sfRenderWindow_pollEvent(tools->window, &tools->event)) {
        if (tools->event.type == sfEvtClosed)
            return (NO_SCENE);
        state = button_event(menu->buttons, tools->event, state);
        if (state == SETTINGS)
            state = launch_settings(tools, MENU);
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

scene_t launch_menu(tool_t *tool, scene_t state)
{
    while (state == MENU || state == SETTINGS) {
        sfRenderWindow_clear(tool->window, sfBlack);
        update_tool(tool);
        draw_menu(tool->window, &tool->menu);
        state = check_event(tool, state);
        sfRenderWindow_display(tool->window);
    }
    return (state);
}