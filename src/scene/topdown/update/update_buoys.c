/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_buoys
*/

#include "update_topdown.h"
#include "math_process.h"

static elem_t get_type_from_buoy(game_obj_t *buoy)
{
    elem_t boat_type = -1;

    switch (buoy->type) {
        case BUOY1:
            boat_type = BOAT2;
            break;
        case BUOY2:
            boat_type = BOAT3;
            break;
        case BUOY3:
            boat_type = BOAT4;
            break;
        case BUOY4:
            boat_type = BOAT5;
            break;
        default:
            break;
    }
    return (boat_type);
}

static void generate_new_boat(game_obj_t *buoy, topdown_t *topdown)
{
    game_obj_t *new_boat = create_game_obj(get_type_from_buoy(buoy));

    if (!new_boat)
        return;
    set_game_object_pos(new_boat, buoy->body.pos);
    if (new_boat->type == BOAT2)
        MY_APPEND_TO_LIST(&(topdown->ennemy_boat), new_boat);
    if (new_boat->type == BOAT3)
        MY_APPEND_TO_LIST(&(topdown->mercenary_boat), new_boat);
    if (new_boat->type == BOAT4)
        MY_APPEND_TO_LIST(&(topdown->ally_boat), new_boat);
    if (new_boat->type == BOAT5)
        MY_APPEND_TO_LIST(&(topdown->golden_boat), new_boat);
}

void update_topdown_buoys(tool_t *tool, topdown_t *topdown)
{
    list_t *list = topdown->map;
    game_obj_t *obj = NULL;

    if (get_randomnb(0, 10 / tool->dtime))
        return;
    for (;list; list = list->next) {
        obj = NODE_DATA(list, game_obj_t *);
        if (!obj)
            continue;
        if ((obj->type == BUOY1 || obj->type == BUOY2) &&
            !get_randomnb(0, 3)) {
            generate_new_boat(obj, topdown);
            break;
        }
    }
}