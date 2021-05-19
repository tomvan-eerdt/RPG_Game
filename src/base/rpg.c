/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** rpg
*/

#include "lib.h"
#include "rpg.h"

int check_usage(char **argv)
{
    for (int i = 0; argv[i] != NULL; i++)
        if (!my_strcmp(argv[i], "-h"))
            return 1;
    return 0;
}

int check_error(int argc, char **argv, char **env)
{
    if (get_env(env, "DISPLAY") == NULL)
        return (0);
    argc = argc;
    argv = argv;
    return 0;
}

int my_rpg(int argc, char **argv, char **env)
{
    rpg_t rpg;

    if (check_usage(argv))
        return help();
    if (check_error(argc, argv, env))
        return 84;
    init(&rpg);
    gameloop(&rpg);
    return 0;
}