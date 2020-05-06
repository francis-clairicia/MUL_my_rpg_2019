/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_boat
*/

#include "generate_boat.h"
#include "math_process.h"

static void generate_ennemy_boat(game_obj_t *buoy, topdown_t *topdown,
                                __attribute__((unused)) tool_t *tool)
{
    game_obj_t *new_boat = NULL;

    if (!get_randomnb(0, 10) &&
        vec_mag(vec_sub(topdown->boat->body.pos, buoy->body.pos)) < 1000) {
        new_boat = create_game_obj(BOAT2);
        if (new_boat) {
            MY_APPEND_TO_LIST(&(topdown->ennemy_boat), new_boat);
            set_game_object_pos(new_boat, buoy->body.pos);
        }
    }
}

static void generate_mercenary_boat(game_obj_t *buoy, topdown_t *topdown,
                                    __attribute__((unused)) tool_t *tool)
{
    game_obj_t *new_boat = NULL;

    if (!get_randomnb(0, 5) &&
        vec_mag(vec_sub(topdown->boat->body.pos, buoy->body.pos)) < 1000) {
        new_boat = create_game_obj(BOAT3);
        if (new_boat) {
            MY_APPEND_TO_LIST(&(topdown->mercenary_boat), new_boat);
            set_game_object_pos(new_boat, buoy->body.pos);
        }
    }
}

static void generate_ally_boat(game_obj_t *buoy, topdown_t *topdown,
                                                        tool_t *tool)
{
    static sfBool key_pressed = sfFalse;
    game_obj_t *boat = topdown->boat;
    game_obj_t *new_boat = NULL;

    if (!is_game_object_collision(boat, buoy))
        return;
    if (!has_comp(boat, XP) || comp_value(boat, XP)->i < 20)
        return;
    if (!sfKeyboard_isKeyPressed(tool->player.control.keys[CONTROL_USE]))
        key_pressed = sfFalse;
    else
        key_pressed = sfTrue;
    if (key_pressed) {
        new_boat = create_game_obj(BOAT4);
        if (new_boat) {
            comp_value(boat, XP)->i -= 20;
            MY_APPEND_TO_LIST(&(topdown->ally_boat), new_boat);
            set_game_object_pos(new_boat, buoy->body.pos);
        }
    }
}

static void generate_golden_boat(game_obj_t *buoy, topdown_t *topdown,
                                    __attribute__((unused)) tool_t *tool)
{
    game_obj_t *boat = topdown->boat;
    game_obj_t *new_boat = NULL;

    if (!has_comp(boat, DEAD_COUNTER))
        return;
    if (comp_value(boat, DEAD_COUNTER)->i < 100)
        return;
    if (!get_randomnb(0, 100)) {
        new_boat = create_game_obj(BOAT5);
        if (new_boat) {
            MY_APPEND_TO_LIST(&(topdown->golden_boat), new_boat);
            set_game_object_pos(new_boat, buoy->body.pos);
        }
    }
}

void generate_new_boat(game_obj_t *buoy, topdown_t *topdown, tool_t *tool)
{
    int index = select_new_boat(buoy);

    if (index == -1)
        return ;
    redirect_generate_boat[index](buoy, topdown, tool);
}