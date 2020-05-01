/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_frame_nb
*/

#include <stdlib.h>
#include "my.h"
#include "game_object.h"

sfBool set_frame_nb(game_obj_t *obj, unsigned int *nb, size_t size)
{
    register size_t index = 0;

    obj->frame_nb = malloc(sizeof(int) * size);
    if (!(obj->frame_nb))
        return (sfFalse);
    for (index = 0; index < size; index += 1) {
        obj->frame_nb[index] = nb[index];
        if (!(obj->frame_nb[index])) {
            my_printf("Game object frame_nb must be > 1\n");
            return (sfFalse);
        }
    }
    return (sfTrue);
}