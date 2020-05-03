/*
** EPITECH PROJECT, 2020
** settings
** File description:
** hearder for settings
*/

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "struct.h"

typedef struct settings_s
{
    sfRectangleShape *box;
    button_t buttons[5];
    int nb_buttons;
    text_t title;
    int previous_state;
}settings_t;

enum SETTINGS_BUTTONS {
    VOLUME_DOWN,
    VOLUME_UP,
    SAVE,
    CLOSE,
    BACK_MENU
};

/* Settings */
sfBool init_settings(settings_t *settings, sfView *view);
void destroy_settings(settings_t *settings);

#endif /* !SETTINGS_H_ */
