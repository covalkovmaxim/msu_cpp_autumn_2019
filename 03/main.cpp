#include"Matrix.hpp"
using namespace std;
int main()
{
    try
    {
        MatrixRow m(5);
        m.print();
        m+=5;
        m.print();
        MatrixRow m1=m;

        m1*=2;
        m+=1;
        printf("%d\n",m[1]);
        m[2]=7;
        m.print();

        Matrix mat(5,5);
        mat+=1;
        Matrix mat2(5,5);
        mat2+=1;
        mat.print();
        Matrix mat1=mat;
        mat1*=7;
        mat1.print();
        mat.print();
        printf("\n%d   %d\n",int(mat!=mat2),int(mat!=mat1));
        mat[1][3]=10;
        mat.print();
    }
    catch(const std::exception & e)
    {
        cout << e.what() << endl;

    }
    return 0;
}

