/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** A header for pirates management.
*/

#ifndef PIRATES_H_
#define PIRATES_H_

#include <SFML/Config.h>
#include "items.h"

typedef struct pirate_stats_s {
    size_t max_hp; // -> Max HP's
    ssize_t hp; // -> Updated HP's during combat phases.
    size_t speed; // -> Movement Speed.
} pirate_stats_t;


typedef enum pirate_hairstyle_s {
    HAIR_BLACK,
    HAIR_BROWN,
    HAIR_GRAY,
    HAIR_BLOND,
    HAIR_BLUE,
} pirate_hairstyle_t;


typedef enum pirate_eyes_s {
    EYES_BLACK,
    EYES_BROWN,
    EYES_LIGHT_BLUE,
    EYES_BLUE,
    EYES_LIGHT_GREEN,
    EYES_GREEN,
} pirate_eyes_t;


typedef struct pirate_face_s {
    pirate_hairstyle_t hairstyle;
    pirate_eyes_t eyes;
} pirate_face_t;


typedef struct pirate {
    pirate_stats_t stats;
    pirate_face_t face;
    weapon_t weapon;
    char *name;
    sfBool selected;
} pirate_t;


#endif /* PIRATES_H_ */