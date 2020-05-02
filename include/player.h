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
    char pseudo[21];
    save_t save;
    list_t *crew;
    list_t *boat;
    sfVector2f pos;
} player_t;

bool init_player(player_t *player, save_t save);
void destroy_player(player_t *player);
bool save_player_data(player_t *player);

typedef bool (*player_field_init_t)(player_t *);
bool init_pseudo(player_t *player);
bool init_control(player_t *player);

typedef bool (*player_field_save_t)(player_t *);
bool save_pseudo(player_t *player);
bool save_control(player_t *player);

#endif