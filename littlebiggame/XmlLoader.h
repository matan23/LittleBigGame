//
//  XmlLoader.h
//  littlebiggame
//
//  Created by Guillaume TESSIER on 13/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef __littlebiggame__XmlLoader__
#define __littlebiggame__XmlLoader__

#include <iostream>
#include <list>
#include "DrawableFactory.h"
#include "tinyxml.h"
#include "Macro.h"

using namespace std;

typedef struct  s_resource
{
    int         type;
    string      name;
    SDL_Surface *surface;
    
}               t_resource;

class XmlLoader
{
public:
    XmlLoader();
    ~XmlLoader();
    
    list<t_resource>    LoadResources(string path);
    list<ADrawable>     LoadSceneContent(string path);
private:
    t_resource          LoadResourceImage(TiXmlElement elem);
    SDL_Surface         *LoadResourceImageSpriteSurface(TiXmlElement elem);
};

#endif /* defined(__littlebiggame__XmlLoader__) */
