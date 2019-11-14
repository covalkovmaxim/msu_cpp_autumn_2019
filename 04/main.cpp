#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<math.h>
#include"BigInt.hpp"
int main()
{
    BigInt it("-99999");
    BigInt it1("10");
    BigInt it2("12");
    BigInt it3("-15");
    BigInt it4("17");
    BigInt it5("1214");

    it=it5=5;
    std::cout << it<< it5 <<std::endl;
    it5="1000";
    std::cout << it<< it5 <<std::endl;
    std::cout<<(-it1)-(-it1) <<(-it1)-(it1) <<(-it1)+(-it1) <<(-it1)+(it1)<<(it1)-(-it1)<<(it1)-(it1)<<(it1)+(-it1)<<(it1)+(it1);
    std::cout << it5+"1000000000000000000"+it-42 <<std::endl;
    std::cout << BigInt("5")+"999999999995" <<std::endl;
    std::cout << BigInt("10000000000000")-it5 <<std::endl;
    std::cout << -it<< it5 <<std::endl;

    return 0;
}
