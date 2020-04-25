/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_background
*/

#include "battle.h"
#include "my.h"

sfBool init_battle_background(battle_t *battle)
{
    battle->background = create_game_obj(SKY);
    if (!(battle->background))
        return (sfFalse);
    return (sfTrue);
}