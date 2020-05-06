/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hud.h
*/

#ifndef RPG_HUD_H_
#define RPG_HUD_H_

#include "tools.h"
#include "player.h"
#include "struct.h"
#include "vector_engine.h"

void display_hud(tool_t *tool);

typedef sfFloatRect (*hud_t)(tool_t *, sfVector2f,  sfFloatRect, sfFloatRect);
sfFloatRect display_pseudo(tool_t *tool, sfVector2f scale,
    sfFloatRect rect, sfFloatRect box_rect);
sfFloatRect display_level(tool_t *tool, sfVector2f scale,
    sfFloatRect rect, sfFloatRect box_rect);
sfFloatRect display_xp(tool_t *tool, sfVector2f scale,
    sfFloatRect rect, sfFloatRect box_rect);
sfFloatRect display_xp_bar(tool_t *tool, sfVector2f scale,
    sfFloatRect rect, sfFloatRect box_rect);

#endif