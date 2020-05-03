/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_level.c
*/

#include <stdio.h>
#include "my.h"
#include "player.h"

static FILE *open_level_save(char const *folder)
{
    char *level_save = join_path(folder, LEVEL_SAVE_FILE);
    FILE *fp = NULL;

    if (level_save == NULL)
        return (NULL);
    fp = fopen(level_save, "rb");
    free(level_save);
    return (fp);
}

static bool load_level(int *level, FILE *save)
{
    if (save == NULL)
        return (false);
    return (fread(level, sizeof(int), 1, save) > 0);
}

bool init_level(player_t *player)
{
    FILE *level_file = NULL;
    bool status = true;

    if (player == NULL)
        return (false);
    if (!(player->save.used)) {
        player->level = 1;
        return (true);
    }
    level_file = open_level_save(player->save.folder);
    status = load_level(&player->level, level_file);
    if (level_file != NULL)
        fclose(level_file);
    return (status);
}