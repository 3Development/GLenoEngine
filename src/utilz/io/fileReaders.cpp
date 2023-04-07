//
// Created by leno on 3/31/23.
//
#include "utilz/io/fileReaders.h"

using namespace std;

/**
 * basic read file and adding to one string
 *
 * @param path
 * @return
 */
const char* readFile(const char* path){
    string line;
    ifstream file(path);

    if(file.is_open()){
        int fileSize = file.tellg();
        char* buffer =(char*) alloca(1024);
        int position = 0;
        while(getline(file,line)){
            memcpy(buffer + position,line.c_str(),sizeof(char) * line.length());
            position =position + ( sizeof(char) * line.length());
        }
        std::cout<< buffer<<std::endl;
        return buffer;
    }
    return nullptr;
}