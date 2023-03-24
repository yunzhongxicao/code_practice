#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* fun(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    int qishuceng=0;
    int oushuceng=0;
    int depth=0;
    while (!que.empty()) {
        int size = que.size();
        depth++;
        if(depth%2==1) qishuceng+=size;
        else if(depth%2==0)oushuceng+=size;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }
    int n=qishuceng+oushuceng;
    int min_ceng=min(qishuceng,oushuceng);
    int sum1=0;
    int sum2=0;

    for (int i=n;i>0;i--){
        if(i>n-min_ceng){
            sum1+=i;
            sum2+=i;
        }
        else{
            sum1+=i;
        }
    }
    if(sum2<sum1-sum2) return NULL;
}
