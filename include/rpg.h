/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hearder of the rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my.h"
#include "struct.h"


typedef struct menu_s
{
    obj_t *background;
}menu_t;

typedef struct mouse_tool_s {
    sfVector2f win_pos;
    sfVector2f pos;
    sfVector2f win_click_pos;
    sfVector2f click_pos;
    sfBool hold;
    sfBool click;
} mouse_tool_t;

typedef struct anchor_s {
    sfVector2f topleft;
    sfVector2f topright;
    sfVector2f bottomleft;
    sfVector2f bottomright;
} anchor_t;

typedef struct tool_s
{
    sfRenderWindow *window;
    sfView *view;
    menu_t menu;
    anchor_t anchor;
    sfVector2f size;
    sfVector2f scale;
    sfVideoMode video_mode;
    sfEvent event;
    mouse_tool_t mouse_tool;
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
sfBool init_menu(menu_t *menu);
int launch_menu(tool_t *tools, int state);
void destroy_menu(menu_t *menu);

/* Tools */
void update_mouse_tool(tool_t *tool);
void update_tool(tool_t *tool);

#endif /* !RPG_H_ */