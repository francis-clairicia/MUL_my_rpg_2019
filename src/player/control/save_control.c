/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save_control.c
*/

#include <stdio.h>
#include "player.h"
#include "my.h"

static FILE *open_control_save(char const *folder)
{
    char *control_save = join_path(folder, CONTROL_SAVE_FILE);

    if (control_save == NULL)
        return (NULL);
    return (fopen(control_save, "w"));
}

static bool write_controls(control_t *control, FILE *save)
{
    if (save == NULL)
        return (false);
    return (fwrite(control, sizeof(control_t), 1, save) > 0);
}

bool save_control(player_t *player)
{
    FILE *control_file = NULL;
    bool status = true;

    if (player == NULL)
        return (false);
    control_file = open_control_save(player->save.folder);
    status = write_controls(&player->control, control_file);
    if (control_file != NULL)
        fclose(control_file);
    return (status);
}