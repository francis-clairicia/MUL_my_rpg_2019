/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_file_with_config.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "loader.h"
#include "my.h"

static int get_element(const config_t config_table[], char c)
{
    int i = 0;

    for (i = 0; config_table && config_table[i].on_txt != '\0'; i += 1) {
        if (config_table[i].on_txt == c)
            return (config_table[i].element);
    }
    return (-1);
}

static bool create_line(list_t **list, char const *line,
    size_t line_nb, const config_t config_table[])
{
    int element;
    game_obj_t *obj = NULL;
    sfVector2f pos = {0, 0};
    int i = 0;

    for (i = 0; line[i] != '\0'; i += 1) {
        element = get_element(config_table, line[i]);
        if (element < 0)
            continue;
        obj = create_game_obj(element);
        if (obj == NULL)
            return (false);
        MY_APPEND_TO_LIST(list, obj);
        pos.x = i * obj->view_box[0].width;
        pos.y = line_nb * obj->view_box[0].height;
        set_game_object_pos(obj, pos);
    }
    return (true);
}

list_t *load_file_with_config(char const *file, const config_t config_table[])
{
    list_t *list = NULL;
    int fd = (!file || !config_table) ? -1 : open(file, O_RDONLY);
    char *line = NULL;
    bool status = true;
    register size_t line_nb = 0;

    if (fd < 0)
        return (NULL);
    while (status == true && get_next_line_2(&line, fd))
        status = create_line(&list, line, line_nb++, config_table);
    free(line);
    close(fd);
    if (status == false)
        my_free_list(&list, &free_game_object);
    return (list);
}

list_t *create_list_from_array(char * const *array,
    const config_t config_table[])
{
    list_t *list = NULL;

    if (!array || !config_table)
        return (NULL);
    for (register int i = 0; array[i] != NULL; i += 1) {
        if (create_line(&list, array[i], i, config_table) == false) {
            my_free_list(&list, &free_game_object);
            break;
        }
    }
    return (list);
}