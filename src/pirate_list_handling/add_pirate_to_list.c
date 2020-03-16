/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** add_pirate_to_list.c
*/

#include "pirates.h"

sfBool add_pirate_to_list(pirate_list_t **head, pirate_list_t *pirate)
{
    if (!head || !pirate)
        return (sfFalse);
    if (!(*head)) {
        pirate->next = pirate;
        pirate->prev = pirate;
        *head = pirate;
    } else {
        pirate->next = *head;
        pirate->prev = (*head)->prev;
        (*head)->prev->next = pirate;
        (*head)->prev = pirate;
    }
    return (sfTrue);
}