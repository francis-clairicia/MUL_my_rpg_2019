/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** A header for different existing items.
*/

#ifndef ITEMS_H_

#define ITEMS_H_

#include <unistd.h>

//A character's range options.
typedef enum range_options_e {
    MELEE,
    RANGE
} range_options_t;


//A weapon is categorized by:
//
//Its range method: MELEE or RANGE.
//
typedef struct weapon_s {
    range_options_t range_method;
    size_t range;
    size_t damage;
    double atk_speed;
} weapon_t;

typedef enum weapon_id_e {
    RIFFLE,
} weapon_id_t;

static const weapon_t weapons[] = {
    {.range_method = RANGE, .range = 200, .damage = 100, .atk_speed = 1.35}
};

#endif /* ITEMS_H_ */