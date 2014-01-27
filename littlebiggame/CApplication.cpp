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
#include "Inputs.h"
#include "Events.h"
#include "Log.h"

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
    Log::writeLog("Application Init");
}

CApplication::~CApplication()
{
    cout<<"Cleaning Application"<<endl;
    Log::writeLog("Cleaning Application");
    SDL_DestroyWindow(this->_owindow);
    SDL_Quit();
}


//public API
void    CApplication::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "ERROR SDL_Init" << std::endl;
        Log::writeLog("ERROR SDL_Init");
        throw "Failed to init";
    }

    // create a window
    this->_owindow = SDL_CreateWindow(
                                           "SDL 2 window",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           this->oGameSettings.getWINDOW_MAX_WIDTH(),
                                           this->oGameSettings.getWINDOW_MAX_HEIGHT(),
                                           SDL_WINDOW_OPENGL        
                                           );
}

void    CApplication::startScene(const std::string name = "")
{

    SceneController *oScene = new SceneController(name);
    Events *events = new Events;
    this->_running = true;

    while (this->_running)
    {
        events->getEvents(oScene);
    }
}

SDL_Window  *CApplication::get_window()
{
    return this->_owindow;
}

void CApplication::set_isRunning(bool isRunning) {
    this->_running = isRunning;
}
