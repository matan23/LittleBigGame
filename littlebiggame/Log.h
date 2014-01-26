//
//  Log.h
//  littlebiggame
//
//  Created by Damien Rebelo on 26/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#ifndef __littlebiggame__Log__
#define __littlebiggame__Log__

#include <iostream>

// The factory
class Log
{

public:
static void    writeLog(const std::string &text);
};

#endif /* defined(__littlebiggame__Log__) */
