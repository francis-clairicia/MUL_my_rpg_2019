/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** player.h
*/

#ifndef RPG_PLAYER_H_
#define RPG_PLAYER_H_

#include <SFML/System/Vector2.h>
#include "mylist.h"
#include "save.h"
#include "control.h"

typedef struct player
{
    control_t control;
    char *pseudo;
    save_t save;
    list_t *crew;
    list_t *boat;
    sfVector2f pos;
} player_t;

sfBool init_control(player_t *player);

#endif