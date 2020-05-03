/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_data.c
*/

#include <stdio.h>
#include "my.h"
#include "player.h"
#include "constants.h"
#include "vector_engine.h"

static const player_data_t default_data = {
    .xp = 0,
    .lvl = 1,
    .life = BOAT_LIFE,
    .damage = 20,
    .attack_speed = 1,
    .cannon_nb = 1,
    .dead_counter = 0,
    .pos = VEC2F(100, 100)
};

static FILE *open_data_save(char const *folder)
{
    char *data_save = join_path(folder, DATA_SAVE_FILE);
    FILE *fp = NULL;

    if (data_save == NULL)
        return (NULL);
    fp = fopen(data_save, "rb");
    free(data_save);
    return (fp);
}

static bool load_data(player_data_t *data, FILE *save)
{
    if (save == NULL)
        return (false);
    return (fread(data, sizeof(player_data_t), 1, save) > 0);
}

bool init_data(player_t *player)
{
    FILE *data_file = NULL;
    bool status = true;

    if (player == NULL)
        return (false);
    if (!(player->save.used)) {
        player->data = default_data;
        return (true);
    }
    data_file = open_data_save(player->save.folder);
    status = load_data(&player->data, data_file);
    if (data_file != NULL)
        fclose(data_file);
    return (status);
}