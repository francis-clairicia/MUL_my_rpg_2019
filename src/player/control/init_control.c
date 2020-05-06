/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_control
*/

#include <stdio.h>
#include "my.h"
#include "player.h"

static const control_t control_template = {
    .keys[CONTROL_UP] = sfKeyZ,
    .keys[CONTROL_DOWN] = sfKeyS,
    .keys[CONTROL_LEFT] = sfKeyQ,
    .keys[CONTROL_RIGHT] = sfKeyD,
    .keys[CONTROL_USE] = sfKeyE,
    .keys[CONTROL_ATTACK1] = sfKeyJ,
    .keys[CONTROL_ATTACK2] = sfKeyL,
    .keys[CONTROL_ZOOM_UP] = sfKeyI,
    .keys[CONTROL_ZOOM_DOWN] = sfKeyK,
};

static FILE *open_control_save(char const *folder)
{
    char *control_save = join_path(folder, CONTROL_SAVE_FILE);
    FILE *fp = NULL;

    if (control_save == NULL)
        return (NULL);
    fp = fopen(control_save, "rb");
    free(control_save);
    return (fp);
}

static bool load_controls(control_t *control, FILE *save)
{
    if (save == NULL) {
        *control = control_template;
        return (true);
    }
    return (fread(control, sizeof(control_t), 1, save) > 0);
}

bool init_control(player_t *player)
{
    FILE *control_file = NULL;
    bool status = true;

    if (player == NULL)
        return (false);
    if (!(player->save.used)) {
        player->control = control_template;
        return (true);
    }
    control_file = open_control_save(player->save.folder);
    status = load_controls(&player->control, control_file);
    if (control_file != NULL)
        fclose(control_file);
    return (status);
}