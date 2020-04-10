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
        .path = "insert_path",
        .frame_nb = 3,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 100, 100),
        .mass = 20,
        .has_comp = true
    },
    [BOAT1] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = 4,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 32, 64),
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [BOAT2] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = 4,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 64, 32, 64),
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [BOAT3] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = 4,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 128, 32, 64),
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [BOAT4] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = 4,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 192, 32, 64),
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [BOAT5] =
    {
        .path = "assets/img/boats.png",
        .frame_nb = 4,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 256, 32, 64),
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [FLORIAN] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 100, 100),
        .mass = __FLT_MAX__,
        .has_comp = true
    },
    [SKY] =
    {
        .path = "assets/img/sky.png",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 1920, 1080),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WATER] =
    {
        .path = "assets/img/water.png",
        .frame_nb = 4,
        .origin = VEC2F(16, 16),
        .view_box = IRECT(0, 0, 32, 32),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [RAIN] =
    {
        .path = "assets/img/rain.png",
        .frame_nb = 22,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 480, 480),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WOOD1_RECT] =
    {
        .path = "assets/img/wood1.png",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 32, 32),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WOOD1_LEFT_TRIANGLE] =
    {
        .path = "assets/img/wood1.png",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(32, 0, 32, 32),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WOOD1_RIGHT_TRIANGLE] =
    {
        .path = "assets/img/wood1.png",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(32, 32, 32, 32),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WOOD2_RECT] =
    {
        .path = "assets/img/wood2.png",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 32, 32),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WOOD2_LEFT_TRIANGLE] =
    {
        .path = "assets/img/wood2.png",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(32, 0, 32, 32),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [WOOD2_RIGHT_TRIANGLE] =
    {
        .path = "assets/img/wood2.png",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(32, 32, 32, 32),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [FENCE] =
    {
        .path = "assets/img/fence.png",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 32, 32),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [LADDER] =
    {
        .path = "assets/img/ladder.png",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 32, 32),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD1] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 0, 640, 300),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD2] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(640, 0, 580, 200),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD3] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(641, 201, 200, 100),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD4] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(844, 214, 340, 120),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD5] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(4, 305, 820, 160),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD6] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(826, 339, 460, 151),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD7] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(0, 472, 699, 160),
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [CLOUD8] =
    {
        .path = "insert_path",
        .frame_nb = 1,
        .origin = VEC2F(0, 0),
        .view_box = IRECT(738, 493, 520, 140),
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
    [FLORIAN] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_CLOCK,
            .type = CLOCK
        },
        {
            .storage_type = TYPE_VECTOR_2F,
            .type = OFFSET,
            .data = (sfVector2f [1]){{10, 10}},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_SOUND,
            .type = SOUND,
            .data = "insert_path",
            .data2 = (int [1]){10}
            },
        {
            .storage_type = TYPE_END
        }
    }
};