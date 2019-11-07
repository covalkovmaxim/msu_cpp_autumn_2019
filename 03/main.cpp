#include"Matrix.hpp"

int main()
{
    Matrix m(5,5);
    m.Print();
    m+=5;
    m.Print();
    Matrix m1=m;

    m1*=2;
    m+=1;
    printf("%d\n",m[1][1]);


    return 0;
}
