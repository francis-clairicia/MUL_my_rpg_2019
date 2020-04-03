/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Main function of my_rpg program.
*/

#include "rpg.h"
#include "game_object.h"

int my_rpg(void);

static int valid_environment(char **envp)
{
    int i = 0;

    if (envp[0] == NULL)
        return (0);
    while (envp[i] != NULL) {
        if (my_strncmp(envp[i], "DISPLAY", my_strlen("DISPLAY")) == 0)
            return (1);
        i += 1;
    }
    return (0);
}

int main(int ac __attribute__((unused)),
    char **av __attribute__((unused)), char **envp)
{
    if (!valid_environment(envp))
        return (84);
    return (my_rpg());
}