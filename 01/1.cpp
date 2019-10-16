#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include<string>
using namespace std;
void del_space(char *s);
void normalize(char*s);
int get_number_by_string(char *s);
int calculate(char* s);
int main(int argc,char*argv[])
{
    char*s=argv[1];

    try
    {
        del_space(s);
        normalize(s);

        cout << calculate(s);
    }
    catch(const char *st)
    {
        cout << st;
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

                throw("Error");
            }
        }

    }
    sprintf(s,"%s",sc);
    delete[]sc;

}
int get_number_by_string(char*s)
{
    int res=0;int key=1;
    for(int i=0;i<strlen(s);i++)
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
int calculate(char*s)
{
    //printf("%s %d\n",s,strlen(s));
    int left,right;
    char*tt;
    char*tt1=new char[strlen(s)];
    if(strlen(s)==0)
    {
        throw("Error");
    }
    if(strchr(s,'+')!=NULL)
    {
        tt=new char[strlen(s)-strlen(strchr(s,'+'))+1];
        tt[strlen(s)-strlen(strchr(s,'+'))]='\0';
        strncpy(tt,s,(int)(strlen(s)-strlen(strchr(s,'+'))));
        left=calculate(tt);
        strcpy(tt1,strchr(s,'+')+1);
        right=calculate(tt1);
        delete[]tt;
        delete[]tt1;
        return left+right;
    }
    if(strchr(s,'*')==NULL&&strchr(s,'/')==NULL)
    {

        return get_number_by_string(s);
    }
    if(strchr(s,'/')==NULL)
    {
        tt=new char[strlen(s)-strlen(strchr(s,'*'))+1];
        tt[strlen(s)-strlen(strchr(s,'*'))]='\0';
        strncpy(tt,s,(int)(strlen(s)-strlen(strchr(s,'*'))));
        left=get_number_by_string(tt);
        strcpy(tt1,strchr(s,'*')+1);
        right=calculate(tt1);
        delete[]tt;
        delete[]tt1;
        return left*right;
    }
    if(strchr(strrchr(s,'/'),'*')!=NULL)
    {
        tt=new char[strlen(s)-strlen(strchr(strrchr(s,'/'),'*'))+1];
        tt[strlen(s)-strlen(strchr(strrchr(s,'/'),'*'))]='\0';
        strncpy(tt,s,(int)(strlen(s)-strlen(strchr(strrchr(s,'/'),'*'))));
        left=calculate(tt);
        strcpy(tt1,strchr(strrchr(s,'/'),'*')+1);
        right=calculate(tt1);
        delete[]tt;
        delete[]tt1;
        return left*right;
    }
    tt=new char[strlen(s)-strlen(strrchr(s,'/'))+1];
    tt[strlen(s)-strlen(strrchr(s,'/'))]='\0';
    strncpy(tt,s,(int)(strlen(s)-strlen(strrchr(s,'/'))));
    //printf("it:%s eee %d %d\n",s,(int)strlen(s),(int)strlen(strrchr(s,'/')));
    left=calculate(tt);
    strcpy(tt1,strrchr(s,'/')+1);
    right=get_number_by_string(tt1);
    delete[]tt;
    delete[]tt1;
    if(right==0)
    {
        throw("Error");
    }
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






