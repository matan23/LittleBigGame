//
//  Entity.h
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef littlebiggame_Entity_h
# define littlebiggame_Entity_h

# include "Resources.h"
# include "Item.h"
# include "Pos.h"

//la classe prototype abordé en II
template <class T> class Prototype
{
public:
    virtual ~Prototype() {}
    virtual T* Clone() const =0 ;
};

// Entity Interface
class Entity : public Prototype<Entity>
{
public:
    t_item      *item;
    t_resource  *rsrc;
    t_pos       *pos;
    
    Entity(t_resource *rsrc);
    ~Entity();
    
    void    setItem(t_item *item);
    void    setResource(t_resource *resource);
    
    virtual void update() = 0;
    
    virtual void draw();
    void    move_right();
    void    move_left();
    void    jump();
};

#endif
