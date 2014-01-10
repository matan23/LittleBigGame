//
//  drawable.h
//  littlebiggame
//
//  Created by mataejoon on 11/15/13.
//  Copyright (c) 2013 mataejoon. All rights reserved.
//

#ifndef littlebiggame_drawable_h
#define littlebiggame_drawable_h

#include <SDL2/SDL.h>

typedef struct  s_pos
{
    int         x;
    int         y;
}               t_pos;

class ADrawable
{
public:
    virtual ~ADrawable() {}

private:
    SDL_Surface *image;
    t_pos       position;
};

#endif
