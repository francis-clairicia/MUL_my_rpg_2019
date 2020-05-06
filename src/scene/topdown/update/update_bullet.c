/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_bullet
*/

#include "update_topdown.h"

static void damage_boat_from_bullet(game_obj_t *bullet, game_obj_t *boat)
{
    int damage = comp_value(bullet, DAMAGE)->i;

    if (!boat || !bullet || !damage)
        return;
    if (comp_value(boat, LIFE)->i <= 0)
        return;
    comp_value(boat, LIFE)->i -= damage;
    comp_value(bullet, DAMAGE)->i = 0;
    update_topdown_boat_state(boat);
    play_game_object_sound(boat, HIT_SOUND);
    if (comp_value(boat, LIFE)->i <= 0 && has_comp(boat, DEAD_BY_BULLET))
        comp_value(boat, DEAD_BY_BULLET)->i = true;
}

static void check_bullet_boat_list(game_obj_t *bullet, list_t *boat_list,
                                            game_obj_t *bonus_boat)
{
    game_obj_t *boat = NULL;

    for (; boat_list; boat_list = boat_list->next) {
        boat = NODE_DATA(boat_list, game_obj_t *);
        if (!boat)
            continue;
        if (is_game_object_collision(bullet, boat))
            damage_boat_from_bullet(bullet, boat);
    }
    if (bonus_boat && is_game_object_collision(bullet, bonus_boat))
        damage_boat_from_bullet(bullet, bonus_boat);
}

static void check_bullet_with_all_boat(game_obj_t *bullet, topdown_t *topdown)
{
    if (!has_comp(bullet, ALLY))
        return ;
    if (comp_value(bullet, ALLY)->i == 1) {
        check_bullet_boat_list(bullet, topdown->ennemy_boat, NULL);
        check_bullet_boat_list(bullet, topdown->mercenary_boat, NULL);
        check_bullet_boat_list(bullet, topdown->golden_boat, NULL);
    } else {
        check_bullet_boat_list(bullet, topdown->ally_boat, topdown->boat);
    }
}

static void clean_bullet_from_map(list_t **bullet_list, sfVector2f map_size)
{
    list_t *list = NULL;
    game_obj_t *bullet = NULL;

    if (!bullet_list)
        return;
    for (list = *bullet_list; list; list = list->next) {
        bullet = NODE_DATA(list, game_obj_t *);
        if (!bullet)
            continue;
        if (bullet->body.pos.x < 0 || bullet->body.pos.x > map_size.x ||
            bullet->body.pos.y < 0 || bullet->body.pos.y > map_size.y ||
            comp_value(bullet, DAMAGE)->i == 0) {
            my_delete_node_from_node(bullet_list, list, free_game_object);
            return;
        }
    }
}

void update_topdown_bullet(tool_t *tool, topdown_t *topdown)
{
    list_t *bullet_list = topdown->bullets;
    game_obj_t *bullet = NULL;

    for (; bullet_list; bullet_list = bullet_list->next) {
        bullet = NODE_DATA(bullet_list, game_obj_t *);
        if (!bullet)
            continue;
        check_bullet_with_all_boat(bullet, topdown);
        update_body(&(bullet->body), tool->dtime);
    }
    clean_bullet_from_map(&(topdown->bullets), topdown->map_size);
}