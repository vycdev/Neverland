//
// Created by Vycto on 14-Oct-20.
//
#include "raylib.h"
#include "raymath.h"
#include "../headers/player.h"
#include "../headers/reusableMethods.h"

float calculatePlayerSpeed(int percentageMultiplier){
    return ((float)deltaSpeed(player.speedMultiplier) + (float)(deltaSpeed(player.speedMultiplier)*percentageMultiplier)/100);
}
void consumeEnergyOnSprint(){
    player.energy -= deltaSpeed(player.speedMultiplier);
}
void playerRegen(){
    player.health += deltaSpeed(player.healthRegen);
    player.energy += deltaSpeed(player.energyRegen);
}

void initPlayer(){
    player.position.x = -25;
    player.position.y = -25;
    player.previousXY = 0;
    player.size = 50;
    player.speed = 5;
    player.velocity.x = 0;
    player.velocity.y = 0;
    player.speedMultiplier = 25;
    player.health = 10000;
    player.energy = 10000;
    player.maxHealth = 10000;
    player.maxEnergy = 10000;
    player.energyRegen = 15;
    player.healthRegen = 15;
}

void updatePlayer(){
    // PLAYER MOVEMENT
    player.previousXY = (int)(player.position.x * player.position.y);

    if(IsKeyPressed('W')) player.velocity.y -= 1;
    if(IsKeyPressed('A')) player.velocity.x -= 1;
    if(IsKeyPressed('S')) player.velocity.y += 1;
    if(IsKeyPressed('D')) player.velocity.x += 1;

    if(IsKeyReleased('W')) player.velocity.y += 1;
    if(IsKeyReleased('A')) player.velocity.x += 1;
    if(IsKeyReleased('S')) player.velocity.y -= 1;
    if(IsKeyReleased('D')) player.velocity.x -= 1;


    if(!(player.velocity.x == 0 && player.velocity.y == 0)){
        player.position.x += (int)(Vector2Normalize(player.velocity).x * player.speed); // NOLINT(cppcoreguidelines-narrowing-conversions)
        player.position.y += (int)(Vector2Normalize(player.velocity).y * player.speed); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }

    // PLAYER SPRINT
    if(IsKeyDown(KEY_LEFT_CONTROL) && player.energy > 0){
        player.speed = calculatePlayerSpeed(25);
        if(player.previousXY != (int)(player.position.x * player.position.y))
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

}

void drawPlayer(){
    DrawRectangle((int)player.position.x, (int)player.position.y, player.size, player.size, RED);
}
