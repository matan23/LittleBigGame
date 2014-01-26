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
                                           WINDOW_MAX_WIDTH,
                                           WINDOW_MAX_HEIGHT,
                                           SDL_WINDOW_OPENGL        
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
            switch (this->_event.type)
            {
                case SDL_QUIT:
                    /* Quit the application */
                    this->_running = false;
                    exit(0);
                    break;

                case SDL_KEYDOWN:
                    switch (this->_event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						exit(0);
                        break;

					case SDLK_UP:
						oScene->move_up();
                        break;

					case SDLK_DOWN:
						oScene->move_down();
                        break;

					case SDLK_LEFT:
						oScene->move_left();
                        break;

					case SDLK_RIGHT:
						oScene->move_right();
                        break;

					default:
                        break;
				}
                    break;

                case SDL_KEYUP:
                    switch (this->_event.key.keysym.sym)
				{
					case SDLK_UP:
						oScene->move_done();
                        break;

					case SDLK_DOWN:
						oScene->move_done();
                        break;

					case SDLK_LEFT:
						oScene->move_done();
                        break;

					case SDLK_RIGHT:
						oScene->move_done();
                        break;

					default:
                        break;
				}
                    break;
            }
        }
        
        oScene->live();
    }
}

SDL_Window  *CApplication::get_window()
{
    return this->_owindow;
}
