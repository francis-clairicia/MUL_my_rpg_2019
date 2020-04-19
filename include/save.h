/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** save.h
*/

#ifndef RPG_SAVES_H_
#define RPG_SAVES_H_

#include <stdbool.h>
#include "constants.h"

typedef struct save
{
    bool used;
    char const *folder;
} save_t;

static const char * const save_folders[] = {
    SAVE_FOLDER "save01",
    SAVE_FOLDER "save02",
    SAVE_FOLDER "save03"
};

bool load_all_saves(save_t saves[3]);

#endif