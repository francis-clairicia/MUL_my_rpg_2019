/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init
*/

#include "init_battle.h"
#include "my.h"

sfBool init_battle(tool_t *tool, battle_t *battle)
{
    if (!battle)
        return (sfFalse);
    my_memset(battle, 0, sizeof(battle_t));
    if (!init_battle_water(tool, battle))
        return (sfFalse);
    if (!init_battle_boat(&(tool->player), battle))
        return (sfFalse);
    if (!init_battle_player(&(tool->player)))
        return (sfFalse);
    if (!init_battle_background(battle))
        return (sfFalse);
    return (sfTrue);
}