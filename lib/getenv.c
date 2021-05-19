/*
** EPITECH PROJECT, 2021
** base
** File description:
** getenv
*/

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int my_strcmp(char const *s1, char const *s2);

int browse_env(char *env_line, char *path)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 50);

    while (env_line[i] != '=') {
        str[i] = env_line[i];
        i = i + 1;
    }
    if (my_strcmp(path, str) == 0) {
        return (1);
    }
    free(str);
    return (0);
}

char *get_env(char **env, char *path)
{
    int i = 0;

    while (env[i] != NULL) {
        if (browse_env(env[i], path) == 1) {
            return (env[i]);
        }
        i = i + 1;
    }
    return (NULL);
}