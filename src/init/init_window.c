/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** init_window
*/

#include "rpg.h"

void init_window(rpg_t *rpg)
{
    sfVideoMode mode;

    if (rpg->is_full == OFF) {
        mode = (sfVideoMode){1082, 830, 32};
        rpg->window = sfRenderWindow_create(mode, "My_Rpg", 7, NULL);
    } else {
        mode = (sfVideoMode){1920, 1080, 32};
        rpg->window = sfRenderWindow_create(mode, "My_Rpg", 8, NULL);
    }
    sfRenderWindow_setFramerateLimit(rpg->window, FPS);
    sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
}