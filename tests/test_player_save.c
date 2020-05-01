/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** test_player_save.c
*/

#include <criterion/criterion.h>
#include "player.h"
#include "my.h"

static const char *save_folder = "./tests/save";

static void init_test(void)
{
    save_t save = {false, save_folder};
    player_t *player = NULL;

    player = create_player(save);
    cr_assert_not_null(player);
    cr_expect_str_eq(player->save.folder, save_folder);
    my_strcpy(player->pseudo, "Francis");
    player->control.keys[CONTROL_UP] = sfKeyA;
    player->control.keys[CONTROL_DOWN] = sfKeyB;
    player->control.keys[CONTROL_LEFT] = sfKeyC;
    player->control.keys[CONTROL_RIGHT] = sfKeyD;
    player->control.keys[CONTROL_USE] = sfKeyE;
    cr_expect_eq(save_player_data(player), true);
    destroy_player(player);
}

Test(create_player, load_a_player_save_and_init_structure)
{
    save_t save;
    player_t *player = NULL;

    init_test();
    cr_assert_eq(load_one_save(&save, save_folder), true);
    player = create_player(save);
    cr_assert_not_null(player);
    cr_expect_eq(player->save.used, true);
    cr_expect_str_eq(player->pseudo, "Francis");
    cr_expect_eq(player->control.keys[CONTROL_UP], sfKeyA);
    cr_expect_eq(player->control.keys[CONTROL_DOWN], sfKeyB);
    cr_expect_eq(player->control.keys[CONTROL_LEFT], sfKeyC);
    cr_expect_eq(player->control.keys[CONTROL_RIGHT], sfKeyD);
    cr_expect_eq(player->control.keys[CONTROL_USE], sfKeyE);
    destroy_player(player);
}