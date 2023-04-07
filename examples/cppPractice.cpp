//
// Created by leno on 3/30/23.
//
#include <iostream>
#include "utilz/io/fileReaders.h"
using namespace std;

int main(){
    const char* buffer = readFile("/home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/resources/shaders/basic/basicShader.vert");
    std::cout<<buffer<<std::endl;

    readFile("afkdlfkdlf");
    std::cout<<buffer<<std::endl;

    return 0;
}