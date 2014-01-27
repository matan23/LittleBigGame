//
//  map.cpp
//  littlebiggame
//
//  Created by Damien Rebelo on 26/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//
#include <stdlib.h>
#include <string.h>
#include "CApplication.h"
#include "map.h"
#include "Inputs.h"
#include "Log.h"
#include "Macro.h"

Map::Map() {}
Map::~Map() {}

void Map::loadMap(std::string name) {
    int x, y;
    int val = 0;
    t_item *item;
    FILE *fp;
    CApplication    &App = CApplication::GetInstance();
    

    fp = fopen(name.c_str(), "rb");
    if (fp == NULL) {
        printf("Failed to open map %s\n", name.c_str());
        Log::writeLog("Failed to open map");
        exit(1);
    }

    for (y=0;y<MAX_MAP_Y;y++) {
        for (x=0;x<MAX_MAP_X;x++) {
            fscanf(fp, "%d", &val);
            if (val)
            {
                item = new t_item;
                item->x = x * App.oGameSettings.getTILE_SIZE();;
                item->y = y * App.oGameSettings.getTILE_SIZE();;
                item->type = val;
                this->itemList.push_back(item);
            }
        }
    }
    
    this->startX = 0;
    this->startY = 0;
    this->maxX = MAX_MAP_X * App.oGameSettings.getTILE_SIZE();;
    this->maxY = MAX_MAP_Y * App.oGameSettings.getTILE_SIZE();;
    
    fclose(fp);
}

const std::list <t_item *> &Map::getItemList()
{
    return (this->itemList);
}