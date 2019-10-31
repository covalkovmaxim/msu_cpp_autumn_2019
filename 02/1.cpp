#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "lib.hpp"
using namespace std;
int main(int argc,char**argv)
{
    if(argc<3)
    {
        printf("Empty input");
        return -1;
    }
    int maxSiz;
    size_t siz;
    if((maxSiz=atoi(argv[1]))<=0)
    {
        printf("Invalid input");
        return -1;
    }
    LinearAllocator aloc(maxSiz);
    for(int i=2;i<argc;i++)
    {
        if((siz=atoi(argv[i]))<=0)
        {
            printf("Invalid input");
            return -1;
        }

        if((int)siz<0)
        {
            aloc.reset();
        }
        else
        {
            char* mas=aloc.alloc(siz);
            if(mas==nullptr)
            {
                printf("nullptr ");
            }
            else
            {
                printf("%d ",(int) siz);
            }
        }
    }


    return 0;
}
