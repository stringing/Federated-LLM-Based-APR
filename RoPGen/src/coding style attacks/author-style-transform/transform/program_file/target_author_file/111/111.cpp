#include<bits/stdc++.h>
using namespace std;
char maze[100][100];
bool vis[100][100];
int n,m,ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(in(tx,ty)&&maze[tx][ty]=='#'&&vis[tx][ty]==0){
            dfs(tx,ty);
        }
    }
    return;
}
int main(){
    freopen("hiking.in","r",stdin);
    freopen("hiking.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>maze[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0&&maze[i][j]=='#'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans;
}
