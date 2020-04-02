/*
** EPITECH PROJECT, 2020
** init_menu
** File description:
** initialisation of the menu
*/

#include "rpg.h"

void init_menu(menu_t *menu)
{
    sfVector2f bg_pos = init_vector2f(0, 0);

    menu->background = create_object(IMG_FOLDER "background_menu.jpeg", NULL);
    sfSprite_setPosition(menu->background->sprite, bg_pos);
}

void destroy_menu(menu_t *menu)
{
    destroy_object(menu->background);
}