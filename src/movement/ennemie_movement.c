/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_game
*/

#include "lib.h"
#include "rpg.h"
#include <stdlib.h>

void move_npc(rpg_t *rpg, sfVector2f mv)
{
    if (rpg->scene == CAVE) {
        sfSprite_move(rpg->sprites->cave->sprite, mv);
        sfSprite_move(rpg->sprites->julien->sprite, mv);
        sfSprite_move(rpg->sprites->goblin->sprite, mv);
        for (int i = 0; i != 3; i++) {
            if (rpg->goblins[i] != NULL)
                sfSprite_move(rpg->goblins[i]->goblin->sprite, mv);
        }
    }
}

void ennemy_attack(rpg_t *rpg)
{
    rpg->life->value = rpg->life->value - 25;
    if (rpg->life->value <= 0) {
        sfRenderWindow_close(rpg->window);
        exit(1);
    }
    sfText_setString(rpg->life->txt, \
    my_itos(rpg->life->value, 10));
    sfSprite_setColor(rpg->sprites->knight->sprite, sfRed);
    sfClock_restart(rpg->clocks->took_dmg->clock);
}

void ennemie_direction(rpg_t *rpg)
{
    sfVector2f gb;
    sfVector2f k = sfSprite_getPosition(rpg->sprites->knight->sprite);
    int hp = 0;

    for (int i = 0; i != 3; i++) {
        gb = sfSprite_getPosition(rpg->goblins[i]->goblin->sprite);
        hp = rpg->goblins[i]->life;
        if (gb.x >= k.x - 25 && gb.x <= k.x + 25 && hp > 0) {
            if (gb.y >= k.y - 25 && gb.y <= k.y + 25 && rpg->scene == CAVE) {
                if (anime(rpg->clocks->dmg))
                    ennemy_attack(rpg);
            }
        }
    }
}

void move_ennemies(rpg_t *rpg)
{
    ennemie_direction(rpg);
    animation_goblin(rpg);
    animation_julien(rpg);
}