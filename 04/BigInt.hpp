#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<math.h>

class BigInt
{
    private:
        bool negative;
        int len;
        int* array;

    public:
        BigInt(int num);
        BigInt(const char* s);
        BigInt(const BigInt& InitBigInt);
        BigInt(BigInt& InitBigInt);

        BigInt operator-() const;

        BigInt& operator=(const BigInt& copied);
        BigInt& operator=(const int& copied);

        bool operator>(const BigInt& RightPart) const;
        bool operator>(const int & RightPart) const;

        bool operator==(const BigInt& RightPart) const;
        bool operator==(const int & RightPart) const;

        bool operator!=(const BigInt& RightPart) const;
        bool operator!=(const int & RightPart) const;

        bool operator<(const BigInt& RightPart) const;
        bool operator<(const int & RightPart) const;

        bool operator<=(const BigInt& RightPart) const;
        bool operator<=(const int & RightPart) const;

        bool operator>=(const BigInt& RightPart) const;
        bool operator>=(const int & RightPart) const;

        BigInt operator+(const BigInt& RightPart) const;

        //BigInt operator+(const int & RightPart) const;

        BigInt operator-(const BigInt& RightPart) const;

        //BigInt operator-(const int & RightPart) const;

        friend std::ostream& operator<< (std::ostream &out, const BigInt &big_int);

        ~BigInt();

};
