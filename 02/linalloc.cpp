#include "lib.hpp"



LinearAllocator::LinearAllocator(size_t maxSize)
{
    pos=0;
    maxSiz=maxSize;
    buf=new char[maxSiz];

}
LinearAllocator::~LinearAllocator()
{
    if(buf!=nullptr)
    {
        delete [] buf;
    }
}
char* LinearAllocator::alloc(size_t size)
{
    if(pos+size>maxSiz)
    {
        pos=maxSiz+1;
        return nullptr;
    }
    char* new_segment=buf+pos;
    pos+=size;
    return new_segment;
}
void LinearAllocator ::reset()
{
   pos=0;
   memset(buf,0,maxSiz*sizeof(char));
}
