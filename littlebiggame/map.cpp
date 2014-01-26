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
		this->map.startX -= SCROLL_SPEED;
		
		if (this->startX < 0)
		{
			this->startX = 0;
		}
	}
	
	else if (input.right == 1)
	{
		this->startX += SCROLL_SPEED;
		
		if (this->startX + SCREEN_WIDTH >= this->maxX)
		{
			this->startX = this->maxX - SCREEN_WIDTH;
		}
	}
	
	if (input.up == 1)
	{
		this->startY -= SCROLL_SPEED;
		
		if (this->startY < 0)
		{
			this->startY = 0;
		}
	}
	
	else if (input.down == 1)
	{
		this->startY += SCROLL_SPEED;
		
		if (this->startY + SCREEN_HEIGHT >= this->maxY)
		{
			this->startY = this->maxY - SCREEN_HEIGHT;
		}
	}
}

void drawMap()
{
	int x, y, mapX, x1, x2, mapY, y1, y2;
    
	mapX = this->startX / TILE_SIZE;
	x1 = (this->startX % TILE_SIZE) * -1;
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
	
	mapY = this->startY / TILE_SIZE;
	y1 = (this->startY % TILE_SIZE) * -1;
	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);
	
	// Draw the background
	
	drawImage(backgroundImage, 0, 0);
    
	// Draw the map starting at the startX and startY
	
	for (y=y1;y<y2;y+=TILE_SIZE)
	{
		mapX = this->startX / TILE_SIZE;
		
		for (x=x1;x<x2;x+=TILE_SIZE)
		{
			if (this->tile[mapY][mapX] != 0)
			{
				drawImage(brickImage, x, y);
			}
			
			mapX++;
		}
		
		mapY++;
	}
}
*/