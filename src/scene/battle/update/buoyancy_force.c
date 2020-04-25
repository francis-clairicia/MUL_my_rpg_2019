/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buoyancy_force
*/

#include "game_object.h"

static float is_diving(list_t *boat_list, list_t *water_list)
{
    game_obj_t *boat = find_game_object_highest_y(boat_list);
    game_obj_t *water = NODE_DATA(water_list, game_obj_t *);
    float water_y = 0;
    float boat_y = 0;

    if (!boat || !water)
        return (0);
    water_y = water->body.pos.y - water->origin[water->state].y;
    boat_y = boat->body.pos.y;
    boat_y += boat->view_box[boat->state].height - boat->origin[boat->state].y;
    return ((boat_y - water_y) / boat->view_box[boat->state].height);
}

static float get_boat_width(list_t *boat_list)
{
    game_obj_t *low_boat = find_game_object_lowest_x(boat_list);
    game_obj_t *high_boat = find_game_object_highest_x(boat_list);
    float boat_min_x = 0;
    float boat_max_x = 0;

    if (!low_boat || !high_boat || !(low_boat->view_box[low_boat->state].width))
        return (0);
    boat_min_x = low_boat->body.pos.x - low_boat->origin[low_boat->state].x;
    boat_max_x = high_boat->body.pos.y;
    boat_max_x += (high_boat->view_box[high_boat->state].width -
                            high_boat->origin[high_boat->state].x);
    return ((boat_max_x - boat_min_x) /
            low_boat->view_box[low_boat->state].width);
}

static float get_boat_density(list_t *boat_list)
{
    game_obj_t *boat = NODE_DATA(boat_list, game_obj_t *);

    if (!boat)
        return (0);
    return (boat->body.mass);
}

void buoyancy_boat_water(list_t *boat, list_t *water)
{
    float depth = 0;
    float boat_width = 0;
    float boat_density = 0;
    sfVector2f buoyancy = VEC2F(0, -98);

    if (!boat || !water)
        return ;
    depth = is_diving(boat, water);
    boat_width = get_boat_width(boat);
    boat_density = get_boat_density(boat);
    if (depth <= 0 || boat_width <= 0)
        return ;
    buoyancy = vec_mult(buoyancy, boat_density * depth * boat_width);
    body_list_vec2f(boat, apply_force, buoyancy);
}