/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_object_constructor
*/

#ifndef GAME_OBJECT_CONSTRUCTOR_H_
#define GAME_OBJECT_CONSTRUCTOR_H_

#include <stdbool.h>
#include "game_object.h"

typedef enum storage_type_e
{
    TYPE_END = 0,
    TYPE_CLOCK,
    TYPE_IMAGE,
    TYPE_TEXT,
    TYPE_SOUND,
    TYPE_VECTOR_2I,
    TYPE_VECTOR_2F,
    TYPE_INT_RECT,
    TYPE_INT,
    TYPE_FLOAT
} storage_type_e;

typedef struct game_object_constructor_s
{
    char *path;
    unsigned int frame_nb;
    sfVector2f origin;
    sfIntRect view_box;
    float mass;
    bool has_comp;
} game_obj_constructor_t;

typedef struct comp_constructor_s
{
    storage_type_e storage_type;
    prop_t type;
    void *data;
    void *data2;
} comp_constructor_t;

extern const game_obj_constructor_t constructor_list[];
extern const comp_constructor_t *comp_constructor_list[];

#endif /* !GAME_OBJECT_CONSTRUCTOR_H_ */