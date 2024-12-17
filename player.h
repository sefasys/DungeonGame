#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"

#define MAX_INVENTORY 5

typedef struct Player {
    int health;
    int strength;
    Item *inventory[MAX_INVENTORY];
    int inventory_count;
    Room *current_room;
} Player;

// Function declarations for player-related functions
Player *create_player(Room *starting_room);
void free_player(Player *player);
void deleteItemFromInventory(Player *player);
void use_item(Player *player);
void equip_sword(Player *player);
void unequip_sword(Player *player);
void read_book(Player *player); //6

#endif