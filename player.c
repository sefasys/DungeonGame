#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

Player *create_player(Room *starting_room) {
    Player *player = (Player *)malloc(sizeof(Player));
    if (!player) {
        fprintf(stderr, "Memory allocation failed for player\n");
        exit(EXIT_FAILURE);
    }
    player->health = 100;
    player->strength = 10;
    player->inventory_count = 0;
    player->current_room = starting_room;
    return player;
}

void free_player(Player *player) {
    for (int i = 0; i < player->inventory_count; i++) {
        if (player->inventory[i]->name) free(player->inventory[i]->name);
        free(player->inventory[i]);
    }
    free(player);
}

void deleteItemFromInventory(Player *player) {
    if (player->inventory_count == 0) {
        printf("Your inventory is empty.\n");
        return;
    }

    // Show the inventory to the player
    printf("Your inventory:\n");
    for (int i = 0; i < player->inventory_count; i++) {
        printf("%d. %s\n", i + 1, player->inventory[i]->name);
    }

    // Ask the player to select an item
    printf("What item do you want to delete? (Select a number): ");
    int choice;
    scanf("%d", &choice);

    // Validate the choice
    if (choice < 1 || choice > player->inventory_count) {
        printf("Invalid selection. No item deleted.\n");
        return;
    }

    // Get the item to delete
    Item *item_to_delete = player->inventory[choice - 1];
    printf("%s is deleted.\n", item_to_delete->name);

    // Free the item's memory
    free(item_to_delete->name);
    free(item_to_delete);

    // Shift remaining items
    for (int i = choice - 1; i < player->inventory_count - 1; i++) {
        player->inventory[i] = player->inventory[i + 1];
    }

    // Clear the last inventory slot and reduce count
    player->inventory[--player->inventory_count] = NULL;
}

void use_item(Player *player) {
    if (player->inventory_count == 0) {
        printf("Your inventory is empty.\n");
        return;
    }

    printf("Your inventory:\n");
    for (int i = 0; i < player->inventory_count; i++) {
        printf("%d. %s\n", i + 1, player->inventory[i]->name);
    }

    printf("Type the name of the item you want to use: ");
    char item_name[50];
    scanf(" %[^\n]", item_name);

    for (int i = 0; i < player->inventory_count; i++) {
        Item *item = player->inventory[i];
        if (strcmp(item->name, item_name) == 0) {
            if (item->is_usable) {
                player->health += item->healing_value;
                if (player->health > 100) player->health = 100;  // Cap health at 100
                printf("You used %s. Your health is now %d.\n", item->name, player->health);

                // Remove the used item from inventory
                for (int j = i; j < player->inventory_count - 1; j++) {
                    player->inventory[j] = player->inventory[j + 1];
                }
                player->inventory[--player->inventory_count] = NULL;
                return;
            } else {
                printf("You can't use %s.\n", item->name);
                return;
            }
        }
    }

    printf("You don't have a %s in your inventory.\n", item_name);
}


void equip_sword(Player *player) {
    printf("Your inventory:\n");
    for (int i = 0; i < player->inventory_count; i++) {
        if (player->inventory[i]->is_weapon) {
            printf("%d. %s (Damage Boost: %d)\n", i + 1, player->inventory[i]->name, player->inventory[i]->damage_boost);
        }
    }

    printf("Choose a sword to equip (enter the number): ");
    int choice;
    scanf("%d", &choice);

    if (choice > 0 && choice <= player->inventory_count && player->inventory[choice - 1]->is_weapon) {
        player->strength = player->inventory[choice - 1]->damage_boost;
        printf("You equipped the %s. Damage is now %d.\n", player->inventory[choice - 1]->name, player->strength);
    } else {
        printf("Invalid choice. No sword equipped.\n");
    }
}

void unequip_sword(Player *player) {
    player->strength = 0;  // No weapon equipped, strength set to 0
    printf("You unequipped your sword. Your strength is now %d.\n", player->strength);
}

void read_book(Player *player) {
    if (player->inventory_count == 0) {
        printf("Your inventory is empty.\n");
        return;
    }

    // Oyuncunun envanterini göster
    printf("Your inventory:\n");
    for (int i = 0; i < player->inventory_count; i++) {
        printf("%d. %s\n", i + 1, player->inventory[i]->name);
    }

    // Kitap seçimi
    printf("Which book do you want to read? (Select a number): ");
    int choice;
    scanf("%d", &choice);

    // Geçersiz giriş kontrolü
    if (choice < 1 || choice > player->inventory_count) {
        printf("Invalid choice. Please select a valid book.\n");
        return;
    }

    Item *selected_item = player->inventory[choice - 1];

    // Kitap olup olmadığını kontrol et
    if (selected_item->description != NULL && selected_item->is_weapon == 0 && selected_item->is_usable == 0) {
        printf("\nReading '%s':\n%s\n", selected_item->name, selected_item->description);
    } else {
        printf("%s is not a book.\n", selected_item->name);
    }
}