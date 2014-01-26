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

#include "EntityFactory.h"
#include "map.h"
#include <iostream>
#include "Macro.h"
#include "Resources.h"

using namespace std;

class SceneController
{
public:
    SceneController();
    SceneController(const std::string name);
    ~SceneController();
    
    void    live();
    void    update();
    void    draw();
    const list<t_resource>  get_resources();
    const t_resource        *getRessourceForType(int type);

private:
    std::list<Entity *> entityList;
    list<t_resource>    resources;
    Map                 *map;
    
    bool    loadModel();
    void    createEntityList();
};

#endif
