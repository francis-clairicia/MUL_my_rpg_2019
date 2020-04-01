/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** ROle player game creation
*/

#include "rpg.h"

static const scene_t scene_launcher[] = {
    [MENU] = &launch_menu
};


tool_t init_window(void)
{
    tool_t tools;

    tools.window = create_window(1920, 1080, 64, "My_RPG");
    init_menu(&tools.menu);
    return (tools);
}

void destroy_window(tool_t tools)
{
    destroy_menu(&tools.menu);
    sfRenderWindow_destroy(tools.window);
}

int my_rpg(void)
{
    tool_t tools = init_window();
    int state = MENU;

    while (sfRenderWindow_isOpen(tools.window)) {
        state = scene_launcher[state](&tools, state);
        if (state == NO_SCENE)
            sfRenderWindow_close(tools.window);
    }
    destroy_window(tools);
    return (0);
}