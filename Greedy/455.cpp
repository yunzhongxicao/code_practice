/*
@File  :455.cpp
@Author:dfc
@Date  :2022/10/26  11:56
@Desc  : �ַ�����
*/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

// g��θ�� s�Ǳ��ɳߴ�
int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int num=0;
    int index_g=(int)g.size()-1;
    for (int i = (int)s.size()-1; i >=0 and index_g>=0; i--) { // ��ʵ����g������ �ҵ��˾���Ȼ���� �Ҳ�����˵��û�� ��Ȼ����
        if (s[i]>=g[index_g])
        {
            index_g--;
            num++;
        }
        else
        {
            index_g--;
            i++;
        }
    }
    return num;
}

int main()
{
    vector<int> g={1,2};
    vector<int> s={1,2,3};
     int result= findContentChildren(g,s);
     cout<<result;
}