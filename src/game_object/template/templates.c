/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** templates
*/

#include "game_object_constructor.h"

const game_obj_constructor_t constructor_list[] = {
    [PIRATE] =
    {
        .path = "assets/img/pirate.png",
        .frame_nb = (unsigned int[]){
                    4,
                    10,
                    6
                    },
        .origin = (sfVector2f[]){
                    {42, 60},
                    {50, 60},
                    {55, 60},
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 69, 60},
                    {0, 60, 84, 60},
                    {20, 20, 30, 30}
                    },
        .state_nb = 3,
        .mass = 20,
        .has_comp = true
    },
    [BOAT1] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = (unsigned int[]){
                    4,
                    },
        .origin = (sfVector2f[]){
                    {32, 32}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 32, 64}
                    },
        .state_nb = 1,
        .mass = 2000,
        .has_comp = false
    },
    [BOAT2] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 64, 32, 64}
                    },
        .state_nb = 1,
        .mass = 2000,
        .has_comp = false
    },
    [BOAT3] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 128, 32, 64}
                    },
        .state_nb = 1,
        .mass = 2000,
        .has_comp = false
    },
    [BOAT4] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 192, 32, 64}
                    },
        .state_nb = 1,
        .mass = 2000,
        .has_comp = false
    },
    [BOAT5] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 256, 32, 64}
                    },
        .state_nb = 1,
        .mass = 2000,
        .has_comp = false
    },
    [SKY] =
    {
        .path = "assets/img/sky.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 1920, 1080}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WATER] =
    {
        .path = "assets/img/water.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WATER2] =
    {
        .path = "assets/img/water2.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {64, 64}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 128, 128}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [RAIN] =
    {
        .path = "assets/img/rain.png",
        .frame_nb = (unsigned int[]){
                    22
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 480, 480}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WOOD1_RECT] =
    {
        .path = "assets/img/wood1.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = 690,
        .has_comp = true
    },
    [WOOD1_LEFT_TRIANGLE] =
    {
        .path = "assets/img/wood1.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {0, 32, 32, 32}
                    },
        .state_nb = 1,
        .mass = 690,
        .has_comp = true
    },
    [WOOD1_RIGHT_TRIANGLE] =
    {
        .path = "assets/img/wood1.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {32, 32, 32, 32}
                    },
        .state_nb = 1,
        .mass = 690,
        .has_comp = true
    },
    [WOOD2_RECT] =
    {
        .path = "assets/img/wood2.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [WOOD2_LEFT_TRIANGLE] =
    {
        .path = "assets/img/wood2.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {0, 32, 32, 32}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [WOOD2_RIGHT_TRIANGLE] =
    {
        .path = "assets/img/wood2.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {32, 32, 32, 32}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [FENCE] =
    {
        .path = "assets/img/fence.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [LADDER] =
    {
        .path = "assets/img/ladder.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD1] =
    {
        .path = "insert_path",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 640, 300}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD2] =
    {
        .path = "insert_path",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {640, 0, 580, 200}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD3] =
    {
        .path = "insert_path",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {641, 201, 200, 100}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD4] =
    {
        .path = "insert_path",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {844, 214, 340, 120}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD5] =
    {
        .path = "insert_path",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {4, 305, 820, 160}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD6] =
    {
        .path = "insert_path",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {826, 339, 460, 151}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD7] =
    {
        .path = "insert_path",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 472, 699, 160}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD8] =
    {
        .path = "insert_path",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {738, 493, 520, 140}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    }
};

const comp_constructor_t *comp_constructor_list[] = {
    [PIRATE] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_CLOCK,
            .type = CLOCK
        },
        {
            .storage_type = TYPE_END
        }
    },
    [WATER2] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_CLOCK,
            .type = CLOCK
        },
        {
            .storage_type = TYPE_END
        }
    },
    [WOOD1_RECT] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_VECTOR_2F,
            .type = SIZE,
            .data = (sfVector2f [1]){{0, 0}},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [WOOD1_LEFT_TRIANGLE] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_VECTOR_2F,
            .type = SIZE,
            .data = (sfVector2f [1]){{0, 0}},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [WOOD1_RIGHT_TRIANGLE] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_VECTOR_2F,
            .type = SIZE,
            .data = (sfVector2f [1]){{0, 0}},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [WOOD2_RECT] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_VECTOR_2F,
            .type = SIZE,
            .data = (sfVector2f [1]){{0, 0}},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [WOOD2_LEFT_TRIANGLE] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_VECTOR_2F,
            .type = SIZE,
            .data = (sfVector2f [1]){{0, 0}},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [WOOD2_RIGHT_TRIANGLE] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_VECTOR_2F,
            .type = SIZE,
            .data = (sfVector2f [1]){{0, 0}},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    }
};