//
//  Events.h
//  littlebiggame
//
//  Created by Damien Rebelo on 26/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef __littlebiggame__Events__
#define __littlebiggame__Events__

#include <iostream>
#include "SceneController.h"

class Events
{
public:
    void getEvents(SceneController *oScene);
    
private:
    SDL_Event           _event;
};
#endif /* defined(__littlebiggame__Events__) */
