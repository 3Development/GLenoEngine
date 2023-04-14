//
// Created by leno on 3/31/23.
//
#include "utilz/io/fileReaders.h"

using namespace std;

/**
 * basic read file and adding to one string
 * this function will also at the end of the buffer add \0 terminator
 * @param path
 * @param buffer buffer that will be filled with path
 * @return
 */
int readFile(const char* path,char* buffer){
    string line;
    ifstream file(path);

    if(file.is_open()){
        int position = 0;
        while(getline(file,line)){
            if(line.length() > 0){
                memcpy(buffer+position,line.append("\n").c_str(),sizeof(char) * (line.length()+1));
                position =position + ( sizeof(char) * (line.length()));
            }
        }
        memcpy(buffer+position,"\0",sizeof(char));
        return 1;
    }
    return -1;
}

/**
 * Returns file size in bytes
 * @param path
 * @return
 */
int getSizeOfFile(const char* path){
    string line;
    ifstream file(path);
    int size = 0;
    while(getline(file,line)){
        size+=line.length()+1;
    }
    return size+1;
}