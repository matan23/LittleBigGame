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

Input input;

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
						input.up = 1;
                        break;
                        
					case SDLK_DOWN:
						input.down = 1;
                        break;
                        
					case SDLK_LEFT:
						input.left = 1;
                        break;
                        
					case SDLK_RIGHT:
						input.right = 1;
                        break;
                        
					default:
                        break;
				}
                    break;
                    
                case SDL_KEYUP:
                    switch (this->_event.key.keysym.sym)
				{
					case SDLK_UP:
						input.up = 0;
                        break;
                        
					case SDLK_DOWN:
						input.down = 0;
                        break;
                        
					case SDLK_LEFT:
						input.left = 0;
                        break;
                        
					case SDLK_RIGHT:
						input.right = 0;
                        break;
                        
					default:
                        break;
				}
                    break;
            }
        }
        oScene->update();
        oScene->draw();
    }
}

SDL_Window  *CApplication::get_window()
{
    return this->_owindow;
}