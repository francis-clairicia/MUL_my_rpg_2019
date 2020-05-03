/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_map
*/

#include "init_topdown.h"
#include "loader.h"

static load_config_t map_config[] =
{
    {"WATER", 0, WATER},
    {"SAND", 0, SAND},
    {"DIRT", 0, DIRT},
    {"BUOY1", 0, BUOY1},
    {"BUOY2", 0, BUOY2},
    {"BUOY3", 0, BUOY3},
    {"BUOY4", 0, BUOY4},
    {NULL, 0, -1}
};

static sfBool set_topdown_map_size(topdown_t *topdown)
{
    game_obj_t *highest_x = find_game_object_highest_x(topdown->map);
    game_obj_t *highest_y = find_game_object_highest_y(topdown->map);

    if (!highest_x || !highest_y)
        return (sfFalse);
    topdown->map_size = VEC2F(highest_x->body.pos.x, highest_y->body.pos.y);
    return (sfTrue);
}

sfBool init_topdown_map(topdown_t *topdown)
{
    topdown->map = load_config_from_file("assets/config/map", map_config);
    if (!topdown->map)
        return (sfFalse);
    if (!set_topdown_map_size(topdown))
        return (sfFalse);
    return (sfTrue);
}