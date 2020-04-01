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
    obj_t *background;
}menu_t;

typedef struct tool_s
{
    sfRenderWindow *window;
    menu_t menu;
}tool_t;

enum scenes_number
{
    NO_SCENE = -1,
    MENU,
    WORLD,
    GAME,
    ENd_MENU
};

#define IMG_FOLDER "assets/img/"

typedef int (*scene_t)(tool_t *tools, int state);

/* Menu */
void init_menu(menu_t *menu);
int launch_menu(tool_t *tools, int state);
void destroy_menu(menu_t *menu);

#endif /* !RPG_H_ */