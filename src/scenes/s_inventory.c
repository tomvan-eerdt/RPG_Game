/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_game
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void check_potions(rpg_t *rpg)
{
    if (check_button(rpg, (btn_t) {456, 297, 60, 60})) {
        if (rpg->life->value < 100 && rpg->health_potion->value > 0) {
            rpg->health_potion->value -= 1;
            rpg->life->value = 100;
            sfText_setString(rpg->life->txt, \
            my_itos(rpg->life->value, 10));
            sfText_setString(rpg->health_potion->txt,
            my_itos(rpg->health_potion->value, 10));
        }
    }
    if (check_button(rpg, (btn_t) {567, 306, 60, 60})) {
        if (rpg->strength_potion->value > 0) {
            rpg->attack_dmg->value = 50;
            rpg->strength_potion->value -= 1;
            sfText_setString(rpg->attack_dmg->txt,
            my_itos(rpg->attack_dmg->value, 10));
            sfText_setString(rpg->strength_potion->txt,
            my_itos(rpg->strength_potion->value, 10));
        }
    }
}

void inventory_event(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (sfKeyboard_isKeyPressed(sfKeyB)) {
            sfText_setPosition(rpg->life->txt, (sfVector2f){115, 33.5});
            sfSprite_setPosition(rpg->sprites->knight->sprite, rpg->old_pos);
            sfText_setCharacterSize(rpg->life->txt, 22);
            rpg->scene = rpg->prev_scene;
        }
        if (event.type == sfEvtMouseButtonReleased)
            check_potions(rpg);
    }
}

void draw_inventory(rpg_t *rpg)
{
    sprite_t *zone = rpg->sprites->map;
    if (rpg->prev_scene == CAVE)
        zone = rpg->sprites->cave;
    sprite_t *arr_sprt[] = {zone, rpg->sprites->inventory,
                            rpg->sprites->knight, rpg->sprites->health_po,
                            rpg->sprites->strength_po, NULL};
    txt_t *arr_txt[] = {rpg->attack_dmg, rpg->life,
                        rpg->strength_potion, rpg->health_potion, NULL};
    sfRenderWindow *win = rpg->window;

    sfRenderWindow_clear(rpg->window, sfBlack);
    for (int i = 0; arr_sprt[i] != NULL; ++i)
        sfRenderWindow_drawSprite(win, arr_sprt[i]->sprite, NULL);
    for (int i = 0; arr_txt[i] != NULL; ++i)
        sfRenderWindow_drawText(rpg->window, arr_txt[i]->txt, NULL);
}

void inventory(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->sprites->knight->sprite, (sfVector2f){340, 330});
    inventory_event(rpg);
    animation_knight(rpg);
    draw_inventory(rpg);
    move_cursor(rpg);
    sfRenderWindow_display(rpg->window);
}