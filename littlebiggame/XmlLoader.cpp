//
//  XmlLoader.cpp
//  littlebiggame
//
//  Created by Guillaume TESSIER on 13/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#include <iostream>
#include "tinyxml.h"
#include "XmlLoader.h"
#include "Log.h"
#include <SDL2/SDL_image.h>

using namespace std;

XmlLoader::XmlLoader()
{
    cout << "XmlLoader constructor" << endl;
    Log::writeLog("XmlLoader constructor");
}

XmlLoader::~XmlLoader()
{
    cout << "XmlLoader destructor" << endl;
    Log::writeLog("XmlLoader destructor");
}

void                XmlLoader::LoadResourceImage(TiXmlElement elem, t_resource &o_resource)
{
    string          tmp_str;
    int             tmp_int;
    TiXmlElement    *subelem;
    
    string          hero = "Hero";
    string          brick = "Brick";
    string          content = "content";
    
    tmp_str = elem.Attribute("type");
    
    if (tmp_str == hero)
        o_resource.type = HERO; 
    else
        o_resource.type = BRICK;
    
    o_resource.name = elem.Attribute("name");
    subelem = elem.FirstChildElement();
    
    if (content == subelem->Value())  
    {
        o_resource.surface = IMG_Load(subelem->Attribute("filepath"));
        subelem->QueryIntAttribute("w", &tmp_int);
        o_resource.size_w = tmp_int;
        subelem->QueryIntAttribute("h", &tmp_int);
        o_resource.size_h = tmp_int;
    }
}

list<t_resource>    XmlLoader::LoadResources(string path)
{
    t_resource          o_resource;
    TiXmlDocument       resource_xml(path.c_str());
    TiXmlHandle         hdl(&resource_xml);
    TiXmlElement        *elem;
    string              image = "image";
    
    if(!resource_xml.LoadFile())
    {
        cerr << "TinyXML: loading error" << endl;
        cerr << "error #" << resource_xml.ErrorId() << " : " << resource_xml.ErrorDesc() << endl;
        Log::writeLog("TinyXml : loading error :");
        return 1;
    }
    
    elem = hdl.FirstChildElement().Element();
    
    while (elem)
    {
        if (image == elem->Value())
        {
            LoadResourceImage(*elem, o_resource);
            this->l_resource.push_back(o_resource);
        }
        
        elem = elem->NextSiblingElement(); 
    }
    
    return this->l_resource;
}

// Je laisse ADrawable pk c'est ce qu'on avait dit mais il faudra surement créer une autre interface pour désigner les entités (player, monstres etc.)
list<Entity *>    XmlLoader::LoadSceneContent(string path)
{
    list<Entity *>     scene_content;
    TiXmlDocument doc(path.c_str());
    TiXmlHandle hdl(&doc);
    
    if(!doc.LoadFile()){
        cerr << "TinyXML: loading error" << endl;
        cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
        Log::writeLog("TinyXml : loading error :");
        return 1;
    }
    
    // Même principe que pour les ressources
    
    return scene_content;
}