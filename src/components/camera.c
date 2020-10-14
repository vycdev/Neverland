//
// Created by Vycto on 14-Oct-20.
//
#include "raylib.h"
#include "../headers/player.h"
#include "../headers/camera.h"

void initCamera(){
    camera.target = (struct Vector2){ 0, 0 };
    camera.offset = (struct Vector2){ (int)(SCREEN_WIDTH/2),(int)(SCREEN_HEIGHT/2) };
    camera.rotation= 0.0f;
    camera.zoom = 1.0f;
}
void updateCamera(){
    // Camera following the player
    camera.target = (struct Vector2){ (float)(player.x + (int)(player.size/2)), (float)(player.y + (int)(player.size/2)) };

    // Camera zoom controls
    camera.zoom += ((float)GetMouseWheelMove()*0.1f);
    if (camera.zoom > 3.0f) camera.zoom = 3.0f;
    else if (camera.zoom < 1.0f) camera.zoom = 1.0f;
}