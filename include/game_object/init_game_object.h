/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_game_object
*/

#ifndef INIT_GAME_OBJECT_H_
#define INIT_GAME_OBJECT_H_

#include "game_object.h"

//Core function for game object initializing
sfBool init_game_object(game_obj_t *obj);

//Allocates a new component and set the type
component_t *add_comp(game_obj_t *obj, prop_t type);

//Allocates a new array of component and fills it with NULL
sfBool alloc_component_array(game_obj_t *obj);

//Returns the number of component for a given game object type
size_t get_component_nb(elem_t type);

//Generic fonction that redirect to set_comp function below
sfBool set_sprite(game_obj_t *obj);
sfBool set_texture(game_obj_t *obj, char *path);
sfBool set_view_box(game_obj_t *obj, sfIntRect *rect);
sfBool set_frame_nb(game_obj_t *obj, unsigned int nb);
sfBool set_origin(game_obj_t *obj, sfVector2f origin);

#endif /* !INIT_GAME_OBJECT_H_ */