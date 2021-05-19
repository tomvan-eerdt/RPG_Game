/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_home
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void handle_buttons(rpg_t *rpg)
{
    if (check_button(rpg, (btn_t) {466, 494, 150, 40})) {
        sfMusic_stop(rpg->sounds->music);
        go_to(rpg, GAME);
    }
    if (check_button(rpg, (btn_t) {466, 545, 150, 40}))
        go_to(rpg, EXIT);
    if (check_button(rpg, (btn_t) {1040, 16, 45, 45}))
        go_to(rpg, SETTINGS);
    if (check_button(rpg, (btn_t) {1040, 48, 38, 47}))
        go_to(rpg, HOW);
}

void home_btn(rpg_t *rpg, sfEvent event)
{
    if (event.mouseButton.button == sfMouseLeft) {
        if (event.type == sfEvtMouseButtonReleased) {
            handle_buttons(rpg);
            check_click(rpg->sprites->btn_start, 0);
            check_click(rpg->sprites->btn_exit, 0);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if (check_button(rpg, (btn_t) {466, 494, 150, 40}))
                check_click(rpg->sprites->btn_start, 152);
            if (check_button(rpg, (btn_t) {466, 545, 150, 40}))
                check_click(rpg->sprites->btn_exit, 152);
        }
    }
}

void home_event(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        check_hover(rpg, rpg->sprites->btn_exit->sprite,
                    (btn_t) {466, 545, 150, 40});
        check_hover(rpg, rpg->sprites->btn_start->sprite,
                    (btn_t) {466, 494, 150, 40});
        home_btn(rpg, event);
    }
}

void draw_home(rpg_t *rpg)
{
    all_sprite_t *spr = rpg->sprites;

    spr->btn_exit->pos = (sfVector2f){466, 545};
    sfSprite_setPosition(spr->btn_exit->sprite, spr->btn_exit->pos);
    sfRenderWindow_clear(rpg->window, sfBlack);
    restart_other_clock(rpg);
    sfRenderWindow_drawSprite(rpg->window, spr->home->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, spr->btn_exit->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, spr->btn_start->sprite, NULL);
    move_cursor(rpg);
}

void home(rpg_t *rpg)
{
    home_event(rpg);
    draw_home(rpg);
    sfRenderWindow_display(rpg->window);
}