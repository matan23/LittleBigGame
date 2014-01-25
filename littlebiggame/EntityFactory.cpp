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

using namespace std;

//Entity* Carre::Clone() const
//{
//    return new Carre(*this);
//}
//
//Entity* Cercle::Clone() const
//{
//    return new Cercle(*this);
//}


std::map<string, Entity *> EntityFactory::m_map = std::map <string, Entity *>();

/*
 ** If the key does not exist yet.
 ** Will copy a new object into the "database"
 */
void EntityFactory::Register(const string& key, Entity* obj)
{
    if (m_map.find(key) == m_map.end())
        m_map[key] = obj;
}

/*
 ** Iterate over the list of known keys.
 ** And will clone a new object from a given key.
 */
Entity *EntityFactory::Produce(const std::string& key) const
{
    Entity *tmp = 0;
    std::map<string, Entity *>::const_iterator it = m_map.find(key);
    
    if (it != m_map.end())
        tmp = ((*it).second)->Clone();
    else
        throw "Key does not exist or have never been registered.";
    return tmp;
}
