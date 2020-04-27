/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_control
*/

#include "my.h"
#include "player.h"

sfBool init_control(player_t *player)
{
    if (!player)
        return (sfFalse);
    my_memcpy(&(player->control), &control_template, sizeof(control_template));
    return (sfTrue);
}