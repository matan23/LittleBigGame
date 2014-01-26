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

    
    //TODO
    //assert the data have been correctly loaded otherwise return false
    this->loadModel();
    
    this->createEntityList();
}

SceneController::SceneController() {}


SceneController::~SceneController()
{

}

#pragma mark Public API
void    SceneController::live()
{
    this->update();
    this->draw();
}

void    SceneController::update()
{
    //appeler methodes update de chaque objet de la liste
}

void    SceneController::draw()
{
    //domap();
    //draw de la map
    
    
    //appeler methodes draw de chaque objet de la liste
    CApplication &App = CApplication::GetInstance();
    
    for (std::list<Entity  *>::const_iterator iterator = this->entityList.begin(), end = this->entityList.end(); iterator != end; ++iterator)
        (*iterator)->draw();

    
    SDL_UpdateWindowSurface(App.get_window());
    
}

const list<t_resource> SceneController::get_resources()
{
    return this->resources;
}

#pragma mark Internals

//TODO
//assert the data have been correctly loaded otherwise return false
bool    SceneController::loadModel()
{
    //let's load the ressources
    XmlLoader xml_loader;
    this->resources = xml_loader.LoadResources("drawable.xml");
    
    //let's load the map
    this->map = new Map;
    this->map->loadMap("data/maps/map01.dat");
    return true;
}

//should be moved into a ressource manager object
//should use a key value system instead of a list
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
    
    //Factory
    //boucler sur la liste crées précedemment
    //Et pour chaque object a partir des ressources du xml + sa position + les game settings
    //Creer le vrai object affichable avec sa logique
    // fin de la boucle = liste (Entity) construite.
    
    EntityFactory Factory;
    
    //Careful if a type in the map is not registered in the factory the program will crash
    EntityFactory::Register(BRICK, new Brick(this->getRessourceForType(BRICK)));
    EntityFactory::Register(HERO, new Brick(this->getRessourceForType(HERO)));
    
    for (std::list<t_item *>::const_iterator iterator = mapItems.begin(), end = mapItems.end(); iterator != end; ++iterator)
        this->entityList.push_back(Factory.ProduceFromItem(*iterator));
}