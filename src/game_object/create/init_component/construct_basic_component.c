/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** construct_basic_component
*/

#include "my.h"
#include "game_object_constructor.h"
#include "init_game_object.h"

sfBool construct_irect(game_obj_t *obj, comp_constructor_t constructor)
{
    prop_t prop = constructor.type;
    sfBool error = sfTrue;

    if (!(constructor.data))
        return (sfFalse);
    if (!add_comp(obj, prop))
        return (sfFalse);
    error = set_comp_irect(obj, prop, *((sfIntRect *)constructor.data));
    return (error);
}

sfBool construct_v2f(game_obj_t *obj, comp_constructor_t constructor)
{
    prop_t prop = constructor.type;
    sfBool error = sfFalse;

    if (!(constructor.data))
        return (sfFalse);
    if (!add_comp(obj, prop))
        return (sfFalse);
    error = set_comp_v2f(obj, prop, *((sfVector2f *)constructor.data));
    return (error);
}

sfBool construct_v2i(game_obj_t *obj, comp_constructor_t constructor)
{
    prop_t prop = constructor.type;
    sfBool error = sfFalse;

    if (!(constructor.data))
        return (sfFalse);
    if (!add_comp(obj, prop))
        return (sfFalse);
    error = set_comp_v2i(obj, prop, *((sfVector2i *)constructor.data));
    return (error);
}

sfBool construct_f(game_obj_t *obj, comp_constructor_t constructor)
{
    prop_t prop = constructor.type;
    sfBool error = sfFalse;

    if (!(constructor.data))
        return (sfFalse);
    if (!add_comp(obj, prop))
        return (sfFalse);
    error = set_comp_float(obj, prop, *((float *)constructor.data));
    return (error);
}

sfBool construct_i(game_obj_t *obj, comp_constructor_t constructor)
{
    prop_t prop = constructor.type;
    sfBool error = sfFalse;

    if (!(constructor.data))
        return (sfFalse);
    if (!add_comp(obj, prop))
        return (sfFalse);
    error = set_comp_int(obj, prop, *((int *)constructor.data));
    return (error);
}