//
//  map.h
//  littlebiggame
//
//  Created by Damien Rebelo on 26/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef __littlebiggame__map__
#define __littlebiggame__map__

#include <iostream>
#include <string.h>
#include <list>
#include "Macro.h"

typedef struct  s_item
{
    int                 type;
    int                 startX;
    int                 startY;
    int                 maxX;
    int                 maxY;
    unsigned int        x;
    unsigned int        y;
}               t_item;


class Map
{
public:
    Map();
    Map(const std::string name);
    ~Map();
    
    void    loadMap(std::string name);
    
    std::list<t_item *> *getItemList;
    
private:
    std::list<t_item *> *itemList;
    
};

#endif /* defined(__littlebiggame__map__) */
