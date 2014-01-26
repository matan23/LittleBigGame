//
//  Log.cpp
//  littlebiggame
//
//  Created by Damien Rebelo on 26/01/2014.
//  Copyright (c) 2014 mataejoon. All rights reserved.
//

#include <fstream>
#include<ctime>

#include "Log.h"

void Log::writeLog(const std::string &text) {
    FILE *fp;
    fp = fopen("log_file.log", "rbw+");
    if (fp == NULL) {
        exit(1);
    }
    
    std::time_t time = std::time(0);
    std::ofstream log_file("log_file.log", std::ios_base::out | std::ios_base::app );
    log_file << "[" << time << "] Log file: " << text << std::endl;
    fclose(fp);
}