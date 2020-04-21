/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_game_object
*/

#include "rpg.h"
#include "game_object.h"

void anime_game_object(game_obj_t *obj, const int lapse)
{
    sfClock *clock = obj->comp[find_comp(obj, CLOCK)]->clock;
    int state = obj->state;
    sfUint32 msecond = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    int frame = 0;

    if (!(obj->view_box[state].width) || !clock)
        return ;
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

void set_game_object_frame(game_obj_t *obj, unsigned int frame)
{
    int state = obj->state;

    if (!obj || obj->frame_nb[state] < frame)
        return ;
    obj->view_box[state].left = frame * obj->view_box[state].width;
}

void draw_game_object(sfRenderWindow *window, game_obj_t *obj)
{
    int state = obj->state;

    update_hitbox(obj);
    sfSprite_setPosition(obj->sprite, obj->body.pos);
    sfSprite_setTextureRect(obj->sprite, obj->view_box[state]);
    sfSprite_setRotation(obj->sprite, obj->body.angle);
    obj->hitbox = sfSprite_getGlobalBounds(obj->sprite);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}