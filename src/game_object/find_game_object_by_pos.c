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