#ifndef ITEM_H
#define ITEM_H

typedef struct Item {
    char *name;            // Item name (e.g., "Health Potion", "Steel Sword", "Book No.1")
    int healing_value;     // Healing points (for potions)
    int damage_boost;      // Extra damage (for swords)
    int is_usable;         // Flag: 1 if the item is usable (like a potion), 0 otherwise
    int is_weapon;         // Flag: 1 if the item is a weapon (like a sword), 0 otherwise
    char *description;     // Description of the item (used for books)
} Item;

#endif