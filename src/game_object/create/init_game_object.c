/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** Inits a game_obj.
*/

#include "init_game_object.h"
#include "construct_game_object_component.h"
#include "game_object_constructor.h"
#include "my.h"

static sfBool fill_game_object_components(game_obj_t *obj)
{
    register size_t index = 0;
    storage_type_e type = TYPE_END;
    comp_constructor_t comp_structor;

    do {
        comp_structor = comp_constructor_list[obj->type][index++];
        type = comp_structor.storage_type;
        if (type && !(construct_comp[type](obj, comp_structor)))
            return (sfFalse);
    } while (type);
    return (sfTrue);
}

static sfBool fill_game_object_core(game_obj_t *obj)
{
    size_t state_nb = 0;

    if (!obj)
        return (sfFalse);
    state_nb = constructor_list[obj->type].state_nb;
    if (!set_frame_nb(obj, constructor_list[obj->type].frame_nb, state_nb) ||
        !set_texture(obj, constructor_list[obj->type].path) ||
        !set_view_box(obj, constructor_list[obj->type].view_box, state_nb) ||
        !set_sprite(obj) ||
        !set_origin(obj, constructor_list[obj->type].origin, state_nb))
        return (sfFalse);
    obj->body.mass = constructor_list[obj->type].mass;
    return (sfTrue);
}

sfBool init_game_object(game_obj_t *obj)
{
    if (!alloc_component_array(obj))
        return (sfFalse);
    if (!fill_game_object_core(obj))
        return (sfFalse);
    if (constructor_list[obj->type].has_comp &&
        !fill_game_object_components(obj))
        return (sfFalse);
    return (sfTrue);
}