//
//  Player.cpp
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#include "Player.h"
#include "Macro.h"

Player::Player(t_resource *rsrc) : Entity(rsrc)
{
    
}

Player::~Player()
{
    
}

#pragma mark imlements Entity Interface

Entity *Player::Clone() const
{
    return new Player(*this);
}

#pragma mark public API

void    Player::update()
{
    
}