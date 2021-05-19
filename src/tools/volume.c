/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** volume
*/

#include "rpg.h"

void volume_off(rpg_t *rpg)
{
    all_sound_t *s = rpg->sounds;
    sound_t *arr_s[2] = {s->build, s->click};
    sfIntRect sound_r = rpg->sprites->sound->rect;

    for (int i = 0; i < 2; ++i)
        sfSound_setVolume(arr_s[i]->sound, 0);
    sfMusic_setVolume(rpg->sounds->music, 0);
    sound_r.left = 39;
    sfSprite_setTextureRect(rpg->sprites->sound->sprite, sound_r);
}

void volume_on(rpg_t *rpg)
{
    sfIntRect sound_r = rpg->sprites->sound->rect;

    sfSound_setVolume(rpg->sounds->build->sound, 100.0);
    sfSound_setVolume(rpg->sounds->click->sound, 100.0);
    sfMusic_setVolume(rpg->sounds->music, 50.0);
    sound_r.left = 0;
    sfSprite_setTextureRect(rpg->sprites->sound->sprite, sound_r);
}

void set_volume(rpg_t *rpg)
{
    if (rpg->is_vol == ON) {
        volume_off(rpg);
        rpg->is_vol = OFF;
    } else {
        volume_on(rpg);
        rpg->is_vol = ON;
    }
}