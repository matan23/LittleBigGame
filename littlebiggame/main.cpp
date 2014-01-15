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
    
    App.Init();
    
    resources = xml_loader.LoadResources("xml/drawable.xml");
    
    App.Start();
    
    while (App.isRunning())
    {
        App.Update();
        App.Live();
    }
    return 0;
}

