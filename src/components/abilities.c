//
// Created by Vycto on 30-Oct-20.
//
#include "raymath.h"
#include "../headers/abilities.h"
#include "../headers/player.h"

void Dash(float animationDuration, int distance){
    player.position.x += distance*(int)(Vector2Normalize(player.velocity).x * player.speed); // NOLINT(cppcoreguidelines-narrowing-conversions)
    player.position.y += distance*(int)(Vector2Normalize(player.velocity).y * player.speed); // NOLINT(cppcoreguidelines-narrowing-conversions)
    player.energy -= 1500;
}