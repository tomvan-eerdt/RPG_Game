/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** gamelopp
*/

#include "rpg.h"
#include "lib.h"

void restart_other_clock(rpg_t *rpg)
{
    clocks_t *arr_clock[6] = {rpg->clocks->dt_home, rpg->clocks->dt_game,
                            rpg->clocks->dt_pause, rpg->clocks->dt_game,
                            rpg->clocks->dt_home, rpg->clocks->dt_home};

    for (int i = 0; i < 6; ++i) {
        if (i != rpg->scene)
            sfClock_restart(arr_clock[i]->clock);
    }
}

int gameloop(rpg_t *rpg)
{
    int scene[] = {HOME, GAME, PAUSE, SETTINGS, HOW,
                    INVENTORY, DIALOGUE, CAVE, -1};
    void (*scene_display[])(rpg_t *) = {home, game, s_pause, settings,
                                        how, inventory, dialogue, cave};

    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, sfWhite);
        for (int i = 0; scene[i] != -1; i++)
            if (rpg->scene == scene[i])
                scene_display[i](rpg);
    }
    return 0;
}