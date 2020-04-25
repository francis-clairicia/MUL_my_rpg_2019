/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_water
*/

#include "battle.h"
#include "my.h"

sfBool init_battle_water(tool_t *tool, battle_t *battle)
{
    game_obj_t *obj = NULL;

    battle->water = my_list(1, create_game_obj(WATER2));
    if (!(battle->water))
        return (sfFalse);
    obj = NODE_DATA(battle->water, game_obj_t *);
    set_game_object_pos(obj, VEC2F(0, tool->size.y - obj->origin[0].y));
    expand_game_object_right(&(battle->water), tool->size.x);
    expand_game_object_left(&(battle->water), 0);
    return (sfTrue);
}