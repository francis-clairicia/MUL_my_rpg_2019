/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** A header for game objects.
*/

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <stdbool.h>
#include "SFML/Audio.h"
#include "SFML/Window.h"
#include "SFML/System.h"
#include "SFML/Graphics.h"

#include "mylist.h"
#include "physic_engine.h"

typedef enum element_e {
    PIRATE,
    FLORIAN,
    BOAT1,
    BOAT2,
    BOAT3,
    BOAT4,
    BOAT5,
    SKY,
    WATER,
    WATER2,
    RAIN,
    WOOD1_RECT,
    WOOD1_LEFT_TRIANGLE,
    WOOD1_RIGHT_TRIANGLE,
    WOOD2_RECT,
    WOOD2_LEFT_TRIANGLE,
    WOOD2_RIGHT_TRIANGLE,
    FENCE,
    LADDER,
    CLOUD1,
    CLOUD2,
    CLOUD3,
    CLOUD4,
    CLOUD5,
    CLOUD6,
    CLOUD7,
    CLOUD8,
    TILLER,
    NONE
} elem_t;

typedef enum properties_e {
    SOUND = 1,
    CLOCK,
    OFFSET,
    SHIFT,
    POS,
    TEXT,
    BOOL,
    SIZE,
    IS_DRIVING,
    CAN_JUMP
} prop_t;

typedef struct component_s {
    prop_t type;
    sfClock *clock;
    sfImage *image;
    sfText *text;
    sfSound *sound;
    sfVector2i v2i;
    sfVector2f v2f;
    sfIntRect irect;
    int i;
    float f;
} component_t;

typedef struct game_obj {
    component_t **comp;
    unsigned int comp_nb;
    rigid_body_t body;
    unsigned int *frame_nb;
    unsigned int *lapse;
    sfVector2f *origin;
    sfIntRect *view_box;
    unsigned int state;
    sfFloatRect hitbox;
    sfTexture *texture;
    sfSprite *sprite;
    struct game_obj *next;
    elem_t type;
} game_obj_t;

//Initializes a game_object considering its type.
//
//Returns a pointer towards the game_object if it was correctly initialized.
//Returns a NULL pointer otherwise.
game_obj_t *create_game_obj(const elem_t type);

sfBool free_game_object_list(game_obj_t *obj);

//Entirely frees a game_object.
//
void free_game_object(game_obj_t *obj);

//Frees the components of a game_object (clock, images ...).
//
//Returns sfTrue if the given pointer isn't NULL.
//Returns sfFalse otherwise.
sfBool free_all_comp(game_obj_t *obj);

//Returns a pointer towards a looked-for game_object in a game_object linked
//list.
//
//Returns a pointer towards the game_object if it has been found.
//Returns a NULL pointer otherwise.
game_obj_t *find_game_object(list_t *list, elem_t type);

//Finds a component thanks to the given type and
//returns the index relative to his game object array position's.
//Returns 0 in case of error.
int find_comp(game_obj_t *obj, prop_t type);

//Checks if a game object has a component corresponding to the given type
//Returns true if it has the wanted comp
//Returns false in other cases
bool has_comp(game_obj_t *obj, const prop_t type);

//Sets game object'sprite position and update sprite
void set_game_object_pos(game_obj_t *obj, sfVector2f pos);
void set_game_object_pos_ptr(game_obj_t *obj, void *data);

//Add pos to game object'sprite position and update sprite
void add_game_object_pos(game_obj_t *obj, sfVector2f pos);
void add_game_object_pos_ptr(game_obj_t *obj, void *data);

//Sets game object'sprite origin and update sprite
void set_game_object_origin(game_obj_t *obj, sfVector2f origin);
void set_game_object_origin_ptr(game_obj_t *obj, void *data);

//Sets game object'sprite scale
void set_game_object_scale(game_obj_t *obj, sfVector2f scale);
void set_game_object_scale_ptr(game_obj_t *obj, void *data);

//Sets the X frame of a game object.
void set_game_object_frame(game_obj_t *obj, unsigned int frame);
void set_game_object_frame_ptr(game_obj_t *obj, void *data);

//Animates game object having CLOCK component with a
//lapse of time in ms between each frame given.
void anime_game_object(game_obj_t *obj);
void anime_game_object_ptr(game_obj_t *obj, __attribute__((unused))void *data);

// Draws the game object on a Window
void draw_game_object(sfRenderWindow *window, game_obj_t *obj);

//Draws every game object in list (from mylist.h)
void draw_game_object_list(sfRenderWindow *window, list_t *list);

//Returns the center of a given game object considering
//the hitbox, the pos and the origin of the actual state
sfVector2f get_game_objet_center(game_obj_t *obj);

//Updates the hitbox of a game object considering his pos and his size.
//Hitbox will be relative to world's coord, not window'scoords.
void update_hitbox(game_obj_t *obj);

//Update sprite position to object position
void update_sprite(game_obj_t *obj);

//Sets state as new value for obj's state
//Updates the new origin linked to the state
//Returns true if no error
//Returns false if error
sfBool update_game_object_state(game_obj_t *obj, unsigned int state);
sfBool update_game_object_state_ptr(game_obj_t *obj, void *data);

void update_game_object_center(game_obj_t *obj);

//Expands list horizontaly if last node's position is higher than offset
void expand_game_object_right(list_t **list, float offset);

//Expands list horizontaly if first node's position is lower than offset
void expand_game_object_left(list_t **list, float offset);

//Detects and solves a collision between two game objects
//Returns true if collision is detected and resolved
//Returns false is the following case :
//-Bad parameters
//-No collision
//-Both object have mass 0 or FLT MAX mass
//Apply the function given as parameter if there is a collision
sfBool game_object_collision(game_obj_t *obj1, game_obj_t *obj2,
                                sfBool (*res_func)
                                (rigid_body_t *, rigid_body_t *, float));

//Detects a AABB collision between 2 game object
//Returns true if collision is detected
//Returns false in any other cases
sfBool is_game_object_collision(game_obj_t *obj1, game_obj_t *obj2);

//Use func passed as parameter for all game object in list
void game_object_list(list_t *list,
                        void (*func)(game_obj_t *, void *),
                        void *data);
void body_list(list_t *list,
                void (*func)(rigid_body_t *, void *),
                void *data);

//Returns the game object in the list which has the lowest/highest x/y
//Returns NULL in case of error
game_obj_t *find_game_object_highest_y(list_t *list);
game_obj_t *find_game_object_lowest_x(list_t *list);
game_obj_t *find_game_object_highest_x(list_t *list);
game_obj_t *find_game_object_lowest_y(list_t *list);

//Finds a component with the given type and set new given value.
sfBool set_comp_int(game_obj_t *obj, prop_t type, int nb);
sfBool set_comp_float(game_obj_t *obj, prop_t type, float nb);
sfBool set_comp_v2i(game_obj_t *obj, prop_t type, sfVector2i vec);
sfBool set_comp_v2f(game_obj_t *obj, prop_t type, sfVector2f vec);
sfBool set_comp_irect(game_obj_t *obj, prop_t type, sfIntRect rect);
sfBool set_comp_sound(game_obj_t *obj, prop_t type, char *path, float volume);
sfBool set_comp_text(game_obj_t *obj, prop_t type, char *path, int size);
sfBool set_comp_image(game_obj_t *obj, prop_t type, char *path);
sfBool reset_comp_clock(game_obj_t *obj, prop_t type);
sfBool set_comp_clock(game_obj_t *obj, prop_t type);

#endif /* !GAME_OBJECT_H_ */