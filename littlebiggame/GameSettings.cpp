//
//  GameSettings.cpp
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#include <cstdlib>
#include "GameSettings.h"
#include "Log.h"

using namespace std;

map<string, string> GameSettings::m_map = map <string, string>();

#pragma mark ctor / dtor

GameSettings::GameSettings()
{
    this->loadFromFile("settings.xml");
}

GameSettings::~GameSettings()
{
}

#pragma mark File parsing

void                GameSettings::parseSetting(const TiXmlElement &elem)
{
    if (!strcmp(elem.Attribute("key"), "WINDOW_MAX_WIDTH"))
        elem.QueryIntAttribute("val", &(this->WINDOW_MAX_WIDTH));
    else if (!strcmp(elem.Attribute("key"), "WINDOW_MAX_HEIGHT"))
        elem.QueryIntAttribute("val", &(this->WINDOW_MAX_HEIGHT));
    else if (!strcmp(elem.Attribute("key"), "WINDOW_BACKGROUND"))
        this->WINDOW_BACKGROUND = elem.Attribute("val");
    else if (!strcmp(elem.Attribute("key"), "HEROSPEED"))
        elem.QueryIntAttribute("val", &(this->HEROSPEED));
    else if (!strcmp(elem.Attribute("key"), "GOOMBASPEED"))
        elem.QueryIntAttribute("val", &(this->GOOMBASPEED));
    else if (!strcmp(elem.Attribute("key"), "HEROLIFE"))
        elem.QueryIntAttribute("val", &(this->HEROLIFE));
    else if (!strcmp(elem.Attribute("key"), "TILE_SIZE"))
        elem.QueryIntAttribute("val", &(this->TILE_SIZE));
    else if (!strcmp(elem.Attribute("key"), "SCROLL_SPEED"))
        elem.QueryIntAttribute("val", &(this->SCROLL_SPEED));
    else
        Log::writeLog("Settings.xml is not correctly formated or has unknown key");
    
//    map<string, string>::const_iterator it = m_map.find(elem.Attribute("key"));
//    
//    if (it != m_map.end())
//    {
//        if (!strcmp(elem.Attribute("type"), "string"))
//        {
//            elem.QueryIntAttribute("val", &((*it).second));
//        }
//        else if (!strcmp(elem.Attribute("type"), "string"))
//        {
//            
//        }
//    }
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
        exit(EXIT_FAILURE);
    }
    
    elem = hdl.FirstChildElement().Element();
    
    while (elem)
    {
        
        parseSetting(*elem);
        elem = elem->NextSiblingElement();
    }
}


#pragma mark Getters

//we do not need const sign they are primitive type
int                 GameSettings::getWINDOW_MAX_WIDTH() { return this->WINDOW_MAX_WIDTH; }
int                 GameSettings::getWINDOW_MAX_HEIGHT() { return this->WINDOW_MAX_HEIGHT; }
const  std::string &GameSettings::getWINDOW_BACKGROUND() { return this->WINDOW_BACKGROUND; }
int                 GameSettings::getHEROSPEED() { return this->HEROSPEED; }
int                 GameSettings::getTILE_SIZE() { return this->TILE_SIZE; }
int                 GameSettings::getSCROLL_SPEED() { return this->SCROLL_SPEED; }