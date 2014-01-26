//
//  Brick.cpp
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#include "Brick.h"

#pragma mark ctor /dtor

Brick::Brick(const t_resource *rsrc) : Entity(rsrc)
{
    
}

Brick::~Brick()
{
    
}

#pragma mark imlements Entity Interface

Entity *Brick::Clone() const
{
    return new Brick(*this);
}

#pragma mark public API

void    Brick::update()
{

}