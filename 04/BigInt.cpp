#include"BigInt.hpp"
BigInt operator+(const int left, const BigInt & right)
{
    return right+left;
}
BigInt operator+(const char* left, const BigInt & right)
{
    return right+left;
}
BigInt operator-(const int left, const BigInt & right)
{
    return -(right-left);
}
BigInt operator-(const char* left, const BigInt & right)
{
    return -(right-left);
}

BigInt::BigInt(int num)
{
    if(num==0)
    {
        negative=false;
        len=1;
        array=new int [len];
        array[0]=0;
    }
    else
    {
        negative=num<0?true:false;
        int maxsiz=int(log(fabs(num))/log(10))+2;
        array=new int [maxsiz];
        for(int i=0;i<maxsiz;i++)
        {
            array[i]=0;
        }
        len=0;
        num=fabs(num);
        while(num>0)
        {
            array[len]=num%10;
            len++;
            num/=10;
        }
    }
}
BigInt::BigInt(bool neg,int n,int*ar)
{
    negative=neg;
    len=n;
    array=new int[len];
    for(int i=0;i<len;i++)
    {
        array[i]=ar[i];
    }
}
BigInt::BigInt(const char* s)
{
    if(s[0]=='0')
    {
        negative=false;
        len=1;
        array=new int [len];
        array[0]=0;
    }
    else
    {
        negative=s[0]=='-'?true:false;
        len=strlen(s);
        int start=0;
        if(s[0]=='-')
        {
            start=1;
            len--;
        }
        int oldlen=strlen(s);
        array=new int [len];
        for(int i=start;i<oldlen;i++)
        {
            array[i-start]=int(s[oldlen-(i-start+1)])-int('0');
        }
    }
}
BigInt::BigInt(const BigInt& InitBigInt)
{

    negative=InitBigInt.negative;
    len=InitBigInt.len;
    array=new int[len];
    for(int i=0;i<len;i++)
    {
        array[i]=InitBigInt.array[i];
    }

}
/*BigInt::BigInt(BigInt& InitBigInt)
{
    std::cout << "nonconst\n";
    negative=InitBigInt.negative;
    len=InitBigInt.len;
    array=new int[len];
    for(int i=0;i<len;i++)
    {
        array[i]=InitBigInt.array[i];
    }

}
*/
BigInt BigInt:: operator-() const
{
    BigInt cur(*this);
    if(cur!=0)
    {
        cur.negative=!cur.negative;
    }
    return cur;
}
BigInt& BigInt::operator=(const BigInt& copied)
{
    if (this == &copied)
    {
        return *this;
    }
    int* ptr = new int[copied.len];
    delete[] array;
    array = ptr;
    len = copied.len;
    negative=copied.negative;
    for(int i=0;i<len;i++)
    {
        array[i]=copied.array[i];
    }
    return *this;
}
BigInt& BigInt::operator=(const int copied)
{
    BigInt cur(copied);
    if (this == &cur)
    {
        return *this;
    }
    int* ptr = new int[cur.len];
    delete[] array;
    array = ptr;
    len = cur.len;
    negative=cur.negative;
    for(int i=0;i<len;i++)
    {
        array[i]=cur.array[i];
    }
    return *this;
}

bool BigInt::operator>(const BigInt& RigthPart) const
{
    if(!negative&&!RigthPart.negative)
    {
        if(len>RigthPart.len)
        {
            return true;
        }
        if(len<RigthPart.len)
        {
            return false;
        }
        for(int i=len-1;i>=0;i--)
        {
            if(array[i]>RigthPart.array[i])
            {
                return true;
            }
            if(array[i]<RigthPart.array[i])
            {
                return false;
            }
        }
        return false;
    }
    if(!negative&&RigthPart.negative)
    {
        return true;
    }
    if(negative&&!RigthPart.negative)
    {
        return false;
    }
    return !(-*this>-RigthPart);
}
bool BigInt::operator>(const int & RightPart) const
{
    BigInt cur(RightPart);

    return *this>cur;
}

bool BigInt::operator==(const BigInt& RightPart) const
{
    if(negative!=RightPart.negative||len!=RightPart.len)
    {
        return false;
    }
    for(int i=0;i<len;i++)
    {
        if(array[i]!=RightPart.array[i])
        {
            return false;
        }
    }
    return true;
}
bool BigInt::operator==(const int & RightPart) const
{
    BigInt cur(RightPart);
    return *this==cur;
}

