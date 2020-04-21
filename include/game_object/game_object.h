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
    CLOUD9,
    CLOUD10,
    CLOUD11,
    CLOUD12,
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
    SIZE
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
    sfVector2f *origin;
    sfIntRect *view_box;
    unsigned int *frame_nb;
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

sfBool free_obj_list(game_obj_t *obj);

//Entirely frees a game_object.
//
void free_obj(game_obj_t *obj);

//Frees the components of a game_object (clock, images ...).
//
//Returns sfTrue if the given pointer isn't NULL.
//Returns sfFalse otherwise.
sfBool free_all_comp(game_obj_t *obj);

//Adds a new uninitialized game_object to a game_object linked list.
//
//Returns sfTrue if the operation was a success.
//Returns sfFalse otherwise.
sfBool add_game_obj_to_list(game_obj_t **list, const elem_t element);

//Returns a pointer towards a looked-for game_object in a game_object linked
//list.
//
//Returns a pointer towards the game_object if it has been found.
//Returns a NULL pointer otherwise.
game_obj_t *find_game_object(game_obj_t *list, const elem_t type);

//Finds a component thanks to the given type and
//returns the index relative to his game object array position's.
//Returns 0 in case of error.
int find_comp(game_obj_t *obj, prop_t type);

//Checks if a game object has a component corresponding to the given type
//Returns true if it has the wanted comp
//Returns false in other cases
bool has_comp(game_obj_t *obj, const prop_t type);


//Set the X frame of a game object.
void set_game_object_frame(game_obj_t *obj, unsigned int frame);

//Animate game object having CLOCK component with a given
//lapse of time in ms between each frame.
void anime_game_object(game_obj_t *obj, const int lapse);

// Draw the game object on a Window
void draw_game_object(sfRenderWindow *window, game_obj_t *obj);

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

//Detect and solve a collision between two game objects
//Returns true if collision is detected and resolved
//Returns false is the following case :
//-Bad parameters
//-No collision
//-Both object have mass 0 or FLT MAX mass
sfBool game_object_aabb_collision(game_obj_t *obj1, game_obj_t *obj2);

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