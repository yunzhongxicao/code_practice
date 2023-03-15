/*
@File  :337_second.cpp
@Author:dfc
@Date  :2023/3/15  15:02
@Desc  :
*/
#include "bits/stdc++.h"
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

// 树形dp的模板
/*const int N = 1e4 + 10;
vector<int> tr[N]; // 这里是一个数组 每个元素是vector<int>
int f[N][2], v[N], Happy[N], n;
void dfs(int u) {
    f[u][0] = 0; f[u][1] = Happy[u];
    for (auto v : tr[u]) {
        dfs(v);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> Happy[i];
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        v[x] = 1;// x has a father
        tr[y].push_back(x);
    }

    int root;
    for (int i = 1; i <= n; ++i)
        if (!v[i]) {root = i; break;}
    dfs(root);
    cout << max(f[root][0], f[root][1]) << "\n";
}*/

vector<int> dfs(TreeNode *p)  // 表示以p为根节点的结果， 注意 上面那种情况是有全局变量来存储子孩子的情况，这里没有 所以需要返回值
{
    // 两个状态，p不偷或者偷
    if (!p) return vector<int>{0,0};
    vector<int>left = dfs(p->left);
    vector<int>right = dfs(p->right);
    int temp0 = max(left[0],left[1]) + max(right[0],right[1]);
    int temp1 = left[0] +right[0] + p->val;
    return vector<int>{temp0,temp1};
}

int rob(TreeNode* root)
{
    vector<int> result = dfs(root);
    return max(result[0],result[1]);
}
