/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_settings
*/

#include "rpg.h"
#include "lib.h"

void check_sett(rpg_t *rpg)
{
    if (check_button(rpg, (btn_t){7, 7, 38, 38}))
        go_to(rpg, HOME);
    if (check_button(rpg, (btn_t){520, 425, 50, 40}))
        set_volume(rpg);
    if (check_button(rpg, (btn_t){520, 340, 95, 40}))
        set_fps(rpg);
}

void sett_event(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (sfMouse_isButtonPressed(0))
            check_sett(rpg);
    }
}

void settings(rpg_t *rpg)
{
    all_sprite_t *spr = rpg->sprites;

    sett_event(rpg);
    sfRenderWindow_clear(rpg->window, sfBlack);
    restart_other_clock(rpg);
    sfRenderWindow_drawSprite(rpg->window, spr->sett->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, spr->sound->sprite, NULL);
    sfRenderWindow_drawText(rpg->window, rpg->fps->txt, NULL);
    move_cursor(rpg);
    sfRenderWindow_display(rpg->window);
}