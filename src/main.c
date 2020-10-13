#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"

#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define GAME_NAME "Neverland"

void Update();
void Draw();

Camera2D camera = { 0 };
struct rectangle{int x, y, size;}player;
bool debug_mode = false;

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(60);
    player.x = 0;
    player.y = 0;
    player.size = 50;


    camera.target = (struct Vector2){ 0, 0 };
    camera.offset = (struct Vector2){ SCREEN_WIDTH/2, SCREEN_HEIGHT/2 };
    camera.rotation= 0.0f;
    camera.zoom = 1.0f;

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    CloseWindow();

    return 0;
}

void Update(){

    // PLAYER MOVEMENT
    if (IsKeyDown('W'))player.y-=5;
    if (IsKeyDown('A'))player.x-=5;
    if (IsKeyDown('S'))player.y+=5;
    if (IsKeyDown('D'))player.x+=5;

    // Camera following the player
    camera.target = (struct Vector2){ player.x + player.size/2, player.y + player.size/2  };

    // Camera zoom controls
    camera.zoom += ((float)GetMouseWheelMove()*0.1f);

    if (camera.zoom > 3.0f) camera.zoom = 3.0f;
    else if (camera.zoom < 1.0f) camera.zoom = 1.0f;

    // Toggle debug mode
    if(IsKeyReleased(KEY_F3)) debug_mode = !debug_mode;

}
void Draw2DGrid(){
    for (int i = 0; i < SCREEN_WIDTH/50 + 1; i++)
    {
        DrawLine(i*100 - SCREEN_WIDTH - (player.x % 100) + player.x,
                 0  - SCREEN_HEIGHT - (player.y % 100) - abs(player.y),
                 i*100  - SCREEN_WIDTH - (player.x % 100) + player.x,
                 SCREEN_HEIGHT  + (player.y % 100) + abs(player.y),
                 BLACK);
    }
    for (int i = 0; i < SCREEN_HEIGHT/50 + 1; i++)
    {
        DrawLine(0 - SCREEN_WIDTH - (player.x % 100) - abs(player.x),
                 i*100 - SCREEN_HEIGHT - (player.y % 100) + player.y,
                 SCREEN_WIDTH - (player.x % 100) + abs(player.x),
                 i*100 - SCREEN_HEIGHT - (player.y % 100) + player.y,
                 BLACK);
    }

}

void Draw(){
    BeginDrawing();
    ClearBackground(WHITE);

    if(debug_mode) {
        DrawFPS(20, 20);
        DrawText(FormatText("x: %d", player.x), 20, 40, 20, DARKGREEN);
        DrawText(FormatText("y: %d", player.y), 20, 60, 20, DARKGREEN);
    }

    BeginMode2D(camera);
        if(debug_mode){
            Draw2DGrid();
        }

        DrawRectangle(player.x, player.y, player.size, player.size, RED);
        DrawRectangle(0, 0, 100, 100, BLUE);
    EndMode2D();

    EndDrawing();
}
