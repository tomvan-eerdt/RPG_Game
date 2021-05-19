/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** init_clock
*/

#include "rpg.h"
#include <stdlib.h>

sfTexture *create_texture(char *path)
{
    return sfTexture_createFromFile(path, NULL);
}

void init_texture(rpg_t *rpg)
{
    rpg->texture = malloc(sizeof(texture_t));
    texture_t *t = rpg->texture;

    t->player_move = create_texture("asset/img/knight_run.png");
    t->player_n_moving = create_texture("asset/img/still_knight.png");
    t->quest2 = create_texture("asset/img/quete2.png");
    t->quest3 = create_texture("asset/img/quete3.png");
    t->dialogue_q_3 = create_texture("asset/img/dialogue_quest3.png");
    t->dialogue_q_4 = create_texture("asset/img/dialogue_quest4.png");
}