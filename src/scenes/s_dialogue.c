/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** s_pause
*/

#include "rpg.h"
#include "lib.h"

void handle_quests(rpg_t *rpg)
{
    if (rpg->quest == 0) {
        sfSprite_setTexture(rpg->sprites->quete->sprite,
                rpg->texture->quest2, sfFalse);
        sfSprite_setTexture(rpg->sprites->dialogue->sprite,
                rpg->texture->dialogue_q_3, sfFalse);
    }
    if (rpg->quest == 1) {
        sfSprite_setTexture(rpg->sprites->quete->sprite,
                rpg->texture->quest3, sfFalse);
        sfSprite_setTexture(rpg->sprites->dialogue->sprite,
                rpg->texture->dialogue_q_4, sfFalse);
        rpg->health_potion->value += 1;
        sfText_setString(rpg->health_potion->txt,
        my_itos(rpg->health_potion->value, 10));
    }
    if (rpg->quest == 2)
        sfRenderWindow_close(rpg->window);
    else
        go_to(rpg, rpg->prev_scene);
    rpg->quest = rpg->quest + 1;
}

void dialogue_event(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        rpg->scene = rpg->prev_scene;
    if (event->type == sfEvtMouseButtonReleased) {
        if (check_button(rpg, (btn_t) {359, 690, 110, 30}))
            handle_quests(rpg);
        if (check_button(rpg, (btn_t) {566, 690, 110, 30}))
            go_to(rpg, rpg->prev_scene);
    }
}

void draw_dialogue(rpg_t *rpg)
{
    all_sprite_t *spr = rpg->sprites;

    sfRenderWindow_drawSprite(rpg->window, spr->dialogue->sprite, NULL);
    move_cursor(rpg);
}

void dialogue(rpg_t *rpg)
{
    sfEvent event;

    sfSprite_setTexture(rpg->sprites->knight->sprite,
                        rpg->texture->player_n_moving, sfFalse);
    while (sfRenderWindow_pollEvent(rpg->window, &event))
        dialogue_event(rpg, &event);
    if (rpg->prev_scene == GAME)
        draw_all(rpg);
    else
        draw_cave(rpg);
    animation_knight(rpg);
    draw_dialogue(rpg);
    sfRenderWindow_display(rpg->window);
}