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
#include <list>
#include "Macro.h"

typedef struct  s_item
{
    int                  type;
    unsigned int         x;
    unsigned int         y;
}               t_item;


class Map
{
public:
    Map();
    Map(const std::string name);
    ~Map();
    
    void    loadMap(char *name);
    
    std::list<t_item *> *getItemList;
    
private:
    std::list<t_item *> *itemList;
    
};

#endif /* defined(__littlebiggame__map__) */