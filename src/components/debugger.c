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
        DrawLine(i*100 - SCREEN_WIDTH - (player.x % 100) + player.x - (100-SCREEN_WIDTH%100),
                 0  - SCREEN_HEIGHT - (player.y % 100) - abs(player.y),
                 i*100  - SCREEN_WIDTH - (player.x % 100) + player.x - (100-SCREEN_WIDTH%100),
                 SCREEN_HEIGHT  + (player.y % 100) + abs(player.y),
                 LIGHTGRAY);
    }
//    Drawing horizontal lines
    for (int i = 0; i < SCREEN_HEIGHT/50 + 1; i++)
    {
        DrawLine(0 - SCREEN_WIDTH - (player.x % 100) - abs(player.x),
                 i*100 - SCREEN_HEIGHT - (player.y % 100) + player.y - (100-SCREEN_HEIGHT%100),
                 SCREEN_WIDTH - (player.x % 100) + abs(player.x),
                 i*100 - SCREEN_HEIGHT - (player.y % 100) + player.y - (100-SCREEN_HEIGHT%100),
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
        DrawText(FormatText("x: %d", player.x), 20, 40, 20, DARKGREEN);
        DrawText(FormatText("y: %d", player.y), 20, 60, 20, DARKGREEN);
        DrawText(FormatText("speed: %d", player.speed), 20, 80, 20, GREEN);
    }
}