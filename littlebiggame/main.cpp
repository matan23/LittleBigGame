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
    
    App.Init();
    
    resources = xml_loader.LoadResources("/Users/Jero/Documents/ETNA2/LittleBigGame/littlebiggame/drawable.xml");
   
    o_resource = resources.front();
    
    App.Start();
    
    
    
    
    while (App.isRunning())
    {
        App.Update();
        SDL_BlitSurface(o_resource.surface, NULL, SDL_GetWindowSurface(App._owindow), NULL);
        
        SDL_UpdateWindowSurface(App._owindow);
        App.Live();
    }
    return 0;
}

