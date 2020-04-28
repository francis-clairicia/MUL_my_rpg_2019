/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_player
*/

#include "battle.h"

static void set_battle_player_pos(player_t *player, list_t *boat_list)
{
    game_obj_t *boat_obj = find_game_object(boat_list, TILLER);
    game_obj_t *pirate = NODE_DATA(player->crew, game_obj_t *);
    sfVector2f pos = VEC2F(0, 0);

    if (!boat_obj)
        boat_obj = NODE_DATA(boat_list, game_obj_t *);
    pos = boat_obj->body.pos;
    pos = vec_add(pos, VEC2F(128, -10));
    set_game_object_pos(pirate, pos);
}

sfBool init_battle_player(player_t *player)
{
    if (!player || !(player->boat))
        return (sfFalse);
    if (!(player->crew))
        MY_APPEND_TO_LIST(&(player->crew), create_game_obj(PIRATE));
    if (!(player->crew))
        return (sfFalse);
    set_battle_player_pos(player, player->boat);
    return (sfTrue);
}