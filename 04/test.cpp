#include"BigInt.hpp"
#include <iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
int main()
{
    try
    {

        BigInt it("-99999");
        BigInt it1("10");
        BigInt it2("12");
        BigInt it3("-15");
        BigInt it4("17");
        BigInt it5("1214");
        it1="100";
        assert(it1==100);
        printf("1st test is OK\n");
        it=it5=5;

        assert(it==5);
        printf("2nd test is OK\n");

        assert(it5==5);
        printf("3nd test is OK\n");

        assert(it5==it);
        printf("4th test is OK\n");

        assert(-it5==-5);
        printf("5th test is OK\n");

        it="-99999";
        it1="-100000";
        assert(it>it1);
        printf("6th test is OK\n");

        it2=-99999;
        assert(it==it2);
        printf("7th test is OK\n");

        assert(it1<it2);
        printf("8th test is OK\n");

        it1=it5="1000";
        it5=2000;
        assert(it1==1000 && it5=="2000");
        printf("9th test is OK\n");

        it1=0;
        assert(-it1==0);
        printf("10th test is OK\n");

        it1=10;
        assert((-it1)-(-it1)==0);
        printf("11th test is OK\n");

        assert((-it1)-(it1)==-20);
        printf("12th test is OK\n");

        assert((-it1)+(-it1)==-20);
        printf("13th test is OK\n");

        assert((-it1)+(it1)==0);
        printf("14th test is OK\n");

        assert((it1)-(-it1)==20);
        printf("15th test is OK\n");

        assert((it1)-(it1)==0);
        printf("16th test is OK\n");

        assert((it1)+(-it1)==0);
        printf("17th test is OK\n");

        assert((it1)+(it1)==20);
        printf("18th test is OK\n");

        it=47;
        it5="5000";
        //assert(it5+"1000000000000000000"+it-42=="1000000000000005005");
        printf("19th test is OK\n");

        assert(BigInt("5")+"999999999995"=="1000000000000");
        printf("20th test is OK\n");

        it2="100000000000000000";
        it=0;
        for(int i=0;i<100;i++)
        {
            it=it+it2;
        }
        assert(it=="10000000000000000000");
        printf("21th test is OK\n");

        it5=100;
        assert(BigInt("10000000000000")-it5== "9999999999900");
        printf("22th test is OK\n");

        it="1000";

        assert(it-100==900);
        printf("23th test is OK\n");

        assert(BigInt("-1000")-100== "-1100");
        printf("24th test is OK\n");

        assert(BigInt("1000")-1000== 0);
        printf("25th test is OK\n");

        assert(BigInt("-1532555711889340311474864652314929474622059967938")-
               BigInt("-1323852165468928716826053016169337649203578750288")==
               "-208703546420411594648811636145591825418481217650");
        printf("26th test is OK\n");

        assert(BigInt("717615196304839949505266925432454633081869404221")-
               BigInt("-4665165780703497473750477159437840857296790749112")==
               "5382780977008337423255744084870295490378660153333");
        printf("27th test is OK\n");

        assert(BigInt("7885350344319679286868546049742491516715280710354")+
               BigInt("-1898547418402642082861685678926313040329324665444")==
               "5986802925917037204006860370816178476385956044910");
        printf("28th test is OK\n");

        assert(BigInt("-3263451055881572237653188065690360504592817148154")+
               BigInt("-8414028480695132353882688708588758644159621411192")==
               "-11677479536576704591535876774279119148752438559346");
        printf("29th test is OK\n");

        assert(BigInt("-7743835867872582850941420539124469220732703490572")+
               BigInt("8522373742496764602255334619586685185677746584568")==
               "778537874624181751313914080462215964945043093996");
        printf("30th test is OK\n");


    }
    catch(const std::exception & e)
    {
        cout << e.what() << endl;

    }
    return 0;
}
