/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_boat.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "player.h"
#include "constants.h"
#include "loader.h"

char **read_file(char const *file);

static FILE *open_boat_save(char const *folder)
{
    char *boat_save = join_path(folder, BOAT_SAVE_FILE);
    FILE *fp = NULL;

    if (boat_save == NULL)
        return (NULL);
    fp = fopen(boat_save, "rb");
    free(boat_save);
    return (fp);
}

static bool get_default_layout(char ***layout)
{
    *layout = read_file(CONFIG_FOLDER "default_boat.txt");
    return (*layout != NULL);
}

static bool load_boat(char ***layout, FILE *save)
{
    char *boat = NULL;
    int boat_size = 0;

    if (save == NULL)
        return (get_default_layout(layout));
    if (fread(&boat_size, sizeof(int), 1, save) != 1)
        return (false);
    boat = my_memset(malloc(sizeof(char) * (boat_size + 1)), 0, boat_size + 1);
    if (boat == NULL)
        return (false);
    if (fread(boat, sizeof(char), boat_size, save) != (size_t)boat_size) {
        free(boat);
        return (false);
    }
    for (int i = 0; i < boat_size; i += 1)
        boat[i] += 'a';
    *layout = my_str_to_word_array(boat, "\n");
    free(boat);
    return (*layout != NULL);
}

bool init_boat_layout(player_t *player)
{
    FILE *boat_file = NULL;
    bool status = true;

    if (player == NULL)
        return (false);
    if (!(player->save.used))
        return (get_default_layout(&player->boat_layout));
    boat_file = open_boat_save(player->save.folder);
    status = load_boat(&player->boat_layout, boat_file);
    if (boat_file != NULL)
        fclose(boat_file);
    return (status);
}