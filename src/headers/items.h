//
// Created by Vycto on 01-Nov-20.
//
#include "raylib.h"
#ifndef NEVERLAND_ITEMS_H
#define NEVERLAND_ITEMS_H

void Execute(int id);
void initItems();
typedef struct Item {
    int id;
    char name[25], description[100];
    struct Texture2D texture;
} Item;

Item items[100];

#endif //NEVERLAND_ITEMS_H
