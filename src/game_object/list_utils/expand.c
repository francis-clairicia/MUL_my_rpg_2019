/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** expand_game_object
*/

#include "game_object.h"

void expand_game_object_right(list_t **list, float offset)
{
    game_obj_t *obj = NULL;
    game_obj_t *new_obj = NULL;

    if (!list || !(*list))
        return ;
    obj = NODE_DATA((*list)->previous, game_obj_t *);
    if (!obj)
        return ;
    if (obj->body.pos.x + obj->origin[obj->state].x < offset) {
        new_obj = create_game_obj(obj->type);
        if (!new_obj)
            return ;
        set_game_object_pos(new_obj, VEC2F(
                            obj->body.pos.x + obj->view_box[0].width,
                            obj->body.pos.y));
        MY_APPEND_TO_LIST(list, new_obj);
        expand_game_object_right(list, offset);
    }
}

void expand_game_object_left(list_t **list, float offset)
{
    game_obj_t *obj = NULL;
    game_obj_t *new_obj = NULL;

    if (!list || !(*list))
        return ;
    obj = NODE_DATA((*list), game_obj_t *);
    if (!obj)
        return ;
    if (obj->body.pos.x > offset) {
        new_obj = create_game_obj(obj->type);
        if (!new_obj)
            return ;
        set_game_object_pos(new_obj, VEC2F(
                            obj->body.pos.x - obj->view_box[0].width,
                            obj->body.pos.y));
        MY_PUT_IN_LIST(list, new_obj);
        expand_game_object_left(list, offset);
    }
}