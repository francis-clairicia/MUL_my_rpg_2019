/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buoyancy_force
*/

#include "game_object.h"

static float is_diving(list_t *boat_list, list_t *water_list)
{
    game_obj_t *boat = NODE_DATA(boat_list, game_obj_t *);
    game_obj_t *water = NODE_DATA(water_list, game_obj_t *);
    float water_y = 0;
    float boat_y = 0;

    if (!boat || !water)
        return (0);
    boat_y = boat->body.pos.y + boat->comp[find_comp(boat, SIZE)]->v2f.y -
                                                boat->origin[boat->state].y;
    water_y = water->body.pos.y - water->origin[water->state].y;
    return ((boat_y - water_y));
}

static float get_boat_width(list_t *boat_list)
{
    game_obj_t *boat = NODE_DATA(boat_list, game_obj_t *);
    float width = 0;

    if (!boat)
        return (0);
    width = boat->comp[find_comp(boat, SIZE)]->v2f.x;
    return (width);
}

void buoyancy_boat_water(list_t *boat, list_t *water)
{
    float depth = 0;
    float boat_width = 0;
    sfVector2f buoyancy = VEC2F(0, -GRAVITY);

    if (!boat || !water)
        return ;
    depth = is_diving(boat, water);
    boat_width = get_boat_width(boat);
    if (depth <= 0 || boat_width <= 0)
        return ;
    buoyancy = vec_mult(buoyancy, depth * boat_width);
    body_list(boat, apply_force_ptr, &buoyancy);
}