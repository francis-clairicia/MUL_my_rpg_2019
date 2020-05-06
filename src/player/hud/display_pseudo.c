/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_pseudo.c
*/

#include "hud.h"
#include "my.h"

sfFloatRect display_pseudo(tool_t *tool, sfVector2f scale,
    sfFloatRect rect UNUSED, sfFloatRect box_rect)
{
    sfVector2f pos = {box_rect.left, box_rect.top};
    text_t text = init_text(tool->player.pseudo, FONT_FOLDER "skull.ttf", 60);
    sfFloatRect new_rect;

    pos.x += (10 * scale.x);
    pos.y += (10 * scale.y);
    sfText_setPosition(text.object, pos);
    sfText_setScale(text.object, scale);
    draw_text(text, tool->window);
    new_rect = sfText_getGlobalBounds(text.object);
    destroy_text(text);
    return (new_rect);
}