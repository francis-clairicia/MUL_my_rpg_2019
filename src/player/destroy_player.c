/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_player.c
*/

#include "player.h"
#include "game_object.h"
#include "my.h"

void destroy_player(player_t *player, bool destroy_boat_layout)
{
    if (player == NULL)
        return;
    my_free_list(&player->crew, &free_game_object);
    my_free_list(&player->boat, &free_game_object);
    if (destroy_boat_layout) {
        my_free_array(player->boat_layout);
        player->boat_layout = NULL;
    }
}