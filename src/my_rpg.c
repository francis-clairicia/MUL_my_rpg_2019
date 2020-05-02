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
    [BATTLE] = &launch_battle,
    [TOPDOWN] = &launch_topdown,
};

static sfBool init_scene(tool_t *tools)
{
    if (!init_menu(&(tools->menu)) || !init_save_chooser(&tools->chooser))
        return (sfFalse);
    if (!init_settings(&(tools->settings)))
        return (sfFalse);
    return (sfTrue);
}

static sfBool init_window(tool_t *tools)
{
    tools->window = create_window(1920, 1080, 32, "My_RPG");
    if (!(tools->window))
        return (sfFalse);
    tools->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    tools->clock = sfClock_create();
    if (!(tools->view) || !(tools->clock))
        return (sfFalse);
    my_memset(&(tools->player), 0, sizeof(player_t));
    init_mouse_tool(tools);
    update_tool(tools);
    if (!init_scene(tools))
        return (sfFalse);
    if (!init_control(&tools->player))
        return (sfFalse);
    return (sfTrue);
}

static void destroy_window(tool_t *tools)
{
    destroy_player(&tools->player);
    destroy_menu(&tools->menu);
    destroy_settings(&tools->settings);
    destroy_save_chooser(&tools->chooser);
    sfView_destroy(tools->view);
    sfRenderWindow_destroy(tools->window);
}

int my_rpg(void)
{
    tool_t tools;
    scene_t state = MENU;

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