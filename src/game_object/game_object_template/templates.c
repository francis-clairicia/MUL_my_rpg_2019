/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** templates
*/

#include "game_object_constructor.h"

const game_obj_constructor_t constructor_list[] = {
    [PIRATE] =
    {
        .path = "insert_path",
        .frame_nb = 3,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 100, 100),
        .mass = 20
    },
    [FLORIAN] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 100, 100),
        .mass = 1
    }
};

const comp_constructor_t *comp_constructor_list[] = {
    [PIRATE] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_CLOCK,
            .type = CLOCK
        },
        {
            .storage_type = TYPE_END
        }
    },
    [FLORIAN] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_CLOCK,
            .type = CLOCK
        },
        {
            .storage_type = TYPE_VECTOR_2F,
            .type = OFFSET,
            .data = (sfVector2f [1]){{10, 10}},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_SOUND,
            .type = SOUND,
            .data = "insert_path",
            .data2 = (int [1]){10}
            },
        {
            .storage_type = TYPE_END
        }
    }
};