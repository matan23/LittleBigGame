//
//  CApplication.h
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#ifndef littlebiggame_CApplication_h
#define littlebiggame_CApplication_h

#include "SceneController.h"
#include "GameSettings.h"

class CApplication
{
public:
    static CApplication &GetInstance();
    void    init();
    void    startScene(const std::string name);
    SDL_Window  *get_window();
    
    SDL_Window          *_owindow;
    GameSettings        oGameSettings;
    
private:
    static CApplication _instance;
    bool                _running;
    SDL_Event           _event;
    
    CApplication &operator= (const CApplication &);
    CApplication(const CApplication &) {}
    CApplication();
    ~CApplication();
};

#endif
