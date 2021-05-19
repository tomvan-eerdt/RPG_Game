/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_pause
*/

#include "rpg.h"
#include "lib.h"

void pause_btn(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonReleased) {
        if (check_button(rpg, (btn_t) {640, 240, 22, 22}))
            go_to(rpg, rpg->prev_scene);
        if (check_button(rpg, (btn_t) {464, 390, 150, 40})) {
            sfMusic_play(rpg->sounds->music);
            go_to(rpg, HOME);
        }
        if (check_button(rpg, (btn_t) {464, 450, 150, 40}))
            go_to(rpg, EXIT);
        check_click(rpg->sprites->btn_menu, 0);
        check_click(rpg->sprites->btn_exit, 0);
    }
    if (event->type == sfEvtMouseButtonPressed) {
        if (check_button(rpg, (btn_t) {464, 390, 150, 40}))
            check_click(rpg->sprites->btn_menu, 152);
        if (check_button(rpg, (btn_t) {464, 450, 150, 40}))
            check_click(rpg->sprites->btn_exit, 152);
    }
}

void pause_event(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        rpg->scene = rpg->prev_scene;
    check_hover(rpg, rpg->sprites->btn_exit->sprite,
                (btn_t){464, 450, 150, 40});
    check_hover(rpg, rpg->sprites->btn_menu->sprite,
                (btn_t){464, 390, 150, 40});
    if (event->mouseButton.button == sfMouseLeft)
        pause_btn(rpg, event);
}

void draw_pause(rpg_t *rpg)
{
    all_sprite_t *spr = rpg->sprites;

    spr->btn_exit->pos = (sfVector2f){464, 450};
    sfSprite_setPosition(spr->btn_exit->sprite, spr->btn_exit->pos);
    sfRenderWindow_clear(rpg->window, sfBlack);
    if (rpg->prev_scene == GAME)
        draw_all(rpg);
    else
        draw_cave(rpg);
    restart_other_clock(rpg);
    sfRenderWindow_drawSprite(rpg->window, spr->pause->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, spr->btn_exit->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, spr->btn_menu->sprite, NULL);
    move_cursor(rpg);
}

void s_pause(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event))
        pause_event(rpg, &event);
    draw_pause(rpg);
    sfRenderWindow_display(rpg->window);
}