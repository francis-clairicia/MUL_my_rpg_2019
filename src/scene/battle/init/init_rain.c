/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_rain
*/

#include "battle.h"
#include "my.h"

sfBool init_battle_rain(tool_t *tool, battle_t *battle)
{
    game_obj_t *obj = NULL;

    battle->rain = my_list(1, create_game_obj(RAIN));
    if ((!battle->rain))
        return (sfFalse);
    obj = NODE_DATA(battle->rain, game_obj_t *);
    set_game_object_pos(obj, VEC2F(0, 0));
    expand_game_object_right(&(battle->rain), tool->size.x);
    expand_game_object_left(&(battle->rain), 0);
    return (sfTrue);
}