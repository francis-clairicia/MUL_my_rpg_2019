##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

MAIN				=	src/main.c

SRC_GAME_OBJ		=	src/game_object/create/init_component/construct_advanced_component.c	\
						src/game_object/create/init_component/construct_basic_component.c		\
						src/game_object/create/init_component/init_component.c					\
						src/game_object/create/init_component/set_advanced_component.c			\
						src/game_object/create/init_component/set_basic_component.c				\
						src/game_object/create/create_game_object.c								\
						src/game_object/create/init_core/set_frame_nb.c							\
						src/game_object/create/init_core/set_lapse.c							\
						src/game_object/create/init_core/set_origin.c							\
						src/game_object/create/init_core/set_sprite.c							\
						src/game_object/create/init_core/set_texture.c							\
						src/game_object/create/init_core/set_view_box.c							\
						src/game_object/create/init_game_object.c								\
						src/game_object/free/free_game_object.c									\
						src/game_object/list_utils/body_list_utils.c							\
						src/game_object/list_utils/draw_list.c									\
						src/game_object/list_utils/expand.c										\
						src/game_object/list_utils/find_by_pos.c								\
						src/game_object/list_utils/game_object_list_utils.c						\
						src/game_object/template/templates.c									\
						src/game_object/add_pos.c												\
						src/game_object/animate.c												\
						src/game_object/attack.c												\
						src/game_object/collision.c												\
						src/game_object/comp_utils.c											\
						src/game_object/draw.c													\
						src/game_object/find.c													\
						src/game_object/get_center.c											\
						src/game_object/set_frame.c												\
						src/game_object/set_origin.c											\
						src/game_object/set_pos.c												\
						src/game_object/set_scale.c												\
						src/game_object/update_center.c											\
						src/game_object/update_state.c											\
						src/game_object/update.c												\

SRC_GAMELOOP		=	src/my_rpg.c											\

SRC_SCENE			= 	src/scene/battle/destroy/destroy_background.c			\
						src/scene/battle/destroy/destroy_clouds.c				\
						src/scene/battle/destroy/destroy_ennemy.c				\
						src/scene/battle/destroy/destroy_water.c				\
						src/scene/battle/destroy/destroy.c						\
						src/scene/battle/init/init_background.c					\
						src/scene/battle/init/init_boat.c						\
						src/scene/battle/init/init_player.c						\
						src/scene/battle/init/init_water.c						\
						src/scene/battle/init/init_rain.c						\
						src/scene/battle/init/init.c							\
						src/scene/battle/update/buoyancy_force.c				\
						src/scene/battle/update/clean_clouds.c					\
						src/scene/battle/update/generate_clouds.c				\
						src/scene/battle/update/pirate_collision_solving.c		\
						src/scene/battle/update/player_boat_interact.c			\
						src/scene/battle/update/player_control.c				\
						src/scene/battle/update/update_boat_param.c				\
						src/scene/battle/update/update_boats.c					\
						src/scene/battle/update/update_clouds.c					\
						src/scene/battle/update/update_player.c					\
						src/scene/battle/update/update.c						\
						src/scene/battle/draw.c									\
						src/scene/battle/loop.c									\
						src/scene/menu/init.c									\
						src/scene/menu/loop.c									\
						src/scene/save_chooser/init.c							\
						src/scene/save_chooser/loop.c							\
						src/scene/save_chooser/draw.c							\
						src/scene/save_chooser/new_player/new_player_scene.c	\
						src/scene/save_chooser/new_player/get_pseudo.c			\
						src/scene/settings/init.c								\
						src/scene/settings/loop.c								\
						src/scene/topdown/destroy/destroy_boat.c				\
						src/scene/topdown/destroy/destroy_bullets.c				\
						src/scene/topdown/destroy/destroy_map.c					\
						src/scene/topdown/destroy/destroy.c						\
						src/scene/topdown/init/init_boat.c						\
						src/scene/topdown/init/init_map.c						\
						src/scene/topdown/init/init.c							\
						src/scene/topdown/update/boat_attack.c					\
						src/scene/topdown/update/boat_collision.c				\
						src/scene/topdown/update/boat_death.c					\
						src/scene/topdown/update/control_boat.c					\
						src/scene/topdown/update/update_boat_state.c			\
						src/scene/topdown/update/update_boat.c					\
						src/scene/topdown/update/update_bullet.c				\
						src/scene/topdown/update/update_buoys.c					\
						src/scene/topdown/update/update_view.c					\
						src/scene/topdown/update/update.c						\
						src/scene/topdown/draw.c								\
						src/scene/topdown/loop.c								\


SRC_INPUT_HANDLING	=	src/input_handling/mouse_input.c

SRC_UPDATE_WINDOW 	=	src/update_window/update_tool.c

SRC_VECTOR_ENGINE 	=	src/vector_engine/vec_basic.c							\
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

SRC_LOADER			=	src/loader/load_config_from_file.c

SRC_PLAYER			=	src/player/init_player.c								\
						src/player/destroy_player.c								\
						src/player/save_player_data.c							\
						src/player/load_saves.c									\
						src/player/pseudo/init_pseudo.c							\
						src/player/pseudo/save_pseudo.c							\
						src/player/control/init_control.c						\
						src/player/control/save_control.c						\
						src/player/level/init_level.c							\
						src/player/level/save_level.c							\

SRC_TEST			=	$(SRC_GAME_OBJ)											\
						$(SRC_INPUT_HANDLING)									\
						$(SRC_UPDATE_WINDOW)									\
						$(SRC_PHYSIC_ENGINE)									\
						$(SRC_VECTOR_ENGINE)									\
						$(SRC_MATH_PROCESS)										\
						$(SRC_GAMELOOP)											\
						$(SRC_SCENE)											\
						$(SRC_PLAYER)											\
						$(SRC_LOADER)

SRC					=	$(MAIN) $(SRC_TEST)

override CFLAGS		+=	-Wall -Wextra

override CPPFLAGS	+=	-I./include/											\
						-I./include/calculation/								\
						-I./include/game_object/								\
						-I./include/scenes/										\
						-I./include/scenes/battle								\
						-I./include/scenes/topdown								\
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
	tar -cf $(ASSETS).tar.xz $(ASSETS)

debug:	CFLAGS += -g
debug:	$(MY_LIBS)
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(LDLIBS) $(CFLAGS) $(CPPFLAGS)

tests_run:	LDLIBS += -lcriterion
tests_run:	CFLAGS += --coverage
tests_run:	$(MY_LIBS)
	@find -name "*.gc*" -delete
	$(CC) -o unit_tests $(SRC_TEST) tests/*.c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	-./unit_tests 2>&1 | grep -v "libgcov"
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
	$(MAKE) -s -C lib/my fclean
	$(MAKE) -s -C lib/csfml fclean

re:	fclean all

.NOTPARALLEL:
.PHONY:	all -lmy -lcsfml debug clean fclean re
