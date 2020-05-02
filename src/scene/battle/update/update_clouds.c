/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_clouds
*/

#include "update_battle.h"

void update_battle_clouds(tool_t *tool, battle_t *battle)
{
    list_t *cloud_list = battle->clouds;
    game_obj_t *cloud = NULL;

    generate_clouds(tool, &(battle->clouds));
    for (; cloud_list; cloud_list = cloud_list->next) {
        cloud = NODE_DATA(cloud_list, game_obj_t *);
        cloud->body.vel = vec_lim(cloud->body.vel,
                                    VEC2F(100, 100), VEC2F(-100, -100));
        update_body(&(cloud->body), tool->dtime);
    }
    clean_clouds(tool, battle);
}