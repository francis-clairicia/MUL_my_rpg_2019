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

typedef struct config
{
    char on_txt;
    int element;
} config_t;

list_t *load_file_with_config(char const *file, const config_t config_table[]);
list_t *create_list_from_array(char * const *array,
    const config_t config_table[]);

#endif /* !LOADER_H_ */
