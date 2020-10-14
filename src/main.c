#include "raylib.h"

#include "headers/player.h"
#include "headers/camera.h"
#include "headers/debugger.h"

#define GAME_NAME "Neverland"

void Update();
void Draw();


int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(60);

    initCamera();
    initPlayer();

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    CloseWindow();

    return 0;
}

void Update(){
    updateCamera();
    updatePlayer();
    updateDebugger();
}


void Draw(){
    BeginDrawing();
    ClearBackground(WHITE);

    drawDebugger();

    // 2D camera mode
    BeginMode2D(camera);
        DrawRectangle(-50, -50, 100, 100, BLUE);
        drawPlayer();
    EndMode2D();

    EndDrawing();
}
