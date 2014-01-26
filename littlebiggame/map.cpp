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


Map::~Map() {}

void Map::loadMap(std::string name) {
    int x, y;
    int val = 0;
    t_item *item;
    FILE *fp;

    fp = fopen(name.c_str(), "rb");
    if (fp == NULL) {
        printf("Failed to open map %s\n", name.c_str());
        exit(1);
    }
    
    for (y=0;y<MAX_MAP_Y;y++) {
        for (x=0;x<MAX_MAP_X;x++) {
            fscanf(fp, "%d", &val);
            if (val)
            {
                item = new t_item;
                item->x = x * MAP_SCALE;
                item->y = y * MAP_SCALE;
                item->type = val;
                this->itemList.push_back(item);
            }
        }
    }
    fclose(fp);
}

const std::list <t_item *> &Map::getItemList()
{
    return (this->itemList);
}