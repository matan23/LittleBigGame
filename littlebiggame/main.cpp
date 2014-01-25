//
//  main.cpp
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#include <SDL2/SDL.h>
#include <iostream>
#include <unistd.h>

#include "XmlLoader.h"
#include "CApplication.h"

int main(int argc, const char * argv[])
{
    CApplication &App = CApplication::GetInstance();
    XmlLoader xml_loader;
    list<t_resource> resources;
    
    App.init();
    
    //bougger cette logique dans application
    //stocker les ressources dans une propriete de l'object capplication
    resources = xml_loader.LoadResources("/Users/Jero/Documents/ETNA2/LittleBigGame/littlebiggame/drawable.xml");
    
    App.startScene("default");
    
    return 0;
}

