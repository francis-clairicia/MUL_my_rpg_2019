/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_player
*/

#include "update_battle.h"

void update_battle_player(tool_t *tool, battle_t *battle)
{
    list_t *player_list = tool->player.crew;
    game_obj_t *pirate = NULL;

    pirate = NODE_DATA(player_list, game_obj_t *);
    anime_game_object(pirate);
    body_add_acc(&(pirate->body), VEC2F(0, GRAVITY));
    control_player(pirate, tool->player.boat, tool->player.control);
    pirate_boat_interact(tool, tool->player.boat);
    friction_force(&(pirate->body), 10);
    pirate->body.vel = vec_lim(pirate->body.vel,
                        VEC2F(100, 100), VEC2F(-100, -200));
    update_body(&(pirate->body), tool->dtime);
}