/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_boat_param
*/

#include "game_object.h"

void update_boat_size(list_t *boat)
{
    game_obj_t *first_obj = NULL;
    game_obj_t *left_boat = find_game_object_lowest_x(boat);
    game_obj_t *right_boat = find_game_object_highest_x(boat);
    game_obj_t *up_boat = find_game_object_lowest_y(boat);
    game_obj_t *down_boat = find_game_object_highest_y(boat);
    sfVector2f size = VEC2F(0, 0);

    if (!boat || !left_boat || !right_boat || !up_boat || !down_boat)
        return;
    first_obj = NODE_DATA(boat, game_obj_t *);
    size.x = right_boat->body.pos.x  +
            (right_boat->view_box[right_boat->state].width -
            right_boat->origin[right_boat->state].x);
    size.x -= (left_boat->body.pos.x - left_boat->origin[left_boat->state].x);
    size.y = down_boat->body.pos.y +
            (down_boat->view_box[down_boat->state].height -
            down_boat->origin[down_boat->state].y);
    size.y -= (up_boat->body.pos.y - up_boat->origin[up_boat->state].y);
    first_obj->comp[find_comp(first_obj, SIZE)]->v2f = size;
}