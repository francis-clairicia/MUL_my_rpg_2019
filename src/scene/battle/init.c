/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init
*/

#include "battle.h"
#include "my.h"

static sfBool init_background(battle_t *battle)
{
    battle->background = create_game_obj(SKY);
    if (!(battle->background))
        return (sfFalse);
    return (sfTrue);
}

static sfBool init_ally_boat(save_t save, battle_t *battle)
{
    save.folder = "saves/save01";
    char *boat_path = join_path(save.folder, "boat");

    battle->ally.bg = load_boat_from_file(boat_path);
    if (!(battle->ally.bg) || !boat_path)
        return (sfFalse);
    free(boat_path);
    return (sfTrue);
}

sfBool init_battle(save_t save, battle_t *battle)
{
    if (!battle)
        return (sfFalse);
    if (!init_background(battle))
        return (sfFalse);
    if (!init_ally_boat(save, battle)) {
        free_game_object(battle->background);
        return (sfFalse);
    }
    return (sfTrue);
}