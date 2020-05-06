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
    &init_data,
    &init_boat_layout,
    NULL
};

bool init_player(player_t *player, save_t save)
{
    if (player == NULL)
        return (false);
    my_memset(player, 0, sizeof(*player));
    player->save = save;
    for (int i = 0; init_function[i] != NULL; i += 1) {
        if (init_function[i](player) == false)
            return (false);
    }
    return (true);
}