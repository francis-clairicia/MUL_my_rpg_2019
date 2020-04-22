/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load_boat_from_file.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "rpg.h"
#include "boat.h"

static boat_config_t config_table[] = {
    {"WOOD1_RECT", 0, WOOD1_RECT},
    {"WOOD1_LEFT_TRIANGLE", 0, WOOD1_LEFT_TRIANGLE},
    {"WOOD1_RIGHT_TRIANGLE", 0, WOOD1_RIGHT_TRIANGLE},
    {"WOOD2_RECT", 0, WOOD2_RECT},
    {"WOOD2_LEFT_TRIANGLE", 0, WOOD2_LEFT_TRIANGLE},
    {"WOOD2_RIGHT_TRIANGLE", 0, WOOD2_RIGHT_TRIANGLE},
    {NULL, 0, -1}
};

static bool set_variable_value(char const *line)
{
    int equal_index = my_strchr_index(line, '=');
    char const *var = NULL;
    int i = 0;

    if (equal_index < 0)
        return (false);
    for (i = 0; config_table[i].variable != NULL; i += 1) {
        var = config_table[i].variable;
        if (my_strncmp(line, var, my_strlen(var)) == 0)
            config_table[i].on_txt = line[equal_index + 1];
    }
    return (true);
}

static bool set_config(char const *file)
{
    char extension[] = ".conf";
    char conf[my_strlen(file) + my_strlen(extension) + 1];
    int fd = 0;
    char *line = NULL;
    bool status = true;

    my_strcat(my_strcpy(conf, file), extension);
    fd = open(conf, O_RDONLY);
    while (status == true && get_next_line(&line, fd))
        status = set_variable_value(line);
    if (line != NULL)
        free(line);
    if (fd != -1)
        close(fd);
    return ((fd != -1) && status == true);
}

static bool create_line(list_t **list, char const *line, size_t line_nb)
{
    elem_t element;
    game_obj_t *obj = NULL;
    int i = 0;

    for (i = 0; line[i] != '\0'; i += 1) {
        element = get_element(config_table, line[i]);
        if (element < 0)
            continue;
        obj = create_game_obj(element);
        if (obj == NULL)
            return (false);
        MY_APPEND_TO_LIST(list, obj);
        set_game_object_pos(obj, VEC2F(i * obj->view_box[0].width,
                                line_nb * obj->view_box[0].height));
    }
    return (true);
}

static bool load_boat(list_t **list, char const *file)
{
    char extension[] = ".txt";
    char txt[my_strlen(file) + my_strlen(extension) + 1];
    int fd = 0;
    char *line = NULL;
    bool status = true;
    register size_t line_nb = 0;

    my_strcat(my_strcpy(txt, file), extension);
    fd = open(txt, O_RDONLY);
    while (status == true && get_next_line(&line, fd))
        status = create_line(list, line, line_nb++);
    if (line != NULL)
        free(line);
    if (fd != -1)
        close(fd);
    return ((fd != -1) && (status == true));
}

list_t *load_boat_from_file(char const *file)
{
    list_t *list = NULL;

    if (file == NULL || !set_config(file))
        return (NULL);
    if (!load_boat(&list, file))
        my_free_list(&list, &free_game_object);
    return (list);
}