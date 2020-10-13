#include "raylib.h"


#define SCREEN_WIDTH (1600)
#define SCREEN_HEIGHT (900)
#define GAME_NAME "Neverland"

void Update();
void Draw();

Camera2D camera = { 0 };

struct rectangle{int x, y, size;}player;


int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(60);
    player.x = SCREEN_WIDTH/2;
    player.y = SCREEN_HEIGHT/2;
    player.size = 50;


    camera.target = (struct Vector2){ 0, 0 };
    camera.offset = (struct Vector2){ 0, 0 };
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

}

void Draw2DGrid(){
    for (int i = 0; i < SCREEN_WIDTH/100 + 1; i++)
    {
        DrawLine(i*100, 0, i*100, SCREEN_HEIGHT, LIGHTGRAY);
    }
    for (int i = 0; i < SCREEN_HEIGHT/100 + 1; i++)
    {
        DrawLine(0, i*100, SCREEN_WIDTH, i*100, LIGHTGRAY);
    }
}

void Draw(){
    BeginDrawing();
    ClearBackground(WHITE);

    BeginMode2D(camera);
        DrawFPS(0,0);
        Draw2DGrid();
        DrawRectangle(player.x, player.y, player.size, player.size, RED);
    EndMode2D();

    EndDrawing();
}
