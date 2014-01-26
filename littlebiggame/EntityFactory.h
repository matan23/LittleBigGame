//
//  EntitiesFactory.h
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#ifndef littlebiggame_EntityFactory_h
# define littlebiggame_EntityFactory_h

# include <map>
# include <string>

# include "Entity.h"
# include "Item.h"
# include "Player.h"
# include "Brick.h"

// The factory
class EntityFactory
{
public:
    static std::map<int, Entity *> m_map;
    
public:
    // Match a key with an associated object
    static void Register(int key, class Entity *obj);
    
    // Create an object from a item
    Entity* ProduceFromItem(t_item *item);
};
#endif
