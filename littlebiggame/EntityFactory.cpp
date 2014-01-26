//
//  EntitiesFactory.cpp
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#include <iostream>
#include <iterator>

#include "EntityFactory.h"
#include "Entity.h"

using namespace std;

std::map<int, Entity *> EntityFactory::m_map = std::map <int, Entity *>();

/*
 ** If the key does not exist yet.
 ** Will copy a new object into the "database"
 */
void EntityFactory::Register(int key, class Entity *obj)
{
    if (m_map.find(key) == m_map.end())
        m_map[key] = obj;
}

/*
 ** Iterate over the list of known keys.
 ** And will clone a new object from an item
 */

Entity *EntityFactory::ProduceFromItem(t_item *item)
{
    Entity *tmp = 0;
    std::map<int, Entity *>::const_iterator it = m_map.find(item->type);
    
    if (it != m_map.end())
    {
        tmp = ((*it).second)->Clone();
        tmp->setItem(item);
    }
    else
        throw "Key does not exist or have never been registered.";
    return tmp;
}
