/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update
*/

#include "rpg.h"
#include "update_battle.h"

void update_battle(tool_t *tool, battle_t *battle, scene_t *state)
{
    update_battle_boats(tool, battle->player->boat);
    update_battle_player(tool, battle);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        *state = MENU;
}