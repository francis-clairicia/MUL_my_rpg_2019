/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_move.c
*/

#include "include/struct.h"

void set_pos_button(button_t button, sfVector2f pos)
{
    sfRectangleShape_setPosition(button.rect, pos);
    button.invisible->rect = sfRectangleShape_getGlobalBounds(button.rect);
}

void move_button(button_t button, sfVector2f offset)
{
    sfRectangleShape_move(button.rect, offset);
    button.invisible->rect = sfRectangleShape_getGlobalBounds(button.rect);
}