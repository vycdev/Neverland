//
// Created by Vycto on 01-Nov-20.
//
#include <string.h>
#include "../headers/abilities.h"
#include "../headers/items.h"

Item initItem(int id, char name[20], char description[100], Texture2D texture){
    Item item;

    item.id = id;
    strcpy_s(item.description,sizeof item.description , description);
    strcpy_s(item.name,sizeof item.name , name);
    item.texture = texture;

    return item;
}

void Execute(int id){
    switch(id){
        case 1:
            Dash(1, 25);
            break;
    }
}

void initItems(){
    Image image = LoadImage("../assets/test.png");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    items[0] = initItem(0, "EmptySlot", "Empty slot item", texture);
    items[1] = initItem(1, "Cloak of Agility", "Gives you the ability to dash.", texture);
}

