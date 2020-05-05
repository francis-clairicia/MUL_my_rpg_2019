/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_put_node_as_end
*/

#include "mylist.h"

void my_put_node_as_end(list_t **list, list_t *node)
{
    list_t *last_node = NULL;
    if (!list || !node || !(*list) || (*list)->previous == node)
        return;
    if (!my_find_node(*list, node, NULL))
        return;
    last_node = (*list)->previous;
    if (*list == node) {
        if ((*list)->next == NULL)
            return;
        *list = (*list)->next;
    } else {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }
    node->previous = last_node;
    node->next = NULL;
    last_node->next = node;
    (*list)->previous = node;
}