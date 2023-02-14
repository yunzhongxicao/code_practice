/*
@File  :task_4.cpp
@Author:dfc
@Date  :2023/2/12  14:58
@Desc  :
*/
#include "vector"
#include "iostream"

using namespace std;

int solution(vector<int> &A, int M)
{
    if (A.size()<=1) return 1;
    int result = 0;
    for (int i = 1; i < A.size(); ++i) {
        int count =1;
        for (int j = 0; j < i; ++j) {
            if (abs(A[i]-A[j]) % M==0)
                count++;
        }
        result = max(result,count);
    }
    return result;
}

int main()
{
    vector<int> A = {7, 1, 11, 8, 4, 10};
    int M = 3;
    cout<<solution(A,M);
}

