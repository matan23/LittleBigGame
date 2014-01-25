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

class SceneController
{
public:
    SceneController();
    SceneController(const std::string name);
    ~SceneController();
    
    void    live();
    void    update();
    void    draw();
private:
    std::list<Entity *> entityList;
};

#endif
