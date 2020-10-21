//
// Created by Vycto on 14-Oct-20.
//
#include <raylib.h>
#include <math.h>
#include "../headers/debugger.h"
#include "../headers/player.h"
#include "../headers/camera.h"

bool debug_mode = false;

void Draw2DGrid(){
//    Drawing vertical lines
    for (int i = 0; i < SCREEN_WIDTH/50 + 1; i++)
    {
        DrawLine(i*100 - SCREEN_WIDTH - ((int)player.position.x % 100) + player.position.x - (100-SCREEN_WIDTH%100),
                 0  - SCREEN_HEIGHT - ((int)player.position.y % 100) - abs(player.position.y),
                 i*100  - SCREEN_WIDTH - ((int)player.position.x % 100) + player.position.x - (100-SCREEN_WIDTH%100),
                 SCREEN_HEIGHT  + ((int)player.position.y % 100) + abs(player.position.y),
                 LIGHTGRAY);
    }
//    Drawing horizontal lines
    for (int i = 0; i < SCREEN_HEIGHT/50 + 1; i++)
    {
        DrawLine(0 - SCREEN_WIDTH - ((int)player.position.x % 100) - abs(player.position.x),
                 i*100 - SCREEN_HEIGHT - ((int)player.position.y % 100) + player.position.y - (100-SCREEN_HEIGHT%100),
                 SCREEN_WIDTH - ((int)player.position.x % 100) + abs(player.position.x),
                 i*100 - SCREEN_HEIGHT - ((int)player.position.y % 100) + player.position.y - (100-SCREEN_HEIGHT%100),
                 LIGHTGRAY);
    }

}

void updateDebugger(){
    // Toggle debug mode
    if(IsKeyReleased(KEY_F3)) debug_mode = !debug_mode;
}
void drawDebugger(){
    BeginMode2D(camera);
    if (debug_mode) {
        Draw2DGrid();
    }
    EndMode2D();
    //    Show fps and coordinates
    if(debug_mode) {
        DrawFPS(20, 20);
        DrawText(FormatText("x: %.1f", player.position.x), 20, 40, 20, DARKGREEN);
        DrawText(FormatText("y: %.1f", player.position.y), 20, 60, 20, DARKGREEN);
        DrawText(FormatText("speed: %.1f", player.speed), 20, 80, 20, GREEN);
        DrawText(FormatText("health: %d", player.health), 20, 100, 15, GREEN);
        DrawText(FormatText("healthRegen: %d", player.healthRegen), 20, 115, 15, GREEN);
        DrawText(FormatText("maxHealth: %d", player.maxHealth), 20, 130, 15, GREEN);
        DrawText(FormatText("energy: %d", player.energy), 20, 145, 15, GREEN);
        DrawText(FormatText("energyRegen: %d", player.energyRegen), 20, 160, 15, GREEN);
        DrawText(FormatText("maxEnergy: %d", player.maxEnergy), 20, 175, 15, GREEN);
    }
}