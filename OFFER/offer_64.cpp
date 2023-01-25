/*
@File  :offer_64.cpp
@Author:dfc
@Date  :2023/1/17  19:44
@Desc  :Çó1+2+¡£¡£+n
*/
#include "iostream"
using namespace std;

int result=0;
int sumNums(int n)
{
    (n>1) and sumNums(n-1);
    result +=n;
    return result;
}


