/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** img_button_event.c
*/

#include "include/struct.h"
#include <stdio.h>

sfBool is_button_img_clicked(image_button_t button, sfEvent event)
{
    return (invisible_button_event(button.invisible, event));
}