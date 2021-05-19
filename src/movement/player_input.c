/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_game
*/

#include "rpg.h"

void change_zone(rpg_t *rpg)
{
    struct s_all_sprites *sp = rpg->sprites;

    if (rpg->scene == GAME) {
        rpg->allowed_mv = sfImage_createFromFile("asset/img/map/mv_cave.png");
        sfSprite_setPosition(sp->knight->sprite, (sfVector2f) {541, 415});
        sfSprite_setPosition(sp->sword->sprite, (sfVector2f) {541, 415});
        sfSprite_setPosition(sp->cave->sprite, (sfVector2f) {-940, 268});
        rpg->scene = CAVE;
    } else {
        rpg->allowed_mv = sfImage_createFromFile("asset/img/map/mv.png");
        sfSprite_setPosition(sp->knight->sprite, (sfVector2f) {860, 450});
        sfSprite_setPosition(sp->sword->sprite, (sfVector2f) {860, 450});
        rpg->scene = GAME;
    }
}

int check_pixel(rpg_t *rpg, int x, int y)
{
    sfColor pixel = sfImage_getPixel(rpg->allowed_mv, x, y);
    if (pixel.r == 255 && pixel.g == 0 && pixel.b == 0)
        return 0;
    else if (pixel.r == 255 && pixel.g == 255 && pixel.b == 0) {
        change_zone(rpg);
        return 1;
    }
    else
        return 1;
}

void p_attack(rpg_t *rpg)
{
    sfVector2f gb;
    sfVector2f knight = sfSprite_getPosition(rpg->sprites->knight->sprite);
    int hp;

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        rpg->attack = 1;
        for (int i = 0; i != 3; i++) {
            gb = sfSprite_getPosition(rpg->goblins[i]->goblin->sprite);
            hp = rpg->goblins[i]->life;
            if (gb.x >= knight.x - 60 && gb.x <= knight.x + 60 && hp >= 0) {
                if (gb.y >= knight.y - 60 && gb.y <= knight.y + 60) {
                    sfClock_restart(rpg->clocks->took_dmg->clock);
                    sfSprite_setColor(rpg->goblins[i]->goblin->sprite, sfRed);
                    rpg->goblins[i]->life -= rpg->attack_dmg->value;
                }
            }
            if (rpg->goblins[i]->life <= 0)
                sfSprite_setColor(rpg->goblins[i]->goblin->sprite,
                        sfTransparent);
        }
    }
}

void open_dialogue(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyB)) {
        rpg->old_pos = sfSprite_getPosition(rpg->sprites->knight->sprite);
        sfSprite_setTexture(rpg->sprites->knight->sprite,
                rpg->texture->player_n_moving, sfFalse);
        sfText_setPosition(rpg->life->txt, (sfVector2f) {313, 447});
        sfText_setCharacterSize(rpg->life->txt, 13);
        go_to(rpg, INVENTORY);
    }
}

void player_input(rpg_t *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        sfSprite_setTexture(rpg->sprites->knight->sprite,
                            rpg->texture->player_move, sfFalse);
        open_dialogue(rpg);
        p_attack(rpg);
        if (anime(rpg->clocks->p_mov))
            move_player(rpg);
        if (sfKeyboard_isKeyPressed(sfKeyT) && check_user_pnj(rpg) == 1) {
            if (check_quest_dialogue(rpg)) {
                    go_to(rpg, DIALOGUE);
            }
        }
    }
}