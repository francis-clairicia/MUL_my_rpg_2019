/*
** EPITECH PROJECT, 2020
** init_menu
** File description:
** initialisation of the menu
*/

#include "rpg.h"
#include "vector_engine.h"

sfBool init_menu(menu_t *menu)
{
    sfVector2f bg_pos = VEC2F(0, 0);

    menu->background = create_object(IMG_FOLDER "background_menu.jpeg", NULL);
    if (!(menu->background))
        return (sfFalse);
    sfSprite_setPosition(menu->background->sprite, bg_pos);
    return (sfTrue);
}

void destroy_menu(menu_t *menu)
{
    destroy_object(menu->background);
}