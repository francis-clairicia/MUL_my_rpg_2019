/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** img_button.c
*/

#include "include/struct.h"

image_button_t create_img_button(char const *filepath, sfIntRect default_rect)
{
    image_button_t button;
    sfFloatRect button_rect;

    button.texture = sfTexture_createFromFile(filepath, &default_rect);
    button.sprite = sfSprite_create();
    button_rect = sfSprite_getGlobalBounds(button.sprite);
    button.invisible = create_invisible_button(&button_rect);
    button.rect[BUTTON_NORMAL] = default_rect;
    button.rect[BUTTON_HOVER] = default_rect;
    button.rect[BUTTON_ACTIVE] = default_rect;
    return (button);
}

void destroy_img_button(image_button_t button)
{
    sfSprite_destroy(button.sprite);
    sfTexture_destroy(button.texture);
    destroy_invisible_button(button.invisible);
}
