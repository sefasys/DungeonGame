#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "room.h"

Room *create_room(const char *description) {
    Room *room = (Room *)malloc(sizeof(Room));
    if (!room) {
        fprintf(stderr, "Memory allocation failed for room\n");
        exit(EXIT_FAILURE);
    }
    room->description = strdup(description);
    room->item = NULL;
    room->creature = NULL;
    room->up = room->down = room->left = room->right = NULL;
    return room;
}

Room *initialize_room_with_item(const char *description, const char *item_name, int healing_value, int is_usable, int is_weapon, int damage_boost, const char *book_description) {
Room *room = create_room(description);
Item *item = (Item *)malloc(sizeof(Item));

item->name = strdup(item_name);
item->healing_value = healing_value;
item->is_usable = is_usable;
item->is_weapon = is_weapon;
item->damage_boost = damage_boost;  // For swords

// If it's a book, set its description
if (book_description != NULL) {
    item->description = strdup(book_description);  // Set book description
} else {
    item->description = NULL;  // Non-book items won't have descriptions
}

room->item = item;
return room;
}


/*Room *initialize_room_with_item(const char *description, const char *item_name, int healing_value, int is_usable) {
    Room *room = create_room(description);
    Item *item = (Item *)malloc(sizeof(Item));
    item->name = strdup(item_name);
    item->healing_value = healing_value;
    item->is_usable = is_usable;
    room->item = item;
    return room;
}

Room *initialize_room_with_sword(const char *description, const char *sword_name, int damage_boost) {
    Room *room = create_room(description);
    Item *sword = (Item *)malloc(sizeof(Item));
    sword->name = strdup(sword_name);
    sword->damage_boost = damage_boost;
    sword->is_weapon = 1;
    sword->is_usable = 0;  // Swords are not usable like potions
    room->item = sword;
    return room;
}*/

void connect_rooms(Room *room1, Room *room2, const char *direction) {
    if (strcmp(direction, "up") == 0) {
        room1->up = room2;
        room2->down = room1;
    } else if (strcmp(direction, "down") == 0) {
        room1->down = room2;
        room2->up = room1;
    } else if (strcmp(direction, "left") == 0) {
        room1->left = room2;
        room2->right = room1;
    } else if (strcmp(direction, "right") == 0) {
        room1->right = room2;
        room2->left = room1;
    }
}

void free_room(Room *room) {
    if (room->description) free(room->description);
    if (room->item) {
        if (room->item->name) free(room->item->name);
        free(room->item);
    }
    if (room->creature) {
        if (room->creature->name) free(room->creature->name);
        free(room->creature);
    }
    free(room);
}

