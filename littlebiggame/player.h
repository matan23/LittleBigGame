//
//  Player.h
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef littlebiggame_Player_h
# define littlebiggame_Player_h

# include "Entity.h"

class Player : public Entity
{
public:
    Player(const t_resource *rsrc);
    ~Player();
    Entity *Clone() const;
    
    void    update();
};

#endif
