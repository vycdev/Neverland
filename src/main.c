#include <stdlib.h>
#include "raylib.h"

#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define GAME_NAME "Neverland"

void Update();
void Draw();

Camera2D camera = { 0 };
struct rectangle{
    int x, y, size;
    float speed;
}player;

bool debug_mode = false;

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(60);
    player.x = 0;
    player.y = 0;
    player.size = 50;
    player.speed = 5;


    camera.target = (struct Vector2){ 0, 0 };
    camera.offset = (struct Vector2){ (int)(SCREEN_WIDTH/2),(int)(SCREEN_HEIGHT/2) };
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
    if (IsKeyDown('W'))player.y-=player.speed;
    if (IsKeyDown('A'))player.x-=player.speed;
    if (IsKeyDown('S'))player.y+=player.speed;
    if (IsKeyDown('D'))player.x+=player.speed;

    // Camera following the player
    camera.target = (struct Vector2){ (float)(player.x + (int)(player.size/2)), (float)(player.y + (int)(player.size/2))};

    // Camera zoom controls
    camera.zoom += ((float)GetMouseWheelMove()*0.1f);
    if (camera.zoom > 3.0f) camera.zoom = 3.0f;
    else if (camera.zoom < 1.0f) camera.zoom = 1.0f;

    // Toggle debug mode
    if(IsKeyReleased(KEY_F3)) debug_mode = !debug_mode;

}
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

void Draw(){
    BeginDrawing();
    ClearBackground(WHITE);

//    2d camera mode
    BeginMode2D(camera);
        DrawRectangle(-50, -50, 100, 100, BLUE);
        if (debug_mode) {
            Draw2DGrid();
        }
        DrawRectangle(player.x, player.y, player.size, player.size, RED);
    EndMode2D();

//    Show fps and coordinates
    if(debug_mode) {
        DrawFPS(20, 20);
        DrawText(FormatText("x: %d", player.x), 20, 40, 20, DARKGREEN);
        DrawText(FormatText("y: %d", player.y), 20, 60, 20, DARKGREEN);
    }

    EndDrawing();
}
