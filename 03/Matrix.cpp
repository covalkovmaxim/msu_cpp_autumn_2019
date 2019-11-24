#include"Matrix.hpp"

MatrixRow::MatrixRow(const size_t ColsNumber)
{
    cols=ColsNumber;
    row=new int[cols];
    for(int i=0;i<cols;i++)
    {
        row[i]=0;
    }
}
MatrixRow::MatrixRow(const MatrixRow& InitRow)
{

    cols=InitRow.cols;

    row=new int[cols];
    for(int i=0;i<cols;i++)
    {
        row[i]=InitRow.row[i];
    }
}
MatrixRow& MatrixRow:: operator *= (int val)
{
    for(int i=0;i<cols;i++)
    {
        row[i]*=val;
    }
    return *this;
}
MatrixRow& MatrixRow:: operator += (int val)
{
    for(int i=0;i<cols;i++)
    {
        row[i]+=val;
    }
    return *this;
}
bool MatrixRow::operator == (const MatrixRow& m) const
{
    if(cols!=m.cols)
    {
        return false;
    }
    for(int i=0;i<cols;i++)
    {
        if(row[i]!=m.row[i])
        {
            return false;
        }
    }
    return true;
}
bool MatrixRow::operator != (const MatrixRow& m) const
{
    return !(*this==m);
}
int& MatrixRow::operator[](const int index)
{
    if(index>=cols)
    {
        throw std::out_of_range("out of range");
    }
    return row[index];

}
int MatrixRow::operator[](const int index) const
{
    if(index>=cols)
    {
        throw std::out_of_range("out of range");
    }
    return row[index];
}
int MatrixRow::getColumns()
{
    return cols;
}
MatrixRow::~MatrixRow()
{
    delete [] row;
}
void MatrixRow::print()
{

    for(int i=0;i<cols;i++)
    {
        printf("%d ",row[i]);
    }

}
Matrix::Matrix(const size_t RowsNumber,const size_t ColsNumber)
{
    cols=ColsNumber;
    rows=RowsNumber;
    data=new MatrixRow*[rows];
    for(int i=0;i<rows;i++)
    {
        data[i]=new MatrixRow(cols);
    }
}
Matrix::Matrix(const Matrix& InitMatrix)
{

    cols=InitMatrix.cols;
    rows=InitMatrix.rows;
    data=new MatrixRow*[rows];
    for(int i=0;i<rows;i++)
    {
        data[i]=new MatrixRow(*InitMatrix.data[i]);
    }
}

Matrix& Matrix::operator  *= (int val)
{
    for(int i=0;i<rows;i++)
    {
        *data[i]*=val;
    }
    return *this;
}
Matrix& Matrix::operator += (int val)
{
    for(int i=0;i<rows;i++)
    {
        *data[i]+=val;
    }
    return *this;
}
bool Matrix::operator == (const Matrix& m) const
{
    if(cols!=m.cols||rows!=m.rows)
    {
        return false;
    }
    for(int i=0;i<rows;i++)
    {
        if(*data[i]!=*m.data[i])
        {
            return false;
        }
    }
    return true;
}
bool Matrix:: operator != (const Matrix& m) const
{
    return !(*this==m);
}
MatrixRow& Matrix:: operator [] (const int index)
{
    if(index>=rows)
    {
        throw std::out_of_range("out of range");
    }
    return *data[index];
}
const MatrixRow& Matrix:: operator [] (const int index) const
{
    if(index>=rows)
    {
        throw std::out_of_range("out of range");
    }
    return *data[index];
}
int Matrix:: getColumns()
{
    return cols;
}
int Matrix:: getRows()
{
    return rows;
}
void Matrix::print()
{
    printf("\n");
    for(int i=0;i<rows;i++)
    {
        data[i]->print();
        printf("\n");
    }
}

Matrix::~Matrix()
{
    for(int i=0;i<rows;i++)
    {
        delete data[i];
    }
    delete[]data;
}
