/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** generate_clouds
*/

#include "update_battle.h"
#include "math_process.h"

static const elem_t clouds_template[] =
{
    CLOUD1, CLOUD2, CLOUD3, CLOUD4,
    CLOUD5, CLOUD6, CLOUD7, CLOUD8
};

static void generate_cloud_left(tool_t *tool, game_obj_t *cloud)
{
    sfVector2f pos = VEC2F(0, 0);

    pos.x -= cloud->view_box[0].width;
    pos.y = get_randomnb(0, 300);
    set_game_object_pos(cloud, pos);
    apply_force(&(cloud->body), VEC2F(get_randomnb(20, 100), 0));
}

static void generate_cloud_right(tool_t *tool, game_obj_t *cloud)
{
    sfVector2f pos = VEC2F(tool->size.x, 0);

    pos.y = get_randomnb(0, 300);
    set_game_object_pos(cloud, pos);
    apply_force(&(cloud->body), VEC2F(-get_randomnb(20, 100), 0));
}

void generate_clouds(tool_t *tool, list_t **clouds)
{
    game_obj_t * new_cloud = NULL;
    int index = CLOUD1;

    if (!clouds || my_list_size(*clouds) > 4)
        return;
    index = get_randomnb(0, sizeof(clouds_template) / sizeof(elem_t) - 1);
    new_cloud = create_game_obj(clouds_template[index]);
    if (!new_cloud)
        return ;
    MY_PUT_IN_LIST(clouds, new_cloud);
    if (get_randomnb(0, 2))
        generate_cloud_right(tool, new_cloud);
    else
        generate_cloud_left(tool, new_cloud);
}
