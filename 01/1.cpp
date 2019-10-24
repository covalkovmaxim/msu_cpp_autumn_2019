#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include<string>

using namespace std;

string del_space(char *s);
string normalize(string &s);
int get_number_by_string(string & s);
int calculate(string const&s1);
string get_left_substring(string &s, int pos);
string get_right_substring(string &s, int pos);
int main(int argc,char*argv[])
{
    char*s=argv[1];

    try
    {
        string without_space=del_space(s);
        string normalize_string=normalize(without_space);
        string str(normalize_string);
        cout<<calculate(normalize_string);

    }
    catch(const exception& ex)
    {
        cout << ex.what();
        return -1;
    }

    return 0;
}

string del_space(char*s)
{
    string new_string="";
    int len=strlen(s);

    for(int i=0;i<len;i++)
    {
        if(s[i]!=' ')
        {
            new_string+=s[i];
            if(s[i]!='+'&&s[i]!='-'&&s[i]!='/'&&s[i]!='*'&&(s[i]>'9'||s[i]<'0'))
            {
               throw(runtime_error("invalid input"));
            }
        }
    }

    return new_string;
}
int get_number_by_string(string& s)
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
int calculate(string const&s1)
{
    //printf("%s %d\n",s,strlen(s));
    //cout << s <<"result=";
    string s(s1);
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
string normalize(string& s)
{
    string new_string="";
    int len=s.size();
    if(len>=1)
    {
        new_string+=s[0];
    }
    else
    {
        throw(runtime_error("empty input"));
    }

    for(int i=1;i<len;i++)
    {
        if(s[i]=='+'&&(s[i-1]>'9'||s[i-1]<'0'))
        {
            continue;
        }
        if(s[i]=='-'&&s[i-1]<='9'&&s[i-1]>='0')
        {
            new_string+="+-";

            continue;
        }
        new_string+=s[i];

    }
    return new_string;
}

string get_left_substring(string &s, int pos)
{
    return s.substr(0,pos);
}

string  get_right_substring(string &s, int pos)
{
    return s.substr(pos+1, s.size()-pos-1);
}



