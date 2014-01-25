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

    App.startScene("default");

    return 0;
}

