//
//  SceneController.cpp
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#include "SceneController.h"
<<<<<<< HEAD
#include "Macro.h"
=======
#include "XmlLoader.h"
#include "CApplication.h"
>>>>>>> ca905c745327d501a47fd4d3b65f7e93c4dc63ba

SceneController::SceneController(const std::string name)
{

    this->map = new Map;
    this->map->loadMap("data/maps/map01.dat");
    //
//    int x, y;
//    
//    drawImage(backgroundImage, 0, 0);
//    
//    for (y=0;y<MAX_MAP_Y;y++) {
//        for (x=0;x<MAX_MAP_X;x++) {
//            if (maptile[y][x] != 0) {
//                drawImage(brickImage, x * TILE_SIZE, y * TILE_SIZE);
//            }
//        }
//    }
    
    //Map
    //parsing de la map
    //recuperer une liste de cle valeur
    //avec comme cle = le type de l'object
    //valeur sa position x,y
    //stocker le tout dans une std:map ou autre
    //ainsi pour chaque object on aura sa position x,y dans la map
    
    //Factory
    //boucler sur la liste crées précedemment
    //Et pour chaque object a partir des ressources du xml + sa position + les game settings
    //Creer le vrai object affichable avec sa logique
    // fin de la boucle = liste (Entity) construite.
    
    XmlLoader xml_loader;
    this->resources = xml_loader.LoadResources("/Users/Jero/Documents/ETNA2/LittleBigGame/littlebiggame/drawable.xml");
}

SceneController::SceneController() {}


SceneController::~SceneController()
{

}


//Public API
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
    //appeler methodes draw de chaque objet de la liste
    t_resource o_resource;
    SDL_Rect mario;
    CApplication &App = CApplication::GetInstance();
    mario.x = 50;
    mario.y = 50;
    o_resource = this->resources.front();
    
    SDL_BlitSurface(o_resource.surface, NULL, SDL_GetWindowSurface(App.get_window()), &mario);
    
    SDL_UpdateWindowSurface(App.get_window());

}

list<t_resource> SceneController::get_resources()
{
    return this->resources;
}