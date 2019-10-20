#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include<string>

using namespace std;

void del_space(char *s);
void normalize(char*s);
int get_number_by_string(string s);
int calculate(string s);
string get_left_substring(string s, int pos);
string get_right_substring(string s, int pos);
int main(int argc,char*argv[])
{
    char*s=argv[1];

    try
    {
        del_space(s);
        normalize(s);
        string str(s);
        cout<<calculate(str);

    }
    catch(const exception& ex)
    {
        cout << ex.what();
        return -1;
    }

    return 0;
}

void del_space(char*s)
{
    char*sc;
    int len=strlen(s);
    sc=new char[len];
    for(int i=0;i<len;i++)
    {
        if(s[i]!=' ')
        {
            sprintf(sc+strlen(sc),"%c",s[i]);
            if(s[i]!='+'&&s[i]!='-'&&s[i]!='/'&&s[i]!='*'&&(s[i]>'9'||s[i]<'0'))
            {
               throw(runtime_error("invalid input"));
            }
        }
    }
    sprintf(s,"%s",sc);
    delete[]sc;
}
int get_number_by_string(string s)
{
    int res=0;int key=1;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='-')
        {
            key*=-1;
            continue;
        }
        if(s[i]=='+')
        {
            continue;
        }
        if(s[i]>='0'&&s[i]<='9')
        {
            res=res*10+s[i]-(int)'0';
        }
    }
    //printf("res=%d\n",key*res);
    return key*res;
}
int calculate(string s)
{
    //printf("%s %d\n",s,strlen(s));
    //cout << s <<"result=";
    int left,right;

    if(s.size()==0)
    {
        throw(runtime_error("invalid input"));
        return 0;
    }
    if(s.find('+')!=string::npos)
    {
        left=calculate(get_left_substring(s,s.find('+')));
        right=calculate(get_right_substring(s,s.find('+')));
        //cout <<s <<"res="<< left+right << endl;
        return left+right;
    }
    if(s.find('*')==string::npos&&s.find('/')==string::npos)
    {
//        cout << s<< "res="<< get_number_by_string(s) << endl;
        return get_number_by_string(s);
    }
    if(s.find('/')==string::npos)
    {
        left=calculate(get_left_substring(s,s.find('*')));
        right=calculate(get_right_substring(s,s.find('*')));
      //  cout <<s<<"res="<< left*right << endl;
        return left*right;
    }
    if(get_right_substring(s,s.rfind('/')).find('*')!=string::npos)
    {
        string sr=get_right_substring(s,s.rfind('/'));
        left=calculate(get_left_substring(s,s.rfind('/')+sr.find('*')+1));
        right=calculate(get_right_substring(sr,sr.find('*')));
    //    cout <<s<<"res="<< left*right << endl;
        return left*right;
    }
    left=calculate(get_left_substring(s,s.rfind('/')));
    right=calculate(get_right_substring(s,s.rfind('/')));
    if(right==0)
    {
        throw(runtime_error("division by zero"));
    }
  //  cout<< s<<"res="<<left/right << endl;
    return left/right;
}
void normalize(char*s)
{
    char*sc;
    int len=strlen(s);
    sc=new char[len];
    sprintf(sc+strlen(sc),"%c",s[0]);
    for(int i=1;i<len;i++)
    {
        if(s[i]=='+'&&(s[i-1]>'9'||s[i-1]<'0'))
        {
            continue;
        }
        if(s[i]=='-'&&s[i-1]<='9'&&s[i-1]>='0')
        {
            sprintf(sc+strlen(sc),"+-");
            continue;
        }
        sprintf(sc+strlen(sc),"%c",s[i]);
    }
    sprintf(s,"%s",sc);
    delete[]sc;
}

string get_left_substring(string s, int pos)
{
    return s.substr(0,pos);
}

string get_right_substring(string s, int pos)
{
    return s.substr(pos+1, s.size()-pos-1);
}



