/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_player
*/

#include "battle.h"

void pirate_collide_boat(game_obj_t *pirate, list_t *boat_list)
{
    game_obj_t *boat = NULL;

    for (; boat_list && boat_list->data; boat_list = boat_list->next) {
        boat = NODE_DATA(boat_list, game_obj_t *);
        if (!boat || boat->type < WOOD1_RECT ||
            boat->type > WOOD2_RIGHT_TRIANGLE)
            continue;
        game_object_aabb_collision(pirate, boat);
    }
}

void update_battle_player(tool_t *tool, battle_t *battle)
{
    list_t *player_list = tool->player.crew;
    game_obj_t *pirate = NULL;

    for (; player_list && player_list->data; player_list = player_list->next) {
        pirate = NODE_DATA(player_list, game_obj_t *);
        body_add_acc(&(pirate->body), VEC2F(0, GRAVITY));
        pirate_collide_boat(pirate, tool->player.boat);
        control_player(tool->player.control, pirate);
        update_body(&(pirate->body), tool->dtime);
    }
}