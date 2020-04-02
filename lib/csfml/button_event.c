/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_event.c
*/

#include "include/struct.h"

sfBool is_button_clicked(button_t button, sfEvent event)
{
    return (invisible_button_event(button.invisible, event));
}