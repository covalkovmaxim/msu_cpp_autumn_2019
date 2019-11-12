#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<assert.h>
#include<string>
#include<string.h>

class MatrixRow
{
    int cols;
    int* row;

    public:

    MatrixRow(int ColsNumber);
    MatrixRow(MatrixRow& InitRow);

    MatrixRow& operator *= (int val);
    MatrixRow& operator += (int val);

    bool operator == (const MatrixRow& m) const;
    bool operator != (const MatrixRow& m) const;

    int& operator[](const int index);
    int operator[](const int index) const;

    int getColumns();
    void print();

    ~MatrixRow();

};
class Matrix
{
    int cols,rows;
    MatrixRow ** data;

    public:

    Matrix(int RowsNumber,int ColsNumber);
    Matrix(Matrix& InitMatrix);

    Matrix& operator *= (int val);
    Matrix& operator += (int val);

    bool operator == (const Matrix& m) const;
    bool operator != (const Matrix& m) const;

    MatrixRow& operator [] (const int index);
    MatrixRow operator [] (const int index) const;

    int getColumns();
    int getRows();
    void print();

    ~Matrix();
};

