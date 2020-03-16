##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## My_RPG Makefile
##

MAIN				=	src/main.c

SRC_PIRATE_LIST		=	src/pirate_list_handling/add_pirate_to_list.c					\
						src/pirate_list_handling/detach_pirate_from_list.c				\
						src/pirate_list_handling/free_pirate_list.c						\
						src/pirate_list_handling/give_pirate_from_list.c				\

SRC_SAVE_LOAD		=	src/save_load_handling/check_file_extension.c					\
						src/save_load_handling/load_pirate_from_file.c					\

OBJ					=	$(MAIN:.c=.o)													\
						$(SRC_PIRATE_LIST:.c=.o)										\
						$(SRC_SAVE_LOAD.c=.o)											\

NAME 				=	my_rpg

override CFLAGS		+=	-W -Wall -Wextra

override CPPFLAGS	+=	-I./include/

override LDFLAGS	+=	-L./lib/

override LDLIBS		+= 	-lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

LIB 				=	lib/libmy.a

ASSETS				=	assets

all:					$(NAME)

$(NAME):				$(LIB) $(OBJ) $(ASSETS)
						$(LINK.o) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIB):
						$(MAKE) -C ./lib/my

$(ASSETS):
						tar -xf assets.tar.xz

debug:					CPPFLAGS += -g
debug:					clean $(LIB) $(OBJ)
						$(CC) -o $@ $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:				LDLIBS += -lcriterion --coverage
tests_run:				CFLAGS += --coverage
tests_run:				$(LIB)
						$(CC) -o $@ $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
						./$@
						mv *.gc* tests/
						$(RM) $@

clean:
						$(RM) $(OBJ)
						$(MAKE) -C lib/my clean

fclean:					clean
						$(RM) $(NAME)
						$(RM) $(OBJ)
						$(RM) -r $(ASSETS)
						$(MAKE) -C lib/my fclean

re:			 			fclean all

.NOTPARALLEL:
.PHONY:					debug all clean fclean re tests_run
