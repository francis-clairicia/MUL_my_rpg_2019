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
    button_t **buttons;
    sfVector2f pos;
    sfVector2f size;
}settings_t;

enum SETTINGS_BUTTONS {
    RESUME,
    VOlUME_UP,
    VOLUME_DOWN,
    SAVE,
    QUIT
};

/* Settings */
sfBool init_settings(settings_t *settings);

#endif /* !SETTINGS_H_ */
