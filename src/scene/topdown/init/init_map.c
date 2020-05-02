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
    {NULL, 0, -1}
};

sfBool init_topdown_map(topdown_t *topdown)
{
    topdown->map = load_config_from_file("assets/config/map", map_config);
    if (!topdown->map)
        return (sfFalse);
    return (sfTrue);
}