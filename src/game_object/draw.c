/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_game_object
*/

#include "rpg.h"
#include "game_object.h"

void draw_game_object(sfRenderWindow *window, game_obj_t *obj)
{
    int state = 0;

    if (!window || !obj)
        return;
    state = obj->state;
    update_hitbox(obj);
    sfSprite_setPosition(obj->sprite, obj->body.pos);
    sfSprite_setTextureRect(obj->sprite, obj->view_box[state]);
    sfSprite_setRotation(obj->sprite, obj->body.angle);
    obj->hitbox = sfSprite_getGlobalBounds(obj->sprite);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}