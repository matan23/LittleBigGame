//
//  Events.cpp
//  littlebiggame
//
//  Created by Damien Rebelo on 26/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#include "Events.h"
#include "CApplication.h"
#include <SDL2/SDL.h>

void Events::getEvents(SceneController *oScene)
{
    CApplication &App = CApplication::GetInstance();
    
    while (SDL_PollEvent(&this->_event))
    {
        switch (this->_event.type)
        {
            case SDL_QUIT:
                /* Quit the application */
                App.set_isRunning(false);
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