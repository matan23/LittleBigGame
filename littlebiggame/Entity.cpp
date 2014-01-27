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

bool Entity::CollisionOnLeft(Entity* entity)
{
    int this_x_start = this->item->x;
    int this_y_start = this->item->y;
    int this_x_end = this->item->x + App.oGameSettings.getTILE_SIZE();
    int this_y_end = this->item->y + App.oGameSettings.getTILE_SIZE();  
    
    int entity_x_start = entity->item->x;
    int entity_y_start = entity->item->y;
    int entity_x_end = entity->item->x + App.oGameSettings.getTILE_SIZE();  
    int entity_y_end = entity->item->y + App.oGameSettings.getTILE_SIZE();
    
    //collision en x sur la gauche
    bool b_x = (this_x_start <= entity_x_end && this_x_end >= entity_x_start);
    //test alignement en y
    bool b_y = (this_y_start >= entity_y_start && this_y_start <= entity_y_end) || (this_y_end >= entity_y_start && this_y_end <= entity_y_end);

    return (b_x && b_y);
}

bool Entity::CollisionOnRight(Entity* entity)
{
    int this_x_start = this->item->x;
    int this_y_start = this->item->y;
    int this_x_end = this->item->x + App.oGameSettings.getTILE_SIZE();  
    int this_y_end = this->item->y + App.oGameSettings.getTILE_SIZE();  
    
    int entity_x_start = entity->item->x;
    int entity_y_start = entity->item->y;
    int entity_x_end = entity->item->x + App.oGameSettings.getTILE_SIZE();  
    int entity_y_end = entity->item->y + App.oGameSettings.getTILE_SIZE();
    
    //collision en x sur la droite
    bool b_x = (this_x_end <= entity_x_start && this_x_start >= entity_x_end);
    //test alignement en y
    bool b_y = (this_y_start >= entity_y_start && this_y_start <= entity_y_end) || (this_y_end >= entity_y_start && this_y_end <= entity_y_end);
    
    return (b_x && b_y);
}

bool Entity::CollisionOnTop(Entity* entity)
{
    int this_x_start = this->item->x;
    int this_y_start = this->item->y;
    int this_x_end = this->item->x + App.oGameSettings.getTILE_SIZE();  
    int this_y_end = this->item->y + App.oGameSettings.getTILE_SIZE();  
    
    int entity_x_start = entity->item->x;
    int entity_y_start = entity->item->y;
    int entity_x_end = entity->item->x + App.oGameSettings.getTILE_SIZE();  
    int entity_y_end = entity->item->y + App.oGameSettings.getTILE_SIZE();
    
    //collision en x sur la droite
    bool b_x = (this_x_start <= entity_x_end && this_x_end >= entity_x_start) || (this_x_end <= entity_x_start && this_x_start >= entity_x_end);
    //test alignement en y
    bool b_y = (this_y_start >= entity_y_start && this_y_start <= entity_y_end);
    
    return (b_x && b_y);
}

bool Entity::CollisionOnBottom(Entity* entity)
{
    int this_x_start = this->item->x;
    int this_y_start = this->item->y;
    int this_x_end = this->item->x + App.oGameSettings.getTILE_SIZE();  
    int this_y_end = this->item->y + App.oGameSettings.getTILE_SIZE();  
    
    int entity_x_start = entity->item->x;
    int entity_y_start = entity->item->y;
    int entity_x_end = entity->item->x + App.oGameSettings.getTILE_SIZE();  
    int entity_y_end = entity->item->y + App.oGameSettings.getTILE_SIZE();
    
    //collision en x sur la droite
    bool b_x = (this_x_start <= entity_x_end && this_x_end >= entity_x_start) || (this_x_end <= entity_x_start && this_x_start >= entity_x_end);
    //test alignement en y
    bool b_y = (this_y_end >= entity_y_start && this_y_end <= entity_y_end);
    
    return (b_x && b_y);
}

bool Entity::CheckCollision(Entity* entity)
{
    return (this->CollisionOnLeft(entity) || this->CollisionOnRight(entity));  
}
