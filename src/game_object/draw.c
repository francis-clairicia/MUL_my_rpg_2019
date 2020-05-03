/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_game_object
*/

#include "rpg.h"
#include "game_object.h"

static sfBool init_hp_bar(sfRectangleShape *hp_bar[])
{
    hp_bar[0] = sfRectangleShape_create();
    hp_bar[1] = sfRectangleShape_create();
    hp_bar[2] = sfRectangleShape_create();
    if (!hp_bar[0] || !hp_bar[1] || !hp_bar[2])
        return (sfFalse);
    sfRectangleShape_setFillColor(hp_bar[0], sfBlack);
    sfRectangleShape_setFillColor(hp_bar[1], sfGreen);
    sfRectangleShape_setFillColor(hp_bar[2], sfTransparent);
    sfRectangleShape_setOutlineColor(hp_bar[2], sfColor_fromRGB(128, 128, 128));
    sfRectangleShape_setOutlineThickness(hp_bar[2], 3);
    return (sfTrue);
}

static void setup_hp_bar(game_obj_t *obj, sfRectangleShape *hp_bar[])
{
    int hp = obj->comp[find_comp(obj, LIFE)]->i;
    int max_hp = obj->comp[find_comp(obj, MAX_LIFE)]->i;
    sfFloatRect rect = obj->hitbox;
    sfVector2f max_hp_size = {rect.width, 5};
    sfVector2f hp_size = {max_hp_size.x * hp / max_hp, max_hp_size.y};
    sfVector2f pos = {rect.left, rect.top - max_hp_size.y - 5};

    sfRectangleShape_setSize(hp_bar[0], max_hp_size);
    sfRectangleShape_setSize(hp_bar[1], hp_size);
    sfRectangleShape_setSize(hp_bar[2], max_hp_size);
    sfRectangleShape_setPosition(hp_bar[0], pos);
    sfRectangleShape_setPosition(hp_bar[1], pos);
    sfRectangleShape_setPosition(hp_bar[2], pos);
}

static void draw_hp_bar(sfRenderWindow *window, game_obj_t *obj)
{
    sfRectangleShape *hp_bar[3] = {NULL, NULL, NULL};

    if (!init_hp_bar(hp_bar))
        return;
    setup_hp_bar(obj, hp_bar);
    for (int i = 0; i < 3; i += 1) {
        sfRenderWindow_drawRectangleShape(window, hp_bar[i], NULL);
        sfRectangleShape_destroy(hp_bar[i]);
        hp_bar[i] = NULL;
    }
}

void draw_game_object(sfRenderWindow *window, game_obj_t *obj)
{
    int state = 0;

    if (!window || !obj)
        return;
    if (has_comp(obj, CLOCK))
        anime_game_object(obj);
    state = obj->state;
    update_hitbox(obj);
    sfSprite_setPosition(obj->sprite, obj->body.pos);
    sfSprite_setTextureRect(obj->sprite, obj->view_box[state]);
    sfSprite_setRotation(obj->sprite, obj->body.angle);
    obj->hitbox = sfSprite_getGlobalBounds(obj->sprite);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
    if (has_comp(obj, LIFE) && has_comp(obj, MAX_LIFE))
        draw_hp_bar(window, obj);
}