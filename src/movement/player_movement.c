/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_game
*/

#include "rpg.h"

void move_up(rpg_t *rpg, sfVector2f p_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (rpg->scene == CAVE)
            p_pos.y = p_pos.y + 12;
        else
            p_pos.y = p_pos.y - 12;
        if (check_pixel(rpg, p_pos.x, p_pos.y) == 1) {
            if (rpg->scene == GAME) {
                sfSprite_move(rpg->sprites->knight->sprite,
                        (sfVector2f) {0, -4});
                sfSprite_move(rpg->sprites->sword->sprite,
                        (sfVector2f) {0, -4});
            }
            move_npc(rpg, (sfVector2f) {0, -4});
        }
    }
}

void move_down(rpg_t *rpg, sfVector2f p_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (rpg->scene == CAVE)
            p_pos.y = p_pos.y - 12;
        else
            p_pos.y = p_pos.y + 12;
        if (check_pixel(rpg, p_pos.x, p_pos.y) == 1) {
            if (rpg->scene == GAME) {
                sfSprite_move(rpg->sprites->knight->sprite,
                        (sfVector2f) {0, 4});
                sfSprite_move(rpg->sprites->sword->sprite,
                        (sfVector2f) {0, 4});
            }
            move_npc(rpg, (sfVector2f) {0, 4});
        }
    }
}

void move_right(rpg_t *rpg, sfSprite *knight, sfVector2f p_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        if (rpg->scene == CAVE)
            p_pos.x = p_pos.x + 12;
        else
            p_pos.x = p_pos.x + 24;
        if (check_pixel(rpg, p_pos.x, p_pos.y) == 1) {
            sfSprite_setScale(knight, (sfVector2f) {3, 3});
            if (rpg->scene == GAME) {
                sfSprite_move(knight, (sfVector2f) {4, 0});
                sfSprite_move(rpg->sprites->sword->sprite, (sfVector2f) {4, 0});
            }
            move_npc(rpg, (sfVector2f) {-4, 0});
        }
    }
}

void move_left(rpg_t *rpg, sfSprite *knight, sfVector2f p_pos)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        if (rpg->scene == CAVE)
            p_pos.x = p_pos.x - 12;
        else
            p_pos.x = p_pos.x - 24;
        if (check_pixel(rpg, p_pos.x - 12, p_pos.y) == 1) {
            sfSprite_setScale(knight, (sfVector2f) {-3, 3});
            if (rpg->scene == GAME) {
                sfSprite_move(knight, (sfVector2f) {-4, 0});
                sfSprite_move(rpg->sprites->sword->sprite,
                        (sfVector2f) {-4, 0});
            }
            move_npc(rpg, (sfVector2f) {4, 0});
        }
    }
}

void move_player(rpg_t *rpg)
{
    sfVector2f horizontal = sfSprite_getPosition(rpg->sprites->knight->sprite);
    sfVector2f vertical = sfSprite_getPosition(rpg->sprites->knight->sprite);
    sfVector2f cave_pos = sfSprite_getPosition(rpg->sprites->cave->sprite);
    sfSprite *knight = rpg->sprites->knight->sprite;

    if (rpg->scene == CAVE) {
        horizontal.x = horizontal.x - cave_pos.x + 20;
        horizontal.y = horizontal.y - cave_pos.y + 20;
        vertical.x = vertical.x - cave_pos.x;
        vertical.y = vertical.y - cave_pos.y;
    }
    move_left(rpg, knight, horizontal);
    move_right(rpg, knight, horizontal);
    move_up(rpg, vertical);
    move_down(rpg, vertical);
}