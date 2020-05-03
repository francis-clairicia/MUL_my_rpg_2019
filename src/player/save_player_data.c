/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save_player_data.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "player.h"
#include "my.h"

static const player_field_save_t save_function[] = {
    &save_pseudo,
    &save_control,
    &save_level,
    NULL
};

static bool write_in_config(player_t *player)
{
    int fd = 0;
    char *config = NULL;

    if (player->save.used == true)
        return (true);
    config = join_path(player->save.folder, CONFIG_SAVE_FILE);
    if (config == NULL)
        return (false);
    fd = open(config, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return (false);
    my_putstr_fd(fd, "IN_USE=1\n");
    close(fd);
    player->save.used = true;
    return (true);
}

bool save_player_data(player_t *player)
{
    if (player == NULL)
        return (false);
    if (!write_in_config(player))
        return (false);
    for (int i = 0; save_function[i] != NULL; i += 1) {
        if (save_function[i](player) == false)
            return (false);
    }
    return (true);
}