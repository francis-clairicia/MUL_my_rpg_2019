/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_control
*/

#include <stdio.h>
#include "my.h"
#include "player.h"

static FILE *open_pseudo_save(char const *folder)
{
    char *save = join_path(folder, PSEUDO_SAVE_FILE);

    if (save == NULL)
        return (NULL);
    return (fopen(save, "r"));
}

static bool load_pseudo(char pseudo[21], FILE *save)
{
    int unicode_pseudo[20];
    int i = 0;

    my_memset(pseudo, 0, 21);
    if (fread(unicode_pseudo, sizeof(int), 20, save) <= 0)
        return (false);
    for (i = 0; i < 20; i += 1)
        pseudo[i] = unicode_pseudo[i] + 'a';
    return (true);
}

bool init_pseudo(player_t *player)
{
    FILE *pseudo_file = NULL;
    bool status = true;

    if (player == NULL)
        return (false);
    if (!(player->save.used))
        return (true);
    pseudo_file = open_pseudo_save(player->save.folder);
    status = load_pseudo(player->pseudo, pseudo_file);
    if (pseudo_file != NULL)
        fclose(pseudo_file);
    return (status);
}