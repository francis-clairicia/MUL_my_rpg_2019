/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_boat
*/

#include "my.h"
#include "battle.h"
#include "loader.h"

static config_t boat_config[] =
{
    {'X', WOOD1_RECT},
    {'L', WOOD1_LEFT_TRIANGLE},
    {'R', WOOD1_RIGHT_TRIANGLE},
    {'x', WOOD2_RECT},
    {'l', WOOD2_LEFT_TRIANGLE},
    {'r', WOOD2_RIGHT_TRIANGLE},
    {'T', TILLER},
    {'F', FENCE},
    {0, -1}
};

void update_boat_size(list_t *boat);

static void set_ally_boat_pos(player_t *player, list_t *water_list)
{
    game_obj_t *water = NODE_DATA(water_list, game_obj_t *);
    game_obj_t *boat = NODE_DATA(player->boat, game_obj_t *);
    sfVector2f size = VEC2F(0, 0);
    sfVector2f pos = VEC2F(0, 0);

    if (!water || !boat)
        return ;
    pos = vec_mult(boat->body.pos, -1);
    size = comp_value(boat, SIZE)->v2f;
    game_object_list(player->boat, add_game_object_pos_ptr, &pos);
    pos = VEC2F(0, water->body.pos.y - size.y - 46);
    game_object_list(player->boat, add_game_object_pos_ptr, &pos);
}

static sfBool init_ally_boat(player_t *player, battle_t *battle)
{
    player->boat = create_list_from_array(player->boat_layout, boat_config);
    if (!(player->boat))
        return (sfFalse);
    battle->player = player;
    update_boat_size(player->boat);
    set_ally_boat_pos(player, battle->water);
    return (sfTrue);
}

sfBool init_battle_boat(player_t *player, battle_t *battle)
{
    if (!player->boat && !init_ally_boat(player, battle))
        return (sfFalse);
    return (sfTrue);
}