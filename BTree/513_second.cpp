/*
@File  :513_second.cpp
@Author:dfc
@Date  :2023/3/6  10:51
@Desc  : 寻找树左下角的值
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

/*int findBottomLeftValue(TreeNode* root) // 层序遍历的方法
{
    if (!root) return 0;
    queue<TreeNode *> my_queue;
    my_queue.push(root);
    vector<vector<int>> result;
    TreeNode *p;
    while (!my_queue.empty())
    {
        int size  = my_queue.size();
        vector<int> path;
        for (int i = 0; i < size; ++i) {
            p = my_queue.front();
            my_queue.pop();
            path.push_back(p->val);
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
        result.push_back(path);
    }
    return result.back()[0];
}*/

int depth=0;
int max_depth = 0;
int result = 0;
void backtracking(TreeNode *p) // 在进入p节点这一层之前已经把深度+1了
{
    if (!p) return;
    if (depth>max_depth)
    {
        depth = max_depth;
        result = p->val;
    }
    depth++;
    backtracking(p->left);
    depth--;
    depth++;
    backtracking(p->right);
    depth--;
}

int findBottomLeftValue(TreeNode* root)
{
    if (!root) return 0;
    depth++;
    backtracking(root);
    return result;
}

