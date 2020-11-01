//
// Created by Vycto on 14-Oct-20.
//

#ifndef NEVERLAND_PLAYER_H
#define NEVERLAND_PLAYER_H

#include "items.h"

typedef struct Cooldowns{
    float ability1;
} Cooldowns;

typedef struct InventorySlot{
    int amount;
    Item item;
} InventorySlot;

typedef struct Player{
    int size, speedMultiplier,
        health, energy,
        energyRegen, healthRegen,
        maxHealth, maxEnergy;
    Vector2 position ,velocity;
    Cooldowns cooldowns;
    float speed;
    InventorySlot inventory[29];
} Player;

Player player;


void initPlayer();
void updatePlayer();
void drawPlayer();

#endif //NEVERLAND_PLAYER_H
