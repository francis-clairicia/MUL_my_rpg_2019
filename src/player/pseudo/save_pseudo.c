/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save_control.c
*/

#include <stdio.h>
#include "player.h"
#include "my.h"

static FILE *open_pseudo_save(char const *folder)
{
    char *save = join_path(folder, PSEUDO_SAVE_FILE);

    if (save == NULL)
        return (NULL);
    return (fopen(save, "w"));
}

static bool write_pseudo(char pseudo[21], FILE *save)
{
    int unicode_pseudo[20];
    int i = 0;

    for (i = 0; pseudo[i] != '\0'; i += 1)
        unicode_pseudo[i] = pseudo[i] - 'a';
    for (; i < 20; i += 1)
        unicode_pseudo[i] = 0 - 'a';
    return (fwrite(unicode_pseudo, sizeof(int), 20, save) > 0);
}

bool save_pseudo(player_t *player)
{
    FILE *pseudo_file = NULL;
    bool status = true;

    if (player == NULL)
        return (false);
    pseudo_file = open_pseudo_save(player->save.folder);
    status = write_pseudo(player->pseudo, pseudo_file);
    if (pseudo_file != NULL)
        fclose(pseudo_file);
    return (status);
}