/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** play_sound.c
*/

#include "game_object.h"

void play_game_object_sound(game_obj_t *obj, prop_t sound_type)
{
    sfSound *sound = NULL;

    if (!obj || !has_comp(obj, sound_type))
        return;
    sound = obj->comp[find_comp(obj, sound_type)]->sound;
    if (!sound)
        return;
    if (sfSound_getStatus(sound) != sfPlaying)
        sfSound_play(sound);
}