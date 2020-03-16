/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** A header for pirates management.
*/

#ifndef PIRATES_H_

#define PIRATES_H_


#include <SFML/System.h>

#include "items.h"

typedef struct pirate_stats_s {
    size_t max_hitpoints; // -> Max HP's
    ssize_t hitpoints; // -> Updated HP's during combat phases.
    size_t speed; // -> Movement Speed.
} pirate_stats_t;


typedef enum pirate_hairstyle_s {
    BLACK,
    BROWN,
    GRAY,
    BLOND,
    BLUE,
} pirate_hairstyle_t;


typedef enum pirate_eyes_s {
    BLACK,
    BROWN,
    LIGHT_BLUE,
    BLUE,
    LIGHT_GREEN,
    GREEN,
} pirate_eyes_t;


typedef struct pirate_face_s {
    pirate_hairstyle_t hairstyle;
    pirate_eyes_t eyes;
} pirate_face_t;


typedef struct pirate_list_s {
    pirate_stats_t stats;
    pirate_face_t face;
    weapon_t weapon;
    char *name;
    sfBool selected;
    struct pirate_list_s *next;
    struct pirate_list_s *prev;
} pirate_list_t;


#endif /* PIRATES_H_ */