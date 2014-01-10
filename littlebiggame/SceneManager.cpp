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
    //load xml
    // boucle sur le fichier xml qui parse les noeuds
    //appel des methodes pour construire la liste.
    
    ADrawable *img = DrawableFactory::Produce("Image");
    
    // fin de la boucle = liste (drawable) construite.
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