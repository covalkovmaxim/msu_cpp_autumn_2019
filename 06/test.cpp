#include "Format.hpp"

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
