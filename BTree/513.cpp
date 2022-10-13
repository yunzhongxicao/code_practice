/*
@File  :513.cpp
@Author:dfc
@Date  :2022/10/10  10:38
@Desc  :找树左下角的值
*/

#include "iostream"
#include "stack"
#include "vector"
#include "queue"
#include <numeric>

using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode(){val=0;left=NULL;right=NULL;};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};


/* 这是非递归的写法
int findBottomLeftValue(TreeNode* root)
{
    vector<vector<int>> result;
    queue<TreeNode*> my_queue;
    TreeNode *p;

    if (!root) return 0;

    my_queue.push(root);
    while (!my_queue.empty())
    {
        int size = my_queue.size();
        vector<int> val;

        for (int i = 0; i < size; ++i) {
            p = my_queue.front();
            my_queue.pop();
            val.push_back(p->val);
            if (p->left) my_queue.push(p->left);
            if (p->right) my_queue.push(p->right);
        }
        result.push_back(val);
    }
    return result.back()[0];

}*/

void get_max_depth(TreeNode* p, int depth, int &max_depth, TreeNode &max_node);
int findBottomLeftValue(TreeNode* root)
{
    TreeNode result_node;
    int max_depth = 0;
    int result;
    if (!root) return result;

    get_max_depth(root,1,max_depth,result_node);
    return result_node.val;
}


void get_max_depth(TreeNode* p, int depth, int &max_depth, TreeNode &max_node)  // 注意 这里的max_node不能用指针传递
                                                                                // 因为指针传递本质上是值传递 是复制 所以在里面修改指针的值无法影响到实参
                                                                                // 而这里我是要把节点传递出来 所以不能用指针传递
                                                                                // 那就可以用引用传递 传进去的就是一个TreeNode型 的变量，然后将变量重新赋值
                                                                                // 再次理解一下 引用传递的参数其实就是一个变量，但是由于间接寻址 可以实现对形参修改影响到实参
{
    if (depth>max_depth)
    {
        max_depth = depth;
        max_node = *p;
    }
    if (p->left==NULL and p->right ==NULL) return;

    if (p->left)
    {
        depth++;
        get_max_depth(p->left,depth,max_depth,max_node);
        depth--;
    }
    if (p->right)
    {
        depth++;
        get_max_depth(p->right,depth,max_depth,max_node);
        depth--;
    }
}
