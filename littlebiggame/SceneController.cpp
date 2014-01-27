//
//  SceneController.cpp
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#include "SceneController.h"
#include "Macro.h"
#include "XmlLoader.h"
#include "CApplication.h"
#include "Resources.h"

#pragma mark Ctor / Dtor

SceneController::SceneController(const std::string name)
{
    this->loadModel();
    
    this->createEntityList();
    this->init_inputs();
}

SceneController::SceneController() {}


SceneController::~SceneController()
{
    
}

#pragma mark Public API
void    SceneController::live()
{
    this->update();
    this->doPlayer();
    this->updateMap();
    this->draw();
}

void    SceneController::update()
{
    for (std::list<Entity  *>::const_iterator iterator = this->entityList.begin(), end = this->entityList.end(); iterator != end; ++iterator)
    {
        (*iterator)->update();
        if ((*iterator)->item->type == HERO)
        {
            if (inputs.right == 1)
                (*iterator)->move_right();
            if (inputs.left == 1)
                (*iterator)->move_left();
        }
    }
}

void    SceneController::draw()
{
    CApplication &App = CApplication::GetInstance();
    
    SDL_Surface *window_surface = SDL_GetWindowSurface(App.get_window());
    SDL_FillRect(window_surface, 0, 0x000000);
    
    for (std::list<Entity  *>::const_iterator iterator = this->entityList.begin(), end = this->entityList.end(); iterator != end; ++iterator)
        (*iterator)->draw();
    
    SDL_UpdateWindowSurface(App.get_window());
    
}

const list<t_resource> SceneController::get_resources()
{
    return this->resources;
}

#pragma mark Internals

bool    SceneController::loadModel()
{
    XmlLoader xml_loader;
    this->resources = xml_loader.LoadResources("drawable.xml");
    
    this->map = new Map;
    this->map->loadMap("data/maps/map01.dat");
    return true;
}

const t_resource  *SceneController::getRessourceForType(int type)
{
    for (std::list<t_resource>::const_iterator iterator = this->resources.begin(), end = this->resources.end(); iterator != end; ++iterator)
        if (iterator->type == type)
            return &(*iterator);
    return NULL;
}


void    SceneController::createEntityList()
{
    const std::list<t_item *> mapItems = this->map->getItemList();
    
    EntityFactory Factory;
    
    EntityFactory::Register(BRICK, new Brick(this->getRessourceForType(BRICK)));
    EntityFactory::Register(HERO, new Player(this->getRessourceForType(HERO)));
    
    for (std::list<t_item *>::const_iterator iterator = mapItems.begin(), end = mapItems.end(); iterator != end; ++iterator)
        this->entityList.push_back(Factory.ProduceFromItem(*iterator));
}

void SceneController::init_inputs()
{
    this->inputs.right = 0;
    this->inputs.left = 0;
}

void SceneController::move_right()
{
    this->inputs.right = 1;
}

void SceneController::move_left()
{
    this->inputs.left = 1;
}

void SceneController::jump()
{
    this->inputs.jump = 1;
}

void SceneController::move_done()
{
    init_inputs();
}

t_inputs SceneController::get_inputs(){
    return this->inputs;
}

void SceneController::doPlayer()
{
    for (std::list<Entity  *>::iterator iterator = this->entityList.begin(), end = this->entityList.end(); iterator != end; ++iterator) {
        if ((*iterator)->item->type == HERO)
        {
            if ((*iterator)->rsrc->thinkTime == 0)
            {
                (*iterator)->rsrc->dirX = 0;
                
                /* Gravity always pulls the player down */
                (*iterator)->rsrc->dirY += GRAVITY_SPEED;
                
                if ((*iterator)->rsrc->dirY >= MAX_FALL_SPEED)
                {
                    (*iterator)->rsrc->dirY = MAX_FALL_SPEED;
                }
                
                if (this->inputs.left == 1)
                {
                    (*iterator)->rsrc->dirX -= HEROSPEED;
                }
                
                else if (this->inputs.right == 1)
                {
                    (*iterator)->rsrc->dirX += HEROSPEED;
                }
                
                if (this->inputs.jump == 1)
                {
                    if ((*iterator)->rsrc->onGround == 1)
                    {
                        (*iterator)->rsrc->dirY = -11;
                    }
                    
                    this->inputs.jump = 0;
                }
                
//                checkToMap(&player);
//                
//                centerEntityOnMap(&player);
            }
            
            if ((*iterator)->rsrc->thinkTime > 0)
            {
                (*iterator)->rsrc->thinkTime--;
                
                if ((*iterator)->rsrc->thinkTime == 0)
                {
                    (*iterator)->item->x = (*iterator)->item->y = 0;
                    (*iterator)->rsrc->dirX = (*iterator)->rsrc->dirY = 0;
                    
                    (*iterator)->rsrc->thinkTime = 0;
                }
            }
        }
    }
}

void SceneController::updateMap()
{
	int mapX, x1, x2, mapY, y1, y2;
    
	mapX = this->map->startX / TILE_SIZE;
	x1 = (this->map->startX % TILE_SIZE) * -1;
	x2 = x1 + WINDOW_MAX_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
	
	mapY = this->map->startY / TILE_SIZE;
	y1 = (this->map->startY % TILE_SIZE) * -1;
	y2 = y1 + WINDOW_MAX_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);
	
    for (std::list<Entity  *>::const_iterator iterator = this->entityList.begin(), end = this->entityList.end(); iterator != end; ++iterator) {
        if ((*iterator)->item->type == BRICK)
        {
            if (this->inputs.right == 1)
                (*iterator)->item->x -= SCROLL_SPEED;
            if (this->inputs.left == 1)
                (*iterator)->item->x += SCROLL_SPEED;
        }
        
    }
}