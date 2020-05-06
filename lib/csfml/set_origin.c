/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_origin.c
*/

#include "include/struct.h"

void set_sprite_origin(sfSprite *sprite, float x, float y)
{
    sfFloatRect rect = sfSprite_getLocalBounds(sprite);
    sfVector2f origin = {rect.width, rect.height};

    origin.x *= x;
    origin.y *= y;
    sfSprite_setOrigin(sprite, origin);
}

void set_rect_origin(sfRectangleShape *rectangle, float x, float y)
{
    sfFloatRect rect = sfRectangleShape_getLocalBounds(rectangle);
    sfVector2f origin = {rect.width, rect.height};

    origin.x *= x;
    origin.y *= y;
    sfRectangleShape_setOrigin(rectangle, origin);
}