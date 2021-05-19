/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** hover_tower
*/

#include "rpg.h"

void hover_tower(rpg_t *rpg)
{
    sprite_t *s = rpg->sprites->infos;
    btn_t arr_b[4] = {(btn_t){361, 469, 54, 59}, (btn_t){416, 469, 54, 59},
                    (btn_t){470, 469, 54, 59}, (btn_t){524, 469, 54, 59}};
    int arr_i[4] = {0, 40, 80, 120};

    for (int i = 0; i != 4; i++)
        if (check_button(rpg, arr_b[i])) {
            rpg->sprites->infos->rect.top = arr_i[i];
            sfSprite_setTextureRect(s->sprite, s->rect);
            draw_sprite(rpg, rpg->sprites->infos);
            return;
        }
    return;
}