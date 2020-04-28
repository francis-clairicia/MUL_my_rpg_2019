/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** control_player
*/

#include "battle.h"

void control_player(control_t control, game_obj_t *pirate)
{
    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_LEFT]))
        apply_force(&(pirate->body), VEC2F(-100, 0));
    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_RIGHT]))
        apply_force(&(pirate->body), VEC2F(100, 0));
}