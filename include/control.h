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
    CONTROL_USE = 4
} control_keys_t;

typedef struct control_s
{
    sfKeyCode keys[5];
} control_t;

#endif /* !CONTROL_H_ */