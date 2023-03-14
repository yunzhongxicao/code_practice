#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int MAXN = 200005;

vector<long long> G[MAXN];
long long cnt[MAXN]; // 记录每个节点的红色和蓝色连通块数量之差
string colors;    // 记录每个节点的颜色
long long ans;          // 记录边权值之和

// DFS遍历计算cnt数组
void dfs(long long u, long long fa) {
    long long tmpcnt=0;
    for (long long v : G[u]) {
        if (v == fa) continue;
        tmpcnt+=1;
    }
    if (tmpcnt==0)
    {
        cnt[u]=1;
        return;
    }
    cnt[u]=1;
    for (long long v : G[u]) {
        if (v == fa) continue;
        dfs(v, u);
        cnt[u]+=cnt[v];
        if (colors[u-1]==colors[v-1])
            cnt[u]--;
    }
}

long long dfs2(long long u, long long fa,long long m) {
    long long tmpcnt=0;
    for (long long v : G[u]) {
        if (v == fa) continue;
        if (colors[u-1]==colors[v-1])
        {
            tmpcnt+=abs(m-2*cnt[v]+1);
        }
        else
        {
            tmpcnt+=abs(m-2*cnt[v]);
        }
        tmpcnt+=dfs2(v,u,m);
    }
    return tmpcnt;
}


int main() {
    long long n;
    cin >> n >> colors;
    for (long long i = 1; i < n; i++) {
        long long u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    long long m=cnt[1];
    ans=dfs2(1, 0,m);

    cout << ans << endl;
    return 0;
}