//
// Created by Vycto on 14-Oct-20.
//

#ifndef NEVERLAND_PLAYER_H
#define NEVERLAND_PLAYER_H

typedef struct Cooldowns{
    float ability1;
} Cooldowns;

typedef struct Rect{
    int size, speedMultiplier,
        health, energy,
        energyRegen, healthRegen,
        maxHealth, maxEnergy;
    Vector2 position ,velocity;
    Cooldowns cooldowns;
    float speed;
} Rect;

Rect player;

void initPlayer();
void updatePlayer();
void drawPlayer();

#endif //NEVERLAND_PLAYER_H
