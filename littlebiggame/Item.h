//
//  Item.h
//  littlebiggame
//
//  Created by mataejoon on 1/26/14.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef littlebiggame_Item_h
#define littlebiggame_Item_h

typedef struct          s_item
{
    int                 type;
    int                 startX;
    int                 startY;
    int                 maxX;
    int                 maxY;
    unsigned int        x;
    unsigned int        y;
}                       t_item;

#endif
