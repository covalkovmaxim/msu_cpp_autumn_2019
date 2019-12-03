#include"Format.hpp"

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
