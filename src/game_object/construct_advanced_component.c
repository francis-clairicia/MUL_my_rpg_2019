/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** construct_advanced_component
*/

#include <stdlib.h>
#include "my.h"
#include "game_object.h"
#include "game_object_constructor.h"
#include "init_game_object.h"

sfBool construct_clock(game_obj_t *obj, comp_constructor_t constructor)
{
    prop_t prop = constructor.type;

    if (!add_comp(obj, prop))
        return (sfFalse);
    return (set_comp_clock(obj, prop));
}

sfBool construct_text(game_obj_t *obj, comp_constructor_t constructor)
{
    prop_t prop = constructor.type;
    sfBool error = sfFalse;

    if (!(constructor.data) || !(constructor.data2))
        return (sfFalse);
    if (!add_comp(obj, prop))
        return (sfFalse);
    error = set_comp_text(obj, prop, (char *)constructor.data,
                                    *((int *)constructor.data2));
    return (error);
}

sfBool construct_sound(game_obj_t *obj, comp_constructor_t constructor)
{
    prop_t prop = constructor.type;
    sfBool error = sfFalse;

    if (!(constructor.data) || !(constructor.data2))
        return (sfFalse);
    if (!add_comp(obj, prop))
        return (sfFalse);
    error = set_comp_sound(obj, prop, (char *)constructor.data,
                                    *((float *)constructor.data2));
    return (error);
}

sfBool construct_image(game_obj_t *obj, comp_constructor_t constructor)
{
    prop_t prop = constructor.type;
    sfBool error = sfFalse;

    if (!(constructor.data))
        return (sfFalse);
    if (!add_comp(obj, prop))
        return (sfFalse);
    error = set_comp_image(obj, prop, (char *)constructor.data);
    return (error);
}