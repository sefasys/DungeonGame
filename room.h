#ifndef ROOM_H
#define ROOM_H

#include "item.h"
#include "creature.h"

typedef struct Room {
    char *description;
    Item *item;
    Creature *creature;
    struct Room *up, *down, *left, *right;
    int is_visited;
} Room;

// Function declarations for room-related functions
Room *create_room(const char *description);
Room *initialize_room_with_item(const char *description, const char *item_name, int healing_value, int is_usable, int is_weapon, int damage_boost, const char *book_description);
void connect_rooms(Room *room1, Room *room2, const char *direction);
void free_room(Room *room); //5

#endif