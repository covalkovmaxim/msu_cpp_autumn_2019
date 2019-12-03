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

std::string PutArguments(const std::string& TemplateString,const std::vector<std::string> & ListOfString);

template<class... Args >
std::string format(const std::string& TemplateString, Args&& ...ListOfArguments)
{
    std::vector<std::string> ResultVectorOfArguments;
    GetArguments(ResultVectorOfArguments,std::forward<Args>(ListOfArguments)...);
    std::string ResultString;
    ResultString=PutArguments(TemplateString,ResultVectorOfArguments);
    return ResultString;
}

