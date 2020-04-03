/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** find_game_object
*/

#include "game_object.h"

game_obj_t *find_game_object(game_obj_t *list, elem_t type)
{
    game_obj_t *tmp = list;

    while (tmp && tmp->type != type)
        tmp = tmp->next;
    return (tmp);
}