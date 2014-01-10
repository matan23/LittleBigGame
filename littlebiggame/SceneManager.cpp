//
//  SceneManager.cpp
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#include "SceneManager.h"

SceneManager::SceneManager(const std::string name)
{
    ADrawable *img = DrawableFactory::Produce("Image");
    delete img;
}

SceneManager::SceneManager() {}


SceneManager::~SceneManager()
{

}

//Public API
void    SceneManager::Live()
{
    
}

void    SceneManager::Update()
{
    
}

void    SceneManager::Draw()
{
    
}