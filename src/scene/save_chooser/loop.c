/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** save.c
*/

#include "rpg.h"

static int button_event(button_t buttons[3], sfEvent event)
{
    int i = 0;

    for (i = 0; i < 3; i += 1) {
        if (is_button_clicked(buttons[i], event))
            return (i);
    }
    return (-1);
}

static int check_event(tool_t *tools, int state, int *save_id)
{
    save_chooser_t *chooser = &tools->chooser;

    while (sfRenderWindow_pollEvent(tools->window, &tools->event)) {
        if (tools->event.type == sfEvtClosed)
            return (NO_SCENE);
        if (is_button_clicked(chooser->menu, tools->event))
            return (MENU);
        *save_id = button_event(chooser->saves, tools->event);
    }
    return (state);
}

static void draw_scene(sfRenderWindow *window, save_chooser_t *chooser)
{
    int i = 0;

    sfRenderWindow_clear(window, chooser->background);
    for (i = 0; i < 3; i += 1)
        draw_button(chooser->saves[i], window);
    draw_button(chooser->menu, window);
}

static scene_t load_player_and_launch_game(tool_t *tool, save_t save)
{
    if (!init_player(&tool->player, save))
        return (SAVE_CHOOSE);
    if (save.used == false)
        return (new_player_setup(tool));
    return (TOPDOWN);
}

scene_t launch_save_chooser(tool_t *tool, scene_t state)
{
    int index = -1;
    save_t saves[3];

    if (!load_all_saves(saves))
        return (MENU);
    set_button_color_for_saves(tool->chooser.saves, saves);
    while (state == SAVE_CHOOSE && index == -1) {
        sfRenderWindow_clear(tool->window, sfBlack);
        update_tool(tool);
        draw_scene(tool->window, &tool->chooser);
        sfRenderWindow_display(tool->window);
        state = check_event(tool, state, &index);
    }
    if (index != -1)
        return (load_player_and_launch_game(tool, saves[index]));
    return (state);
}