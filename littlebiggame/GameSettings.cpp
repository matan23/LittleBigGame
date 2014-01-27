//
//  GameSettings.cpp
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#include "GameSettings.h"
#include "tinyxml.h"
#include "Log.h"

using namespace std;

GameSettings::GameSettings()
{
    this->WINDOW_MAX_WIDTH = 640;
    this->WINDOW_MAX_HEIGHT = 480;
    this->WINDOW_BACKGROUND = "background.png";
    this->HEROSPEED = 1;
    this->GOOMBASPEED = 50;
    this->HEROLIFE = 1;
    this->TILE_SIZE = 32;
    this->SCROLL_SPEED = 4;
}

GameSettings::~GameSettings()
{
}

void    GameSettings::loadFromFile(string path)
{
    TiXmlDocument       resource_xml(path.c_str());
    TiXmlHandle         hdl(&resource_xml);
    TiXmlElement        *elem;
    
    if (!resource_xml.LoadFile())
    {
        cerr << "TinyXML: loading error" << endl;
        cerr << "error #" << resource_xml.ErrorId() << " : " << resource_xml.ErrorDesc() << endl;
        Log::writeLog("TinyXml : loading error :");
    }
    
    elem = hdl.FirstChildElement().Element();
}

//we do not need const sign they are primitive type
int                 GameSettings::getWINDOW_MAX_WIDTH() { return this->WINDOW_MAX_WIDTH; }
int                 GameSettings::getWINDOW_MAX_HEIGHT() { return this->WINDOW_MAX_HEIGHT; }
const  std::string &GameSettings::getWINDOW_BACKGROUND() { return this->WINDOW_BACKGROUND; }
int                 GameSettings::getHEROSPEED() { return this->HEROSPEED; }
int                 GameSettings::getTILE_SIZE() { return this->TILE_SIZE; }
int                 GameSettings::getSCROLL_SPEED() { return this->SCROLL_SPEED; }