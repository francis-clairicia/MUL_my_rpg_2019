/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** A header for pirate lists related functions.
*/

#ifndef PIRATE_LIST_FUNC_H_

#define PIRATE_LIST_FUNC_H_

#include "pirates.h"

//Gives a pirate from a source list to a destination list.
//
//Returns sfTrue (1) if the trade correctly applied the pointer changes.
//Returns sfFalse (0) otherwise.
sfBool give_pirate_from_list(pirate_list_t **source,
                            pirate_list_t **destination,
                            pirate_list_t *pirate);

//Puts a given pirate a the end of a pirate list.
//
//Returns sfTrue (1) if success.
//Returns sfFalse (0) otherwise.
sfBool add_pirate_to_list(pirate_list_t **list, pirate_list_t *pirate);

//Detaches a pirate node from a list.
//
//Returns sfTrue (1) if success.
//Returns sfFalse (0) otherwise;
sfBool detach_pirate_from_list(pirate_list_t **list, pirate_list_t *pirate);

//Frees previously allocated memory for a pirate list.
//Automatically checks whether the memory can be freed before freeing it.
void free_pirate_list(pirate_list_t **head);

//Frees previously allocated memory for a single pirate.
//Automatically checks whether the memory can be freed before freeing it.
void free_pirate_node(pirate_list_t *node);

#endif /* PIRATE_LIST_FUNC_H_ */