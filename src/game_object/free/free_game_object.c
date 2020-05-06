/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free_game_object
*/

#include <stdlib.h>
#include "game_object.h"

static void free_sound(component_t *comp)
{
    sfSoundBuffer *sb = NULL;

    sb = (sfSoundBuffer *)sfSound_getBuffer(comp->sound);
    if (sb)
        sfSoundBuffer_destroy(sb);
    sfSound_destroy(comp->sound);
}

sfBool free_comp(component_t *comp)
{
    if (!comp)
        return (sfFalse);
    if (comp->clock)
        sfClock_destroy(comp->clock);
    if (comp->image)
        sfImage_destroy(comp->image);
    if (comp->text)
        sfText_destroy(comp->text);
    if (comp->sound)
        free_sound(comp);
    return (sfTrue);
}

sfBool free_all_comp(game_obj_t *obj)
{
    register size_t index = 0;

    if (!obj || !(obj->comp))
        return (sfFalse);
    while (obj->comp[index]) {
        free_comp(obj->comp[index]);
        free(obj->comp[index]);
        index += 1;
    }
    free(obj->comp);
    return (sfTrue);
}

void free_game_object(game_obj_t *obj)
{
    if (!obj)
        return;
    free_all_comp(obj);
    if (obj->sprite)
        sfSprite_destroy(obj->sprite);
    if (obj->texture)
        sfTexture_destroy(obj->texture);
    if (obj->view_box)
        free(obj->view_box);
    if (obj->origin)
        free(obj->origin);
    if (obj->frame_nb)
        free(obj->frame_nb);
    if (obj->lapse)
        free(obj->lapse);
    free(obj);
}

sfBool free_game_object_list(game_obj_t *obj)
{
    game_obj_t *tmp = obj;

    if (!obj)
        return (sfFalse);
    do {
        tmp = obj;
        obj = obj->next;
        if (tmp)
            free_game_object(tmp);
    } while (obj);
    return (sfTrue);
}