##
## EPITECH PROJECT, 2021
## B-MUL-200-BDX-2-1-myrpg-tom.vaneerdt
## File description:
## Makefile
##

##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC_LIB		=	lib/clonestr.c					\
				lib/my_in.c						\
				lib/my_itos.c					\
				lib/my_strcat.c					\
				lib/my_strcmp.c					\
				lib/load_file.c					\
				lib/my_strlen.c					\
				lib/my_putstr.c					\
				lib/my_revstr.c					\
				lib/my_getnbr.c					\
				lib/getenv.c

SRC			=	$(SRC_LIB)						\
				src/animation/anime.c			\
				src/animation/anime2.c			\
				src/base/rpg.c					\
				src/base/gameloop.c				\
				src/base/help.c					\
				src/base/draw.c					\
				src/init/init_clock.c			\
				src/init/init.c					\
				src/init/init_window.c			\
				src/init/init_txt.c				\
				src/init/init_sprites.c			\
				src/init/init_zones.c			\
				src/init/init_texture.c			\
				src/init/init_sound.c			\
				src/movement/player_input.c		\
				src/movement/player_movement.c	\
				src/movement/ennemie_movement.c \
				src/scenes/s_game.c				\
				src/scenes/s_home.c				\
				src/scenes/s_pause.c			\
				src/scenes/s_cave.c				\
				src/scenes/s_inventory.c		\
				src/scenes/s_settings.c			\
				src/scenes/s_dialogue.c			\
				src/scenes/s_how.c				\
				src/tools/button.c				\
				src/tools/fps.c					\
				src/tools/fullscreen.c			\
				src/tools/volume.c				\
				src/tools/drawsprite.c			\
				src/tools/hover_tower.c			\

SRC_ALL		=	$(SRC)							\
				src/main.c

TESTS		=	$(SRC)							\
				tests/test.c

LDFLAGS		=	-lcsfml-graphics -lcsfml-window -l csfml-system -lcsfml-audio -lm

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS	=	-Iinclude

CC			=	gcc -g -no-pie

DIR_GCOVR	=	gcovr/

OBJ			=	$(SRC_ALL:.c=.o)

T_OBJ		=	$(TESTS:.c=.o)

NAME		=	my_rpg

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(T_OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

tests_run: $(T_OBJ)
	$(CC) -o unit_tests ${SRC_TEST} -Iinclude tests/test.c --coverage -lcriterion
	./unit_tests

gcovr: tests_run
	mkdir -p $(DIR_GCOVR) && cd $(DIR_GCOVR); \
		gcovr --root ../ --exclude "../tests" --html --html-details --html-title $(NAME) -o $(NAME).html