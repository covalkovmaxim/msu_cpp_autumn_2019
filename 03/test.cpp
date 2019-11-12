#include "Matrix.hpp"
#include <iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
int main()
{
    try{
        const size_t rows = 5;
        const size_t cols = 3;
        Matrix m(rows,cols);

        assert(m.getRows() == 5);
        assert(m.getColumns() == 3);
        cout << "1st test is OK" << endl;

        m+=5;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                assert(m[i][j]==5);
            }
        }
        cout << "2nd test is OK" <<endl;
        try
        {
            int r=m[2][7];
        }
       catch(const std::exception & e)
        {
            if(string("out of range")==e.what())
            {
                cout << "3nd test is OK" << endl;
            }
            else
            {
                 cout << "3nd test is Wrong" << endl;
            }
        }
        try
        {
            int r=m[7][2];
        }
        catch(const std::exception & e)
        {
            if(string("out of range")==e.what())
            {
                cout << "4th test is OK" << endl;
            }
            else
            {
                 cout << "4th test is Wrong" << endl;
            }
        }
        Matrix m1=m;
        assert(m==m1);
        cout << "5th test is OK" << endl;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                m[i][j]=i*cols+j;
                assert(m[i][j]==i*cols+j);
            }
        }
        cout << "6th test is OK" <<endl;
        assert(m!=m1);
        cout << "7th test is OK" <<endl;

    }
    catch(const std::exception & e)
    {
        cout << e.what() << endl;

    }

    return 0;
}
