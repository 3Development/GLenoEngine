//
// Created by leno on 3/30/23.
//
#include <iostream>
#include "utilz/io/fileReaders.h"
using namespace std;

struct test{
    int a;
    int b;
};


void function(void* dest){
    test a{.a=1,.b=2};
    int sizeOfPointer = 8;



    memcpy(dest,&a,sizeof(a));
}

void testCopy(){
    const char* test = "king";
    int index =0;
    int size= 0;

    void* test1 = alloca(4);

    memcpy(test1,test, 5);


    while(*((char*)test1+index) != '\0'){
        std::cout<<*((char*)test1+index)<<std::endl;
        ++index;
        ++size;
    }

}

int main(){
    void* dest = alloca(1000000);


    function(dest);

    test* a = (test*)dest;

    std::cout<<a->b<<std::endl;
    return 0;
}