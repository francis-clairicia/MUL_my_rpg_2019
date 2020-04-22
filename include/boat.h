/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** boat.h
*/

#ifndef HEADER_BOAT
#define HEADER_BOAT

#include "mylist.h"
#include "game_object.h"

typedef struct boat_config
{
    char const *variable;
    char on_txt;
    int element;
} boat_config_t;

list_t *load_boat_from_file(char const *file);

static inline int get_element(boat_config_t config_table[], char c)
{
    int i = 0;

    for (i = 0; config_table && config_table[i].variable != NULL; i += 1) {
        if (config_table[i].on_txt == c)
            return (config_table[i].element);
    }
    return (-1);
}

#endif