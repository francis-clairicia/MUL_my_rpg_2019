/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_level.c
*/

#include "hud.h"
#include "my.h"

static char *get_level(int level)
{
    char msg_before[] = "Level ";
    char *nbr = my_nbr_to_str(level);
    int len = my_strlen(msg_before) + my_strlen(nbr);
    char *str_level = malloc(sizeof(char) * (len + 1));

    my_strcat(my_strcat(my_memset(str_level, 0, len + 1), msg_before), nbr);
    free(nbr);
    return (str_level);
}

sfFloatRect display_level(tool_t *tool, sfVector2f scale,
    sfFloatRect rect UNUSED, sfFloatRect box_rect)
{
    char *level_msg = get_level(tool->player.data.lvl);
    text_t level = init_text(level_msg, FONT_FOLDER "skull.ttf", 60);
    sfFloatRect new_rect;
    sfVector2f pos = {box_rect.left + box_rect.width, box_rect.top};

    pos.x -= (10 * scale.x);
    pos.y += (10 * scale.y);
    sfText_setPosition(level.object, pos);
    sfText_setScale(level.object, scale);
    set_text_origin(level, 1, 0);
    draw_text(level, tool->window);
    new_rect = sfText_getGlobalBounds(level.object);
    destroy_text(level);
    free(level_msg);
    return (new_rect);
}