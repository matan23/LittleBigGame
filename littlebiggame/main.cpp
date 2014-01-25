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
    t_resource o_resource;
    
    App.init();
    
    //bougger cette logique dans application
    //stocker les ressources dans une propriete de l'object capplication
    resources = xml_loader.LoadResources("/Users/Jero/Documents/ETNA2/LittleBigGame/littlebiggame/drawable.xml");
   
    o_resource = resources.front();
    
    App.startScene("default");
    
//    SDL_Rect mario;
//    
//    mario.x = 50;
//    mario.y = 50;
//    App.Start();
//    
//    
//    while (App.isRunning())
//    {
//        App.Update();
//        SDL_BlitSurface(o_resource.surface, NULL, SDL_GetWindowSurface(App._owindow), &mario);
//        
//        SDL_UpdateWindowSurface(App._owindow);
//        App.Live();
//    }
    return 0;
}

