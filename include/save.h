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
#define DATA_SAVE_FILE "data.sav"
#define CONTROL_SAVE_FILE "controls.sav"
#define BOAT_SAVE_FILE "boat.sav"

bool load_one_save(save_t *save, char const *folder);

#endif