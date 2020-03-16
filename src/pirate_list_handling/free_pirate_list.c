/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Frees allocated memory for a pirate list.
*/

#include <stdlib.h>
#include "pirates.h"

void free_pirate_node(pirate_list_t *node)
{
    if (!node)
        return;
    if (node->name)
        free(node->name);
    free(node);
}

void free_pirate_list(pirate_list_t **head)
{
    pirate_list_t *ending_point = NULL;
    pirate_list_t *tmp = NULL;

    if (!head || !(*head))
        return;
    ending_point = (*head)->prev;
    for (tmp = *head; tmp != ending_point; tmp = tmp->next) {
        free_pirate_node(tmp);
        *head = (*head)->next;
    }
    free_pirate_node(tmp);
    *head = NULL;
}