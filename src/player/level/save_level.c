/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save_level.c
*/

#include <stdio.h>
#include "player.h"
#include "my.h"

static FILE *open_level_save(char const *folder)
{
    char *level_save = join_path(folder, LEVEL_SAVE_FILE);
    FILE *fp = NULL;

    if (level_save == NULL)
        return (NULL);
    fp = fopen(level_save, "wb");
    free(level_save);
    return (fp);
}

static bool write_level(int *level, FILE *save)
{
    if (save == NULL)
        return (false);
    return (fwrite(level, sizeof(int), 1, save) > 0);
}

bool save_level(player_t *player)
{
    FILE *level_file = NULL;
    bool status = true;

    if (player == NULL)
        return (false);
    level_file = open_level_save(player->save.folder);
    status = write_level(&player->level, level_file);
    if (level_file != NULL)
        fclose(level_file);
    return (status);
}