/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_player.c
*/

#include "player.h"
#include "my.h"

static const player_field_init_t init_function[] = {
    &init_pseudo,
    &init_control,
    NULL
};

bool init_player(player_t *player, save_t save)
{
    if (player == NULL)
        return (false);
    player->save = save;
    player->crew = NULL;
    player->boat = NULL;
    my_memset(player->pseudo, 0, sizeof(player->pseudo));
    for (int i = 0; init_function[i] != NULL; i += 1) {
        if (init_function[i](player) == false)
            return (false);
    }
    return (true);
}