/*
@File  :110.cpp
@Author:dfc
@Date  :2022/10/9  11:32
@Desc  : 平衡二叉树
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
int get_height(TreeNode *t);
bool isBalanced(TreeNode* root)
{
    if (!root) return true;
    bool flag ;
    return get_height(root) != -1;
}

int get_height(TreeNode *t)  // 这个算高度的过程已经走了一遍遍历了，所以上面判断不用再走遍历了
{
    if (!t) return 0;
    int left_height = get_height(t->left);

    if (left_height==-1) return -1;  // 如果左子树高度为-1 那么父节点的高度就直接为-1  这样就可以让不平衡这个参数一路向上传上去
                                    // 所以求root节点的高度 如果有不平衡的子树  就可以一路传上去 使得为-1

    int right_height = get_height(t->right);

    if (right_height==-1) return -1;


    if (abs(left_height-right_height)>=2) return -1;  // 如果左右子树高度差大于2 那就让父节点高度为-1 表明不是平衡了
    else return 1+max(left_height,right_height);

}
