/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** boat_attack
*/

#include "topdown.h"

void boat_attack(game_obj_t *boat, list_t **bullets, sfBool side)
{
    game_obj_t *bullet = create_game_obj(BULLET);

    if (!boat || !bullets || !bullet)
        return ;
}