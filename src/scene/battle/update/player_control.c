/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_control
*/

#include "battle.h"

static void player_control_player(game_obj_t *pirate, control_t control)
{
    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_LEFT])) {
        update_game_object_state(pirate, 1);
        apply_force(&(pirate->body), VEC2F(-1000, 0));
    } else if (sfKeyboard_isKeyPressed(control.keys[CONTROL_RIGHT])) {
        update_game_object_state(pirate, 2);
        apply_force(&(pirate->body), VEC2F(1000, 0));
    } else
        update_game_object_state(pirate, 0);
}

static void player_control_ship(list_t *boat_list, control_t control)
{
    sfVector2f impulse = VEC2F(0, 0);
    game_obj_t *boat = NULL;

    if (sfKeyboard_isKeyPressed(control.keys[CONTROL_LEFT]))
        impulse = VEC2F(-1000, 0);
    else if (sfKeyboard_isKeyPressed(control.keys[CONTROL_RIGHT]))
        impulse = VEC2F(1000, 0);
    for (; boat_list && boat_list->data; boat_list = boat_list->next) {
        boat = NODE_DATA(boat_list, game_obj_t *);
        if (boat)
            apply_force(&(boat->body), impulse);
    }

}

void control_player(game_obj_t *pirate, list_t *boat_list,
                                        control_t control)
{
    if (pirate->comp[find_comp(pirate, IS_DRIVING)]->i)
        player_control_ship(boat_list, control);
    else
        player_control_player(pirate, control);
}