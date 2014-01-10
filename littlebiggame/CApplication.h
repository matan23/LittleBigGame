//
//  CApplication.h
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#ifndef littlebiggame_CApplication_h
#define littlebiggame_CApplication_h

#include "SceneManager.h"

class CApplication
{
public:
    static CApplication &GetInstance();
    void    Init();
    void    Start();
    void    Update();
    void    Live();
    bool    isRunning();
    void    setScene(const std::string name);

private:
    static CApplication _instance;
    SDL_Window          *_owindow;
    bool                _running;
    SDL_Event           _event;
    SceneManager        *_scene;
    std::string         _scene_str;
    std::string         _current_scene_str;

    
    CApplication &operator= (const CApplication &);
    CApplication(const CApplication &) {}
    CApplication();
    ~CApplication();
    
    void    ManageScene();
};

#endif
