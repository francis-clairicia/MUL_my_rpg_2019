/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** add_game_obj_to_list
*/

#include "game_object.h"

sfBool add_game_obj_to_list(game_obj_t **list, const elem_t element)
{
    game_obj_t *obj = NULL;
    game_obj_t *tmp = NULL;

    if (!list)
        return (sfFalse);
    obj = create_game_obj(element);
    if (!obj)
        return (sfFalse);
    if (!(*list))
        (*list) = obj;
    else {
        for (tmp = (*list); tmp->next; tmp = tmp->next);
        tmp->next = obj;
    }
    return (sfTrue);
}