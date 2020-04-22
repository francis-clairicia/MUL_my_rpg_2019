/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** player.h
*/

#ifndef RPG_PLAYER_H_
#define RPG_PLAYER_H_

#include "mylist.h"
#include "save.h"

typedef struct player
{
    char *pseudo;
    save_t save;
    list_t *crew;
    list_t *boat;
    sfVector2f pos;
} player_t;

#endif