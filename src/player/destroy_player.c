/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_player.c
*/

#include "player.h"
#include "game_object.h"

void destroy_player(player_t *player)
{
    if (player == NULL)
        return;
    my_free_list(&player->crew, &free_game_object);
    my_free_list(&player->boat, &free_game_object);
}