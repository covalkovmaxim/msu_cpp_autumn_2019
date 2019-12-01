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


int main()
{
    auto text = format("{1}+{1} = {0}", 2, "one");
    assert(text == "one+one = 2");
    std::cout << "1st test is OK" << std::endl;

    std::string s="{1}+{1} = {0}";
    text=format(s, 2, "one");
    assert(text == "one+one = 2");
    std::cout << "2nd test is OK" << std::endl;

    text=format(s, 2, "one",5,4,"asfsdfsfdf");
    assert(text == "one+one = 2");
    std::cout << "3nd test is OK" << std::endl;


    try
    {
        text = format("}{1}+{1} = {0}", 2, "one");
    }
    catch(const std::exception & e)
    {
        if(std::string("Start with closing bracket")==e.what())
        {
            std::cout << "4th test is OK" <<std::endl;
        }
    }

    try
    {
        text = format("{1}+{1", 2, "one");
    }
    catch(const std::exception & e)
    {
        if(std::string("Closing bracket don't exist")==e.what())
        {
            std::cout << "5th test is OK" <<std::endl;
        }
    }

    try
    {
        text = format("{1{}+{1}={0}", 2, "one");
    }
    catch(const std::exception & e)
    {
        if(std::string("Two opening bracket in a row")==e.what())
        {
            std::cout << "6th test is OK" <<std::endl;
        }
    }

    try
    {
        text = format("{1}+{Test}={0}", 2, "one");
    }
    catch(const std::exception & e)
    {
        if(std::string("Data between brackets isn't integer")==e.what())
        {
            std::cout << "7th test is OK" <<std::endl;
        }
    }

    try
    {
        text = format("{1}+{2}={0}", 2, "one");
    }
    catch(const std::exception & e)
    {
        if(std::string("Index larger than number of arguments or less than zero")==e.what())
        {
            std::cout << "8th test is OK" <<std::endl;
        }
    }

    try
    {
        text = format("{1}+{-1}={0}", 2, "one");
    }
    catch(const std::exception & e)
    {
        if(std::string("Index larger than number of arguments or less than zero")==e.what())
        {
            std::cout << "9th test is OK" <<std::endl;
        }
    }


    const std::string& name="Maxim";
    int age=22;
    const std::string&& lang="Russian";

    text = format("My name is {1}. My age is {0} years. My nature language is {2}. My English is very bad. But I learn it {3} years",age,name,lang, age/2);
    assert(text == "My name is Maxim. My age is 22 years. My nature language is Russian. My English is very bad. But I learn it 11 years");
    std::cout << "10th test is OK" << std::endl;

    std::cout << "All tests are OK" << std:: endl;
    return 0;
}
