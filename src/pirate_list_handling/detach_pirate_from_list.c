/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Detaches a pirate node from a list.
*/

#include "pirates.h"

sfBool detach_pirate_from_list(pirate_list_t **head, pirate_list_t *pirate)
{
    if (!head || !(*head))
        return (sfFalse);
    if (*head == (*head)->next)
        *head = NULL;
    else {
        (*head)->prev->next = pirate->prev;
        if ((*head)->prev == pirate)
            (*head)->prev = pirate->prev;
        pirate->prev->next = pirate->next;
        pirate->next->prev = pirate->prev;
    }
    pirate->next = pirate;
    pirate->prev = pirate;
    return (sfTrue);
}