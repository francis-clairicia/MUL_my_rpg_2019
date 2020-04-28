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

static bool init_all_structure(player_t *player)
{
    for (int i = 0; init_function[i] != NULL; i += 1) {
        if (init_function[i](player) == false)
            return (false);
    }
    return (true);
}

player_t *create_player(save_t save)
{
    player_t *player = malloc(sizeof(*player));

    if (player != NULL) {
        player->save = save;
        my_memset(player->pseudo, 0, sizeof(player->pseudo));
        if (!init_all_structure(player)) {
            free(player);
            player = NULL;
        }
    }
    return (player);
}