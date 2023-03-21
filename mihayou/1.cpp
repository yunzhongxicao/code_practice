
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int maxn=100;
struct Node{
    int x,y;
}node;
int n,m;
static  int r=0;
static int g=0;
static int b=0;
char matrix[maxn][maxn];
bool inq[maxn][maxn]={false};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
bool judge(int x,int y,char t){
    if(x>=n||x<0||y>=m||y<0) return false;
    if(matrix[x][y]!=t||inq[x][y]==true) return false;
    return true;
}
void DFS(int x,int y,char t){

    inq[x][y]=true;
    for(int i=0;i<4;i++){
        int newX=x+X[i];
        int newY=y+Y[i];
        if(judge(newX,newY,t)){
            r++;
            DFS(newX,newY,t);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int x=0;x<n;x++){

        scanf("%s",&matrix[x]);

    }
    int ans=0;
    int wans=0;
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){

            if(matrix[x][y]=='G'&&inq[x][y]==false){
                g++;
                DFS(x,y,'G');  //访问整个块

                ans+=(g-1);  //块数+1
                g=0;
            }
        }
    }

    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){

            if(matrix[x][y]=='B'&&inq[x][y]==false){
                b++;
                DFS(x,y,'B');  //访问整个块

                ans+=(b-1);  //块数+1
                b=0;
            }
        }
    }

    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){

            if(matrix[x][y]=='R'&&inq[x][y]==false){
                r++;
                DFS(x,y,'R');  //访问整个块

                ans+=(r-1);  //块数+1
                r=0;
            }
        }
    }


    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(matrix[x][y]=='G'){
                matrix[x][y]='B';
            }
            inq[x][y]=false;
        }}

    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){

            if(matrix[x][y]=='B'&&inq[x][y]==false){

                DFS(x,y,'B');  //访问整个块
                wans++;  //块数+1
            }
        }
    }


    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){

            if(matrix[x][y]=='R'&&inq[x][y]==false){

                DFS(x,y,'R');  //访问整个块
                wans++;  //块数+1
            }
        }
    }

    int h=ans-wans;
    printf("%d\n",h);
}