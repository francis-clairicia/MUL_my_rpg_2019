/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hearder of the rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include "my.h"
#include "struct.h"
typedef struct menu_s
{
    sfSprite *background;
}menu_t;

typedef struct tool_s
{
    sfRenderWindow *window;

}tool_t;

enum scenes_number
{
    NO_SCENE = -1,
    MENU,
    WORLD,
    GAME,
    ENd_MENU
};

typedef int (*gameloop_t)(void);

typedef int (*scene_t)(void);

/* Menu */
int launch_menu(void);
int init_menu(void);

#endif /* !RPG_H_ */