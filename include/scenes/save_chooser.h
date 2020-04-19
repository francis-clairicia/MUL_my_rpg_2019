/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save_chooser.h
*/

#ifndef HEADER_SAVE_CHOOSER_SCENE
#define HEADER_SAVE_CHOOSER_SCENE

#include "struct.h"
#include "save.h"

typedef struct save_chooser
{
    sfColor background;
    button_t saves[3];
    button_t menu;
} save_chooser_t;

sfBool init_save_chooser(save_chooser_t *chooser);
void destroy_save_chooser(save_chooser_t *chooser);
void set_button_color_for_saves(button_t buttons[3], save_t saves[3]);

#endif