/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** anime
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

int anime(clocks_t *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock->clock);
    if (sfTime_asSeconds(time) > clock->limit) {
        sfClock_restart(clock->clock);
        return 1;
    }
    return 0;
}

void animation_goblin(rpg_t *rpg)
{
    sfIntRect pos;
    sfSprite *g = NULL;

    if (anime(rpg->clocks->goblin)) {
        for (int i = 0; i != 3; i++) {
            if (rpg->goblins[i] != NULL) {
                g = rpg->goblins[i]->goblin->sprite;
                pos = sfSprite_getTextureRect(g);
                pos.left = pos.left + 16;
                sfSprite_setTextureRect(g, pos);
                if (sfSprite_getTextureRect(g).left >= 96) {
                    pos.left = 0;
                    sfSprite_setTextureRect(g, pos);
                }
            }
        }
    }
}

void animation_julien(rpg_t *rpg)
{
    sfIntRect pos = sfSprite_getTextureRect(rpg->sprites->julien->sprite);

    if (anime(rpg->clocks->julien)) {
        pos.left = pos.left + 50;
        sfSprite_setTextureRect(rpg->sprites->julien->sprite, pos);
        if (sfSprite_getTextureRect(rpg->sprites->julien->sprite).left > 100) {
            pos.left = 0;
            sfSprite_setTextureRect(rpg->sprites->julien->sprite, pos);
        }
    }
}

void animation_knight(rpg_t *rpg)
{
    sfIntRect pos = sfSprite_getTextureRect(rpg->sprites->knight->sprite);

    if (anime(rpg->clocks->knight)) {
        pos.left = pos.left + 16;
        sfSprite_setTextureRect(rpg->sprites->knight->sprite, pos);
        if (sfSprite_getTextureRect(rpg->sprites->knight->sprite).left >= 96) {
            pos.left = 0;
            sfSprite_setTextureRect(rpg->sprites->knight->sprite, pos);
        }
    }
}

void animation_map(rpg_t *rpg)
{
    sfIntRect pos = sfSprite_getTextureRect(rpg->sprites->map->sprite);

    if (anime(rpg->clocks->map)) {
        pos.left = pos.left + 1082;
        sfSprite_setTextureRect(rpg->sprites->map->sprite, pos);
        if (sfSprite_getTextureRect(rpg->sprites->map->sprite).left >= 3246) {
            pos.left = 0;
            sfSprite_setTextureRect(rpg->sprites->map->sprite, pos);
        }
    }
}