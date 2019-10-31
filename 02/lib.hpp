#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include <stddef.h>
using namespace std;
class LinearAllocator
{
    char* buf;
    size_t pos;
    size_t maxSiz;
    public:
        LinearAllocator(size_t maxSize);
        ~LinearAllocator();
        char* alloc(size_t size);
        void reset();
};
