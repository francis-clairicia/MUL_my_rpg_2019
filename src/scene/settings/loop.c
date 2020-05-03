/*
** EPITECH PROJECT, 2020
** init_loop.c
** File description:
** loop of the option
*/

#include "rpg.h"
#include "vector_engine.h"

static int button_event(button_t *buttons, int nb_buttons, sfEvent event,
    int prev_state)
{
    int i = 0;

    while (i < nb_buttons) {
        if (is_button_clicked(buttons[i], event) == sfTrue)
            break;
        i += 1;
    }
    if (i == VOLUME_UP || i == VOLUME_DOWN) {
        return (SETTINGS);
    } else if (i == SAVE) {
        return (SETTINGS);
    } else {
        if (i == CLOSE) {
            return (prev_state);
        } else if (i == BACK_MENU && prev_state != MENU) {
            return (MENU);
        }
    }
    return (SETTINGS);
}

static int check_event(tool_t *tools, int state)
{
    settings_t *sett = &tools->settings;

    while (sfRenderWindow_pollEvent(tools->window, &tools->event)) {
        if (tools->event.type == sfEvtClosed)
            return (NO_SCENE);
    }
    state = button_event(sett->buttons, sett->nb_buttons, tools->event, 
        sett->previous_state);
    return (state);
}

static void draw_settings(sfRenderWindow *window, settings_t *sett)
{
    int i = 0;
    int nb_buttons = sett->nb_buttons;
    sfVector2f prev_pos = {0, 0};
    sfFloatRect rect = {0, 0, 0, 0};

    if (sett->previous_state == MENU) {
        nb_buttons -= 1;
        prev_pos = sfRectangleShape_getPosition(sett->buttons[CLOSE].rect);
        rect = sfRectangleShape_getGlobalBounds(sett->box);
        sfRectangleShape_setPosition(sett->buttons[CLOSE].rect, 
            VEC2F(rect.left + rect.width / 2, rect.top + rect.height / 4 * 3));
    }
    sfRenderWindow_drawRectangleShape(window, sett->box, NULL);
    sfRenderWindow_drawText(window, sett->title.object, NULL);
    for (i = 0; i < nb_buttons; i += 1)
        draw_button(sett->buttons[i], window);
    if (sett->previous_state == MENU)
        sfRectangleShape_setPosition(sett->buttons[CLOSE].rect, prev_pos);
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