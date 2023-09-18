/*
@File  :shenxinfu_2.cpp
@Author:dfc
@Date  :2023/9/6  19:41
@Desc  :
*/
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0, left = 0;
        unordered_map<char, int> cnt;
        for (int right = 0; right < n; ++right) {
            char c = s[right];
            ++cnt[c];
            while (cnt[c] > 1) // ������Ҫ��
                --cnt[s[left++]];
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    int a;
    vector<int> nums;
    while (cin>>a)  // cin�Ὣ�ո�ͻ�����Ϊ����
    {
        nums.push_back(a);
        if (cin.get()=='\n') // ÿ�ζ��������getȥ���������Ľ����ַ�������cin���
        {
            break;
        }
    }
    int left =0 , right =0;
    unordered_map<int,int> my_map;
    int result = 0;
    while (right<=nums.size()-1)
    {
        my_map[nums[right]]++;
        while (my_map[nums[right]]>1)
        {
            my_map[nums[left]]--;
            left++;
        }
        result = max(result, right-left+1);
        right++;
    }
    cout<<result;
}