bool BigInt::operator!=(const BigInt& RightPart) const
{
    return !(*this==RightPart);
}
bool BigInt::operator!=(const int & RightPart) const
{
    return !(*this==RightPart);
}

bool BigInt::operator<(const BigInt& RightPart) const
{
    return !((*this>RightPart)||(*this==RightPart));
}
bool BigInt::operator<(const int & RightPart) const
{
     return !((*this>RightPart)||(*this==RightPart));
}

bool BigInt::operator<=(const BigInt& RigthPart) const
{
     return !(*this>RigthPart);
}
bool BigInt::operator<=(const int & RightPart) const
{
    return !(*this>RightPart);
}

bool BigInt::operator>=(const BigInt& RightPart) const
{
    return (*this>RightPart)||(*this==RightPart);
}
bool BigInt::operator>=(const int & RightPart) const
{
    return (*this>RightPart)||(*this==RightPart);
}


BigInt BigInt::operator+(const BigInt& RightPart) const
{
    if(!negative&&!RightPart.negative)
    {
        int maxlen=len>RightPart.len?len:RightPart.len;
        int *result=new int[maxlen+1];
        for(int i=0;i<maxlen+1;i++)
        {
            result[i]=0;
        }
        int ost=0;
        for(int i=0;i<maxlen;i++)
        {
            if(i<len && i<RightPart.len)
            {
                result[i]=(array[i]+RightPart.array[i]+ost)%10;
                ost=(array[i]+RightPart.array[i]+ost)/10;
            }
            if(i>=len && i<RightPart.len)
            {
                result[i]=(RightPart.array[i]+ost)%10;
                ost=(RightPart.array[i]+ost)/10;
            }
            if(i<len && i>=RightPart.len)
            {
                result[i]=(array[i]+ost)%10;
                ost=(array[i]+ost)/10;
            }
        }
        result[maxlen]=ost;
        const BigInt res(false,result[maxlen]>0?maxlen+1:maxlen,result);
        delete[]result;
        return res;
    }
    if(!negative&&RightPart.negative)
    {
        return (*this)-(-RightPart);
    }
    if(negative&&!RightPart.negative)
    {
        return RightPart-(-*this);
    }
    if(negative&&RightPart.negative)
    {
        return -(-*this+-RightPart);
    }


}
/*BigInt BigInt::operator+(const int & RightPart) const
{

}*/

BigInt BigInt::operator-(const BigInt& RightPart) const
{
    if(!negative&&!RightPart.negative)
    {
        if(*this<RightPart)
        {
            return -(RightPart-(*this));
        }
        int maxlen=len>RightPart.len?len:RightPart.len;
        int *result=new int[maxlen];
        for(int i=0;i<maxlen;i++)
        {
            result[i]=0;
        }
        int ost=0;
        for(int i=0;i<maxlen;i++)
        {
            if(i<RightPart.len)
            {
                ost=(10+array[i]-RightPart.array[i]+ost);
                result[i]=ost%10;
                ost=ost<10?-1:0;
            }
            if(i>=RightPart.len)
            {
                ost=(10+array[i]+ost);
                result[i]=ost%10;
                ost=ost<10?-1:0;
            }
        }
        while(0==result[maxlen-1])
        {
            maxlen--;
            if(1==maxlen)
            {
                break;
            }
        }
        const BigInt res(false,maxlen,result);
        delete[]result;
        return res;
    }
    if(!negative&&RightPart.negative)
    {
        return *this+(-RightPart);
    }
    if(negative&&!RightPart.negative)
    {
        return -(-*this+RightPart);
    }
    if(negative&&RightPart.negative)
    {
        return -(-*this-(-RightPart));
    }
}
/*BigInt BigInt::operator-(const int & RightPart) const
{

}*/

std::ostream& operator<< (std::ostream &out, const BigInt &big_int)
{
    if(big_int.negative)
    {
        out << '-';
    }
    for(int i=big_int.len-1;i>=0;i--)
    {
        out << big_int.array[i];
    }
    out << std::endl;
}

BigInt::~BigInt()
{
    delete [] array;
}


