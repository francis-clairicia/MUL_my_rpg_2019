/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_center
*/

#include "game_object.h"

sfVector2f get_game_objet_center(game_obj_t *obj)
{
    sfVector2f center = VEC2F(0, 0);
    sfVector2f size = VEC2F(0, 0);

    if (!obj)
        return (center);
    center = vec_sub(obj->body.pos, obj->origin[obj->state]);
    size = VEC2F(obj->view_box[obj->state].width,
                obj->view_box[obj->state].height);
    center = vec_add(center, vec_div(size, 2));
    return (center);
}