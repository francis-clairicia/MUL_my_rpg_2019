/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update
*/

#include "update_topdown.h"

void update_topdown(tool_t *tool, topdown_t *topdown, scene_t *state)
{
    update_topdown_boat(tool, topdown);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        *state = MENU;
    if (sfKeyboard_isKeyPressed(sfKeyF12))
        *state = BATTLE;
}