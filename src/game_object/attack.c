/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** attack
*/

#include "game_object.h"

sfBool can_game_object_attack(game_obj_t *obj)
{
    sfClock *clock = NULL;
    sfTime time = {0};

    if (!obj || !has_comp(obj, ATTACK_TIME) || !has_comp(obj, ATTACK_SPEED))
        return (sfFalse);
    clock = obj->comp[find_comp(obj, ATTACK_TIME)]->clock;
    if (!clock)
        return (sfFalse);
    time = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(time) > obj->comp[find_comp(obj, ATTACK_SPEED)]->f) {
        reset_comp_clock(obj, ATTACK_TIME);
        return (sfTrue);
    }
    return (sfFalse);
}