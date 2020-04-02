/*
** EPITECH PROJECT, 2020
** init_text
** File description:
** initialization of sfText
*/

#include "include/struct.h"

text_t init_text(char const *message, char const *font_path, int size)
{
    text_t text_struct;
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(font_path);

    sfText_setString(text, message);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    text_struct.object = text;
    text_struct.font = font;
    return (text_struct);
}

void destroy_text(text_t text)
{
    sfText_destroy(text.object);
    sfFont_destroy(text.font);
}

void set_text_origin(text_t text, float x, float y)
{
    sfFloatRect rect = sfText_getLocalBounds(text.object);
    sfVector2f origin = {rect.width, rect.height};

    origin.x *= x;
    origin.y *= y;
    sfText_setOrigin(text.object, origin);
}