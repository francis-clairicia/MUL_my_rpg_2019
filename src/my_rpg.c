/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** ROle player game creation
*/

#include "rpg.h"

static const scene_t scene_launcher[] = {
    &launch_menu
};

static const gameloop_t gameloop[] = {
    [MENU] = &launch_menu
};

int my_rpg(void)
{
    tool_t tool;
    tool.window = create_window(1820, 1080, 64, "My_RPG");
    int state = MENU;

    init_menu();
    while (sfRenderWindow_isOpen(tool.window)) {
        state = scene_launcher[state]();
        if (state == NO_SCENE)
            sfRenderWindow_close(tool.window);
    }
    sfRenderWindow_destroy(tool.window);
    return (0);
}