/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_battle
*/

#ifndef INIT_BATTLE_H_
#define INIT_BATTLE_H_

#include "battle.h"

sfBool init_battle_boat(player_t *player, battle_t *battle);
sfBool init_battle_background(battle_t *battle);
sfBool init_battle_water(tool_t *tool, battle_t *battle);

#endif /* !INIT_BATTLE_H_ */