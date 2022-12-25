/*
@File  :offer_33.cpp
@Author:dfc
@Date  :2022/12/25  10:43
@Desc  : 二叉搜索树的后序遍历序列
*/
#include "iostream"
#include "vector"
using namespace std;

bool verify_tree(vector<int>& postorder, int start ,int end);

bool verifyPostorder(vector<int>& postorder)
{
    return verify_tree(postorder,0,postorder.size()-1);
}

bool verify_tree(vector<int>& postorder, int start ,int end)
{


    if (end<=start) return true;
    int left_start,left_end;
    int right_start,right_end;
    int root_val = postorder[end];
    int pos;
    for (int i = start; i <=end ; ++i) {
        if (postorder[i]>=root_val) // 这里取等是为了给pos托底  至少有个end赋值给他
        {
            pos= i;
            break;
        }
    }
    bool flag= true;
    for (int i = pos; i <=end ; ++i) {
        if (postorder[i]<root_val)  // 这里不能取等
        {
            return false;
            break;
        }
    }
    left_start = start; left_end = pos-1;
    right_start= pos;right_end = end-1;
    bool left_flag = verify_tree(postorder,left_start,left_end);
    bool right_flag = verify_tree(postorder,right_start,right_end);
    return flag and left_flag and right_flag;
}

 int main()
 {
    vector<int> postorder = {5, 4, 3, 2, 1};
    cout<<verifyPostorder(postorder);
 }