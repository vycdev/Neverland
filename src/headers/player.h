//
// Created by Vycto on 14-Oct-20.
//

#ifndef NEVERLAND_PLAYER_H
#define NEVERLAND_PLAYER_H

typedef struct Rect{
    int x, y,
        size, speed,
        health, mana,
        maxHealth, maxMana;
} Rect;

Rect player;

void initPlayer();
void updatePlayer();
void drawPlayer();

#endif //NEVERLAND_PLAYER_H
