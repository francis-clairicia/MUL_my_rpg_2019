/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu.h
*/

#ifndef MENU_H_
#define MENU_H_

#include "struct.h"

typedef struct menu_s
{
    obj_t *background;
    button_t buttons[1];
    int nb_buttons;
}menu_t;

enum MENU_BUTTONS
{
    MENU_QUIT
};

#endif