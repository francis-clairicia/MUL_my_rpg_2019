/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** ia
*/

#ifndef IA_H_
#define IA_H_

#include "update_topdown.h"

static inline void ia_attack(game_obj_t *boat, list_t **bullets, sfBool side)
{
    if (can_game_object_attack(boat)) {
        boat_attack(boat, bullets, side);
    }
}

#endif /* !IA_H_ */