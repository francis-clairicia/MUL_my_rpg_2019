/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** set_lapse
*/

#include <stdlib.h>
#include "my.h"
#include "game_object.h"

sfBool set_lapse(game_obj_t *obj, unsigned int *nb, size_t size)
{
    obj->lapse = malloc(sizeof(int) * size);
    if (!(obj->lapse))
        return (sfFalse);
    if (nb) {
        my_memcpy(obj->lapse, nb, size);
    }
    return (sfTrue);
}