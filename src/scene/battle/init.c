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

static sfBool init_water(tool_t *tool, battle_t *battle)
{
    battle->water = my_list(1, create_game_obj(WATER2));
    if (!(battle->water))
        return (sfFalse);
    set_game_object_pos(NODE_DATA(battle->water, game_obj_t *),
                                        VEC2F(0, tool->size.y));
    expand_game_object_right(&(battle->water), 500);
    return (sfTrue);
}

sfBool init_battle(tool_t *tool, battle_t *battle)
{
    if (!battle)
        return (sfFalse);
    if (!init_background(battle))
        return (sfFalse);
    if (!init_ally_boat(&(tool->player), battle)) {
        free_game_object(battle->background);
        return (sfFalse);
    }
    if (!init_water(tool, battle))
        return (sfFalse);
    return (sfTrue);
}