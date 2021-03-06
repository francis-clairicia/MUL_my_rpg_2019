/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** topdown
*/

#ifndef TOPDOWN_H_
#define TOPDOWN_H_

#include "rpg.h"
#include "game_object.h"

struct zoom_s
{
    float actual;
    float min;
    float max;
};

typedef struct topdown_s
{
    game_obj_t *boat;
    list_t *bullets;
    list_t *ally_boat;
    list_t *ennemy_boat;
    list_t *mercenary_boat;
    list_t *golden_boat;
    list_t *map;
    sfVector2f map_size;
    struct zoom_s zoom;
} topdown_t;

sfBool init_topdown(tool_t *tool, topdown_t *topdown);

void update_topdown(tool_t *tool, topdown_t *topdown, scene_t *state);

void draw_topdown(tool_t *tool, topdown_t topdown);

void destroy_topdown(topdown_t *topdown);

#endif /* !TOPDOWN_H_ */