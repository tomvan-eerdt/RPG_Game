/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** init_sprites
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

sprite_t *new_sprite(char *file, sfIntRect rect, sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    char *filepath = my_strcat("asset/img/", file);

    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    free(filepath);
    return sprite;
}

void add_style(all_sprite_t *s)
{
    sfSprite_setOrigin(s->jack->sprite, (sfVector2f){15, 15});
    sfSprite_setScale(s->sword->sprite, (sfVector2f){3, 3});
    sfSprite_setScale(s->jack->sprite, (sfVector2f){2.3, 2.3});
    sfSprite_setScale(s->julien->sprite, (sfVector2f){1.3, 1.3});
    sfSprite_setRotation(s->sword->sprite, 110);
    sfSprite_setOrigin(s->sword->sprite, (sfVector2f){0, 14});
    sfSprite_setScale(s->knight->sprite, (sfVector2f){3, 3});
    sfSprite_setOrigin(s->knight->sprite, (sfVector2f){8, 8});
    sfSprite_setScale(s->health_po->sprite, (sfVector2f){0.7, 0.7});
    sfSprite_setScale(s->strength_po->sprite, (sfVector2f){0.8, 0.8});
}

void init_sprites3(all_sprite_t *s)
{
    s->sound = new_sprite("sound.png", (sfIntRect){0, 0, 39, 34},
                        (sfVector2f){520, 425});
    s->jack = new_sprite("pnj.png", (sfIntRect){0, 0, 39, 34},
                        (sfVector2f){320, 455});
    s->dialogue = new_sprite("dialogue_quest1.png",
            (sfIntRect){0, 0, 1082, 830}, (sfVector2f){0, 0});
    s->cave = new_sprite("map/cave.png", (sfIntRect){0, 0, 3000, 3000},
                        (sfVector2f){0, 0});
    s->infos = new_sprite("info.png", (sfIntRect){0, 0, 126, 40},
                        (sfVector2f){409, 398});
    s->sword = new_sprite("sword.png", (sfIntRect){0, 0, 126, 40},
                        (sfVector2f){100, 550});
    s->julien = new_sprite("smith.png", (sfIntRect){0, 0, 50, 256},
                        (sfVector2f){1500, 1500});
    s->btn_start = new_sprite("start.png", (sfIntRect){0, 0, 152, 39},
                        (sfVector2f){466, 494});
    add_style(s);
}

void init_sprites2(all_sprite_t *s)
{
    s->hud = new_sprite("hud.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0});
    s->health_po = new_sprite("health_potion.png", (sfIntRect){0, 0, 60, 60},
                        (sfVector2f){467, 307});
    s->strength_po = new_sprite("strength_potion.png",
            (sfIntRect){0, 0, 60, 60}, (sfVector2f){567, 306});
    s->how = new_sprite("how_to.png", (sfIntRect){0, 0, 1082, 830},
                        (sfVector2f){0, 0});
    s->sett = new_sprite("settings.png", (sfIntRect){0, 0, 1082, 830},
                        (sfVector2f){0, 0});
    s->inventory = new_sprite("inventory.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0});
    s->knight = new_sprite("still_knight.png", (sfIntRect){0, 0, 16, 16},
                        (sfVector2f){100, 550});
    s->goblin = new_sprite("goblin_run.png", (sfIntRect){0, 0, 16, 16},
                        (sfVector2f){480, 600});
    s->tree = new_sprite("map/tree.png", (sfIntRect){0, 0, 1082, 830},
                        (sfVector2f){0, 0});
    init_sprites3(s);
}

void init_sprites(rpg_t *rpg)
{
    all_sprite_t *s = malloc(sizeof(all_sprite_t));

    s->mouse = new_sprite("cursor.png", (sfIntRect){0, 0, 27, 28},
                        (sfVector2f){0, 0});
    s->pause = new_sprite("pause.png", (sfIntRect){0, 0, 1082, 830},
                        (sfVector2f){0, 0});
    s->home = new_sprite("home.png", (sfIntRect){0, 0, 1082, 830},
                        (sfVector2f){0, 0});
    s->map = new_sprite("map/mapp.png", (sfIntRect){0, 0, 1082, 830},
                        (sfVector2f){0, 0});
    s->btn_exit = new_sprite("exit.png", (sfIntRect){0, 0, 152, 39},
                        (sfVector2f){404, 49});
    s->btn_menu = new_sprite("menu.png", (sfIntRect){0, 0, 152, 39},
                        (sfVector2f){464, 390});
    s->mission = new_sprite("mission.png", (sfIntRect){0, 0, 1082, 830},
                        (sfVector2f){0, 0});
    s->quete = new_sprite("quete1.png", (sfIntRect){0, 0, 1082, 830},
                        (sfVector2f){0, 0});
    init_sprites2(s);
    rpg->sprites = s;
}