#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[40][40];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ans = 0;
int b[40][40];
int anss[40][40];
//ֱ�Ӱ��߹��ĺ����Ⱦ�ɰ�ɫ
void dfs(int x, int y) {
    //�ĸ�����ȥ��
    for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 0 && yy >= 0 && xx < n && yy < m && b[xx][yy] == 1) {
            b[xx][yy] = 0;
            dfs(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    char t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> t;
            if(t=='W'){a[i][j]=0;}
            else{a[i][j]=1;}
            b[i][j]=a[i][j];
        }
    }
    for (int p = 0; p < n; ++p) {
        for (int q = 0; q<m; ++q) {
            b[p][q]=0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {

                    //ÿ������Ӷ�Ҫ��Ϊ�������ʼ����
                    if (b[i][j] == 1) {
                        dfs(i, j);
                        //��ͨ��ĸ������������Ĵ���
                        ans++;
                    }
                }
            }
            anss[p][q]=ans;
            ans=0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    b[i][j]=a[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<anss[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


