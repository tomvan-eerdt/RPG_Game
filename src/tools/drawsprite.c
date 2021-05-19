/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** drawsprite
*/

#include "rpg.h"

void draw_sprite(rpg_t *rpg, sprite_t *sprite)
{
    sfRenderWindow_drawSprite(rpg->window, sprite->sprite, NULL);
}