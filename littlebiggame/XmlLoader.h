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
#include "tinyxml.h"
#include "Macro.h"
#include "Resources.h"
#include "Entity.h"

using namespace std;

class XmlLoader
{
public:
    XmlLoader();
    ~XmlLoader();
    
    list<t_resource>    LoadResources(string path);
    list<Entity *>      LoadSceneContent(string path);
private:
    void                LoadResourceImage(TiXmlElement elem, t_resource &o_resource);
    list<t_resource>    l_resource;
};

#endif /* defined(__littlebiggame__XmlLoader__) */
