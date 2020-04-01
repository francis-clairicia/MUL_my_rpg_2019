##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

MAIN				=	src/main.c

SRC_PIRATE_LIST		=	src/pirate_list_handling/add_pirate_to_list.c					\
						src/pirate_list_handling/detach_pirate_from_list.c				\
						src/pirate_list_handling/free_pirate_list.c						\
						src/pirate_list_handling/give_pirate_from_list.c				\

SRC					=	$(MAIN) $(SRC_PIRATE_LIST) $(SRC_SAVE_LOAD)

override CFLAGS		+=	-Wall -Wextra

override CPPFLAGS	+=	-I./include/

override LDFLAGS	=	-L./lib

override LDLIBS		+=	-lmy -lcsfml

OBJ					=	$(SRC:.c=.o)

NAME				=	my_rpg

ASSETS				=	assets

all:	$(NAME)

$(NAME):	CFLAGS += -O2
$(NAME):	$(LDLIBS)
$(NAME):	LDLIBS += -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm
$(NAME):	$(OBJ) #$(ASSETS)
	$(LINK.o) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
	$(MAKE) -s -C ./lib/my

-lcsfml:
	$(MAKE) -s -C ./lib/csfml

$(ASSETS):
	tar -xf assets.tar.xz

debug:	CFLAGS += -g
debug:	$(LDLIBS)
debug:	LDLIBS += -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm
debug:
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(LDLIBS) $(CFLAGS) $(CPPFLAGS)

tests_run:	LDLIBS += -lcriterion
tests_run:	CFLAGS += --coverage
tests_run:	$(LDLIBS)
	@find -name "*.gc*" -delete
	$(CC) -o unit_tests $(SRC_TEST) tests/*.c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./unit_tests
	$(RM) unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

clean:
	$(RM) $(OBJ)
	$(MAKE) -C lib/my clean
	$(RM) unit_tests *.gc*

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(OBJ)
	$(RM) -r $(ASSETS)
	$(MAKE) -C lib/my fclean

re:	fclean all

.NOTPARALLEL:
.PHONY:	all -lmy -lcsfml debug clean fclean re
