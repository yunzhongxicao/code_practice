/*
@File  :257.cpp
@Author:dfc
@Date  :2022/10/9  16:30
@Desc  : ������������·��
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};
void traversal(TreeNode *t, vector<int> &path, vector<string> &result);
vector<string> binaryTreePaths(TreeNode* root);
vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> result;
    if (!root) return result;
    vector<int> path;

    traversal(root,path,result);
    return result;
}

void traversal(TreeNode *t, vector<int> &path, vector<string> &result)
{
    path.push_back(t->val);

    if (t->left==NULL and t->right == NULL) // ������ֹ�����ǵ�Ҷ�ӽڵ� ֮���Բ����ж�t����Ϊ��  ����Ϊ�����ʱ����ж��� ���ÿյĴ���ȥ
    {
        string tpm;
        tpm = to_string(path[0]);
        for (int i = 1; i < path.size(); ++i) {
            tpm +="->" + to_string(path[i]);
        }
        result.push_back(tpm);
        return;
    }
    if (t->left)
    {
        traversal(t->left,path,result );
        path.pop_back();
    }
    if (t->right)
    {
        traversal(t->right,path,result);
        path.pop_back();
    }

}

