/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <math.h>

#define HOME 0
#define GAME 1
#define PAUSE 2
#define INVENTORY 3
#define EXIT 4
#define SETTINGS 5
#define HOW 6
#define DIALOGUE 7
#define CAVE 8

#define FPS 60
#define ON 1
#define OFF 0

#define MONEY_BASE 20
#define LIFE 5
#define TIME_MONEY 1
#define CAR_TIMER 0.001
#define DMG_TIMER 1

typedef struct s_clock
{
    sfClock *clock;
    float limit;
} clocks_t;

typedef struct texture_s
{
    sfTexture *player_move;
    sfTexture *player_n_moving;
    sfTexture *quest2;
    sfTexture *quest3;
    sfTexture *dialogue_q_3;
    sfTexture *dialogue_q_4;
} texture_t;

typedef struct all_clock
{
    clocks_t *dt_game;
    clocks_t *dt_pause;
    clocks_t *dt_home;
    clocks_t *car;
    clocks_t *p_mov;
    clocks_t *dmg;
    clocks_t *map;
    clocks_t *julien;
    clocks_t *took_dmg;
    clocks_t *money;
    clocks_t *knight;
    clocks_t *goblin;
    clocks_t *sword;
} all_clock_t;

typedef struct s_sprite
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} sprite_t;

typedef struct s_all_sprites
{
    sprite_t *mouse;
    sprite_t *btn_exit;
    sprite_t *dialogue;
    sprite_t *mission;
    sprite_t *quete;
    sprite_t *btn_menu;
    sprite_t *btn_start;
    sprite_t *knight;
    sprite_t *health_po;
    sprite_t *strength_po;
    sprite_t *sword;
    sprite_t *inventory;
    sprite_t *cave;
    sprite_t *julien;
    sprite_t *pause;
    sprite_t *map;
    sprite_t *home;
    sprite_t *jack;
    sprite_t *sett;
    sprite_t *how;
    sprite_t *screen;
    sprite_t *sound;
    sprite_t *tree;
    sprite_t *hud;
    sprite_t *goblin;
    sprite_t *infos;
} all_sprite_t;

typedef struct goblin_s
{
    int life;
    int attack;
    sprite_t *goblin;
    struct goblin_s *next;
} goblin_t;

typedef struct s_txt
{
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    int value;
    char *txt_char;
} txt_t;

typedef struct s_button
{
    int x;
    int y;
    int width;
    int height;
} btn_t;

typedef struct s_sound
{
    sfSound *sound;
    sfSoundBuffer *buff;
} sound_t;

typedef struct s_all_sound
{
    sfMusic *music;
    sound_t *build;
    sound_t *click;
} all_sound_t;

typedef struct s_rpg
{
    sfRectangleShape *night;
    int scene;
    int prev_scene;
    int is_vol;
    int is_full;
    int attack;
    int quest;
    sfVector2f old_pos;
    goblin_t *goblins[3];
    texture_t *texture;
    sfImage *allowed_mv;
    txt_t *fps;
    txt_t *attack_dmg;
    txt_t *health_potion;
    txt_t *strength_potion;
    txt_t *life;
    sfRenderWindow *window;
    all_clock_t *clocks;
    all_sprite_t *sprites;
    all_sound_t *sounds;
} rpg_t;

int help(void);
void init(rpg_t *rpg);
void init_window(rpg_t *rpg);
txt_t *init_txt(sfVector2f pos, char *txt, int size, int value);
void init_all_clock(rpg_t *rpg);
void init_sprites(rpg_t *rpg);
void init_zones(rpg_t *rpg);
void init_sounds(rpg_t *rpg);
void draw_cave(rpg_t *rpg);
clocks_t *init_clock(float limit);
sprite_t *new_sprite(char *file, sfIntRect rect, sfVector2f pos);
int gameloop(rpg_t *rpg);
void home(rpg_t *rpg);
void game(rpg_t *rpg);
int check_quest_dialogue(rpg_t *rpg);
void s_pause(rpg_t *rpg);
void animation_julien(rpg_t *rpg);
void settings(rpg_t *rpg);
void how(rpg_t *rpg);
void draw_all(rpg_t *rpg);
void restart_game(rpg_t *rpg);
void move_cursor(rpg_t *rpg);
int check_user_pnj(rpg_t *rpg);
void inventory(rpg_t *rpg);
int check_pixel(rpg_t *rpg, int x, int y);
void move_player(rpg_t *rpg);
int check_button(rpg_t *rpg, btn_t coord);
void restart_other_clock(rpg_t *rpg);
void init_texture(rpg_t *rpg);
void animation_goblin(rpg_t *rpg);
void animate_dmg(rpg_t *rpg);
void move_ennemies(rpg_t *rpg);
void go_to(rpg_t *rpg, int scene);
void cave(rpg_t *rpg);
void set_fps(rpg_t *rpg);
void move_npc(rpg_t *rpg, sfVector2f mv);
void set_volume(rpg_t *rpg);
void set_fullscreen(rpg_t *rpg);
void animation_knight(rpg_t *rpg);
void dialogue(rpg_t *rpg);
void init_goblins(rpg_t *rpg);
void player_input(rpg_t *rpg, sfEvent event);
void check_hover(rpg_t *rpg, sfSprite *sprite, btn_t coords);
void check_click(sprite_t *sprite, int rect);
void animation_map(rpg_t *rpg);
void animation_sword(rpg_t *rpg);
int anime(clocks_t *clock);
void draw_sprite(rpg_t *rpg, sprite_t *sprite);

#endif