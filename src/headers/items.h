//
// Created by Vycto on 01-Nov-20.
//
#include "raylib.h"
#ifndef NEVERLAND_ITEMS_H
#define NEVERLAND_ITEMS_H

void Execute(int id);
void InitItems();
typedef struct Item {
    int id;
    char name[25], description[100];
    struct Texture2D texture;
} Item;

Item
    empty,
    cloakOfAgility;


#endif //NEVERLAND_ITEMS_H
