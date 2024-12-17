#ifndef GAME_H
#define GAME_H
#define MAX_DESC_LENGTH 256

#include "player.h"
#include "room.h"
#include "item.h"
#include "creature.h"

// Function declarations for game-related functions
void clear_input_buffer();
void game_loop(Player *player);
void execute_command(Player *player, char *command);
void show_commands();
void move_player(Player *player, const char *direction);
void look_around(Player *player);
void show_inventory(Player *player);
void pickup_item(Player *player);
void attack_creature(Player *player);
void interact_creature(Player *player);
void save_game(Player *player, const char *filename);
void load_game(Player *player, const char *filename);

#endif