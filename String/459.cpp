/*
@File  :459.cpp
@Author:dfc
@Date  :2022/9/4  10:25
@Desc  : ÖØ¸´µÄ×Ó×Ö·û´®
*/
#include "iostream"
#include "string"
using namespace std;

void get_next(int *next,const string& s);


bool repeatedSubstringPattern(string s);


int main()
{

}

void get_next(int *next,const string& s)
{
    int j =0;
    next[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (j>0 and s[i] != s[j])
        {
            j = next[j-1];
        }
        if (s[i]== s[j])
        {
            j++;
        }
        next[i] = j;
    }
}

bool repeatedSubstringPattern(string s)
{
    if (s.size() == 0) {
        return false;
    }
    int next[s.size()];
    get_next(next,s);
    int len = s.size();
    if (next[len-1] != 0 and  len % (len - next[len-1]) == 0)
    {
        return true;
    }
    return false;
}