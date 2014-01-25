//
//  SceneController.cpp
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#include "SceneController.h"

SceneController::SceneController(const std::string name)
{
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
}