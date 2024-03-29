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

extern CApplication &App;


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
    //this->doMap();
    this->draw();
}

void    SceneController::update()
{
    for (std::list<Entity  *>::const_iterator iterator = this->entityList.begin(), end = this->entityList.end(); iterator != end; ++iterator)
    {
        (*iterator)->update();
        if ((*iterator)->item->type == HERO)
        {
            bool collision = false;
            if (inputs.right == 1)
            {
                for (std::list<Entity  *>::const_iterator iterator2 = this->entityList.begin(), end = this->entityList.end(); iterator2 != end; ++iterator2)
                {
                    if ((*iterator2)->item->type != HERO)
                    {
                        collision = (*iterator)->CollisionOnRight(*iterator2);
                        if (collision)
                        {
                            break;
                        }
                    }
                    
                }
                if (!collision)
                {
                    (*iterator)->move_right();
                    this->updateMap();
                }
            }
            if (inputs.left == 1)
            {
                for (std::list<Entity  *>::const_iterator iterator2 = this->entityList.begin(), end = this->entityList.end(); iterator2 != end; ++iterator2)
                {
                    if ((*iterator2)->item->type != HERO)
                    {
                        collision = (*iterator)->CollisionOnLeft(*iterator2);
                        if (collision)
                        {
                            break;
                        }
                    }
                    
                }
                if (!collision)
                {
                    (*iterator)->move_left();
                    this->updateMap();
                }
            }
            if (inputs.up == 1)
            {
                for (std::list<Entity  *>::const_iterator iterator2 = this->entityList.begin(), end = this->entityList.end(); iterator2 != end; ++iterator2)
                {
                    if ((*iterator2)->item->type != HERO)
                    {
                        collision = (*iterator)->CollisionOnTop(*iterator2);
                        if (collision)
                        {
                            break;
                        }
                    }
                    
                }
                if (!collision)
                {
                    (*iterator)->move_up();
                }
            }
            if (inputs.down == 1)
            {
                for (std::list<Entity  *>::const_iterator iterator2 = this->entityList.begin(), end = this->entityList.end(); iterator2 != end; ++iterator2)
                {
                    if ((*iterator2)->item->type != HERO)
                    {
                        collision = (*iterator)->CollisionOnBottom(*iterator2);
                        if (collision)
                        {
                            break;
                        }
                    }
                    
                }
                if (!collision)
                {
                    (*iterator)->move_down();
                }
            }
            collision = false;
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
    this->inputs.up = 0;
    this->inputs.down = 0;
}

void SceneController::move_right()
{
   this->inputs.right = 1; 
}

void SceneController::move_left()
{
    this->inputs.left = 1; 
}

void SceneController::move_up()
{
    this->inputs.up = 1;   
}

void SceneController::move_down()
{
    this->inputs.down = 1; 
}

void SceneController::move_done()
{
    init_inputs();
}

t_inputs SceneController::get_inputs(){
    return this->inputs;
}

void SceneController::doMap(){    
    if (this->inputs.left == 1)
	{
		this->map->startX -= App.oGameSettings.getSCROLL_SPEED();
		
		if (this->map->startX < 0)
		{
			this->map->startX = 0;
		}
	}
	
	else if (this->inputs.right == 1)
	{
		this->map->startX += App.oGameSettings.getSCROLL_SPEED();
		
		if (this->map->startX + App.oGameSettings.getWINDOW_MAX_WIDTH() >= this->map->maxX)
		{
			this->map->startX = this->map->maxX - App.oGameSettings.getWINDOW_MAX_WIDTH();
		}
	}
	
	if (this->inputs.up == 1)
	{
		this->map->startY -= App.oGameSettings.getSCROLL_SPEED();
		
		if (this->map->startY < 0)
		{
			this->map->startY = 0;
		}
	}
	
	else if (this->inputs.down == 1)
	{
		this->map->startY += App.oGameSettings.getSCROLL_SPEED();
		
		if (this->map->startY + App.oGameSettings.getWINDOW_MAX_HEIGHT() >= this->map->maxY)
		{
			this->map->startY = this->map->maxY - App.oGameSettings.getWINDOW_MAX_HEIGHT();
		}
	}
}

void SceneController::updateMap()
{
	int mapX, x1, x2, mapY, y1, y2;
    
	mapX = this->map->startX / App.oGameSettings.getTILE_SIZE();
	x1 = (this->map->startX % App.oGameSettings.getTILE_SIZE()) * -1;
	x2 = x1 + App.oGameSettings.getWINDOW_MAX_WIDTH() + (x1 == 0 ? 0 : App.oGameSettings.getTILE_SIZE());
	
	mapY = this->map->startY / App.oGameSettings.getTILE_SIZE();
	y1 = (this->map->startY % App.oGameSettings.getTILE_SIZE()) * -1;
	y2 = y1 + App.oGameSettings.getWINDOW_MAX_HEIGHT() + (y1 == 0 ? 0 : App.oGameSettings.getTILE_SIZE());
	
    for (std::list<Entity  *>::const_iterator iterator = this->entityList.begin(), end = this->entityList.end(); iterator != end; ++iterator) {
//        if ((*iterator)->item->type == BRICK)
//        {
            if (this->inputs.right == 1)
                (*iterator)->item->x -= App.oGameSettings.getSCROLL_SPEED();
            if (this->inputs.left == 1)
                (*iterator)->item->x += App.oGameSettings.getSCROLL_SPEED();
//        }
        
    }
}