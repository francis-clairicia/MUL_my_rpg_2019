/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clean_clouds
*/

#include "update_battle.h"

void clean_clouds(tool_t *tool, battle_t *battle)
{
    list_t *node = NULL;
    int node_index = 0;
    game_obj_t *cloud = NULL;

    while ((node = my_node(battle->clouds, node_index)) != NULL) {
        cloud = NODE_DATA(node, game_obj_t *);
        if (!cloud) {
            node_index += 1;
            continue;
        }
        if ((cloud->body.vel.x > 0 && cloud->body.pos.x > tool->size.x) ||
        (cloud->body.vel.x < 0 && cloud->body.pos.x + cloud->view_box[cloud->state].width < 0)) {
           my_delete_node(&(battle->clouds), node_index, &free_game_object);
        } else {
            node_index += 1;
        }
    }
}