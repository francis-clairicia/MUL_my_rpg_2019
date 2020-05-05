/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** load_saves.c
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "player.h"

static void create_config_file(char const *config)
{
    int fd = open(config, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    my_putstr_fd(fd, "IN_USE=0\n");
    close(fd);
}

bool load_one_save(save_t *save, char const *folder)
{
    char *config = join_path(folder, CONFIG_SAVE_FILE);
    char *line = NULL;
    int fd = 0;

    if (config == NULL)
        return (false);
    fd = open(config, O_RDONLY);
    while (get_next_line_2(&line, fd)) {
        if (my_strncmp(line, "IN_USE=", 7) == 0)
            break;
    }
    close(fd);
    save->folder = folder;
    if (line == NULL) {
        save->used = false;
        create_config_file(config);
    } else
        save->used = (my_getnbr(&line[my_strchr_index(line, '=') + 1]) != 0);
    free(line);
    free(config);
    return (true);
}

bool load_all_saves(player_t players[3])
{
    int i = 0;
    save_t save;

    if (players == NULL)
        return (false);
    for (i = 0; i < 3; i += 1) {
        if (!load_one_save(&save, save_folders[i]))
            return (false);
        if (!init_player(&players[i], save))
            return (false);
    }
    return (true);
}