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

#define CONFIG_SAVE_FILE "save.conf"
#define PSEUDO_SAVE_FILE "pseudo.sav"
#define CONTROL_SAVE_FILE "controls.sav"

bool load_all_saves(save_t saves[3]);
bool load_one_save(save_t *save, char const *folder);

#endif