/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_buoys
*/

#include "update_topdown.h"
#include "math_process.h"

void update_topdown_buoys(tool_t *tool, topdown_t *topdown)
{
    list_t *list = topdown->map;
    game_obj_t *obj = NULL;

    if (!sfKeyboard_isKeyPressed(tool->player.control.keys[CONTROL_USE]) &&
        get_randomnb(0, 2 / tool->dtime))
        return;
    for (;list; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        if (obj->type >= BUOY1 && obj->type <= BUOY4) {
            generate_new_boat(obj, topdown, tool);
        }
        if (obj->type == WATER)
            break;
    }
}