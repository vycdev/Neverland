//
// Created by Vycto on 14-Oct-20.
//

#ifndef NEVERLAND_PLAYER_H
#define NEVERLAND_PLAYER_H

typedef struct Rect{
    int x, y,
        previousXY,
        size, speed, speedMultiplier,
        health, energy,
        energyRegen, healthRegen,
        maxHealth, maxEnergy;
} Rect;

Rect player;

void initPlayer();
void updatePlayer();
void drawPlayer();

#endif //NEVERLAND_PLAYER_H
