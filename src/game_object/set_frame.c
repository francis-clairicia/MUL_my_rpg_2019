/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_frame
*/

#include "game_object.h"

void set_game_object_frame(game_obj_t *obj, unsigned int frame)
{
    int state = obj->state;

    if (!obj || obj->frame_nb[state] < frame)
        return ;
    obj->view_box[state].left = frame * obj->view_box[state].width;
}

void set_game_object_frame_ptr(game_obj_t *obj, void *data)
{
    unsigned int frame = 0;
    int state = 0;

    if (!obj || !data)
        return ;
    state = obj->state;
    frame = *(unsigned int *)data;
    if (obj->frame_nb[state] < frame)
        return ;
    obj->view_box[state].left = frame * obj->view_box[state].width;
}