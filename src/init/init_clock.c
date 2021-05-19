/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** init_clock
*/

#include "rpg.h"
#include <stdlib.h>

clocks_t *init_clock(float limit)
{
    clocks_t *clock = malloc(sizeof(clocks_t));

    clock->clock = sfClock_create();
    clock->limit = limit;
    return clock;
}

void init_all_clock(rpg_t *rpg)
{
    all_clock_t *clock = malloc(sizeof(all_clock_t));

    clock->dt_game = init_clock(0);
    clock->dt_home = init_clock(0);
    clock->dt_pause = init_clock(0);
    clock->car = init_clock(CAR_TIMER);
    clock->money = init_clock(TIME_MONEY);
    clock->knight = init_clock(0.1);
    clock->goblin = init_clock(0.1);
    clock->julien = init_clock(0.2);
    clock->p_mov = init_clock(0.005);
    clock->map = init_clock(0.1);
    clock->sword = init_clock(0.008);
    clock->dmg = init_clock(DMG_TIMER);
    clock->took_dmg = init_clock(0.5);
    rpg->clocks = clock;
}