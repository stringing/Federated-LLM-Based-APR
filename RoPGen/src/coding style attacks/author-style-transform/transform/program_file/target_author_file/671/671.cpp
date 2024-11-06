#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[1005][1005];
char maze[1005][1005];
int ans;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool in(int x,int y){
  return x>=0&&x<n&&y>=0&&y<m;
}
void dfs(int x,int y){
  vis[x][y]=true;
  for(int i=0;i<4;i++){
    int tx=x+dir[i][0];
    int ty=y+dir[i][1];
    if(in(tx,ty)&&!vis[tx][ty]&&maze[tx][ty]=='#'){
      dfs(tx,ty);
    }
  }
}
int main(){
  freopen("hiking.in","r",stdin);
    freopen("hiking.out","w",stdout);
cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>maze[i];
  }
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(maze[i][j]=='#'&&vis[i][j]){
        dfs(i,j);
        ans++;
      }
  cout<<ans<<endl;
  return 0;
}
