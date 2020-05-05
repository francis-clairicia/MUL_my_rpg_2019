/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_map
*/

#include "init_topdown.h"
#include "loader.h"

static config_t map_config[] =
{
    {'W', WATER},
    {'S', SAND},
    {'D', DIRT},
    {'1', BUOY1},
    {'2', BUOY2},
    {'3', BUOY3},
    {'4', BUOY4},
    {0, -1}
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

void sort_map_list(list_t **list)
{
    list_t *save = NULL;
    game_obj_t *obj = NULL;
    list_t *tmp = NULL;

    if (!list)
        return;
    for (tmp = *list; tmp; tmp = tmp->next) {
        obj = NODE_DATA(tmp, game_obj_t *);
        if (!obj)
            continue;
        if (obj->type != WATER && save) {
            my_put_node_as_end(list, save);
            sort_map_list(list);
            return;
        }
        if (obj->type == WATER)
            save = tmp;
    }
}

sfBool init_topdown_map(topdown_t *topdown)
{
    topdown->map = load_file_with_config(CONFIG_FOLDER "map.txt", map_config);

    if (!topdown->map)
        return (sfFalse);
    if (!set_topdown_map_size(topdown))
        return (sfFalse);
    sort_map_list(&(topdown->map));
    return (sfTrue);
}