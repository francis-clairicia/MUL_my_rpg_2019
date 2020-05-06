/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_xp.c
*/

#include "hud.h"
#include "my.h"

static char *get_xp(int xp, int max_xp)
{
    char *msg[] = {NULL, "/", NULL, " XP", NULL};
    char *xp_str = my_nbr_to_str(xp);
    char *max_xp_str = my_nbr_to_str(max_xp);
    int len = 0;
    char *str_to_draw = NULL;

    msg[0] = xp_str;
    msg[2] = max_xp_str;
    for (int i = 0; msg[i] != NULL; i += 1)
        len += my_strlen(msg[i]);
    str_to_draw = my_memset(malloc(sizeof(char) * (len + 1)), 0, len + 1);
    if (str_to_draw != NULL) {
        for (int i = 0; msg[i] != NULL; i += 1)
            my_strcat(str_to_draw, msg[i]);
    }
    free(xp_str);
    free(max_xp_str);
    return (str_to_draw);
}

sfFloatRect display_xp(tool_t *tool, sfVector2f scale,
    sfFloatRect rect, sfFloatRect box_rect)
{
    char *msg = get_xp(tool->player.data.xp, tool->player.max_xp);
    text_t xp = init_text(msg, FONT_FOLDER "skull.ttf", 60);
    sfFloatRect new_rect;
    sfVector2f pos = {box_rect.left, rect.top + rect.height};

    pos.x += (10 * scale.x);
    pos.y += (60 * scale.y);
    sfText_setPosition(xp.object, pos);
    sfText_setScale(xp.object, scale);
    draw_text(xp, tool->window);
    new_rect = sfText_getGlobalBounds(xp.object);
    destroy_text(xp);
    free(msg);
    return (new_rect);
}