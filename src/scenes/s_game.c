/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_game
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void game_event(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (event.type == sfEvtKeyPressed)
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                go_to(rpg, PAUSE);
        player_input(rpg, event);
        if (event.type == sfEvtKeyReleased)
            sfSprite_setTexture(rpg->sprites->knight->sprite,
                                rpg->texture->player_n_moving, sfFalse);
    }
}

int check_quest_dialogue(rpg_t *rpg)
{
    if (rpg->scene == GAME) {
        if (rpg->quest == 0 || rpg->quest == 2)
            return 1;
    } else {
        if (rpg->quest == 1)
            return 1;
    }
    return 0;
}

int check_user_pnj(rpg_t *rpg)
{
    sfVector2f pnj;
    sfVector2f knight;
    sfVector2f cave_pos = sfSprite_getPosition(rpg->sprites->cave->sprite);

    if (rpg->scene == GAME) {
        pnj = sfSprite_getPosition(rpg->sprites->jack->sprite);
        knight = sfSprite_getPosition(rpg->sprites->knight->sprite);
    } else {
        pnj = sfSprite_getPosition(rpg->sprites->julien->sprite);
        knight = sfSprite_getPosition(rpg->sprites->knight->sprite);
        knight.x = knight.x - cave_pos.x + 20;
        knight.y = knight.y - cave_pos.y + 20;
        pnj.x = pnj.x - cave_pos.x + 20;
        pnj.y = pnj.y - cave_pos.y + 200;
    }
    if (pnj.x >= knight.x - 60 && pnj.x <= knight.x + 60) {
        if (pnj.y >= knight.y - 60 && pnj.y <= knight.y + 60) {
            return 1;
        }
    }
    return 0;
}

void game(rpg_t *rpg)
{
    if (rpg->attack == 1) {
        sfRenderWindow_drawSprite(rpg->window,
                rpg->sprites->sword->sprite, NULL);
        animation_sword(rpg);
    }
    animate_dmg(rpg);
    animation_knight(rpg);
    animation_map(rpg);
    move_ennemies(rpg);
    game_event(rpg);
    draw_all(rpg);
    move_cursor(rpg);
    sfRenderWindow_display(rpg->window);
}
