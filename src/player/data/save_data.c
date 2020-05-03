/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save_data.c
*/

#include <stdio.h>
#include "player.h"
#include "my.h"

static FILE *open_data_save(char const *folder)
{
    char *data_save = join_path(folder, DATA_SAVE_FILE);
    FILE *fp = NULL;

    if (data_save == NULL)
        return (NULL);
    fp = fopen(data_save, "wb");
    free(data_save);
    return (fp);
}

static bool write_data(player_data_t *data, FILE *save)
{
    if (save == NULL)
        return (false);
    return (fwrite(data, sizeof(player_data_t), 1, save) > 0);
}

bool save_data(player_t *player)
{
    FILE *data_file = NULL;
    bool status = true;

    if (player == NULL)
        return (false);
    data_file = open_data_save(player->save.folder);
    status = write_data(&player->data, data_file);
    if (data_file != NULL)
        fclose(data_file);
    return (status);
}