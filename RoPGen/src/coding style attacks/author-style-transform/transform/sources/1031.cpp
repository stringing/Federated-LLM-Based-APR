#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
char maze[105][105];
bool vis[105][105];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool in(int x,int y){
    return 0<=x&&x<=n&&0<=y&&y<=m;
}
void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(in(tx,ty)&&maze[tx][ty]=='#'&&!vis[tx][ty])dfs(tx,ty);
    }
}
int main(){
    freopen("hiking.in","r",stdin);freopen("hiking.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(maze[i][j]=='#'&&!vis[i][j]){
        
        dfs(i,j);cnt++;
    }
    cout<<cnt;
    return 0;
}
