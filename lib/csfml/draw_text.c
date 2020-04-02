/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** draw_text.c
*/

#include "include/struct.h"

void draw_text(text_t text, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, text.object, NULL);
}