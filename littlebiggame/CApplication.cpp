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
    this->_current_scene_str = "main";
    this->_scene_str = "main";
    setScene(this->_scene_str);
    cout<<"Application Init"<<endl;
}

CApplication::~CApplication()
{
    cout<<"Cleaning Application"<<endl;
    SDL_DestroyWindow(this->_owindow);
    SDL_Quit();
}


//public API
void    CApplication::Init()
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

void CApplication::Start()
{
    this->_running = true;
}

void CApplication::Live()
{
    this->_scene->Live();
}

void CApplication::Update()
{
    while(SDL_PollEvent(&this->_event))
    {
        /* If a quit event has been sent */
        if (this->_event.type == SDL_QUIT)
        {
            /* Quit the application */
            this->_running = false;
        }
    }
    CApplication::ManageScene();
}

bool CApplication::isRunning()
{
    return this->_running;
}

void CApplication::setScene(const std::string name)
{
    this->_scene = new SceneManager(name);
}

//priv
void CApplication::ManageScene()
{
    if (this->_scene_str != this->_current_scene_str)
    {
        this->_scene = new SceneManager(this->_scene_str);
    }
}