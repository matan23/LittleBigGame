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

class CApplication
{
public:
    static CApplication &GetInstance();
    void    init();
    void    startScene(const std::string name);

private:
    static CApplication _instance;
    SDL_Window          *_owindow;
    bool                _running;
    SDL_Event           _event;
    
    CApplication &operator= (const CApplication &);
    CApplication(const CApplication &) {}
    CApplication();
    ~CApplication();
};

#endif
