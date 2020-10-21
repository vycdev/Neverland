//
// Created by Vycto on 14-Oct-20.
//
#include <stdio.h>
#include "raylib.h"
#include "../headers/player.h"
#include "../headers/reusableMethods.h"

int calculatePlayerSpeed(int percentageMultiplier){
    return (int)(deltaSpeed(player.speedMultiplier) + (deltaSpeed(player.speedMultiplier)*percentageMultiplier)/100);
}
void consumeEnergyOnSprint(){
    player.energy -= deltaSpeed(player.speedMultiplier);
}
void playerRegen(){
    player.health += deltaSpeed(player.healthRegen);
    player.energy += deltaSpeed(player.energyRegen);
}

void initPlayer(){
    player.x = -25;
    player.y = -25;
    player.previousXY = 0;
    player.size = 50;
    player.speed = 5;
    player.speedMultiplier = 20;
    player.health = 5000;
    player.energy = 5000;
    player.maxHealth = 10000;
    player.maxEnergy = 10000;
    player.energyRegen = 15;
    player.healthRegen = 15;
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

    printf("%d\n", deltaSpeed(10));
}

void drawPlayer(){
    DrawRectangle(player.x, player.y, player.size, player.size, RED);
}
