/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** attack
*/

#include "game_object.h"

void game_object_attack(game_obj_t *obj, void (*attack_func)(game_obj_t *))
{
    sfClock *clock = NULL;
    sfTime time = {0};

    if (!obj || !attack_func)
        return;
    clock = obj->comp[find_comp(obj, ATTACK_TIME)]->clock;
    if (!clock)
        return;
    time = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(time) > obj->comp[find_comp(obj, ATTACK_SPEED)]->f) {
        reset_comp_clock(obj, ATTACK_TIME);
        obj->comp[find_comp(obj, CAN_ATTACK)]->i = 1;
        attack_func(obj);
    }
}