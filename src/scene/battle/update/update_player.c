/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_player
*/

#include "battle.h"

void player_boat_collision(game_obj_t *pirate, game_obj_t *boat)
{
    if (!boat || !pirate)
        return;
    if (boat->type < WOOD1_RECT ||
        boat->type > WOOD2_RIGHT_TRIANGLE)
        return ;
    game_object_collision(pirate, boat, pirate_collision_solving);
}

void player_control_boat(game_obj_t *pirate, game_obj_t *boat,
                            control_t control)
{
    static sfBool key_pressed = sfFalse;

    if (!boat || !pirate)
        return;
    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_USE])) {
        if (!key_pressed) {
            pirate->comp[find_comp(pirate, IS_DRIVING)]->i ^= 1;
            pirate->body.vel = VEC2F(0, 0);
        }
        key_pressed = sfTrue;
    } else
        key_pressed = sfFalse;
}

void pirate_boat_interact(tool_t *tool, list_t *boat_list)
{
    game_obj_t *pirate = NODE_DATA(tool->player.crew, game_obj_t *);
    game_obj_t *boat = NULL;

    for (; boat_list && boat_list->data; boat_list = boat_list->next) {
        boat = NODE_DATA(boat_list, game_obj_t *);
        if (boat->type == TILLER)
            player_control_boat(pirate, boat, tool->player.control);
        player_boat_collision(pirate, boat);
    }
}

void update_battle_player(tool_t *tool, battle_t *battle)
{
    list_t *player_list = tool->player.crew;
    game_obj_t *pirate = NULL;

    pirate = NODE_DATA(player_list, game_obj_t *);
    body_add_acc(&(pirate->body), VEC2F(0, GRAVITY));
    control_player(pirate, tool->player.boat, tool->player.control);
    pirate_boat_interact(tool, tool->player.boat);
    update_body(&(pirate->body), tool->dtime);
}