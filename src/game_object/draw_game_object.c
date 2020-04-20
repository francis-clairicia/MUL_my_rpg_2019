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
    int index = get_game_object_state(obj);
    sfUint32 msecond = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    int frame = 0;

    if (!(obj->view_box[index].width) || !clock)
        return ;
    frame = obj->view_box[index].left / obj->view_box[index].width;
    if (lapse * (frame + 1) < (int)msecond &&
        lapse * (frame + 2) > (int)msecond &&
        obj->view_box[index].left == frame * obj->view_box[index].width)
        obj->view_box[index].left += obj->view_box[index].width;
    if (lapse * (int)obj->frame_nb < (int)msecond) {
        sfClock_restart(clock);
        obj->view_box[index].left = 0;
    }
}

void set_game_object_frame(game_obj_t *obj, unsigned int frame)
{
    int index = get_game_object_state(obj);

    if (!obj || obj->frame_nb < frame)
        return ;
    obj->view_box[index].left = frame * obj->view_box[index].width;
}

void draw_game_object(sfRenderWindow *window, game_obj_t *obj)
{
    int view_box_index = get_game_object_state(obj);

    update_hitbox(obj);
    sfSprite_setPosition(obj->sprite, obj->body.pos);
    sfSprite_setTextureRect(obj->sprite, obj->view_box[view_box_index]);
    sfSprite_setRotation(obj->sprite, obj->body.angle);
    obj->hitbox = sfSprite_getGlobalBounds(obj->sprite);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}