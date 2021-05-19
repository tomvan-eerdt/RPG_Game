/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** init
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void init_goblins(rpg_t *rpg)
{
    sfVector2f pos = {480, 600};

    for (int i = 0; i != 3; i++) {
        rpg->goblins[i] = malloc(sizeof(goblin_t));
        rpg->goblins[i]->life = 100;
        rpg->goblins[i]->attack = 25;
        rpg->goblins[i]->goblin = new_sprite("goblin_run.png",
        (sfIntRect){0, 0, 16, 16}, pos);
        sfSprite_setScale(rpg->goblins[i]->goblin->sprite, (sfVector2f){3, 3});
        sfSprite_setOrigin(rpg->goblins[i]->goblin->sprite, (sfVector2f){8, 8});
        pos.y += 150;
    }
}

void init_p2(rpg_t *rpg)
{
    sfColor night = sfColor_fromRGBA(5, 15, 70, 150);
    rpg->attack = 25;
    init_sprites(rpg);
    init_all_clock(rpg);
    init_sounds(rpg);
    init_texture(rpg);
    rpg->allowed_mv = sfImage_createFromFile("asset/img/map/mv.png");
    rpg->night = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->night, (sfVector2f){1082, 830});
    sfRectangleShape_setFillColor(rpg->night, night);
    rpg->quest = 0;
    init_goblins(rpg);
}

void init(rpg_t *rpg)
{
    char *txt = my_itos(MONEY_BASE, 10);
    char *fps = my_itos(FPS, 10);

    rpg->is_full = OFF;
    init_window(rpg);
    rpg->scene = HOME;
    rpg->fps = init_txt((sfVector2f){520, 340}, fps, 30, FPS);
    rpg->life = init_txt((sfVector2f){115, 33.5}, "100", 22, 100);
    rpg->attack_dmg = init_txt((sfVector2f){313, 480}, "25", 13, 25);
    rpg->strength_potion = init_txt((sfVector2f){567, 306}, "1", 15, 1);
    rpg->health_potion = init_txt((sfVector2f){460, 306}, "0", 15, 0);
    rpg->is_vol = ON;
    sfText_setColor(rpg->fps->txt, sfBlack);
    free(txt);
    free(fps);
    init_p2(rpg);
}