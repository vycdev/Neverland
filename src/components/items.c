//
// Created by Vycto on 01-Nov-20.
//
#include <string.h>
#include "../headers/abilities.h"
#include "../headers/items.h"

void initItem(Item item, int id, char name[20], char description[100], Texture2D texture){
    item.id = id;
    strcpy_s(item.description,sizeof item.description , description);
    strcpy_s(item.name,sizeof item.name , name);
    item.texture = texture;
}

void Execute(int id){
    switch(id){
        case 1:
            Dash(1, 25);
            break;
        case 2:
            break;
    }
}

void InitItems(){
    Image image = LoadImage("resources/test.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    initItem(cloakOfAgility, 1, "Cloak of Agility", "Gives you the ability to dash.", texture);
}

