/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw.c
*/

#include "rpg.h"

static sfRectangleShape *load_box(sfVector2u window_size, sfVector2f pos)
{
    sfVector2f size = {window_size.x / 2, window_size.y / 5};
    sfVector2f origin = {size.x, 0};
    sfRectangleShape *shape = sfRectangleShape_create();

    if (shape != NULL) {
        sfRectangleShape_setSize(shape, size);
        sfRectangleShape_setOrigin(shape, origin);
        sfRectangleShape_setPosition(shape, pos);
        sfRectangleShape_setFillColor(shape, sfColor_fromRGB(33, 170, 217));
        sfRectangleShape_setOutlineColor(shape, sfWhite);
        sfRectangleShape_setOutlineThickness(shape, 3);
    }
    return (shape);
}

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

static void draw_player_infos(sfRenderWindow *window, player_t *player)
{
    sfVector2u size = sfRenderWindow_getSize(window);
    char *level_msg = get_level(player->data.lvl);
    sfRectangleShape *frame = load_box(size, VEC2F(size.x - 100, 100));
    text_t pseudo = init_text(player->pseudo, FONT_FOLDER "skull.ttf", 50);
    text_t level = init_text(level_msg, FONT_FOLDER "skull.ttf", 50);
    sfFloatRect rect;

    rect = sfRectangleShape_getGlobalBounds(frame);
    sfText_setPosition(pseudo.object, VEC2F(rect.left + 10, rect.top + 10));
    rect = sfText_getGlobalBounds(pseudo.object);
    rect.top += rect.height;
    sfText_setPosition(level.object, VEC2F(rect.left + 10, rect.top + 10));
    sfRenderWindow_drawRectangleShape(window, frame, NULL);
    draw_text(pseudo, window);
    draw_text(level, window);
    destroy_text(pseudo);
    destroy_text(level);
    sfRectangleShape_destroy(frame);
    free(level_msg);
}

void draw_save_chooser(sfRenderWindow *window, save_chooser_t *chooser,
    player_t players[3])
{
    if (!window || !chooser || !players)
        return;
    sfRenderWindow_clear(window, chooser->background);
    for (int i = 0; i < 3; i += 1) {
        draw_button(chooser->saves[i], window);
        if (players[i].save.used
        && chooser->saves[i].invisible->state == BUTTON_HOVER)
            draw_player_infos(window, &players[i]);
    }
    draw_button(chooser->menu, window);
}