//
//  Entity.cpp
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#include "CApplication.h"
#include "Entity.h"

#pragma mark ctor /dtor

extern CApplication &App;

Entity::Entity(const t_resource *rsrc)
{
    this->rsrc = rsrc;
}

Entity::~Entity()
{
    
}

#pragma mark public API

void    Entity::setItem(t_item *item)
{
    this->item = item;
}

void    Entity::draw()
{
    SDL_Rect sdl_rect;
    
    sdl_rect.x = this->item->x;
    sdl_rect.y = this->item->y;
    
    CApplication &App = CApplication::GetInstance();
    
    SDL_BlitSurface(this->rsrc->surface, NULL, SDL_GetWindowSurface(App.get_window()), &sdl_rect);
}


void    Entity::move_right()
{
    this->item->x += App.oGameSettings.getHEROSPEED();
}

void    Entity::move_left()
{
    this->item->x -= App.oGameSettings.getHEROSPEED();
}

void    Entity::move_up()
{
    this->item->y -= App.oGameSettings.getHEROSPEED();

    if (this->item->y < 0)
    {
        this->item->y = 0;
    }
}

void    Entity::move_down()
{
    this->item->y += App.oGameSettings.getHEROSPEED();
    if (this->item->y + 32 >= App.oGameSettings.getWINDOW_MAX_HEIGHT())
    {
        this->item->y = 0;
    }
    
}