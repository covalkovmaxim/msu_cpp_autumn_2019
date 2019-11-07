#include"Matrix.hpp"

Matrix:: Matrix(Matrix& InitMatrix)
{
    cols=InitMatrix.cols;
    rows=InitMatrix.rows;
    data=new int[cols*rows];
    for (int i=0;i<cols*rows;i++)
    {
        data[i]=InitMatrix.data[i];
    }
}
Matrix:: Matrix(int row, int col)
{
    cols=col;
    rows=row;
    data=new int[cols*rows];
    for (int i=0;i<cols*rows;i++)
    {
        data[i]=0;
    }

}
Matrix:: ~Matrix()
{
    delete [] data;
}

int Matrix:: getColumns() const
{
    return cols;
}
int Matrix:: getRows() const
{
    return rows;
}
Matrix& Matrix::operator *= (int val)
{
    for(int i=0;i<rows*cols;i++)
    {
        data[i]*=val;
    }
    return *this;
}
Matrix& Matrix::operator += (int val)
{
    for(int i=0;i<rows*cols;i++)
    {
        data[i]+=val;
    }
    return *this;
}
bool Matrix::operator == (const Matrix& m) const
{
    if(cols!=m.cols||rows!=m.rows)
    {
        return false;
    }
    else
    {
        for(int i=0;i<cols*rows;i++)
        {
            if(data[i]!=m.data[i])
            {
                return false;
            }
        }
    }
    return true;
}
bool Matrix:: operator != (const Matrix& m) const
{
    return !(*this==m);
}
void Matrix:: Print()
{
    printf("\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",data[i*cols+j]);
        }
        printf("\n");
    }
}

ProcsiMatrix& Matrix::  operator [](const int val)
{

    return data+cols*val;
}


