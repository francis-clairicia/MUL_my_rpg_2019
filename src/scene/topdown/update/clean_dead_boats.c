/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clean_dead_boats
*/

#include "topdown.h"
#include "update_topdown.h"

static const int XP_PER_BOAT[][2] = {
    {BOAT2, 5},
    {BOAT3, 7}
};

static int get_xp_gained(int dead_boat)
{
    int size = sizeof(XP_PER_BOAT) / sizeof(XP_PER_BOAT[0]);

    for (int i = 0; i < size; i += 1) {
        if (XP_PER_BOAT[i][0] == dead_boat)
            return (XP_PER_BOAT[i][1]);
    }
    return (0);
}

static void update_player_stat(game_obj_t *boat, game_obj_t *dead_boat)
{
    int xp_gained = 0;

    if (dead_boat && has_comp(boat, DEAD_COUNTER)) {
        xp_gained = get_xp_gained(dead_boat->type);
        comp_value(boat, XP)->i += xp_gained;
        if (xp_gained > 0) {
            comp_value(boat, EARN_XP)->i = true;
            comp_value(boat, DEAD_COUNTER)->i += 1;
        }
    }
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
        if (comp_value(tmp, LIFE)->i <= 0) {
            update_player_stat(boat, tmp);
            my_delete_node_from_node(boat_list, list, free_game_object);
            clean_dead_boats(boat, boat_list);
            break;
        }
    }
}

void clean_topdown_dead_boats(topdown_t *topdown)
{
    clean_dead_boats(topdown->boat, &(topdown->ally_boat));
    clean_dead_boats(topdown->boat, &(topdown->ennemy_boat));
    clean_dead_boats(topdown->boat, &(topdown->golden_boat));
    clean_dead_boats(topdown->boat, &(topdown->mercenary_boat));
}