/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** draw
*/

#include "rpg.h"

void move_cursor(rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);
    sprite_t *mouse = rpg->sprites->mouse;

    mouse->pos.x = mouse_pos.x;
    mouse->pos.y = mouse_pos.y;
    sfSprite_setPosition(mouse->sprite, mouse->pos);
    sfRenderWindow_drawSprite(rpg->window, mouse->sprite, NULL);
}

void draw_all(rpg_t *rpg)
{
    sprite_t *arr_sprt[] = {rpg->sprites->map, rpg->sprites->jack,
                            rpg->sprites->knight, rpg->sprites->tree,
                            rpg->sprites->sword, rpg->sprites->hud,
                            rpg->sprites->mission, rpg->sprites->quete,
                            NULL};
    txt_t *arr_txt[] = {rpg->life, NULL};
    sfRenderWindow *win = rpg->window;
    sfSprite *sword = rpg->sprites->sword->sprite;

    for (int i = 0; arr_sprt[i] != NULL; ++i) {
        if (arr_sprt[i]->sprite == sword && rpg->attack == 1)
            sfRenderWindow_drawSprite(win, arr_sprt[i]->sprite, NULL);
        else if (arr_sprt[i]->sprite != sword)
            sfRenderWindow_drawSprite(win, arr_sprt[i]->sprite, NULL);
        if (i == 4 && rpg->quest == 2)
            sfRenderWindow_drawRectangleShape(rpg->window, rpg->night, NULL);
    }
    for (int i = 0; arr_txt[i] != NULL; ++i) {
        sfRenderWindow_drawText(rpg->window, arr_txt[i]->txt, NULL);
    }
}