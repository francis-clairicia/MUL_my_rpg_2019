/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_boat
*/

#ifndef GENERATE_BOAT_H_
#define GENERATE_BOAT_H_


#include "update_topdown.h"

static const elem_t boat_template[] = {
    BUOY1, BUOY2, BUOY3, BUOY4, 0
};

static inline int select_new_boat(game_obj_t *buoy)
{
    int index = 0;

    for (; boat_template[index]; index += 1) {
        if (boat_template[index] == buoy->type)
            return (index);
    }
    return (-1);
}

static void generate_golden_boat(game_obj_t *buoy, topdown_t *topdown,
                                                            tool_t *tool);
static void generate_mercenary_boat(game_obj_t *buoy, topdown_t *topdown,
                                                            tool_t *tool);
static void generate_ennemy_boat(game_obj_t *buoy, topdown_t *topdown,
                                                            tool_t *tool);
static void generate_ally_boat(game_obj_t *buoy, topdown_t *topdown,
                                                            tool_t *tool);

static void (*redirect_generate_boat[])(game_obj_t *, topdown_t *, tool_t *) = {
    generate_ennemy_boat,
    generate_mercenary_boat,
    generate_ally_boat,
    generate_golden_boat,
};

#endif /* !GENERATE_BOAT_H_ */