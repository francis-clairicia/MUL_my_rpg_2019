/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_player.c
*/

#include "player.h"

void destroy_player(player_t *player)
{
    if (player == NULL)
        return;
    free(player);
}