//
// Created by Vycto on 21-Oct-20.
//

#include "raylib.h"
#include "../headers/methods.h"

int deltaSpeed(int velocity){
    if(GetFPS() == 0) return 0;
    if(GetFrameTime()/(float)GetFPS() < 0.0001) return (int)(velocity*0.1);
    if(GetFrameTime()/(float)GetFPS() > 0.0005) return (int)(velocity*0.5);
    return (int)((float)velocity*(GetFrameTime()/(float)GetFPS())*1000);
}