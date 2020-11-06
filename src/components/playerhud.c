//
// Created by Vycto on 14-Oct-20.
//

#include <raylib.h>
#include "../headers/player.h"
#include "../headers/camera.h"
#include "../headers/playerhud.h"

bool inventory_opened = false;
Texture2D inventoryTexture;

void initHud(){
    inventoryTexture = LoadTexture("../assets/inventory.png");
}

void drawMana(){
    DrawRectangle((int)(2*SCREEN_WIDTH/10), SCREEN_HEIGHT - SCREEN_HEIGHT/25 - 10, (int)(6*SCREEN_WIDTH/10), SCREEN_HEIGHT/25, LIGHTGRAY);
    DrawRectangle((int)(2*SCREEN_WIDTH/10), SCREEN_HEIGHT - SCREEN_HEIGHT/25 - 10, (int)(6*SCREEN_WIDTH/10) * player.energy / player.maxEnergy, SCREEN_HEIGHT / 25, DARKPURPLE);
    DrawText(FormatText("%d/%d", player.energy/100, player.maxEnergy/100), SCREEN_WIDTH / 5 + 10, SCREEN_HEIGHT - SCREEN_HEIGHT / 25 - 4, 16, WHITE);
}

void drawHealth(){
    DrawRectangle((int)(2*SCREEN_WIDTH/10), SCREEN_HEIGHT - 2*SCREEN_HEIGHT/25 - 20, (int)(6*SCREEN_WIDTH/10), SCREEN_HEIGHT/25, LIGHTGRAY);
    DrawRectangle((int)(2*SCREEN_WIDTH/10), SCREEN_HEIGHT - 2*SCREEN_HEIGHT/25 - 20, (int)(6*SCREEN_WIDTH/10)*player.health/player.maxHealth, SCREEN_HEIGHT/25, RED);
    DrawText(FormatText("%d/%d",player.health/100,player.maxHealth/100), SCREEN_WIDTH/5 + 10,SCREEN_HEIGHT - 2*SCREEN_HEIGHT/25 - 14, 16, WHITE);
}

void drawAbilitiesCooldowns(){
    DrawText(FormatText("Dash: %.2fs", player.cooldowns.ability1), 100, SCREEN_HEIGHT - 40, 20, BLACK);
}

void drawInventory(){
    if(inventory_opened){
        DrawTextureEx(inventoryTexture,(Vector2){(float)(SCREEN_WIDTH - inventoryTexture.width)/1.8f, (float)(SCREEN_HEIGHT- inventoryTexture.height)*5.8f}, 0, 0.8f, WHITE);
    }
}

void updateHud(){
    if(IsKeyReleased(KEY_TAB)) inventory_opened = !inventory_opened;
}

void drawHud(){
    drawMana();
    drawHealth();
    drawInventory();
    drawAbilitiesCooldowns();
}