//
//  DrawableFactory.cpp
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#include "tinyxml.h"
#include "DrawableFactory.h"

using namespace std;

ADrawable   *DrawableFactory::Produce(const std::string &type)
{
    LoadXml("drawable.xml");
    if (type == "Image")
        return new Image();
    else if (type == "Font")
        return new Font();
    return (NULL);
}


void    DrawableFactory::LoadXml(const std::string name)
{
    TiXmlDocument doc(name.c_str());
    doc.LoadFile();
}

//real types
Image::Image()
{
    //instantie toute la config de l'image (width, height etc etc)
    cout << "Creation of image" << endl;
}

Image::~Image()
{
    cout << "Destruction of image" << endl;
}

Font::Font()
{
    cout << "Creation of font" << endl;
}

Font::~Font()
{
    cout << "Destruction of font" << endl;
}