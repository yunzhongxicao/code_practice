/*
@File  :738.cpp
@Author:dfc
@Date  :2022/11/1  21:35
@Desc  : 单调递增的数字
*/
#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
using namespace std;

int monotoneIncreasingDigits(int n);

int monotoneIncreasingDigits(int n)
{
    vector<int> a;
    int n_copy = n;
    while (n_copy>0)
    {
        int tmp = n_copy % 10;
        a.push_back(tmp);
        n_copy = n_copy / 10;
    }
    // 注意 此时的序列是反着的 从个位到最高位
/*     这种遍历顺序是错误的 还是要从低位往高位遍历
    int flag = -1;
    for (int i = a.size()-1 ; i>=1 ; --i) {  // 可以从高位向低位遍历，因为要最大 所以高位尽量能留就留 如果出现了递减的情况 那么就只能把当前-1 后面的全部变成9 这样肯定是最大的
        if (a[i]>a[i-1])
        {
            a[i]--;
            flag = i-1;
            break;
        }
    }
    for (int i =flag ; i >=0 ; --i) {
        a[i] = 9;
    }*/

    // 找到从低位往高位遍历的最后一位，在这之后的低位都置为9
    int flag = -1;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i]>a[i-1])
        {
            a[i]--;
            flag=i-1;
        }
    }
    for (int i = 0; i <=flag ; ++i) {
        a[i]=9  ;
    }
    int result=0;
    for (int i = 0; i < a.size(); ++i) {
        result+=a[i]* pow(10,i);
    }
    return result;
}

int main()
{
    int n = 332;
    int result = monotoneIncreasingDigits(n);
    cout<<result;
}

