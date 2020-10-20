//
// Created by Vycto on 14-Oct-20.
//
#include <stdio.h>
#include "raylib.h"
#include "../headers/player.h"

int calculatePlayerSpeed(int percentageMultiplier){
    return player.speedMultiplier*(int)(100*GetFrameTime()) + (player.speedMultiplier*(int)(100*GetFrameTime())*percentageMultiplier)/100;
}
void consumeEnergyOnSprint(){
    player.energy -= (int)(100*GetFrameTime()) * player.speed/4;
}
void playerRegen(){
    player.health += (int)(100*GetFrameTime()) * player.healthRegen;
    player.energy += (int)(100*GetFrameTime()) * player.energyRegen;
}


void initPlayer(){
    player.x = -25;
    player.y = -25;
    player.previousXY = 0;
    player.size = 50;
    player.speed = (int)(100*GetFrameTime());
    player.speedMultiplier = 5;
    player.health = 10000;
    player.energy = 10000;
    player.maxHealth = 10000;
    player.maxEnergy = 10000;
    player.energyRegen = 1;
    player.healthRegen = 1;
}

void updatePlayer(){
    // PLAYER MOVEMENT
    player.previousXY = player.x * player.y;

    if (IsKeyDown('W'))player.y-=player.speed;
    if (IsKeyDown('A'))player.x-=player.speed;
    if (IsKeyDown('S'))player.y+=player.speed;
    if (IsKeyDown('D'))player.x+=player.speed;
    // PLAYER SPRINT
    if(IsKeyDown(KEY_LEFT_CONTROL) && player.energy > 0){
        player.speed = calculatePlayerSpeed(25);
        if(player.previousXY != player.x * player.y)
            consumeEnergyOnSprint();
    }
    else {
        player.speed = calculatePlayerSpeed(0);
    }

    if(IsKeyUp(KEY_LEFT_CONTROL))
        playerRegen();

    // Making sure that the health and energy are not below 0 or above their maximum allowed values.
    if(player.health < 0 ) player.health = 0;
    if(player.energy < 0 ) player.energy = 0;
    if(player.health > player.maxHealth) player.health = player.maxHealth;
    if(player.energy > player.maxEnergy) player.energy = player.maxEnergy;

    printf("%d\n", (int)(100*GetFrameTime()));

}

void drawPlayer(){
    DrawRectangle(player.x, player.y, player.size, player.size, RED);
}
