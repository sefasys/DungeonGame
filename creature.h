#ifndef CREATURE_H
#define CREATURE_H

typedef struct Creature {
    char *name;            // Creature name (e.g., "Goblin", "King Fyonir")
    int health;            // Creature's health
    int strength;          // Creature's attack strength
    const char *story;     // Optional story or flavor text about the creature
    int is_defeated;       // Flag to track if the creature has been defeated
} Creature;

#endif