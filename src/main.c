#include "raylib.h"

#include "headers/player.h"
#include "headers/camera.h"
#include "headers/debugger.h"
#include "headers/playerhud.h"

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

    updatePlayer();
    updateCamera();
    updateHud();

    updateDebugger();

}

void Draw(){
    BeginDrawing();
    ClearBackground(WHITE);

    BeginMode2D(camera);
        DrawRectangle(-50, -50, 100, 100, BLUE);
        drawPlayer();
    EndMode2D();

    drawDebugger();
    drawHud();

    EndDrawing();
}
