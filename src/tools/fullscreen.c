/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** fullscreen
*/

#include "rpg.h"

void set_fullscreen(rpg_t *rpg)
{
    switch (rpg->is_full) {
        case ON:
            rpg->is_full = OFF;
            break;
        case OFF:
            rpg->is_full = ON;
            break;
    }
    sfRenderWindow_destroy(rpg->window);
    init_window(rpg);
}