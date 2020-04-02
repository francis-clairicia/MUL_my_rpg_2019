/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** img_button_move.c
*/

#include "include/struct.h"

void set_pos_img_button(image_button_t button, sfVector2f pos)
{
    sfSprite_setPosition(button.sprite, pos);
    button.invisible->rect = sfSprite_getGlobalBounds(button.sprite);
}

void move_img_button(image_button_t button, sfVector2f offset)
{
    sfSprite_move(button.sprite, offset);
    button.invisible->rect = sfSprite_getGlobalBounds(button.sprite);
}