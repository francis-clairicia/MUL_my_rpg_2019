/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_component
*/

#include <stdlib.h>
#include "my.h"
#include "game_object_constructor.h"

component_t *add_comp(game_obj_t *obj, prop_t type)
{
    component_t *new_prop = malloc(sizeof(component_t));
    register size_t index = 0;

    while (obj->comp[index] && index < obj->comp_nb)
        index += 1;
    if (!new_prop)
        return (NULL);
    my_memset((char *)new_prop, '\0', sizeof(component_t));
    new_prop->type = type;
    obj->comp[index] = new_prop;
    return (new_prop);
}

size_t get_component_nb(elem_t type)
{
    size_t index = 0;

    while (comp_constructor_list[type][index].storage_type) {
        index += 1;
    }
    return (index);
}

sfBool alloc_component_array(game_obj_t *obj)
{
    if (!obj)
        return (sfFalse);
    obj->comp_nb = get_component_nb(obj->type);
    obj->comp = malloc(sizeof(component_t *) * (obj->comp_nb + 1));
    if (!(obj->comp))
        return (sfFalse);
    my_memset(obj->comp, 0, sizeof(component_t *) * (obj->comp_nb + 1));
    return (sfTrue);
}