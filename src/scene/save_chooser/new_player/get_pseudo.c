/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** get_pseudo.c
*/

#include "rpg.h"
#include "vector_engine.h"
#include "my.h"

static bool enter_pseudo(player_t *player, sfEvent event)
{
    int max_length = (sizeof(player->pseudo) - 1);
    int length = my_strlen(player->pseudo);

    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyReturn)
            return (true);
        if (event.key.code == sfKeyBackspace && length > 0)
            player->pseudo[length - 1] = '\0';
    } else if (event.text.unicode >= 32 && event.text.unicode < 127) {
        if (length < max_length)
            player->pseudo[length] = event.text.unicode;
    }
    return (false);
}

static int check_event(tool_t *tools, int state, bool *validated)
{
    while (sfRenderWindow_pollEvent(tools->window, &tools->event)) {
        if (tools->event.type == sfEvtClosed)
            return (NO_SCENE);
        if (tools->event.type == sfEvtKeyPressed
        && tools->event.key.code == sfKeyEscape)
            return (SAVE_CHOOSE);
        if (tools->event.type == sfEvtKeyPressed
        || tools->event.type == sfEvtTextEntered)
            *validated = enter_pseudo(&tools->player, tools->event);
        if (*validated)
            break;
    }
    return (state);
}

static void draw_scene(sfRenderWindow *window, sfRectangleShape *frame,
    char const *pseudo)
{
    text_t text = init_text(pseudo, FONT_FOLDER "skull.ttf", 100);
    sfVector2u size = sfRenderWindow_getSize(window);

    sfRenderWindow_drawRectangleShape(window, frame, NULL);
    set_text_origin(text, 0.5, 0.5);
    sfText_setPosition(text.object, VEC2F(size.x / 2, size.y / 2));
    draw_text(text, window);
    destroy_text(text);
}

static bool init_frame(sfRectangleShape *frame, sfRenderWindow *window)
{
    int width = 1600;
    int height = 160;
    sfVector2u size = sfRenderWindow_getSize(window);

    if (frame == NULL)
        return (false);
    sfRectangleShape_setSize(frame, VEC2F(width, height));
    sfRectangleShape_setOrigin(frame, VEC2F(width / 2, height / 2));
    sfRectangleShape_setPosition(frame, VEC2F(size.x / 2, size.y / 2));
    sfRectangleShape_setFillColor(frame, sfColor_fromRGB(33, 170, 217));
    sfRectangleShape_setOutlineColor(frame, sfWhite);
    sfRectangleShape_setOutlineThickness(frame, 3);
    return (true);
}

scene_t get_pseudo_new_player(tool_t *tools)
{
    int state = NEW_PLAYER;
    bool validated = false;
    sfRectangleShape *frame = sfRectangleShape_create();

    if (!init_frame(frame, tools->window))
        return (NO_SCENE);
    while (!validated && state == NEW_PLAYER) {
        sfRenderWindow_clear(tools->window, tools->chooser.background);
        update_tool(tools);
        draw_scene(tools->window, frame, tools->player.pseudo);
        sfRenderWindow_display(tools->window);
        state = check_event(tools, state, &validated);
    }
    sfRectangleShape_destroy(frame);
    return (state);
}