//
//  SceneController.h
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#ifndef littlebiggame_SceneController_h
#define littlebiggame_SceneController_h

#include <list>

#include "DrawableFactory.h"
#include "EntityFactory.h"
<<<<<<< HEAD
#include "map.h"
=======
#include <iostream>
#include "Macro.h"
#include "Resources.h"

using namespace std;
>>>>>>> ca905c745327d501a47fd4d3b65f7e93c4dc63ba

class SceneController
{
public:
    SceneController();
    SceneController(const std::string name);
    ~SceneController();
    
    void    live();
    void    update();
    void    draw();
<<<<<<< HEAD
    
private:
    std::list<Entity *> entityList;
    Map *map;
=======
    list<t_resource> get_resources();
    
private:
    list<Entity *> entityList;
    list<t_resource> resources; 
>>>>>>> ca905c745327d501a47fd4d3b65f7e93c4dc63ba
};

#endif
