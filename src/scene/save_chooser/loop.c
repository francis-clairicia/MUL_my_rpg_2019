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

static scene_t load_player_and_launch_game(tool_t *tool, player_t players[3],
    int save_chosen)
{
    tool->player = players[save_chosen];
    for (int i = 0; i < 3; i += 1) {
        if (i != save_chosen)
            destroy_player(&players[i], true);
    }
    if (tool->player.save.used == false)
        return (new_player_setup(tool));
    return (TOPDOWN);
}

scene_t launch_save_chooser(tool_t *tool, scene_t state)
{
    int index = -1;
    player_t players[3];

    if (!load_all_saves(players))
        return (MENU);
    set_button_color_for_saves(tool->chooser.saves, players);
    while (state == SAVE_CHOOSE && index == -1) {
        sfRenderWindow_clear(tool->window, sfBlack);
        update_tool(tool);
        draw_save_chooser(tool->window, &tool->chooser, players);
        sfRenderWindow_display(tool->window);
        state = check_event(tool, state, &index);
    }
    if (index != -1)
        return (load_player_and_launch_game(tool, players, index));
    return (state);
}