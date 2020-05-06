/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** control
*/

#ifndef CONTROL_H_
#define CONTROL_H_

#include <SFML/Window/Keyboard.h>

typedef enum control_keys_e
{
    CONTROL_UP = 0,
    CONTROL_DOWN = 1,
    CONTROL_LEFT = 2,
    CONTROL_RIGHT = 3,
    CONTROL_USE = 4,
    CONTROL_ATTACK1 = 5,
    CONTROL_ATTACK2 = 6,
    CONTROL_ZOOM_UP = 7,
    CONTROL_ZOOM_DOWN = 8,
} control_keys_t;

typedef struct control_s
{
    sfKeyCode keys[9];
} control_t;

#endif /* !CONTROL_H_ */