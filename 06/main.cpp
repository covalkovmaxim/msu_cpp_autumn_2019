#include"Format.h"

int main()
{
    std::vector<std::string> result;
    std::string ee="{0}+{0}={1}";
    //std::regex rx("\\{\\d*\\}");
    //std::cout << regex_search(ee.begin(),ee.end(),rx) <<std::endl;
    int ii=0;
    //ii=std::stoi(ee);
   /* std::cout <<  ee.size()<< std::endl;
    GetArguments(result,"one",2);
    for(int i=0;i<result.size();i++)
    {
        std::cout << result[i] << std::endl;
    }
    std::cout << PutArguments(ee,result) << std:: endl;
    */
    std::string Result=format(ee,"one",2);
    std::cout << Result << std::endl;
    return 0;
}
