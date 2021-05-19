/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** fps
*/

#include "rpg.h"

void set_fps(rpg_t *rpg)
{
    int new_fps;
    char *new;

    switch (rpg->fps->value) {
        case 30:
            new_fps = 60;
            new = "60";
            break;
        case 60:
            new_fps = 120;
            new = "120";
            break;
        default:
            new_fps = 30;
            new = "30";
            break;
    }
    sfText_setString(rpg->fps->txt, new);
    sfRenderWindow_setFramerateLimit(rpg->window, new_fps);
    rpg->fps->value = new_fps;
}