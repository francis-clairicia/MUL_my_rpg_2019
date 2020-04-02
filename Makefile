##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

MAIN				=	src/main.c

# SRC_GAME_OBJ		=	src/game_object/init_advanced_component.c			\
# 						src/game_object/set_basic_component.c				\
# 						src/game_object/free_game_object.c					\
# 						src/game_object/init_game_object.c					\
# 						src/game_object/init_basic_component.c				\
# 						src/game_object/draw_game_object.c					\
# 						src/game_object/find_game_object.c					\
# 						src/game_object/set_advanced_component.c			\
# 						src/game_object/get_config_path.c					\
# 						src/game_object/set_game_object_param.c				\
# 						src/game_object/init_component.c					\
# 						src/game_object/add_game_obj_to_list.c				\
# 						src/game_object/create_game_object.c				\
# 						src/game_object/init_game_object_param.c

SRC_GAMELOOP		=	src/my_rpg.c

SRC_MENU			= 	src/menu/init.c										\
						src/menu/loop.c										\

SRC_PIRATE_LIST		=	src/pirate_list_handling/add_pirate_to_list.c		\
						src/pirate_list_handling/detach_pirate_from_list.c	\
						src/pirate_list_handling/free_pirate_list.c			\
						src/pirate_list_handling/give_pirate_from_list.c	\

SRC_INPUT_HANDLING	=	src/input_handling/mouse_input.c					\

SRC_UPDATE_WINDOW 	=	src/update_window/update_tool.c						\

SRC_VECTOR_ENGINE 	=	src/vector_engine/min_max.c										\
						src/vector_engine/vec_basic.c									\
						src/vector_engine/vec_cross.c									\
						src/vector_engine/vec_dot.c										\
						src/vector_engine/vec_lim.c										\
						src/vector_engine/vec_mag.c										\
						src/vector_engine/vec_norm.c									\
						src/vector_engine/vec_normal.c									\

SRC_PHYSIC_ENGINE	=	src/physic_engine/apply_force.c									\
						src/physic_engine/sat_collision.c								\
						src/physic_engine/update_obb.c									\
						src/physic_engine/update_rigid_body.c							\

SRC					=	$(MAIN) $(SRC_GAMELOOP) $(SRC_MENU) $(SRC_PIRATE_LIST) $(SRC_SAVE_LOAD) $(SRC_INPUT_HANDLING) $(SRC_UPDATE_WINDOW) $(SRC_PHYSIC_ENGINE) $(SRC_VECTOR_ENGINE)

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
$(NAME):	LDLIBS += -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm
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
debug:	LDLIBS += -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm
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
	$(MAKE) -s -C lib/my clean
	$(MAKE) -s -C lib/csfml clean
	$(RM) unit_tests *.gc*

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(OBJ)
	$(MAKE) -s -C lib/my fclean
	$(MAKE) -s -C lib/csfml fclean

re:	fclean all

.NOTPARALLEL:
.PHONY:	all -lmy -lcsfml debug clean fclean re
