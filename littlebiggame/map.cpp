//
//  map.cpp
//  littlebiggame
//
//  Created by Damien Rebelo on 26/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//
#include <stdlib.h>
#include "map.h"
#include "Inputs.h"

extern Input input;

Map::Map() {}


Map::~Map() {}

void Map::loadMap(std::string name) {
    int x, y;
    this->itemList = new std::list <t_item *>;
    
    t_item *item;
    item = (t_item*)malloc(sizeof(*item));
    
    FILE *fp;

    fp = fopen(name.c_str(), "rb");
    
    if (fp == NULL) {
        printf("Failed to open map %s\n", name.c_str());
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
    
    item->startX = 0;
    item->startY = 0;
    item->maxX = MAX_MAP_X * TILE_SIZE;
    item->maxY = MAX_MAP_Y * TILE_SIZE;
    
    fclose(fp);
}
/*
void doMap()
{
	if (input.left == 1)
	{
		map.startX -= SCROLL_SPEED;
		
		if (map.startX < 0)
		{
			map.startX = 0;
		}
	}
	
	else if (input.right == 1)
	{
		map.startX += SCROLL_SPEED;
		
		if (map.startX + SCREEN_WIDTH >= map.maxX)
		{
			map.startX = map.maxX - SCREEN_WIDTH;
		}
	}
	
	if (input.up == 1)
	{
		map.startY -= SCROLL_SPEED;
		
		if (map.startY < 0)
		{
			map.startY = 0;
		}
	}
	
	else if (input.down == 1)
	{
		map.startY += SCROLL_SPEED;
		
		if (map.startY + SCREEN_HEIGHT >= map.maxY)
		{
			map.startY = map.maxY - SCREEN_HEIGHT;
		}
	}
}

void drawMap()
{
	int x, y, mapX, x1, x2, mapY, y1, y2;
    
	mapX = map.startX / TILE_SIZE;
	x1 = (map.startX % TILE_SIZE) * -1;
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
	
	mapY = map.startY / TILE_SIZE;
	y1 = (map.startY % TILE_SIZE) * -1;
	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);
	
	// Draw the background
	
	drawImage(backgroundImage, 0, 0);
    
	// Draw the map starting at the startX and startY
	
	for (y=y1;y<y2;y+=TILE_SIZE)
	{
		mapX = map.startX / TILE_SIZE;
		
		for (x=x1;x<x2;x+=TILE_SIZE)
		{
			if (map.tile[mapY][mapX] != 0)
			{
				drawImage(brickImage, x, y);
			}
			
			mapX++;
		}
		
		mapY++;
	}
}
*/