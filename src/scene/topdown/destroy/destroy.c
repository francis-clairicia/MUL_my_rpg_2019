/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroy
*/

#include "destroy_topdown.h"

void destroy_topdown(tool_t *tool, topdown_t *topdown)
{
    destroy_topdown_boat(tool, topdown);
    destroy_topdown_map(topdown);
    destroy_topdown_bullets(topdown);
}