/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** animate
*/

#include "game_object.h"

void anime_game_object(game_obj_t *obj)
{
    sfClock *clock = obj->comp[find_comp(obj, CLOCK)]->clock;
    sfUint32 msecond = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    unsigned int state = obj->state;
    unsigned int lapse = 0;
    unsigned int frame = 0;

    if (!(obj->view_box[state].width) || !clock || !(obj->lapse))
        return ;
    lapse = obj->lapse[state];
    frame = obj->view_box[state].left / obj->view_box[state].width;
    if (lapse * (frame + 1) < msecond &&
        lapse * (frame + 2) > msecond &&
        obj->view_box[state].left == (int)frame * obj->view_box[state].width)
        obj->view_box[state].left += obj->view_box[state].width;
    if (lapse * obj->frame_nb[state] < msecond) {
        sfClock_restart(clock);
        obj->view_box[state].left = 0;
    }
}

void anime_game_object_ptr(game_obj_t *obj, __attribute__((unused))void *data)
{
    sfClock *clock = obj->comp[find_comp(obj, CLOCK)]->clock;
    int state = obj->state;
    sfUint32 msecond = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    int frame = 0;
    int lapse = 0;

    if (!(obj->view_box[state].width) || !clock || !(obj->lapse))
        return ;
    lapse = obj->lapse[state];
    frame = obj->view_box[state].left / obj->view_box[state].width;
    if (lapse * (frame + 1) < (int)msecond &&
        lapse * (frame + 2) > (int)msecond &&
        obj->view_box[state].left == frame * obj->view_box[state].width)
        obj->view_box[state].left += obj->view_box[state].width;
    if (lapse * (int)obj->frame_nb[state] < (int)msecond) {
        sfClock_restart(clock);
        obj->view_box[state].left = 0;
    }
}