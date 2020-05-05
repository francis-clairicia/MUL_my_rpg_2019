/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_map
*/

#include "init_topdown.h"
#include "loader.h"

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
    topdown->map = load_file_with_config("assets/config/map", map_config);

    if (!topdown->map)
        return (sfFalse);
    if (!set_topdown_map_size(topdown))
        return (sfFalse);
    return (sfTrue);
}