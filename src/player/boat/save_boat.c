/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save_boat.c
*/

#include <stdio.h>
#include "player.h"
#include "my.h"

static FILE *open_boat_save(char const *folder)
{
    char *save = join_path(folder, BOAT_SAVE_FILE);
    FILE *fp = NULL;

    if (save == NULL)
        return (NULL);
    fp = fopen(save, "wb");
    free(save);
    return (fp);
}

static bool write_line(char const *line, FILE *save)
{
    char obj_of_boat = 0;

    for (int i = 0; line[i] != '\0'; i += 1) {
        obj_of_boat = line[i] - 'a';
        if (fwrite(&obj_of_boat, sizeof(char), 1, save) != 1)
            return (false);
    }
    obj_of_boat = '\n' - 'a';
    if (fwrite(&obj_of_boat, sizeof(char), 1, save) != 1)
        return (false);
    return (true);
}

static bool write_boat(char **boat_layout, FILE *save)
{
    int all_size = 0;
    int i = 0;

    for (i = 0; boat_layout[i] != NULL; i += 1)
        all_size += my_strlen(boat_layout[i]) + 1;
    if (fwrite(&all_size, sizeof(int), 1, save) != 1)
        return (false);
    for (i = 0; boat_layout[i] != NULL; i += 1) {
        if (!write_line(boat_layout[i], save))
            return (false);
    }
    return (true);
}

bool save_boat_layout(player_t *player)
{
    FILE *boat_file = NULL;
    bool status = true;

    if (player == NULL || player->boat_layout == NULL)
        return (false);
    boat_file = open_boat_save(player->save.folder);
    status = write_boat(player->boat_layout, boat_file);
    if (boat_file != NULL)
        fclose(boat_file);
    return (status);
}