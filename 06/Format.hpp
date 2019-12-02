#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cassert>
#include<string.h>
#include<string>
#include<vector>
#include <sstream>
#include <stdexcept>
//#include<regex>

template<class Arg>
void GetArguments(std::vector<std::string>& FinishArguments, Arg&& arg)
{
    std::ostringstream st;
    st << std::forward<Arg>(arg);
    if(!st)
    {
        throw std::runtime_error("Error in input data");
    }
    FinishArguments.push_back(st.str());
}

template<class Arg, class ... Args>
void GetArguments(std::vector<std::string>& FinishArguments, Arg&& arg,Args&& ... args)
{
    GetArguments(FinishArguments, std::forward<Arg>(arg));
    GetArguments(FinishArguments,std::forward<Args>(args)...);

}

std::string PutArguments(const std::string& TemplateString,const std::vector<std::string> & ListOfString)
{
    std::string result="";
    int len=TemplateString.size();
    int i=0,j=0;
    int argument_num;
    while(i<len)
    {
        j=0;
        if(TemplateString[i]=='}')
        {
             throw std::runtime_error("Start with closing bracket");
        }
        if(TemplateString[i]=='{')
        {
            j=1;
            while(true)
            {
                if(i+j==len)
                {
                     throw std::runtime_error("Closing bracket don't exist");
                }
                if(TemplateString[i+j]=='{')
                {
                     throw std::runtime_error("Two opening bracket in a row");
                }
                if(TemplateString[i+j]=='}')
                {
                    try
                    {
                        argument_num=stoi(TemplateString.substr(i+1,j-1));
                    }
                    catch(const std::exception & e)
                    {
                        throw std::runtime_error("Data between brackets isn't integer");
                    }

                    if(argument_num>=ListOfString.size()||argument_num<0)
                    {
                         throw std::runtime_error("Index larger than number of arguments or less than zero");
                    }
                    result+=ListOfString[argument_num];
                    break;
                }
                j++;
            }
        i+=j;
        }
        else
        {
            result+=TemplateString[i];
        }
        i++;
    }
    return result;

}

template<class... Args >
std::string format(const std::string& TemplateString, Args&& ...ListOfArguments)
{
    std::vector<std::string> ResultVectorOfArguments;
    GetArguments(ResultVectorOfArguments,std::forward<Args>(ListOfArguments)...);
    std::string ResultString;
    ResultString=PutArguments(TemplateString,ResultVectorOfArguments);
    return ResultString;
}

