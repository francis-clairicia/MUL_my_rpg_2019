/*
** EPITECH PROJECT, 2020
** init_loop.c
** File description:
** loop of the option
*/

#include "rpg.h"


static int check_event(tool_t *tools, int state)
{
    settings_t *settings = &tools->settings;

    while (sfRenderWindow_pollEvent(tools->window, &tools->event)) {
        if (tools->event.type == sfEvtClosed)
            return (NO_SCENE);
    }
    return (state);
}

static void draw_settings(sfRenderWindow *window, settings_t *settings)
{
    sfRenderWindow_drawRectangleShape(window, settings->box, NULL);
}

scene_t launch_settings(tool_t *tools, scene_t state)
{
    while (state == SETTINGS) {
        draw_settings(tools->window, &tools->settings);
        sfRenderWindow_display(tools->window);
        state = check_event(tools, state);
    }
    return (state);
}