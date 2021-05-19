/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_how
*/

#include "rpg.h"
#include "lib.h"

void how_event(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (sfMouse_isButtonPressed(0))
        if (check_button(rpg, (btn_t){21, 21, 131, 61}))
            go_to(rpg, HOME);
}

void how(rpg_t *rpg)
{
    all_sprite_t *spr = rpg->sprites;
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event))
        how_event(rpg, &event);
    sfRenderWindow_clear(rpg->window, sfBlack);
    restart_other_clock(rpg);
    sfRenderWindow_drawSprite(rpg->window, spr->how->sprite, NULL);
    move_cursor(rpg);
    sfRenderWindow_display(rpg->window);
}