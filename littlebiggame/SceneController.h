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
#include "Inputs.h"

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
    void init_inputs();
    void move_right();
    void move_left();
    void move_up();
    void move_down();
    void move_done();
    t_inputs get_inputs();
    void    doMap();
    void    updateMap();
    
private:
    std::list<Entity *> entityList;
    list<t_resource>    resources;
    Map                 *map;
    t_inputs             inputs;
    bool    loadModel();
    void    createEntityList();
};

#endif
