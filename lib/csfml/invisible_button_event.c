/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** invisible_button_event.c
*/

#include "include/struct.h"

static int click_down(invisible_button_t *button, sfMouseButtonEvent event)
{
    if (event.button != sfMouseLeft)
        return (0);
    if (sfFloatRect_contains(&button->rect, event.x, event.y)) {
        if (button->state == BUTTON_HOVER)
            button->state = BUTTON_ACTIVE;
    }
    return (0);
}

static int click_up(invisible_button_t *button, sfMouseButtonEvent event)
{
    int state = 0;

    if (event.button != sfMouseLeft)
        return (0);
    if (sfFloatRect_contains(&button->rect, event.x, event.y)) {
        if (button->state == BUTTON_ACTIVE) {
            button->state = BUTTON_HOVER;
            state = 1;
        }
    } else {
        button->state = BUTTON_NORMAL;
    }
    if (state == 1 && button->sounds[S_CLICKED] != NULL) {
        sfMusic_setPlayingOffset(button->sounds[S_CLICKED], (sfTime){0});
        sfMusic_play(button->sounds[S_CLICKED]);
    }
    return (state);
}

static int move(invisible_button_t *button, sfMouseMoveEvent event)
{
    int former_state = button->state;

    if (sfFloatRect_contains(&button->rect, event.x, event.y)) {
        if (button->state == BUTTON_NORMAL)
            button->state = BUTTON_HOVER;
    } else {
        button->state = BUTTON_NORMAL;
    }
    if (button->state == BUTTON_HOVER && former_state == BUTTON_NORMAL
    && button->sounds[S_HOVER] != NULL) {
        sfMusic_setPlayingOffset(button->sounds[S_HOVER], (sfTime){0});
        sfMusic_play(button->sounds[S_HOVER]);
    }
    return (0);
}

sfBool invisible_button_event(invisible_button_t *button, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        return (click_down(button, event.mouseButton));
    if (event.type == sfEvtMouseButtonReleased)
        return (click_up(button, event.mouseButton));
    if (event.type == sfEvtMouseMoved)
        return (move(button, event.mouseMove));
    return (0);
}