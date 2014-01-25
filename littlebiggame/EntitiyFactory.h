//
//  EntitiesFactory.h
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#ifndef littlebiggame_EntitiyFactory_h
# define littlebiggame_EntityFactory_h

# include <map>
# include <string>

//la classe prototype abordé en II
template <class T> class Prototype
{
public:
    virtual ~Prototype() {}
    virtual T* Clone() const =0 ;
};

// Entity Interface
class Entity : public  Prototype<Entity>
{
public:
    int type;
    
};

// The factory
class EntityFactory
{
public:
    static std::map<std::string, Entity *> m_map;
    
public:
    // Match a key with an associated object
    static void Register(const std::string& key, Entity* obj);
    
    // Create an object from a given key
    Entity* Produce(const std::string& key) const;
};
#endif
