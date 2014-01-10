//
//  SceneManager.h
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#ifndef littlebiggame_SceneManager_h
#define littlebiggame_SceneManager_h

#include "DrawableFactory.h"
#include "drawable.h"

class SceneManager
{
public:
    SceneManager();
    SceneManager(const std::string name);
    ~SceneManager();
    
    void    Live();
    void    Update();
    void    Draw();
};

#endif
