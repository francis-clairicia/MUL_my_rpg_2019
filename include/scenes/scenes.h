/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** scenes.h
*/

#ifndef HEADER_SCENES_ENUM
#define HEADER_SCENES_ENUM

#include "tools.h"

typedef enum SCENES_NUMBER
{
    NO_SCENE = -1,
    MENU,
    SETTINGS,
    SAVE_CHOOSE,
    PERSO_CREATION,
    WORLD,
    GAME,
    END_MENU,
    BATTLE
} scene_t;

typedef scene_t (*scene_loop_t)(tool_t *tools, scene_t state);

/* Scenes */
scene_t launch_menu(tool_t *tool, scene_t state);
scene_t launch_save_chooser(tool_t *tool, scene_t state);
scene_t launch_battle(tool_t *tool, scene_t state);
scene_t launch_settings(tool_t *tool, scene_t state);

#endif