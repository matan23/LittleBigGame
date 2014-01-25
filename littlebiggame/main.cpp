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
    
    App.init();
    
<<<<<<< HEAD
    //bougger cette logique dans application
    //stocker les ressources dans une propriete de l'object capplication
    resources = xml_loader.LoadResources("drawable.xml");
   
    o_resource = resources.front();
    
=======
>>>>>>> ca905c745327d501a47fd4d3b65f7e93c4dc63ba
    App.startScene("default");

    return 0;
}

