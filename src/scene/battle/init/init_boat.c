/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_boat
*/

#include "battle.h"
#include "my.h"

static sfBool init_ally_boat(player_t *player, battle_t *battle)
{
    char *boat_path = join_path("saves/save01", "boat");

    player->boat_bg = load_boat_from_file(boat_path);
    if (!(player->boat_bg) || !boat_path)
        return (sfFalse);
    free(boat_path);
    battle->player = player;
    return (sfTrue);
}

sfBool init_battle_boat(player_t *player, battle_t *battle)
{
    if (!init_ally_boat(player, battle))
        return (sfFalse);
    return (sfTrue);
}