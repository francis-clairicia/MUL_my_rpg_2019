/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** construct_game_object_component
*/

#ifndef INIT_COMP_GAME_OBJECT_H_
#define INIT_COMP_GAME_OBJECT_H_

#include "game_object_constructor.h"

sfBool construct_clock(game_obj_t *obj, comp_constructor_t constructor);
sfBool construct_image(game_obj_t *obj, comp_constructor_t constructor);
sfBool construct_text(game_obj_t *obj, comp_constructor_t constructor);
sfBool construct_sound(game_obj_t *obj, comp_constructor_t constructor);
sfBool construct_v2i(game_obj_t *obj, comp_constructor_t constructor);
sfBool construct_v2f(game_obj_t *obj, comp_constructor_t constructor);
sfBool construct_irect(game_obj_t *obj, comp_constructor_t constructor);
sfBool construct_i(game_obj_t *obj, comp_constructor_t constructor);
sfBool construct_f(game_obj_t *obj, comp_constructor_t constructor);

static sfBool (*construct_comp[])(game_obj_t *obj,
                        comp_constructor_t constructor) = {
    [0] = NULL,
    [TYPE_CLOCK] = construct_clock,
    [TYPE_IMAGE] = construct_image,
    [TYPE_TEXT] = construct_text,
    [TYPE_SOUND] = construct_sound,
    [TYPE_VECTOR_2I] = construct_v2i,
    [TYPE_VECTOR_2F] = construct_v2f,
    [TYPE_INT_RECT] = construct_irect,
    [TYPE_INT] = construct_i,
    [TYPE_FLOAT] = construct_f
};

#endif /* !INIT_COMP_GAME_OBJECT_H_ */