/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_boat
*/

#include "topdown.h"

sfBool init_topdown_boat(topdown_t *topdown)
{
    topdown->boat = create_game_obj(BOAT1);
    if (!(topdown->boat))
        return (sfFalse);
    set_game_object_pos(topdown->boat, VEC2F(100, 100));
    return (sfTrue);
}