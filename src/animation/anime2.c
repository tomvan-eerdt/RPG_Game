/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** anime
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void animate_dmg(rpg_t *rpg)
{
    if (anime(rpg->clocks->took_dmg)) {
        sfSprite_setColor(rpg->sprites->knight->sprite, sfWhite);
        for (int i = 0; i != 3; i++) {
            if (rpg->goblins[i]->life > 0)
                sfSprite_setColor(rpg->goblins[i]->goblin->sprite, \
                sfWhite);
        }
    }
}

void animation_sword(rpg_t *rpg)
{
    float rotation = sfSprite_getRotation(rpg->sprites->sword->sprite);

    if (anime(rpg->clocks->sword)) {
        if (rotation == 50) {
            rpg->attack = 0;
            sfSprite_setRotation(rpg->sprites->sword->sprite, -20);
        }
        sfSprite_setRotation(rpg->sprites->sword->sprite, rotation + 20);
    }
}
