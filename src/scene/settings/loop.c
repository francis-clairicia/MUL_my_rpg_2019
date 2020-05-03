/*
** EPITECH PROJECT, 2020
** init_loop.c
** File description:
** loop of the option
*/

#include "rpg.h"
#include "vector_engine.h"

static int button_event(tool_t *tools, settings_t *sett)
{
    int i = 0;

    while (i < sett->nb_buttons) {
        if (is_button_clicked(sett->buttons[i], tools->event) == sfTrue)
            break;
        i += 1;
    }
    if (i == CLOSE)
        return (sett->previous_state);
    if (i == BACK_MENU)
        return (MENU);
    if (i == VOLUME_UP || i == VOLUME_DOWN) {
        return (SETTINGS);
    } else if (i == SAVE && sett->previous_state != MENU) {
        save_player_data(&tools->player);
    }
    return (SETTINGS);
}

static int check_event(tool_t *tools, int state)
{
    settings_t *sett = &tools->settings;

    while (sfRenderWindow_pollEvent(tools->window, &tools->event)) {
        if (tools->event.type == sfEvtClosed)
            return (NO_SCENE);
        state = button_event(tools, sett);
    }
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
    if (state != SETTINGS)
        tools->settings.previous_state = state;
    state = SETTINGS;
    set_text_origin(tools->settings.buttons[VOLUME_UP].text, 0.5, 1.2);
    set_text_origin(tools->settings.buttons[VOLUME_DOWN].text, 0.5, 3);
    while (state == SETTINGS) {
        draw_settings(tools->window, &tools->settings);
        update_tool(tools);
        sfRenderWindow_display(tools->window);
        state = check_event(tools, state);
    }
    return (state);
}