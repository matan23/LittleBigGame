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

using namespace std;

XmlLoader::XmlLoader()
{
    cout << "XmlLoader constructor" << endl;
}

XmlLoader::~XmlLoader()
{
    cout << "XmlLoader destructor" << endl;
}

//Public API
list<t_resource>    XmlLoader::LoadResources(string path)
{
    t_resource          resource;
    list<t_resource>    resources;
    TiXmlDocument       doc(path.c_str());
    TiXmlHandle         hdl(&doc);
    TiXmlElement        *elem;
    TiXmlElement        *sub_elem;
    t_pos               position;
    string              filepath;
    
    if(!doc.LoadFile()){
        cerr << "TinyXML: loading error" << endl;
        cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
        return 1;
    }
    
    elem = hdl.FirstChildElement().FirstChildElement().Element();
    
    // Note : il va falloir standardiser les fichiers xml ou séparer les images des fonts
    // pour pouvoir généraliser le traitement avec une boucle du genre :
    
    // On boucle sur les ressources
    while (elem){
        sub_elem = elem->FirstChildElement();
        // On parcourt les composants de la ressource
        while (sub_elem){
            // GetText() pour choper le contenu entre les balises ouvrante/fermante
            resource.id = atoi(sub_elem->GetText());
            sub_elem = sub_elem->NextSiblingElement();

            filepath = sub_elem->GetText();
            sub_elem = sub_elem->NextSiblingElement();
            
            // QueryUnisgnedAttribute pour choper un attribut de type unsigned int
            sub_elem->QueryUnsignedAttribute("x", &position.x);
            sub_elem->QueryUnsignedAttribute("y", &position.y);
            
            // Générer l'image à partir du path de la sprite et de la position
            // resource.content = new Image(filepath, position);
            
            // ajouter ici les autres éléments du xml que nous serons amenés à utiliser
            
            sub_elem = sub_elem->NextSiblingElement();
        }
        
        resources.push_back(resource);
        elem = elem->NextSiblingElement();
    }

    return resources;
}

// Je laisse ADrawable pk c'est ce qu'on avait dit mais il faudra surement créer une autre interface pour désigner les entités (player, monstres etc.)
list<ADrawable>    XmlLoader::LoadSceneContent(string path)
{
    list<ADrawable>     scene_content;
    TiXmlDocument doc(path.c_str());
    TiXmlHandle hdl(&doc);
    TiXmlElement *elem;
    
    if(!doc.LoadFile()){
        cerr << "TinyXML: loading error" << endl;
        cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
        return 1;
    }
    
    // Même principe que pour les ressources
    
    return scene_content;
}

