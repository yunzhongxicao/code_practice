/*
@File  :oppo_qiuzhao_1.cpp
@Author:dfc
@Date  :2023/8/26  17:24
@Desc  :
*/
#include "iostream"
#include "string"

using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n<4)
    {
        cout<<" "<<endl;
        return 0;
    }
    int count = 4;
    string result = "oppo";
    int carry =0;
    while (count<n)
    {
        if (carry % 3 ==0)
            result  += "p";
        if (carry % 3 ==1 )
            result += "p";
        if (carry % 3 == 2)
            result += "o";
        carry++;
        count++;
    }
    cout<<result;
}


