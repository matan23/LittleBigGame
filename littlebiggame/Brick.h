//
//  Brick.h
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef littlebiggame_Brick_h
#define littlebiggame_Brick_h

# include "Entity.h"

class Brick : public Entity
{
public:
    Brick(const t_resource *rsrc);
    ~Brick();
    Entity *Clone() const;
    
    void    update();
};

#endif
