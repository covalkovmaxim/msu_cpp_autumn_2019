#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
class Matrix;
class ProcsiMatrix
{
  private:

    int*position;

  public:
    friend class Matrix;
    ProcsiMatrix(int* pos)
    {
        position=pos;
    }
    int& operator[](const int val)
    {
        return position[val];
    }
};
class Matrix
{
    public:

    friend class ProcsiMatrix;

    private:

        int cols,rows;
        int* data;


    public:


        Matrix(Matrix & InitMatrix);
        Matrix(int row,int col);


        int getColumns() const;
        int getRows() const;

        Matrix& operator *= (int val);
        Matrix& operator += (int val);

        bool operator == (const Matrix& m) const;
        bool operator != (const Matrix& m) const;

        ProcsiMatrix& operator[](const int val);

        void Print();
        ~Matrix();

};

