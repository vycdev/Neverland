//
// Created by Vycto on 14-Oct-20.
//

#include <raylib.h>
#include "../headers/player.h"
#include "../headers/camera.h"
#include "../headers/playerhud.h"

void drawMana(){
    DrawRectangle((int)(2*SCREEN_WIDTH/10), SCREEN_HEIGHT - SCREEN_HEIGHT/25 - 10, (int)(6*SCREEN_WIDTH/10), SCREEN_HEIGHT/25, LIGHTGRAY);
    DrawRectangle((int)(2*SCREEN_WIDTH/10), SCREEN_HEIGHT - SCREEN_HEIGHT/25 - 10, (int)(6*SCREEN_WIDTH/10)*player.mana/player.maxMana, SCREEN_HEIGHT/25, BLUE);
    DrawText(FormatText("%d/%d",player.mana,player.maxMana), SCREEN_WIDTH/5 + 10,SCREEN_HEIGHT - SCREEN_HEIGHT/25 - 4, 16, WHITE);
}

void drawHealth(){
    DrawRectangle((int)(2*SCREEN_WIDTH/10), SCREEN_HEIGHT - 2*SCREEN_HEIGHT/25 - 20, (int)(6*SCREEN_WIDTH/10), SCREEN_HEIGHT/25, LIGHTGRAY);
    DrawRectangle((int)(2*SCREEN_WIDTH/10), SCREEN_HEIGHT - 2*SCREEN_HEIGHT/25 - 20, (int)(6*SCREEN_WIDTH/10)*player.health/player.maxHealth, SCREEN_HEIGHT/25, RED);
    DrawText(FormatText("%d/%d",player.health,player.maxHealth), SCREEN_WIDTH/5 + 10,SCREEN_HEIGHT - 2*SCREEN_HEIGHT/25 - 14, 16, WHITE);
}


void updateHud(){

}

void drawHud(){
    drawMana();
    drawHealth();
}