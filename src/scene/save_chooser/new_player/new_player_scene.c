/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** new_player_scene.c
*/

#include "scenes.h"

static scene_t (*processus[])(tool_t *) = {
    &get_pseudo_new_player,
    NULL
};

scene_t new_player_setup(tool_t *tool)
{
    int state = 0;

    for (int i = 0; processus[i] != NULL; i += 1) {
        state = processus[i](tool);
        if (state != NEW_PLAYER)
            return (state);
    }
    tool->player.new_player = sfTrue;
    save_player_data(&tool->player);
    return (TOPDOWN);
}