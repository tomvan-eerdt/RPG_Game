/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** button
*/

#include "rpg.h"

void check_click(sprite_t *sprite, int rect)
{
    sprite->rect.left = rect;
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
}

void check_hover(rpg_t *rpg, sfSprite *sprite, btn_t coords)
{
    if (check_button(rpg, coords))
        sfSprite_setColor(sprite, (sfColor){255, 255, 255, 150});
    else
        sfSprite_setColor(sprite, (sfColor){255, 255, 255, 255});
}

int check_button(rpg_t *rpg, btn_t coord)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->window);

    if (mouse.x < coord.x + coord.width && mouse.y < coord.y + coord.height &&
        mouse.x > coord.x && mouse.y > coord.y)
        return 1;
    return 0;
}

void go_to(rpg_t *rpg, int scene)
{
    sfSound_play(rpg->sounds->click->sound);
    if (scene == EXIT)
        sfRenderWindow_close(rpg->window);
    else {
        rpg->prev_scene = rpg->scene;
        rpg->scene = scene;
    }
}