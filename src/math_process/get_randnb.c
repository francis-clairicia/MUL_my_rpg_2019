/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_randnb
*/

#include <stdbool.h>
#include "stdlib.h"

int get_randomnb(int min, int max)
{
    static bool first_call = true;
    int nb = 0;

    if (first_call) {
        srand((size_t) &first_call);
        first_call == false;
    }
    if (max == min || max == 0)
        return (max);
    nb = rand() % (max - min) + min;
    return (nb);
