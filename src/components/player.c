//
// Created by Vycto on 14-Oct-20.
//
#include "raylib.h"
#include "../headers/player.h"

void initPlayer(){
    player.x = -25;
    player.y = -25;
    player.size = 50;
    player.speed = 5;

}

void updatePlayer(){
    // PLAYER MOVEMENT
    if (IsKeyDown('W'))player.y-=player.speed;
    if (IsKeyDown('A'))player.x-=player.speed;
    if (IsKeyDown('S'))player.y+=player.speed;
    if (IsKeyDown('D'))player.x+=player.speed;
}

void drawPlayer(){
    DrawRectangle(player.x, player.y, player.size, player.size, RED);
}
