/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** img_button_draw.c
*/

#include "include/struct.h"

void draw_img_button(image_button_t button, sfRenderWindow *window)
{
    enum BUTTON_STATE state = button.invisible->state;

    sfSprite_setTextureRect(button.sprite, button.rect[state]);
    sfRenderWindow_drawSprite(window, button.sprite, NULL);
}