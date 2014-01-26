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
#include "Item.h"

class Map
{
public:
    Map();
    Map(const std::string name);
    ~Map();
    int startX;
    int startY;
    int maxX;
    int maxY;
    
    void    loadMap(std::string name);
    
    const std::list<t_item *> &getItemList();
    
private:
    std::list<t_item *> itemList;
};

#endif /* defined(__littlebiggame__map__) */
