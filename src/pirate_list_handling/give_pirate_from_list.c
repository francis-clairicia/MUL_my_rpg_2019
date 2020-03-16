/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Push a pirate from a list to another list.
*/

#include "pirate_list_functions.h"

sfBool give_pirate_from_list(pirate_list_t **source, pirate_list_t **dest,
                                pirate_list_t *pirate)
{
    if (!detach_pirate_from_list(source, pirate))
        return (sfFalse);
    if (!add_pirate_to_list(dest, pirate))
        return (sfFalse);
    return (sfTrue);
}