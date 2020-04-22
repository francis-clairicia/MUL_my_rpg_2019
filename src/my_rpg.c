/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** ROle player game creation
*/

#include "rpg.h"
#include "game_object.h"

static const scene_loop_t scene_launcher[] = {
    [MENU] = &launch_menu,
    [SAVE_CHOOSE] = &launch_save_chooser,
    [BATTLE] = &launch_battle
};

sfBool init_window(tool_t *tools)
{
    tools->window = create_window(1920, 1080, 32, "My_RPG");
    if (!(tools->window))
        return (sfFalse);
    tools->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    if (!(tools->view))
        return (sfFalse);
    init_mouse_tool(tools);
    if (!init_menu(&(tools->menu)) || !init_save_chooser(&tools->chooser))
        return (sfFalse);
    return (sfTrue);
}

void destroy_window(tool_t *tools)
{
    destroy_menu(&tools->menu);
    destroy_save_chooser(&tools->chooser);
    sfView_destroy(tools->view);
    sfRenderWindow_destroy(tools->window);
}

int my_rpg(void)
{
    tool_t tools;
    scene_t state = BATTLE;

    if (!init_window(&tools))
        return (84);
    while (sfRenderWindow_isOpen(tools.window)) {
        state = scene_launcher[state](&tools, state);
        if (state == NO_SCENE)
            sfRenderWindow_close(tools.window);
    }
    destroy_window(&tools);
    return (0);
}