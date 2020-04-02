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
    int width = 1920;
    int height = 1080;
    int bpp = 32;
    tool_t tools;

    tools.video_mode = (sfVideoMode){width, height, bpp};
    tools.window = create_window(width, height, bpp, "My_RPG");
    tools.view = sfView_createFromRect((sfFloatRect){0, 0, width, height});
    init_menu(&tools.menu);
    return (tools);
}

void destroy_window(tool_t tools)
{
    destroy_menu(&tools.menu);
    sfView_destroy(tools.view);
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