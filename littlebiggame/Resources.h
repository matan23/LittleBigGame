//
//  Resources.h
//  littlebiggame
//
//  Created by Jero Jeyen on 26/01/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef littlebiggame_Resources_h
#define littlebiggame_Resources_h

# include <string>
# include <SDL2/SDL_image.h>

using namespace std;

typedef struct  s_resource
{
    int         type;
    string      name;
    SDL_Surface *surface;
    int         size_w;
    int         size_h;
    int         onGround;
	int         thinkTime;
	float       dirX, dirY;
}               t_resource;

#endif
