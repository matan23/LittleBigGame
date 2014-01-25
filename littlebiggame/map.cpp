//
//  map.cpp
//  littlebiggame
//
//  Created by Damien Rebelo on 26/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//
#include <stdlib.h>
#include "map.h"

Map::Map() {}


Map::~Map()
{
    
}

void Map::loadMap(char *name) {
    int x, y;
    this->itemList = new std::list <t_item *>;
    
    t_item *item;
    item = (t_item*)malloc(sizeof(*item));
    
    FILE *fp;

    fp = fopen(name, "rb");
    
    if (fp == NULL) {
        printf("Failed to open map %s\n", name);
        exit(1);
    }
    
    for (y=0;y<MAX_MAP_Y;y++) {
        for (x=0;x<MAX_MAP_X;x++) {
            item->x = x;
            item->y = y;
            fscanf(fp, "%d", &item->type);
            this->itemList->push_back(item);
        }
    }
    
    fclose(fp);
}