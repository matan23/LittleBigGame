//
//  GameSettings.h
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef littlebiggame_GameSettings_h
#define littlebiggame_GameSettings_h

# include <string>

using namespace std;

class GameSettings
{
public:
    GameSettings();
    ~GameSettings();
    
    int                 WINDOW_MAX_WIDTH;
    int                 WINDOW_MAX_HEIGHT;
    std::string         WINDOW_BACKGROUND;
    int                 HEROSPEED;
    int                 GOOMBASPEED;
    int                 HEROLIFE;
    int                 TILE_SIZE;
    int                 SCROLL_SPEED;
    
    int                 getWINDOW_MAX_WIDTH();
    int                 getWINDOW_MAX_HEIGHT();
    const std::string   &getWINDOW_BACKGROUND();
    int                 getHEROSPEED();
    int                 getGOOMBASPEED();
    int                 getHEROLIFE();
    int                 getTILE_SIZE();
    int                 getSCROLL_SPEED();
private:
    void                loadFromFile(string path);
};

#endif