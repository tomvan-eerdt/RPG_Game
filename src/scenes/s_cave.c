/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_game
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void cave_event(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (event.type == sfEvtKeyPressed)
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                go_to(rpg, PAUSE);
        player_input(rpg, event);
        if (event.type == sfEvtKeyReleased)
            sfSprite_setTexture(rpg->sprites->knight->sprite,
                                rpg->texture->player_n_moving, sfFalse);
    }
}

void draw_goblins(rpg_t *rpg)
{
    for (int i = 0; i != 3; i++) {
        sfRenderWindow_drawSprite(rpg->window,
        rpg->goblins[i]->goblin->sprite, NULL);
    }
}

void draw_cave(rpg_t *rpg)
{
    sprite_t *spr[] = {rpg->sprites->cave,
                            rpg->sprites->knight, rpg->sprites->sword,
                            rpg->sprites->mission, rpg->sprites->quete,
                            rpg->sprites->julien, rpg->sprites->hud, NULL};
    sfRenderWindow *win = rpg->window;
    txt_t *arr_txt[] = {rpg->life, NULL};

    for (int i = 0; spr[i] != NULL; ++i) {
        if (spr[i]->sprite == rpg->sprites->sword->sprite && rpg->attack == 1)
            sfRenderWindow_drawSprite(win, spr[i]->sprite, NULL);
        else if (spr[i]->sprite != rpg->sprites->sword->sprite)
            sfRenderWindow_drawSprite(win, spr[i]->sprite, NULL);
        if (i == 5) {
            draw_goblins(rpg);
        }
    }
    for (int i = 0; arr_txt[i] != NULL; ++i)
        sfRenderWindow_drawText(rpg->window, arr_txt[i]->txt, NULL);
}

void cave(rpg_t *rpg)
{
    if (rpg->attack == 1) {
        sfRenderWindow_drawSprite(rpg->window,
                rpg->sprites->sword->sprite, NULL);
        animation_sword(rpg);
    }
    sfRenderWindow_clear(rpg->window, (sfColor){0, 0, 0, 0});
    animate_dmg(rpg);
    animation_knight(rpg);
    animation_julien(rpg);
    move_ennemies(rpg);
    animation_goblin(rpg);
    check_user_pnj(rpg);
    cave_event(rpg);
    draw_cave(rpg);
    move_cursor(rpg);
    sfRenderWindow_display(rpg->window);
}
