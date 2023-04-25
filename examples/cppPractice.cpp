//
// Created by leno on 3/30/23.
//
#include <iostream>
#include "utilz/io/fileReaders.h"
using namespace std;

struct test{
    int a;
    int b;
    int c;
};


struct B{
    int a;
    test t[5];
};



void testSizeOfArray(){
    float positions[8]={
            1,2,3,4,5,6,7,8
    };
    std::cout<<sizeof(short)<<std::endl;

}

void function(void* dest){
    test a{.a=1,.b=2,.c=34};
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


void kl(){
    std::cout<<sizeof(B)<<std::endl;
}

int main(){
    kl();
    return 0;
}