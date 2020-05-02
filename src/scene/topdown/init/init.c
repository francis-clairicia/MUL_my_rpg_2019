/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init
*/

#include "init_topdown.h"

sfBool init_topdown(topdown_t *topdown)
{
    if (!topdown)
        return (sfFalse);
    my_memset(topdown, 0, sizeof(topdown_t));
    if (!init_topdown_map(topdown) ||
        !init_topdown_boat(topdown))
        return (sfFalse);
    return (sfTrue);
}