//
//  CApplication.cpp
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#include <SDL2/SDL.h>
#include <iostream>

#include "CApplication.h"

using namespace std;


//canonical form
CApplication CApplication::_instance=CApplication();

CApplication& CApplication::GetInstance()
{
    return _instance;
}

CApplication::CApplication()
{
    cout<<"Application Init"<<endl;
}

CApplication::~CApplication()
{
    cout<<"Cleaning Application"<<endl;
    SDL_DestroyWindow(this->_owindow);
    SDL_Quit();
}


//public API
void    CApplication::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "ERROR SDL_Init" << std::endl;
        throw "Failed to init";
    }
    
    // create a window
    this->_owindow = SDL_CreateWindow(
                                           "SDL 2 window",             // window title
                                           SDL_WINDOWPOS_CENTERED,     // x position, centered
                                           SDL_WINDOWPOS_CENTERED,     // y position, centered
                                           640,                        // width, in pixels
                                           480,                        // height, in pixels
                                           SDL_WINDOW_OPENGL           // flags
                                           );

}

void    CApplication::startScene(const std::string name = "")
{
    
    SceneController *oScene = new SceneController(name);
    this->_running = true;
    
    while (this->_running)
    {
        while (SDL_PollEvent(&this->_event))
        {
            /* If a quit event has been sent */
            if (this->_event.type == SDL_QUIT)
            {
                /* Quit the application */
                this->_running = false;
            }
        }
        oScene->update();
        oScene->draw();
    }
}