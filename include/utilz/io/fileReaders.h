//
// Created by leno on 3/31/23.
//

#ifndef LENOENGINE_FILEREADERS_H
#define LENOENGINE_FILEREADERS_H
#include <iostream>
#include <fstream>
#include <string.h>

int readFile(const char* path,char* buffer);
int getSizeOfFile(const char* path);

#endif //LENOENGINE_FILEREADERS_H
