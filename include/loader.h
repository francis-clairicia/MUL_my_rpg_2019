/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loader
*/

#ifndef LOADER_H_
#define LOADER_H_

#include "mylist.h"
#include "game_object.h"

typedef struct load_config
{
    char const *variable;
    char on_txt;
    int element;
} load_config_t;

list_t *load_config_from_file(char const *file, load_config_t config_table[]);

static inline int get_element(load_config_t config_table[], char c)
{
    int i = 0;

    for (i = 0; config_table && config_table[i].variable != NULL; i += 1) {
        if (config_table[i].on_txt == c)
            return (config_table[i].element);
    }
    return (-1);
}

#endif /* !LOADER_H_ */
