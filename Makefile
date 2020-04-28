##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

MAIN				=	src/main.c

SRC_GAME_OBJ		=	src/game_object/create/construct_advanced_component.c	\
						src/game_object/create/construct_basic_component.c		\
						src/game_object/create/create_game_object.c				\
						src/game_object/create/init_component.c					\
						src/game_object/create/init_game_object_core.c			\
						src/game_object/create/init_game_object.c				\
						src/game_object/create/set_advanced_component.c			\
						src/game_object/create/set_basic_component.c			\
						src/game_object/free/free_game_object.c					\
						src/game_object/list_utils/body_list_utils.c			\
						src/game_object/list_utils/draw_list.c					\
						src/game_object/list_utils/expand.c						\
						src/game_object/list_utils/find_by_pos.c				\
						src/game_object/list_utils/game_object_list_utils.c		\
						src/game_object/template/templates.c					\
						src/game_object/add_pos.c								\
						src/game_object/animate.c								\
						src/game_object/collision.c								\
						src/game_object/comp_utils.c							\
						src/game_object/draw.c									\
						src/game_object/find.c									\
						src/game_object/set_frame.c								\
						src/game_object/set_origin.c							\
						src/game_object/set_pos.c								\
						src/game_object/set_scale.c								\
						src/game_object/update_state.c							\
						src/game_object/update.c								\

SRC_GAMELOOP		=	src/my_rpg.c											\

SRC_SCENE			= 	src/scene/battle/init/init_background.c					\
						src/scene/battle/init/init_boat.c						\
						src/scene/battle/init/init_player.c						\
						src/scene/battle/init/init_water.c						\
						src/scene/battle/init/init.c							\
						src/scene/battle/update/buoyancy_force.c				\
						src/scene/battle/update/control_player.c				\
						src/scene/battle/update/update_boat_param.c				\
						src/scene/battle/update/update_boats.c					\
						src/scene/battle/update/update_player.c					\
						src/scene/battle/update/update.c						\
						src/scene/battle/draw.c									\
						src/scene/battle/loop.c									\
						src/scene/menu/init.c									\
						src/scene/menu/loop.c									\
						src/scene/save_chooser/init.c							\
						src/scene/save_chooser/loop.c							\
						src/scene/save_chooser/load_saves.c						\


SRC_INPUT_HANDLING	=	src/input_handling/mouse_input.c

SRC_UPDATE_WINDOW 	=	src/update_window/update_tool.c

SRC_VECTOR_ENGINE 	=	src/vector_engine/min_max.c								\
						src/vector_engine/vec_basic.c							\
						src/vector_engine/vec_cross.c							\
						src/vector_engine/vec_dot.c								\
						src/vector_engine/vec_lim.c								\
						src/vector_engine/vec_mag.c								\
						src/vector_engine/vec_norm.c							\
						src/vector_engine/vec_normal.c							\

SRC_PHYSIC_ENGINE	=	src/physic_engine/force/apply_force.c					\
						src/physic_engine/force/friction_force.c				\
						src/physic_engine/force/traction_force.c				\
						src/physic_engine/body_add_acc.c						\
						src/physic_engine/sat_collision.c						\
						src/physic_engine/update_obb.c							\
						src/physic_engine/update_rigid_body.c					\

SRC_MATH_PROCESS	=	src/math_process/get_randnb.c							\
						src/math_process/magnet_number.c						\

SRC_BOAT			=	src/boat/load_boat_from_file.c

SRC_CONTROL			=	src/control/init_control.c								\
						src/control/template.c									\

SRC					=	$(MAIN)													\
						$(SRC_GAME_OBJ)											\
						$(SRC_INPUT_HANDLING)									\
						$(SRC_UPDATE_WINDOW)									\
						$(SRC_PHYSIC_ENGINE)									\
						$(SRC_VECTOR_ENGINE)									\
						$(SRC_GAMELOOP)											\
						$(SRC_SCENE)											\
						$(SRC_BOAT)												\
						$(SRC_CONTROL)											\

override CFLAGS		+=	-Wall -Wextra

override CPPFLAGS	+=	-I./include/											\
						-I./include/game_object/								\
						-I./include/calculation/								\
						-I./include/scenes/										\
						-I./include/scenes/battle								\
						-I./include/pirates/									\

MY_LIBS				=	-lmy -lcsfml

override LDFLAGS	=	-L./lib

override LDLIBS		+=	$(MY_LIBS) -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

OBJ					=	$(SRC:.c=.o)

NAME				=	my_rpg

ASSETS				=	assets

all:	$(NAME)

$(NAME):	CFLAGS += -O2
$(NAME):	$(MY_LIBS) $(OBJ) $(ASSETS)
	$(LINK.o) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
	$(MAKE) -s -C ./lib/my

-lcsfml:
	$(MAKE) -s -C ./lib/csfml

$(ASSETS):
	tar -xf $@.tar.xz

compress:
	tar -cf assets.tar.xz $(ASSETS)

debug:	CFLAGS += -g
debug:	$(MY_LIBS)
	$(CC) -o $@ $(SRC) $(LDFLAGS) $(LDLIBS) $(CFLAGS) $(CPPFLAGS)

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
	$(RM) -r $(ASSETS)
	$(RM) $(NAME)
	$(RM) $(OBJ)
	$(MAKE) -s -C lib/my fclean
	$(MAKE) -s -C lib/csfml fclean

re:	fclean all

.NOTPARALLEL:
.PHONY:	all -lmy -lcsfml debug clean fclean re
