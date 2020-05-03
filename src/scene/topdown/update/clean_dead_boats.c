/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clean_dead_boats
*/

#include "topdown.h"

static void update_player_stat(game_obj_t *boat, game_obj_t *dead_boat)
{
    if (dead_boat && (dead_boat->type == BOAT2 || dead_boat->type == BOAT3) &&
        has_comp(boat, DEAD_COUNTER))
        boat->comp[find_comp(boat, DEAD_COUNTER)]->i += 1;
}

static void clean_dead_boats(game_obj_t *boat, list_t **boat_list)
{
    game_obj_t *tmp = NULL;
    list_t *list = NULL;

    if (!boat_list)
        return;
    list = *boat_list;
    for (; list; list = list->next) {
        tmp = NODE_DATA(list, game_obj_t *);
        if (!tmp || !has_comp(tmp, LIFE))
            continue;
        if (tmp->comp[find_comp(tmp, LIFE)]->i <= 0) {
            update_player_stat(boat, tmp);
            my_delete_node_from_node(boat_list, list, free_game_object);
            clean_dead_boats(boat, boat_list);
        }
    }
}

void clean_topdown_dead_boats(tool_t *tool, topdown_t *topdown)
{
    static float time_buffer = 0;

    time_buffer += tool->dtime;
    if (time_buffer > 5) {
        clean_dead_boats(topdown->boat, &(topdown->ally_boat));
        clean_dead_boats(topdown->boat, &(topdown->ennemy_boat));
        clean_dead_boats(topdown->boat, &(topdown->golden_boat));
        clean_dead_boats(topdown->boat, &(topdown->mercenary_boat));
        time_buffer = 0;
    }
}