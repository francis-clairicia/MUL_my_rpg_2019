/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_boat_interact
*/

#include "update_battle.h"

static void player_boat_collision(game_obj_t *pirate, game_obj_t *boat)
{
    if (!boat || !pirate)
        return;
    if ((boat->type == WOOD1_RECT || boat->type == WOOD1_RECT ||
        boat->type <= WOOD1_RIGHT_TRIANGLE) &&
        game_object_collision(pirate, boat, pirate_collision_solving))
        comp_value(pirate, CAN_JUMP)->i = 1;
}

static void player_control_boat(game_obj_t *pirate, game_obj_t *boat,
                            control_t control)
{
    static sfBool key_pressed = sfFalse;

    if (!boat || !pirate)
        return;
    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_USE])) {
        if (!key_pressed && (is_game_object_collision(pirate, boat) ||
            comp_value(pirate, IS_DRIVING)->i)) {
            comp_value(pirate, IS_DRIVING)->i ^= 1;
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