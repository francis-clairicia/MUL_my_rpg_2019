/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_game_object
*/

#include "game_object.h"

void update_hitbox(game_obj_t *obj)
{
    int view_box_index = get_game_object_state(obj);

    obj->hitbox.left = obj->body.pos.x;
    obj->hitbox.top = obj->body.pos.y;
    obj->hitbox.width = obj->view_box[view_box_index].width;
    obj->hitbox.height = obj->view_box[view_box_index].height;
}