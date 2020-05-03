/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** find_game_object_in_list
*/

#include "game_object.h"

game_obj_t *find_game_object_lowest_y(list_t *list)
{
    game_obj_t *obj = NULL;
    game_obj_t *save = NULL;
    float best_pos = __FLT_MAX__;

    if (!list)
        return (NULL);
    for (; list && list->data; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        if (obj->body.pos.y < best_pos) {
            save = obj;
            best_pos = obj->body.pos.y;
        }
    }
    return (save);
}

game_obj_t *find_game_object_highest_y(list_t *list)
{
    game_obj_t *obj = NULL;
    game_obj_t *save = NULL;
    float best_pos = __FLT_MIN__;

    if (!list)
        return (NULL);
    for (; list && list->data; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        if (obj->body.pos.y > best_pos) {
            save = obj;
            best_pos = obj->body.pos.y;
        }
    }
    return (save);
}

game_obj_t *find_game_object_lowest_x(list_t *list)
{
    game_obj_t *obj = NULL;
    game_obj_t *save = NULL;
    float best_pos = __FLT_MAX__;

    if (!list)
        return (NULL);
    for (; list && list->data; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        if (obj->body.pos.x < best_pos) {
            save = obj;
            best_pos = obj->body.pos.x;
        }
    }
    return (save);
}

game_obj_t *find_game_object_highest_x(list_t *list)
{
    game_obj_t *obj = NULL;
    game_obj_t *save = NULL;
    float best_pos = __FLT_MIN__;

    if (!list)
        return (NULL);
    for (; list && list->data; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        if (obj->body.pos.x > best_pos) {
            save = obj;
            best_pos = obj->body.pos.x;
        }
    }
    return (save);
}

game_obj_t *find_closest_game_object(game_obj_t *obj, list_t *list)
{
    float best_dist = __FLT_MAX__;
    game_obj_t *tmp = NULL;
    game_obj_t *save = NULL;
    sfVector2f pos = VEC2F(0, 0);
    float magn = 0;

    if (!obj)
        return (NULL);
    for (; list && list->data; list = list->next) {
        tmp = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        pos = vec_sub(obj->body.pos, tmp->body.pos);
        magn = vec_mag(pos);
        if (magn < best_dist) {
            best_dist = magn;
            save = tmp;
        }
    }
    return (save);
}