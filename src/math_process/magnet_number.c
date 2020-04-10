/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** magnet_number
*/

#include <stdbool.h>

static bool magner_neg_number(float *nb, const float offset,
                            const int acc, const float magnet)
{
    int modulo = (int)(acc * magnet);
    int sized_nb = (int)(*nb * acc);

    if ((-sized_nb % modulo) >= (int)(acc * (magnet - offset))) {
        *nb -= (float)((acc * magnet) + sized_nb % modulo) / acc;
        return (true);
    } else if ((-sized_nb % modulo) <= (int)(offset * acc)) {
        *nb += (float)(-sized_nb % modulo) / acc;
        return (true);
    }
    return (false);
}

static bool magner_pos_number(float *nb, const float offset,
                            const int acc, const float magnet)
{
    int modulo = (int)(acc * magnet);
    int sized_nb = (int)(*nb * acc);

    if (sized_nb % modulo >= (int)(acc * (magnet - offset))) {
        *nb += (float)((acc * magnet) - sized_nb % modulo) / acc;
        return (true);
    } else if (sized_nb % modulo <= (int)(offset * acc)) {
        *nb -= (float)(sized_nb % modulo) / acc;
        return (true);
    }
    return (false);
}

bool magnet_number(float *nb, const float offset,
                    const int acc, const float magnet)
{
    if (!nb || !acc || !magnet)
        return;
    if (*nb >= 0) {
        return (magner_pos_number(nb, offset, acc, magnet));
    } else {
        return (magner_neg_number(nb, offset, acc, magnet));
    }
    return (false);
}