/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** templates
*/

#include "game_object_constructor.h"
#include "constants.h"

const game_obj_constructor_t constructor_list[] = {
    [PIRATE] =
    {
        .path = IMG_FOLDER "pirate.png",
        .frame_nb = (unsigned int[]){
                    4,
                    10,
                    10,
                    6,
                    6
                    },
        .lapse = (unsigned int[]){
                    2000,
                    100,
                    100,
                    100,
                    100
                    },
        .origin = (sfVector2f[]){
                    {42, 60},
                    {50, 60},
                    {35, 60},
                    {55, 60},
                    {41, 60}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 69, 60},
                    {0, 60, 84, 60},
                    {0, 120, 84, 60},
                    {0, 180, 96, 60},
                    {0, 240, 96, 60}
                    },
        .state_nb = 5,
        .mass = 20,
        .has_comp = true
    },
    [BOAT1] =
    {
        .path = IMG_FOLDER "boats.png",
        .frame_nb = (unsigned int[]){
                    4,
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 32}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 32, 64}
                    },
        .state_nb = 1,
        .mass = 600,
        .has_comp = true
    },
    [BOAT2] =
    {
        .path = IMG_FOLDER "boats.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 32}
                    },
        .view_box = (sfIntRect[]){
                    {0, 64, 32, 64}
                    },
        .state_nb = 1,
        .mass = 600,
        .has_comp = true
    },
    [BOAT3] =
    {
        .path = IMG_FOLDER "boats.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 32}
                    },
        .view_box = (sfIntRect[]){
                    {0, 128, 32, 64}
                    },
        .state_nb = 1,
        .mass = 600,
        .has_comp = true
    },
    [BOAT4] =
    {
        .path = IMG_FOLDER "boats.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 32}
                    },
        .view_box = (sfIntRect[]){
                    {0, 192, 32, 64}
                    },
        .state_nb = 1,
        .mass = 600,
        .has_comp = true
    },
    [BOAT5] =
    {
        .path = IMG_FOLDER "boats.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 32}
                    },
        .view_box = (sfIntRect[]){
                    {0, 256, 32, 64}
                    },
        .state_nb = 1,
        .mass = 500,
        .has_comp = true
    },
    [BULLET] =
    {
        .path = IMG_FOLDER "bullet.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {4, 4}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 8, 8}
                    },
        .state_nb = 1,
        .mass = 20,
        .has_comp = true
    },
    [SKY] =
    {
        .path = IMG_FOLDER "sky.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
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
        .path = IMG_FOLDER "water.png",
        .frame_nb = (unsigned int[]){
                    4
                    },
        .lapse = (unsigned int[]){
                    500,
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
    [WATER2] =
    {
        .path = IMG_FOLDER "water2.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = (unsigned int[]){
                    100
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
    [SAND] =
    {
        .path = IMG_FOLDER "sand.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = (unsigned int[]){
                    100
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
    [DIRT] =
    {
        .path = IMG_FOLDER "dirt.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = (unsigned int[]){
                    100
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
    [BUOY1] =
    {
        .path = IMG_FOLDER "buoy.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
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
    [BUOY2] =
    {
        .path = IMG_FOLDER "buoy.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {32, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [BUOY3] =
    {
        .path = IMG_FOLDER "buoy.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {64, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [BUOY4] =
    {
        .path = IMG_FOLDER "buoy.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {96, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = __FLT_MAX__,
        .has_comp = false
    },
    [RAIN] =
    {
        .path = IMG_FOLDER "rain.png",
        .frame_nb = (unsigned int[]){
                    22
                    },
        .lapse = (unsigned int[]){
                    100
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
        .path = IMG_FOLDER "wood1.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
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
        .path = IMG_FOLDER "wood1.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
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
        .path = IMG_FOLDER "wood1.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
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
        .path = IMG_FOLDER "wood2.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
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
    [WOOD2_LEFT_TRIANGLE] =
    {
        .path = IMG_FOLDER "wood2.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
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
    [WOOD2_RIGHT_TRIANGLE] =
    {
        .path = IMG_FOLDER "wood2.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
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
    [FENCE] =
    {
        .path = IMG_FOLDER "fence.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = 690,
        .has_comp = false
    },
    [LADDER] =
    {
        .path = IMG_FOLDER "ladder.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {16, 16}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 32, 32}
                    },
        .state_nb = 1,
        .mass = 690,
        .has_comp = false
    },
    [CLOUD1] =
    {
        .path = IMG_FOLDER "cloud.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 0, 640, 300}
                    },
        .state_nb = 1,
        .mass = 1,
        .has_comp = false
    },
    [CLOUD2] =
    {
        .path = IMG_FOLDER "cloud.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {640, 0, 580, 200}
                    },
        .state_nb = 1,
        .mass = 1,
        .has_comp = false
    },
    [CLOUD3] =
    {
        .path = IMG_FOLDER "cloud.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {641, 201, 200, 100}
                    },
        .state_nb = 1,
        .mass = 1,
        .has_comp = false
    },
    [CLOUD4] =
    {
        .path = IMG_FOLDER "cloud.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {844, 214, 340, 120}
                    },
        .state_nb = 1,
        .mass = 1,
        .has_comp = false
    },
    [CLOUD5] =
    {
        .path = IMG_FOLDER "cloud.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {4, 305, 820, 160}
                    },
        .state_nb = 1,
        .mass = 1,
        .has_comp = false
    },
    [CLOUD6] =
    {
        .path = IMG_FOLDER "cloud.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {826, 339, 460, 151}
                    },
        .state_nb = 1,
        .mass = 1,
        .has_comp = false
    },
    [CLOUD7] =
    {
        .path = IMG_FOLDER "cloud.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {0, 472, 699, 160}
                    },
        .state_nb = 1,
        .mass = 1,
        .has_comp = false
    },
    [CLOUD8] =
    {
        .path = IMG_FOLDER "cloud.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
        .origin = (sfVector2f[]){
                    {0, 0}
                    },
        .view_box = (sfIntRect[]){
                    {738, 493, 520, 140}
                    },
        .state_nb = 1,
        .mass = 1,
        .has_comp = false
    },
    [TILLER] =
    {
        .path = IMG_FOLDER "tiller.png",
        .frame_nb = (unsigned int[]){
                    1
                    },
        .lapse = NULL,
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
};

const comp_constructor_t *comp_constructor_list[] = {
    [PIRATE] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_CLOCK,
            .type = CLOCK
        },
        {
            .storage_type = TYPE_INT,
            .type = IS_DRIVING,
            .data = (int[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = CAN_JUMP,
            .data = (int[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = XP,
            .data = (int[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = LVL,
            .data = (int[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = LIFE,
            .data = (int[1]){PIRATE_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = MAX_LIFE,
            .data = (int[1]){PIRATE_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = DAMAGE,
            .data = (int[1]){10},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = INVINCIBLE,
            .data = (int[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_CLOCK,
            .type = INVINCIBLE_TIME,
        },
        {
            .storage_type = TYPE_FLOAT,
            .type = ATTACK_SPEED,
            .data = (float[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_CLOCK,
            .type = ATTACK_TIME,
        },
        {
            .storage_type = TYPE_END
        }
    },
    [BOAT1] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_INT,
            .type = XP,
            .data = (int[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = LVL,
            .data = (int[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = LIFE,
            .data = (int[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = MAX_LIFE,
            .data = (int[1]){BOAT_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = DAMAGE,
            .data = (int[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_FLOAT,
            .type = ATTACK_SPEED,
            .data = (float[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_CLOCK,
            .type = ATTACK_TIME,
        },
        {
            .storage_type = TYPE_INT,
            .type = CANNON_NB,
            .data = (int[1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_SOUND,
            .type = FIRE_SOUND,
            .data = (char *)SOUND_FOLDER "boat_fire.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = HIT_SOUND,
            .data = (char *)SOUND_FOLDER "boat_hit.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = DEATH_SOUND,
            .data = (char *)SOUND_FOLDER "boat_death.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = LVL_UP_SOUND,
            .data = (char *)SOUND_FOLDER "level_up.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = XP_SOUND,
            .data = (char *)SOUND_FOLDER "xp.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_INT,
            .type = DEAD_COUNTER,
            .data = (int [1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [BOAT2] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_INT,
            .type = LVL,
            .data = (int[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = LIFE,
            .data = (int[1]){BOAT_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = MAX_LIFE,
            .data = (int[1]){BOAT_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = DAMAGE,
            .data = (int[1]){10},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_FLOAT,
            .type = ATTACK_SPEED,
            .data = (float[1]){3},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_CLOCK,
            .type = ATTACK_TIME,
        },
        {
            .storage_type = TYPE_INT,
            .type = CANNON_NB,
            .data = (int[1]){3},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_SOUND,
            .type = FIRE_SOUND,
            .data = (char *)SOUND_FOLDER "boat_fire.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = HIT_SOUND,
            .data = (char *)SOUND_FOLDER "boat_hit.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = DEATH_SOUND,
            .data = (char *)SOUND_FOLDER "boat_death.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_INT,
            .type = VIEW_RANGE,
            .data = (int [1]){1000},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = FIRE_RANGE,
            .data = (int [1]){300},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [BOAT3] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_INT,
            .type = LVL,
            .data = (int[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = LIFE,
            .data = (int[1]){BOAT_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = MAX_LIFE,
            .data = (int[1]){BOAT_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = DAMAGE,
            .data = (int[1]){2},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_FLOAT,
            .type = ATTACK_SPEED,
            .data = (float[1]){2},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_CLOCK,
            .type = ATTACK_TIME,
        },
        {
            .storage_type = TYPE_INT,
            .type = CANNON_NB,
            .data = (int[1]){2},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_SOUND,
            .type = FIRE_SOUND,
            .data = (char *)SOUND_FOLDER "boat_fire.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = HIT_SOUND,
            .data = (char *)SOUND_FOLDER "boat_hit.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = DEATH_SOUND,
            .data = (char *)SOUND_FOLDER "boat_death.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_INT,
            .type = VIEW_RANGE,
            .data = (int [1]){750},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = FIRE_RANGE,
            .data = (int [1]){200},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [BOAT4] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_INT,
            .type = LVL,
            .data = (int[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = LIFE,
            .data = (int[1]){BOAT_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = MAX_LIFE,
            .data = (int[1]){BOAT_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = DAMAGE,
            .data = (int[1]){10},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_FLOAT,
            .type = ATTACK_SPEED,
            .data = (float[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_CLOCK,
            .type = ATTACK_TIME,
        },
        {
            .storage_type = TYPE_INT,
            .type = CANNON_NB,
            .data = (int[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_SOUND,
            .type = FIRE_SOUND,
            .data = (char *)SOUND_FOLDER "boat_fire.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = HIT_SOUND,
            .data = (char *)SOUND_FOLDER "boat_hit.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = DEATH_SOUND,
            .data = (char *)SOUND_FOLDER "boat_death.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_INT,
            .type = VIEW_RANGE,
            .data = (int [1]){500},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = FIRE_RANGE,
            .data = (int [1]){200},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [BOAT5] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_INT,
            .type = LVL,
            .data = (int[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = LIFE,
            .data = (int[1]){BOAT_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = MAX_LIFE,
            .data = (int[1]){BOAT_LIFE},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = DAMAGE,
            .data = (int[1]){10},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_FLOAT,
            .type = ATTACK_SPEED,
            .data = (float[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_CLOCK,
            .type = ATTACK_TIME,
        },
        {
            .storage_type = TYPE_INT,
            .type = CANNON_NB,
            .data = (int[1]){1},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_SOUND,
            .type = FIRE_SOUND,
            .data = (char *)SOUND_FOLDER "boat_fire.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = HIT_SOUND,
            .data = (char *)SOUND_FOLDER "boat_hit.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_SOUND,
            .type = DEATH_SOUND,
            .data = (char *)SOUND_FOLDER "boat_death.ogg",
            .data2 = (float [1]){10}
        },
        {
            .storage_type = TYPE_END
        }
    },
    [BULLET] =
    (comp_constructor_t[]){
        {
            .storage_type = TYPE_INT,
            .type = DAMAGE,
            .data = (int [1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_INT,
            .type = ALLY,
            .data = (int [1]){0},
            .data2 = NULL
        },
        {
            .storage_type = TYPE_END
        }
    },
    [WATER] =
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
    },
    [TILLER] =
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