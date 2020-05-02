/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clean_clouds
*/

#include "update_battle.h"

void clean_clouds(tool_t *tool, battle_t *battle)
{
    list_t *cloud_list = battle->clouds;
    game_obj_t *cloud = NULL;

    for (; cloud_list; cloud_list = cloud_list->next) {
        cloud = NODE_DATA(cloud_list, game_obj_t *);
        if (!cloud)
            continue;
        //if ((cloud->body.vel.x > 0 && cloud->body.pos.x > tool->size.x) ||
        //    (cloud->body.vel.x < 0 && cloud->body.pos.x < 0)) {
        //    my_delete_node_from_node(&(battle->clouds), cloud_list,
        //                                            free_game_object);
        //}
    }
}