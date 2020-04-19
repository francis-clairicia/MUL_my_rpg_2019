/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** tools.h
*/

#ifndef RPG_TOOLS_H_
#define RPG_TOOLS_H_

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/RenderWindow.h>
#include "menu.h"
#include "save_chooser.h"
#include "player.h"

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

typedef struct tool_s {
    // Window tools
    sfRenderWindow *window;
    anchor_t anchor;
    sfView *view;
    sfVector2f size;
    sfVector2f scale;
    sfVideoMode video_mode;
    sfEvent event;
    mouse_tool_t mouse_tool;
    // Scenes structures
    menu_t menu;
    save_chooser_t chooser;
    //Gameplay tools
    player_t player;
} tool_t;

/* Tools */
void init_mouse_tool(tool_t *tool);
void update_mouse_tool(tool_t *tool);
void update_tool(tool_t *tool);

#endif